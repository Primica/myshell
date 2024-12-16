//
// Created by Arthur Malfere on 12/12/2024.
//

#include "myshell.h"

void ls(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cerr << "ls: too many arguments" << std::endl;
        return;
    }
    std::cout << std::left << std::setw(30) << "Name"
              << std::setw(10) << "Type"
              << std::setw(10) << "Size"
              << std::setw(20) << "Last Modified" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::string type;
        uintmax_t size = 0;
        if (entry.is_directory()) {
            type = "Directory";
            for (const auto& sub_entry : std::filesystem::recursive_directory_iterator(entry)) {
                if (sub_entry.is_regular_file()) {
                    size += sub_entry.file_size();
                }
            }
        } else if (entry.is_regular_file()) {
            type = "File";
            size = entry.file_size();
        } else if (entry.is_symlink()) {
            type = "Symlink";
        } else {
            type = "Other";
        }

        auto ftime = std::filesystem::last_write_time(entry);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(ftime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
        std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);

        std::cout << std::left << std::setw(30) << entry.path().filename().string()
                  << std::setw(10) << type
                  << std::setw(10) << size
                  << std::setw(20) << std::put_time(std::localtime(&cftime), "%F %T") << std::endl;
    }
}