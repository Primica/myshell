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

TabCompletion tabCompletion;

char** completion(const char* text, const int start, int end) {
    rl_attempted_completion_over = 1;
    char** matches = nullptr;
    if (start == 0) {
        matches = rl_completion_matches(text, [](const char* text, int state) -> char* {
            static size_t list_index, len;
            if (!state) {
                list_index = 0;
                len = strlen(text);
            }
            while (list_index < tabCompletion.commands.size()) {
                const std::string& cmd = tabCompletion.commands[list_index++];
                if (cmd.compare(0, len, text) == 0) {
                    return strdup(cmd.c_str());
                }
            }
            return nullptr;
        });
    }
    return matches;
}

int main() {
    rl_attempted_completion_function = completion;
    while (true) {
        std::string prompt = show_current_path() + " $ ";
        char* input = readline(prompt.c_str());
        if (!input) {
            break;
        }
        std::string line(input);
        free(input);
        if (line == "exit") {
            break;
        }
        run(split(line));
    }
    return 0;
}