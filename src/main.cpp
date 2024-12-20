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

void run(const std::vector<std::string>& args) {
    static const std::vector<std::pair<std::string, void(*)(const std::vector<std::string>&)>> commands = {
        {"echo", echo},
        {"cd", cd},
        {"pwd", pwd},
        {"ls", ls},
        {"cat", cat},
        {"mkdir", mkdir},
        {"rmdir", rmdir},
    };

    for (const auto&[fst, snd] : commands) {
        if (args[0] == fst) {
            snd(args);
            return;
        }
    }

    std::cerr << args[0] << ": command not found" << std::endl;
}

int main() {
    while (true) {
        std::string prompt = std::string(show_current_path()) + " myshell> ";
        char* line = readline(prompt.c_str());
        if (!line) {
            break;
        }
        if (line[0]) {
            add_history(line);
            std::vector<std::string> args = split(line);
            run(args);
        }
        free(line);
    }
    return 0;
}