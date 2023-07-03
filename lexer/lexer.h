#ifndef LEXER_H
#define LEXER_H

#include "../error/error.h"
#include "../constants/constants.h"
#include "../token/token.h"
#include <iostream>
#include <regex>
#include <vector>

using namespace std;
struct GeneratedTokens {
    vector<Token> tokens;
    IllegalCharError error;
    int error_count;

    GeneratedTokens(vector<Token> tokens, IllegalCharError error, int error_count);
        
    void print();
};




class Lexer {
    public:
        vector<char> text;
        char curr_char;
        int pos = -1;
        Lexer(vector<char> input_text);

        void advance();

        GeneratedTokens make_tokens();

        Token make_number();

        void print();
};

#endif
