#include "token.h"

Token::Token(string type, string value) {
    token_type = type;
    token_value = value;
}
Token::Token(string type) {
    token_type = type;
}
string Token::get_type() {
    return token_type;
}
string Token::get_value() {
    return token_value;
}
void Token::set_type(string type) {
    token_type = type;
}
void Token::set_value(string value) {
    token_value = value;
}
void Token::print() {
    if(!token_value.empty()) {
        cout << token_type << ":" << token_value << endl;
    } else {
        cout << token_type << endl;
    }
}
