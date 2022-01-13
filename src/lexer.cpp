#include "../include/lexer.hpp"
#include <iostream>
#include <string>

GLOBAL_STRUCT *global_cmd_struct; 
Lexer *lexer_ptr; 

void cmd_to_struct(std::string cmd) {
    global_cmd_struct = new GLOBAL_STRUCT(cmd); 
    lexer_ptr = new Lexer(); 
}

Lexer::Lexer() {
    for(char c='a'; c<='z'; c++)
       this->char_mapper[c] = IDENTIFIER; 
    for(char c='0'; c<='9'; c++)
       this->char_mapper[c] = NUMBER;  
}

Lexer::~Lexer() {
    // I can use this to rest the tokens 
}

void Lexer::iterate_cmd(GLOBAL_STRUCT *global_struct) {
    for(auto gs : global_struct->cmd) 
        std::cout<<gs; 
}

void clean_up() {
    delete global_cmd_struct; 
    delete lexer_ptr; 
}
