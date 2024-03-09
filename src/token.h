#pragma once

#include <string>
#include <set>

class Token {  
public:
    enum class Type : int {
        STM,
        COND,
        LBRACE,
        RBRACE,
        IF,
        ELSE,
        WHILE,
        END
    };

    Type type;
    std::pair<int, int> pos;

    static const char lparen;
    static const char rparen;
    static const char semicolon;
    static const char lbrace;
    static const char rbrace;
    static const char space;
    static const std::string iftoken;
    static const std::string elsetoken;
    static const std::string whiletoken;
    static const std::set<char> delimiters;
    static const std::set<char> whitespaces;

    Token(const Type type);
    Token(const Type type, std::pair<int, int> pos);
};

class StmToken : public Token {
public:
    std::string sstm;
    StmToken(const std::string &sstm, std::pair<int, int> pos);
};

class CondToken : public Token{
public:
    std::string cond;

    CondToken(const std::string &cond, std::pair<int, int> pos);
};

class LBraceToken : public Token {
public:
    LBraceToken(std::pair<int, int> pos);
};

class RBraceToken : public Token {
public:
    RBraceToken(std::pair<int, int> pos);
};

class IfToken : public Token {
public:
    IfToken(std::pair<int, int> pos);
};

class ElseToken : public Token {
public:
    ElseToken(std::pair<int, int> pos);
};

class WhileToken : public Token {
public:
    WhileToken(std::pair<int, int> pos);
};

class EndToken : public Token {
public:
    EndToken();
};