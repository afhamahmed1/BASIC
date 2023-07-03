#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>
using namespace std;

class Error {
public:
    string error_type;
    string error_description;
    
    Error(string type, string description);
};

class IllegalCharError : public Error {
public:
    IllegalCharError(string description);
};
#endif