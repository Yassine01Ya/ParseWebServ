#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include "Utils.hpp"
#include "ConfigManager.hpp"
#include "LocationHandler.hpp"



int main()
{
	std::vector<std::string> tVector;
	std::vector<std::string> tVector2;
	std::string delimiter = "	";
	std::string string = "	hello	world	from yassine";

	tVector2 = Utils::SplitByDelimiter(string, delimiter);
	std::cout << "\n--------------------------------------------\n";
	for (size_t i = 0; i < tVector2.size(); i++)
	{
		std::cout << "[" << tVector2[i] << "]";
	}
	std::cout << "\n--------------------------------------------\n";

}