#include "token.h"

const char Token::lparen = '(';
const char Token::rparen = ')';
const char Token::semicolon = ';';
const char Token::lbrace = '{';
const char Token::rbrace = '}';
const char Token::space = ' ';
const std::string Token::iftoken = "if";
const std::string Token::elsetoken = "else";
const std::string Token::whiletoken = "while";
const std::set<char> Token::delimiters = {';', '(', ')', '{', '}'};
const std::set<char> Token::whitespaces = {' ', '\n', '\t'};

// implement the constructors
Token::Token(const Type type) : type(type) {}

Token::Token(const Type type, std::pair<int, int> pos) : type(type), pos(pos) {}

StmToken::StmToken(const std::string &sstm, std::pair<int, int> pos) : Token(Type::STM, pos), sstm(sstm) {}

CondToken::CondToken(const std::string &cond, std::pair<int, int> pos) : Token(Type::COND, pos), cond(cond) {}

LBraceToken::LBraceToken(std::pair<int, int> pos) : Token(Type::LBRACE, pos) {}

RBraceToken::RBraceToken(std::pair<int, int> pos) : Token(Type::RBRACE, pos) {}

IfToken::IfToken(std::pair<int, int> pos) : Token(Type::IF, pos) {}

ElseToken::ElseToken(std::pair<int, int> pos) : Token(Type::ELSE, pos) {}

WhileToken::WhileToken(std::pair<int, int> pos) : Token(Type::WHILE, pos) {}

EndToken::EndToken() : Token(Type::END) {}