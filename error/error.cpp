#include "error.h"


Error::Error(string type, string description)
    : error_type(type), error_description(description) {}



IllegalCharError::IllegalCharError(string description)
    : Error("Illegal Character Error", description) {}
