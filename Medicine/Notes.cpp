// Medicine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include "HomePath.h"
#include "GetChildren.h"

namespace fs = std::filesystem;

int main()
{
	fs::path homePath = getHomePath();
	std::cout << homePath << std::endl;
	
	std::vector<fs::directory_entry> children = getChildren(homePath, true);

	for(auto entry : children) {
		std::cout << entry << std::endl;
	}
}

