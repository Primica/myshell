//
// Created by Arthur Malfere on 12/12/2024.
//

#include "myshell.h"


char *show_current_path() {
    char *buf = getcwd(nullptr, 0);
    if (buf == nullptr) {
        std::cerr << "cd: getcwd failed" << std::endl;
        exit(1);
    }
    return buf;
}

void change_directory(const std::string& path) {
    const std::filesystem::path dir = path;
    if (!exists(dir) || !is_directory(dir)) {
        std::cerr << "cd: " << path << ": No such file or directory" << std::endl;
        return;
    }
    current_path(dir);
}

void cd(const std::vector<std::string>& args) {
    if (args.size() == 1) {
        change_directory(getenv("HOME"));
    } else if (args.size() == 2) {
        change_directory(args[1]);
    } else {
        std::cerr << "cd: too many arguments" << std::endl;
    }
}