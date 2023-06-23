#include <iostream>
#include <vector>
#include <regex>
using namespace std;

///////////////////////////////////////////////
//											 //
//					CONSTANTS				 //
//											 //
///////////////////////////////////////////////
regex DIGIT("[0-9]");


///////////////////////////////////////////////
//											 //
//					ERRORS					 //
//											 //
///////////////////////////////////////////////

class Error {
public:
    string error_type;
    string error_description;
    
    Error(string type, string description)
        : error_type(type), error_description(description) {}
};

class IllegalCharError : public Error {
public:
    IllegalCharError(string description)
        : Error("Illegal Character Error", description) {}
};

///////////////////////////////////////////////
//											 //
//					TOKENS					 //
//											 //
///////////////////////////////////////////////

string TT_INT = "INT";
string TT_FLOAT = "FLOAT";
string TT_PLUS = "PLUS";
string TT_MINUS = "MINUS";
string TT_MUL = "MUL";
string TT_DIV = "DIV";
string TT_LPAREN =  "LPAREN";
string TT_RPAREN = "RPAREN";

class Token {

	public:
		string token_type;
		string token_value;
		Token(string type, string value = "") {
			token_type = type;
			token_value = value;
		}
		string get_type() {
			return token_type;
		}
		string get_value() {
			return token_value;
		}
		void set_type(string type) {
			token_type = type;
		}
		void set_value(string value) {
			token_value = value;
		}
		void print() {
			if(!token_value.empty()) {
				cout << token_type << ":" << token_value << endl;
			} else {
				cout << token_type << endl;
			}
		}

};

///////////////////////////////////////////////
//											 //
//					LEXER					 //
//											 //
///////////////////////////////////////////////

struct GeneratedTokens {
    vector<Token> tokens;
    IllegalCharError error;
    int error_count;

    GeneratedTokens(vector<Token> tokens, IllegalCharError error, int error_count)
        : tokens(tokens), error(error), error_count(error_count) {}
};


class Lexer {
	public:
		vector<char> text;
		char curr_char;
		int pos = -1;

		Lexer(vector<char> input_text) {
			text = input_text;
			advance();
		}

		void advance() {
			pos++;

			if (pos < text.size()) {
				curr_char = text[pos];
			} else {
				curr_char = '\0';
			}
		}

		GeneratedTokens make_tokens() {
			vector<Token> tokens;
			string currentCharacter(1, curr_char);
			int error_count = 0;
			IllegalCharError error("no error");
			while (curr_char != '\0') {

				if (curr_char == '+') {
					Token token(TT_PLUS);
					tokens.push_back(token);
				} else if (regex_match(currentCharacter, DIGIT)) {
					Token token = make_number();
					tokens.push_back(token);
				} else if (curr_char == '-') {
					Token token(TT_MINUS);
					tokens.push_back(token);
				} else if (curr_char == '*') {
					Token token(TT_MUL);
					tokens.push_back(token);
				} else if (curr_char == '/') {
					Token token(TT_DIV);
					tokens.push_back(token);
				} else if (curr_char == '(') {
					Token token(TT_LPAREN);
					tokens.push_back(token);
				} else if (curr_char == ')') {
					Token token(TT_RPAREN);
					tokens.push_back(token);
				} else {
					
					error = IllegalCharError(curr_char + " character is not supported");
            		error_count = 1;
            		break;
				}
				advance();
			}
			IllegalCharError illegalChar("no error");
		    return GeneratedTokens(tokens, error, error_count);
		}

		Token make_number() {
			string num_str = "";
			int dot_count = 0;
			string characterString(1, curr_char);

			while ((curr_char != '\0') && (regex_match(characterString, DIGIT))) {
				if (regex_match(characterString, regex("\\."))) {

					dot_count++;
					if(dot_count > 1) {
						break;
					}
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

		void print() {
			cout << "Current Character: " << curr_char << endl;
			cout << "Current Position: " << pos << endl;
		}
};


///////////////////////////////////////////////
//											 //
//					MAIN					 //
//											 //
///////////////////////////////////////////////


int main(int argc, char** argv) {
	Token token("TT_test");
	token.print();
	vector<char> program;
	char data;
	int i = 0;
	cout << "Basic >" << endl;
	do {
		cin >> data;
		program.push_back(data);

	} while(program.at(program.size() - 1) != '0');

	Lexer lex(program);
	GeneratedTokens tokens = lex.make_tokens();
	
	return 0;
}


