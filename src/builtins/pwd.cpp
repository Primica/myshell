//
// Created by Arthur Malfere on 12/12/2024.
//

#include "myshell.h"

#include <filesystem>

void pwd(const std::vector<std::string>& args) {
    if (args.size() > 2) {
        std::cerr << "pwd: too many arguments" << std::endl;
        return;
    }

    if (args.size() == 2) {
        std::filesystem::path filePath(args[1]);
        if (std::filesystem::exists(filePath)) {
            std::cout << std::filesystem::absolute(filePath).parent_path() << std::endl;
        } else {
            std::cerr << "pwd: " << args[1] << ": No such file or directory" << std::endl;
        }
    } else {
        std::cout << show_current_path() << std::endl;
    }
}

