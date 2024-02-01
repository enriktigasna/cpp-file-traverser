// Medicine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include "HomePath.h"
#include "GetFiles.h"

namespace fs = std::filesystem;

int main()
{
	fs::path homePath = getHomePath();
	std::cout << "Root directory that will be searched: " << homePath << std::endl;
	std::cout << "What extension of file do you want to find? " << std::endl;

	std::string ext;
	std::cin >> ext;

	
	std::vector<fs::directory_entry> children = getFiles(homePath, true, ext);

	for(auto entry : children) {
		std::cout << entry << "\n";
	}
}

