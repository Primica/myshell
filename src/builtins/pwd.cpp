//
// Created by Arthur Malfere on 12/12/2024.
//

#include "myshell.h"

void pwd(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cerr << "pwd: too many arguments" << std::endl;
        return;
    }
    std::cout << show_current_path() << std::endl;
}

