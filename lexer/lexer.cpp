#include "lexer.h"

regex DIGIT("[0-9]");
regex FLOAT("[0-9.]");

GeneratedTokens::GeneratedTokens(vector<Token> tokens, IllegalCharError error, int error_count)
    : tokens(tokens), error(error), error_count(error_count) {}

void GeneratedTokens::print(){
    cout << "Tokens:" << endl;
    for (unsigned i = 0; i < tokens.size(); i++) {
            tokens[i].print();
    }
}

Lexer::Lexer(vector<char> input_text) {
	text = input_text;
	advance();
}

void Lexer::advance() {
	pos++;
	if (pos < text.size()) {
		curr_char = text[pos];
	} else {
		curr_char = '\0';
	}
}

GeneratedTokens Lexer::make_tokens() {
	vector<Token> tokens;
	
	int error_count = 0;
	IllegalCharError error("no error");
	while (curr_char != '\0') {
		string currentCharacter(1, curr_char);
		if (currentCharacter == "+") {
			Token token(TT_PLUS);
			tokens.push_back(token);
			advance();
		} else if (regex_match(currentCharacter, DIGIT)) {
			Token token = make_number();
			tokens.push_back(token);
		} else if (currentCharacter == "-") {
			Token token(TT_MINUS);
			tokens.push_back(token);
			advance();
		} else if (currentCharacter == "*") {
			Token token(TT_MUL);
			tokens.push_back(token);
			advance();
		} else if (currentCharacter == "/") {
			Token token(TT_DIV);
			tokens.push_back(token);
			advance();
		} else if (currentCharacter == "(") {
			Token token(TT_LPAREN);
			tokens.push_back(token);
			advance();
		} else if (currentCharacter == ")") {
			Token token(TT_RPAREN);
			tokens.push_back(token);
			advance();
		} else {
			
			error.error_description = curr_char + " character is not supported";
			error_count = 1;
			break;
		}
		
		
	}
	
	return GeneratedTokens(tokens, error, error_count);
}

Token Lexer::make_number() {
	string num_str = "";
	int dot_count = 0;
	string characterString(1, curr_char);

	while ((curr_char != '\0') && (regex_match(characterString, FLOAT))) {
		
		if (regex_match(characterString, regex("\\."))) {

			if(dot_count == 1) {
				break;
			}
			dot_count++;
			num_str += characterString;

		} else if (regex_match(characterString, DIGIT)) {
			num_str += characterString;
		} else {
			break;
		}
		advance();
		characterString = string(1, curr_char);
	}
	Token token(TT_INT, num_str);
	if(dot_count != 0) {
		token.set_type(TT_FLOAT);
	}


	return token;
}

void Lexer::print() {
	cout << "Current Character: " << curr_char << endl;
	cout << "Current Position: " << pos << endl;
}
