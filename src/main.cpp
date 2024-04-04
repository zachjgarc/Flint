#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <optional>
#include <vector>

#include "Lexer.h"

std::string readFile(const std::string& path) {
    std::ifstream fileStream(path);

    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file\n";
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect compilation syntax\n";
        return 1;
    }

    const std::string input = readFile(argv[1]);

    std::vector<Token> tokens = Lexer::tokenize(input);
    for (Token token : tokens) {
        std::cout << token;
    }

    return 0;
}