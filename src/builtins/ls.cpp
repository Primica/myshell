//
// Created by Arthur Malfere on 12/12/2024.
//

#include "../myshell.h"

void ls(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cerr << "ls: too many arguments" << std::endl;
        return;
    }
    for (const std::filesystem::directory_iterator it("."); const auto& entry : it) {
        std::cout << entry.path().filename().string() << "\t";
    }
    std::cout << std::endl;
}