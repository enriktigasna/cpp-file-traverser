#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::directory_entry> getFiles(fs::path folderPath, bool recursive=false, std::string fileExtension="") {
    std::vector<fs::directory_entry> children;
    try {
        if (recursive) {
            if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
                for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
                    if (fs::exists(entry.status()) && entry.path().extension() == fileExtension || fileExtension == "") {
                        children.push_back(entry);
                    }
                }
            }
        }
        else {
            if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
                for (const auto& entry : fs::directory_iterator(folderPath)) {
                    if (fs::is_directory(entry.status())) {
                        children.push_back(entry);
                    }
                }
            }
        }
    }
    catch (fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return children;
}
