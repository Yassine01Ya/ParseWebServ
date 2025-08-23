#include "Utils.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{
}

std::vector<std::string> Utils::SplitByDelimiter(const std::string& string, const std::string& delimiter)
{
	std::vector<std::string> stringOutput
    ;
    size_t startPosition = 0, endPosition;
    size_t delimiterLenght = delimiter.length();
    std::string token;

	while ((endPosition = string.find(delimiter, startPosition)) != std::string::npos)
	{
        token = string.substr(startPosition, endPosition - startPosition);
        startPosition = endPosition + delimiterLenght;
        if (!token.empty())
        	stringOutput.push_back(token);
    }
    if (!string.substr(startPosition).empty())
    	stringOutput
        .push_back(string.substr(startPosition));
    return stringOutput
    ;
}



