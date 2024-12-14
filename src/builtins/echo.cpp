//
// Created by Arthur Malfere on 12/12/2024.
//

#include "../myshell.h"

void echo(const std::vector<std::string>& args) {
    bool append = false;
    bool redirect_output = false;
    bool redirect_input = false;
    std::string output_file;
    std::string input_file;
    std::ostringstream output;

    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == ">") {
            if (i + 1 < args.size()) {
                output_file = args[i + 1];
                redirect_output = true;
                ++i;
            } else {
                std::cerr << "echo: syntax error near unexpected token `newline`" << std::endl;
                return;
            }
        } else if (args[i] == ">>") {
            if (i + 1 < args.size()) {
                output_file = args[i + 1];
                append = true;
                redirect_output = true;
                ++i;
            } else {
                std::cerr << "echo: syntax error near unexpected token `newline`" << std::endl;
                return;
            }
        } else if (args[i] == "<") {
            if (i + 1 < args.size()) {
                input_file = args[i + 1];
                redirect_input = true;
                ++i;
            } else {
                std::cerr << "echo: syntax error near unexpected token `newline`" << std::endl;
                return;
            }
        } else if (args[i] == "<<") {
            std::cerr << "echo: here-document (`<<`) not supported" << std::endl;
            return;
        } else {
            output << args[i] << " ";
        }
    }

    if (redirect_input) {
        std::ifstream infile(input_file);
        if (!infile) {
            std::cerr << "echo: " << input_file << ": No such file or directory" << std::endl;
            return;
        }
        std::string line;
        while (std::getline(infile, line)) {
            output << line << " ";
        }
    }

    if (redirect_output) {
        std::ofstream outfile;
        if (append) {
            outfile.open(output_file, std::ios_base::app);
        } else {
            outfile.open(output_file);
        }
        if (!outfile) {
            std::cerr << "echo: " << output_file << ": No such file or directory" << std::endl;
            return;
        }
        outfile << output.str() << std::endl;
    } else {
        std::cout << output.str() << std::endl;
    }
}