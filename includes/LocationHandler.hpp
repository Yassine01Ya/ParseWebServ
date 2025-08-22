#pragma once

#include <string>
#include <map>
#include <vector>
#include "ConfigManager.hpp"

class LocationHandler
{
private:
    int first;
    ConfigManager* config;
    std::map<std::string, void(LocationHandler::*)(std::vector<std::string>)>DirectiveLocations;
    void validatePath(const std::vector<std::string>&);
    void validateRoot(const std::vector<std::string>&);
    void validateRoderict(const std::vector<std::string>&);
    void validateErrors(const std::vector<std::string>&);
public:

    LocationHandler(ConfigManager &config);
    ~LocationHandler();
public:
    std::string _cgi;
    std::string _cgiPath;
    std::string _root;
    std::string _path;
    std::string _redirect;

};