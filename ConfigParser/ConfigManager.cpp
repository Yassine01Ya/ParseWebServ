#include "ConfigManager.hpp"

ConfigManager::ConfigManager()
{
    this->initMap();
    this->_root = "";
    this->_host = "";
    this->_port = "";
    this->maxBodySize = 1024;
}

void ConfigManager::validateDirective(std::string &token)
{
    std::vector<std::string>Splited = Utils::SplitByDelimiter(token, "\t");
    std::map<std::string, void(ConfigManager::*)(std::vector<std::string>)>::iterator it = this->DirectiveParser.find(Splited[0]);
    if(it == this->DirectiveParser.end())
        std::runtime_error("unknown directive " + Splited[0]);// throw exption for unknown directive 
    (this->*(it->second))(std::vector<std::string>(Splited.begin() + 1, Splited.end()));
}   

ConfigManager::~ConfigManager()
{
}

void ConfigManager::initMap()
{
    this->DirectiveParser.insert(std::make_pair("Listen", &ConfigManager::validateListen));
    this->DirectiveParser.insert(std::make_pair("root", &ConfigManager::validateRoot));
    this->DirectiveParser.insert(std::make_pair("host", &ConfigManager::validateHost));
    this->DirectiveParser.insert(std::make_pair("server_name", &ConfigManager::validateServerName));
    this->DirectiveParser.insert(std::make_pair("index", &ConfigManager::validateIndex));
    this->DirectiveParser.insert(std::make_pair("client_max_body_size", &ConfigManager::validateMaxBodySize));
    this->DirectiveParser.insert(std::make_pair("error_page", &ConfigManager::validateErors));
}

void ConfigManager::validateRoot(const std::vector<std::string> root)
{
    if(root.size() < 1)
        std::runtime_error("Empty root");
    if (root.size() > 1)
        std::runtime_error("Multiple roots");
    if (!this->_root.empty())
        std::runtime_error("root already defined");
    this->_root = root[0];
    if(this->_root[_root.length() - 1] == '/' && _root.length() != 1)
        this->_root.erase(_root.length() - 1);
}

void ConfigManager::validateHost(const std::vector<std::string> host) 
{
    if (host.size() < 1)
        std::runtime_error("Empty host");
    if (host.size() > 1)
        std::runtime_error("Multiple host");
    if (!this->_host.empty())
        std::runtime_error("host already defined");
    this->_host = host[0];    
}

void ConfigManager::validateListen(const std::vector<std::string> listen)
{
    if (listen.size() < 1)
        std::runtime_error("Empty listen");
    if (listen.size() > 1)
        std::runtime_error("Multiple listen");
    if (!this->_port.empty())
        std::runtime_error("listen already defined");
    this->_port = listen[0];
}

void ConfigManager::validateServerName(const std::vector<std::string>server_name)
{
    if (!server_name.size())
        std::runtime_error("Empty server_name");
    if (!this->_port.size())
        std::runtime_error("Multiple server_name directive");
    for (size_t i = 0; i < server_name.size(); i++)
        this->_serverName.push_back(server_name[i]);
}

void ConfigManager::validateIndex(const std::vector<std::string>index)
{
        if (!index.size())
        std::runtime_error("Empty index");
    if (!this->_port.size())
        std::runtime_error("Multiple index directive");
    for (size_t i = 0; i < index.size(); i++)
        this->_index.push_back(index[i]);
}

void ConfigManager::validateErors(const std::vector<std::string>error_page)
{
    if(error_page.size() != 2)
        std::runtime_error("Bad usage of error_page");
    // we need to parse value code of error_page
    this->_errors[atoi(error_page[0]. c_str())] = error_page[1];
}

void ConfigManager::validateMaxBodySize(const std::vector<std::string>)
{
}
