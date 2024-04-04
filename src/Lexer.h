#pragma once
#include "Token.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Lexer {
public:
    static std::vector<Token> tokenize(const std::string& fileStr);

private:
    static std::vector<Token> tokens; // output of tokenize
    static const std::unordered_map<std::string, std::function<void()>> tokenHandlers;

    static std::string input;
    static size_t inputLength;

    // used for lexing
    static char currentChar, nextChar;
    static size_t index;
    static std::string buffer;

    static char getChar(const size_t lookAhead);
    static void incChar();
};