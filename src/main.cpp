#include "myshell.h"

std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> args;
    std::string arg;
    std::stringstream ss(line);
    while (ss >> arg) {
        args.push_back(arg);
    }
    return args;
}

void run (const std::vector<std::string>& args) {
    if (args[0] == "echo") {
        echo(args);
    } else if (args[0] == "cd") {
        cd(args);
    } else if (args[0] == "pwd") {
        pwd(args);
    } else if (args[0] == "ls") {
        ls(args);
    } else {
        std::cerr << args[0] << ": command not found" << std::endl;
    }
}

int main() {
    const std::string prompt = show_current_path() + std::string(" $ ");
        char* line = readline(prompt.c_str());
        if (!line) {
            return 1;
        }
        add_history(line);
        const std::string str_line(line);
        const std::vector<std::string> args = split(str_line);
        run(args);
        free(line);
    return 0;

}