#include "myshell.h"

void rmdir(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Error: rmdir: missing operand" << std::endl;
        return;
    }

    for (size_t i = 1; i < args.size(); i++) {
        std::uintmax_t spaceFreed = 0;
        try {
            spaceFreed = std::filesystem::remove_all(args[i]);
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }

        if (spaceFreed == static_cast<std::uintmax_t>(-1)) {
            std::cerr << "Error: Unable to remove directory " << args[i] << std::endl;
        } else {
            std::cout << "Directory removed: " << args[i] << " (Freed " << spaceFreed << " bytes)" << std::endl;
        }
    }
}

bool delRecursive(const std::string& path) {
    std::filesystem::path p(path);
    if (!exists(p)) {
        std::cerr << "Error: Directory does not exist: " << path << std::endl;
        return false;
    }

    if (!is_directory(p)) {
        std::cerr << "Error: Not a directory: " << path << std::endl;
        return false;
    }

    try {
        remove_all(p);
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }

    return true;
}