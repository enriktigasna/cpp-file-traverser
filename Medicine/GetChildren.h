#pragma once

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::directory_entry> getChildren(fs::path folderPath, bool recursive=false);