#include "../include/lexer.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>

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
    char_mapper['\n'] = SKIPPABLE; 
    char_mapper['\t'] = SKIPPABLE; 
    char_mapper[' '] = SKIPPABLE; 
    char_mapper[';'] = DELIMITER; 
    char_mapper['\\'] = DELIMITER;

}

Lexer::~Lexer() {
    this->list_of_tokens.clear(); 
}

// Tokenizing SKIPPABLES MAKE SURE THOSE ARE SKIPPED; 
// Add a Switch Case thing here. 
Token* Lexer::make_token(std::string value, Type type) {
    Token *t = new Token(value, type); 
    return t; 
}

void Lexer::iterate_cmd(GLOBAL_STRUCT *global_struct) {
    for(int index = global_struct->curr_index; index < global_struct->cmd_length; index++) {
        if(index == global_struct->cmd_length) {
            current_type = get_char_type(index); 
            if(current_type != SKIPPABLE) {
                current_value += get_char(index); 
                list_of_tokens.push_back(make_token(current_value, current_type)); 
                reset(); 
            } else 
                continue; 
        } else {
           current_type = get_char_type(index);  
           next_type = get_char_type(index+1); 
           if(current_type == SKIPPABLE) {
               flagIden = false; 
               continue; 
           }
           if(current_type == next_type) {
               current_value += get_char(index); 
               if(current_type == IDENTIFIER) {
                   flagIden = true; 
               }
           } else {
               if(current_type == IDENTIFIER) {
                   if(!flagIden) {
                       flagIden = true;
                   }
                   current_value += get_char(index); 
               } 


               if(flagIden && current_type == NUMBER) {
                   current_value += get_char(index); 
                   current_type = IDENTIFIER; 
               } else if(flagIden && next_type != NUMBER){
                   list_of_tokens.push_back(make_token(current_value, current_type)); 
                   reset(); 
                   continue; 
               }

               if(!flagIden && current_type != next_type) {
                   current_value += get_char(index); 
                   list_of_tokens.push_back(make_token(current_value, current_type)); 
                   reset(); 
                   continue; 
               } else if(flagIden && (next_type == SKIPPABLE || next_type == OPERATOR)) {
                   list_of_tokens.push_back(make_token(current_value, current_type)); 
                   reset(); 
                   continue; 
               }
           }
        }
    }
}

void Lexer::reset() {
    this->current_value = ""; 
}

char Lexer::get_char(int index) {
    return (global_cmd_struct->cmd[index]); 
}

Type Lexer::get_char_type(int index) {
    return (char_mapper[global_cmd_struct->cmd[index]]); 
}

void clean_up() {
    delete global_cmd_struct; 
    delete lexer_ptr; 
}
