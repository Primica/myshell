//
// Created by Arthur Malfere on 14/12/2024.
//

#include "../myshell.h"

void cat(const std::vector<std::string>& args) {
    if (args.size() == 1) {
        std::cerr << "cat: missing file operand" << std::endl;
        return;
    }
    for (size_t i = 1; i < args.size(); i++) {
        std::ifstream file(args[i]);
        if (!file.is_open()) {
            std::cerr << "cat: " << args[i] << ": No such file or directory" << std::endl;
            continue;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}
