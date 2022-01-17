#pragma once 
#include <iostream>
#include <string> 
#include "../include/common.hpp"

// Will be a friend class of the class Lexer 

class Lexer; 
class Token {
    private:
    std::string value_of_token; 
    Type type_of_token; 


    // Added this to work with the specificity of the token type. 

    public:
    Token(std::string v, Type t): value_of_token(v), type_of_token(t) {}; 
    // Token(std::string v, Type t,  Overload the constructor to give the values to Operators. 
    // To specify the Operator values. 
    void set_operator(); 
    Type get_type(); 
    void show(); 
}; 
