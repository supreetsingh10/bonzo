#include "../include/token.hpp"
#include <iostream>
#include <string> 

void Token::show() {
    std::cout<<this->value_of_token<< " "<<this->type_of_token << std::endl; 
}


