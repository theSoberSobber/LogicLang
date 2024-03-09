#include <iostream>
#include <cstdlib>
#include <cassert>

#include "lexer.h"

lexer::lexer(const std::string &path) {
    this->fs = std::fstream();
    this->fs.open(path.c_str(), std::fstream::in);
    if (!this->fs.is_open()) {
        std::cout << "[Error] No Such File Found." << std::endl;
        exit(-1);
    }
}

lexer::~lexer() {
    this->fs.close();
}

void lexer::scan() {
    char c;
    std::string str; // code
    std::pair<int, int> cntPos = std::make_pair<int, int>(1, 0); // Lno, Cno
    while (this->fs.get(c)) {
        if (c == '\n') {
            cntPos.first++;
            cntPos.second = 0;
        }
        else cntPos.second++;

        if (Token::delimiters.find(c) != Token::delimiters.end()) {
            // c is a delim () {} ;
            std::string::size_type idx = str.length() - 1; // last significant character
            for(int i=str.length()-1; i>=0; i--){
                if(str[i]!=' '){
                    idx = i;
                    break;
                }
            }
            // erase all whitespace between this delim and the token in prefix
            // std::cout << str << " " << idx << " " << std::endl;
            str.erase(idx + 1);
            
            if (str == Token::iftoken){
                this->tokenList.push_back(new IfToken(cntPos));
            } 
            else if (str == Token::elsetoken) {
                this->tokenList.push_back(new ElseToken(cntPos));
            }
            else if (str == Token::whiletoken) {
                this->tokenList.push_back(new WhileToken(cntPos));
            }
            else if (!str.empty()) {
                if (c == Token::rparen) {
                    // condition for decesion structures
                    this->tokenList.push_back(new CondToken(str, cntPos));
                }
                else {
                    // statement
                    this->tokenList.push_back(new StmToken(str, cntPos));
                }
            }

            // delim char
            if (c == Token::lbrace) {
                this->tokenList.push_back(new LBraceToken(cntPos));
            }
            else if (c == Token::rbrace) {
                this->tokenList.push_back(new RBraceToken(cntPos));
            }
            str.clear();
        }
        else {
            if (Token::whitespaces.find(c) == Token::whitespaces.end()) str += c;
            else if (c == Token::space && !str.empty()) {
                // just indents, must ignore leading spaces
                str += c;
            }
        }
    }
    // the $ appended
    this->tokenList.push_back(new EndToken());

    #ifdef DEBUG_LEXER
    this->printTokenList();
    #endif
}