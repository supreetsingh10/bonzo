#include "../include/token.hpp"
#include <iostream>
#include <string> 

void Token::show() {
    std::cout<<this->value_of_token<< " "<<this->type_of_token << std::endl; 
}

Type Token::get_type() {
    return this->type_of_token; 
}

void Token::set_operator() {

}
