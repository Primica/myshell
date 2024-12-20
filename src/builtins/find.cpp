//
// Created by Arthur Malfere on 20/12/2024.
//
#include "myshell.h"

void find(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Error: find: missing operand" << std::endl;
        return;
    }

    if (args.size() < 3) {
        std::cerr << "Error: find: missing search term" << std::endl;
        return;
    }

    const std::string& searchTerm = args[2];
    const std::string path = show_current_path();

    if (!std::filesystem::exists(path)) {
        std::cerr << "Error: Directory does not exist: " << path << std::endl;
        return;
    }

    if (!std::filesystem::is_directory(path)) {
        std::cerr << "Error: Not a directory: " << path << std::endl;
        return;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::ifstream file(entry.path());
            std::string line;
            while (std::getline(file, line)) {
                if (line.find(searchTerm) != std::string::npos) {
                    std::cout << entry.path() << std::endl;
                    break;
                }
            }
        }
    }
}