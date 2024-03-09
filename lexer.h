#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include "token.h"

class lexer {
private:
    std::fstream fs;
    std::vector<Token*> tokenList;

public:
    lexer(const std::string &path);
    ~lexer();
    void scan();
    void printTokenList(){
        for (Token *token : this->tokenList) {
            if (token->type == Token::Type::IF) std::cout << "if";
            if (token->type == Token::Type::ELSE) std::cout << "else";
            if (token->type == Token::Type::WHILE) std::cout << "while";
            if (token->type == Token::Type::LBRACE) std::cout << "{";
            if (token->type == Token::Type::RBRACE) std::cout << "}";
            if (token->type == Token::Type::STM) std::cout << "stm-" << ((StmToken *)token)->sstm;
            if (token->type == Token::Type::COND) std::cout << "cond-" << ((CondToken *)token)->cond;
            if (token->type == Token::Type::END) std::cout << "$" << std::endl;
            std::cout << "   (" << token->pos.first << ", " << token->pos.second << ")" << std::endl;
        }
    };
};