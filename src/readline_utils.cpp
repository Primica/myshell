//
// Created by Arthur Malfere on 15/12/2024.
//

#include "myshell.h"

std::vector<std::string> history;

char* readline(const char* prompt) {
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) {
        return nullptr;
    }
    auto cstr = new char[line.length() + 1];
    std::strcpy(cstr, line.c_str());
    return cstr;
}

void add_history(const char* line) {
    history.emplace_back(line);
}