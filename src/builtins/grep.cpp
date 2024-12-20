#include "myshell.h"

void grep(const std::vector<std::string> &args) {
    bool ignoreCase = false, invertMatch = false, countOnly = false, lineNum = false;
    std::string pattern;
    std::vector<std::string> files;

    for (const auto &arg : args) {
        if (arg == "-i")
            ignoreCase = true;
        else if (arg == "-v")
            invertMatch = true;
        else if (arg == "-c")
            countOnly = true;
        else if (arg == "-n")
            lineNum = true;
        else if (pattern.empty())
            pattern = arg;
        else
            files.push_back(arg);
    }

    if (pattern.empty() || files.empty()) {
        std::cerr << "Usage: grep [options] PATTERN [FILE...]" << std::endl;
        return;
    }

    std::regex regexPattern(pattern, ignoreCase ? std::regex_constants::icase : std::regex_constants::ECMAScript);
    for (const auto &file : files) {
        std::ifstream inFile(file);
        if (!inFile) {
            std::cerr << "grep: " << file << ": No such file or directory" << std::endl;
            continue;
        }

        std::string line;
        int lineNumber = 0, matchCount = 0;

        while (std::getline(inFile, line)) {
            ++lineNumber;
            bool isMatch = std::regex_search(line, regexPattern);
            if (invertMatch)
                isMatch = !isMatch;

            if (isMatch) {
                ++matchCount;
                if (!countOnly) {
                    if (lineNum)
                        std::cout << lineNumber << ":";
                    std::cout << line << std::endl;
                }
            }
        }

        if (countOnly) {
            std::cout << file << ": " << matchCount << std::endl;
        }
    }
}