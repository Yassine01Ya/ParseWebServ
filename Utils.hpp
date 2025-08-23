#pragma once 
#include <string>
#include <vector>
#include <map>

class ConfigManager;

// #include "LocationHandler.hpp"
// #include "ConfigManager.hpp"

class Utils
{
private:
    Utils();
    ~Utils();
public:
    static std::vector<std::string> SplitByDelimiter(const std::string& input, const std::string& delimiter);

    
};

