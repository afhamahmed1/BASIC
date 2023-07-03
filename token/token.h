#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;
class Token {

	public:
		string token_type;
		string token_value;
		Token(string type, string value);
		Token(string type);
		string get_type();
		string get_value();
		void set_type(string type);
		void set_value(string value);
		void print();

};
#endif