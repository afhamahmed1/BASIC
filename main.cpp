#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
		string token_name;
		Token(string type, string name = ""){
			token_type = type;
			token_name = name;
		}
		void print(){
			if(!token_name.empty()){
				cout << token_type << ":" << token_name << endl;
			}
			else{
				cout << token_type << endl;
			}
		}
	
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
        }
        else {
             curr_char = '\0';  
        }
    }
    
    vector<Token> make_tokens(){
    	vector<Token> tokens;
    	while (curr_char != '\0')
    	{
    		if (curr_char == '+')
    		{
    			Token token(TT_PLUS);
    			tokens.push_back(token);
			}
			
			else if (curr_char == '-')
			{
				Token token(TT_MINUS);
    			tokens.push_back(token);
			}
			else if (curr_char == '*')
			{
				Token token(TT_MUL);
    			tokens.push_back(token);
			}
			else if (curr_char == '/')
			{
				Token token(TT_DIV);
    			tokens.push_back(token);
			}
			else if (curr_char == '(')
			{
				Token token(TT_LPAREN);
    			tokens.push_back(token);
			}
			else if (curr_char == ')')
			{
				Token token(TT_RPAREN);
    			tokens.push_back(token);
			}
			else
			{
				cout << "ERROR SOMETHING WENT WRONG";
				break;
			}
		}
		return tokens;
	}
    void print(){
    	cout << "Current Character: " << curr_char << endl;
    	cout << "Current Position: " << pos << endl;
	}
};


int main(int argc, char** argv) {
	Token token("TT_test");
	token.print();
	vector<char> program;
	char data;
	int i = 0;
	cout << "Basic >" << endl;
	do{
		cin >> data;
		program.push_back(data);
		
	}
	while(program.at(program.size() - 1) != '0');
	
	Lexer lex(program);
	vector<Token> tokens = lex.make_tokens();
	for(int k =0; k<tokens.size();k++)
	{
		tokens[i].print();
	}
	return 0;
}


