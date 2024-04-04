#include "Token.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "Token(Type: ";
    switch (token.type) {
        case TokenType::INT_LIT: os << "INT_LIT"; break;
        case TokenType::EXIT:    os << "EXIT";    break;
        case TokenType::SEMI:    os << "SEMI";    break;
        default:                 os << "UNKNOWN"; break;
    }
    os << ", Data: ";
    if (token.data) {
        os << '"' << *token.data << '"';
    } else {
        os << "nullopt";
    }
    os << ")\n";
    return os;
}