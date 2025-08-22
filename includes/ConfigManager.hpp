#pragma once
#include <string>
#include <vector>
#include <map>
// #include <>
#include "LocationHandler.hpp"

class ConfigManager
{
public:
    std::string _root;
    std::string _port;
    std::string _host;
    std::vector<std::string> _serverName;
    std::map<int, std::string> _errors;
    std::vector<std::string> _index;
    std::map<std::string, LocationHandler> _locations;
    unsigned long maxBodySize;
private:
    std::map<std::string, void(ConfigManager::*)(std::vector<std::string>)> DirectiveParser;
    void initMap();
    void validateRoot(const std::vector<std::string>);
    void validateHost(const std::vector<std::string>);
    void validateListen(const std::vector<std::string>);
    void validateServerName(const std::vector<std::string>);
    void validateIndex(const std::vector<std::string>);
    void validateErors(const std::vector<std::string>);
    void validateMaxBodySize(const std::vector<std::string>);
public:
    ConfigManager();
    void validateDirective(std::string&);
    ~ConfigManager();
};
