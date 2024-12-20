#include "myshell.h"

void createDirectory(const std::string& path) {
    if (mkdir(path.c_str(), 0755) == -1) {
        std::cerr << "Error: Unable to create directory " << path << std::endl;
    } else {
        std::cout << "Directory created: " << path << std::endl;
    }
}

bool goToDirectory(const std::string& path) {
    if (chdir(path.c_str()) == -1) {
        std::cerr << "Error: Unable to change directory to " << path << std::endl;
        return false;
    }
    return true;
}

void mkdir(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Error: mkdir: missing operand" << std::endl;
        return;
    }

    for (size_t i = 1; i < args.size(); i++) {
        createDirectory(args[i]);
        std::cout << "Do you want to go to the new directory " << args[i] << "? (y/n): ";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y') {
            if (!goToDirectory(args[i])) {
                std::cerr << "Error: Unable to change to directory " << args[i] << std::endl;
            }
        }
    }
}

