//
// Created by Arthur Malfere on 12/12/2024.
//

#include "myshell.h"

TabCompletion::TabCompletion() {
    commands = {"echo", "cd", "pwd", "ls", "exit"};
}

std::string TabCompletion::complete(const std::string& prefix) const {
    for (const auto& cmd : commands) {
        if (cmd.find(prefix) == 0) {
            return cmd;
        }
    }
    return prefix;
}
