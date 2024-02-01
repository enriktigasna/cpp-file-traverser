#pragma once

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::directory_entry> getFiles(fs::path folderPath, bool recursive=false, std::string fileExtension=".js");