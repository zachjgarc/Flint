#include "Lexer.h"

#include <cctype>
#include <iostream>

// initialize variables
std::string Lexer::input = "";
size_t Lexer::inputLength = 0;
char Lexer::currentChar = '\0';
char Lexer::nextChar = '\0';
size_t Lexer::index = 0;
std::vector<Token> Lexer::tokens = {};
std::string Lexer::buffer = "";

const std::unordered_map<std::string, std::function<void()>> Lexer::tokenHandlers = {
    {"exit", []() {
        tokens.push_back(Token(TokenType::EXIT));
    }}
};

char Lexer::getChar(const size_t lookAhead) {
    const size_t lookAheadIndex = index + lookAhead;
    return (lookAheadIndex < inputLength) ? input[lookAheadIndex] : '\0';
}

void Lexer::incChar() {
    index++;
    
    currentChar = nextChar;
    nextChar = (index + 1 < inputLength) ? input[index + 1] : '\0';
}

std::vector<Token> Lexer::tokenize(const std::string& fileStr) {
    // initialize / reset class vars
    tokens.clear(); buffer.clear();
    input = fileStr; inputLength = input.length();

    index = 0;
    currentChar = '\0';
    nextChar = '\0';

    if (inputLength > 0) {
        currentChar = input[0];
        if (inputLength > 1) nextChar = input[1];
    }

    while (currentChar != '\0') {
        if (std::isspace(currentChar)) { incChar(); continue; }

        if (std::isalpha(currentChar)) {
            buffer.push_back(currentChar);

            while (std::isalpha(nextChar)) {
                buffer.push_back(nextChar);
                incChar();
            }

            auto handler = tokenHandlers.find(buffer);
            if (handler != tokenHandlers.end()) {
                handler -> second();
            } else {
                std::cerr << "Unknown word: " << buffer << "\n";
            }

        } else if (std::isdigit(currentChar) || (currentChar == '.' && std::isdigit(nextChar)) || (currentChar == '-' && (std::isdigit(nextChar) || nextChar == '.'))) {
            // ^ digit, decimal, or negative sign
            bool foundDecimal = (currentChar == '.');
            buffer.push_back(currentChar);

            while (true) {
                if (!std::isdigit(nextChar) && nextChar != '.') break;
                if (nextChar == '.' && foundDecimal == true) break;
                buffer.push_back(nextChar);
                incChar();
            }

            tokens.push_back(Token(TokenType::INT_LIT, buffer));
        }

        buffer.clear();
        incChar();
    }

    return tokens;
}