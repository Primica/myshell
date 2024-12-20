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
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <cerrno>
#include <string>

// Built-in functions
void echo(const std::vector<std::string>& args);
char *show_current_path();
void cd(const std::vector<std::string>& args);
void pwd(const std::vector<std::string>& args);
void ls(const std::vector<std::string>& args);
void cat(const std::vector<std::string>& args);

// Directory related functions
void mkdir(const std::vector<std::string>& args);
void rmdir(const std::vector<std::string>& args);

// Helper functions
char* readline(const char* prompt);
void add_history(const char* line);

#endif //ECHO_H
