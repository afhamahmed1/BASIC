#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include "token/token.h"
#include "lexer/lexer.h"
#include "error/error.h"

using namespace std;


///////////////////////////////////////////////
//											 //
//					MAIN					 //
//											 //
///////////////////////////////////////////////


int main() {
	vector<char> program;
	char data;
	cout << "Basic >" << endl;
	
	ofstream file("input.txt");
	cin >> data;
	do {
		file << data;
		cin >> data;
	} while(data != 'E');
	file.close();
	char output;
	ifstream file2("input.txt");
	while(file2 >> output) {
			program.push_back(output);
	}


	Lexer lex(program);
	GeneratedTokens tokens = lex.make_tokens();
	if(tokens.error_count == 0)
	{
		tokens.print();
	}else{
		cout << tokens.error.error_type << ": " << tokens.error.error_description << endl;
	}
	return 0;
}


