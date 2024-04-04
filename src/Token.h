#pragma once
#include <string>
#include <optional>

enum class TokenType {
    INT_LIT, EXIT, SEMI
};

class Token {
public:
    Token(TokenType type, std::optional<std::string> data = std::nullopt) : type(type), data(data) {}

    TokenType type;
    std::optional<std::string> data;

    friend std::ostream& operator<<(std::ostream& os, const Token& token);
};