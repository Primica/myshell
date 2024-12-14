//
// Created by Arthur Malfere on 12/12/2024.
//

#ifndef ECHO_H
#define ECHO_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>
#include <unistd.h>
#include <climits>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <readline/readline.h>
#include <readline/history.h>

class TabCompletion {
public:
    TabCompletion();
    [[nodiscard]] std::string complete(const std::string& prefix) const;
    std::vector<std::string> commands;
};


// Built-in functions
void echo(const std::vector<std::string>& args);
void cd(const std::vector<std::string>& args);
char *show_current_path();
void pwd(const std::vector<std::string>& args);
void ls(const std::vector<std::string>& args);

#endif //ECHO_H