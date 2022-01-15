#pragma once 
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../include/token.hpp"
#include "../include/common.hpp"

typedef struct Global_Struct {
    std::string cmd; 
    int curr_index; 
    int cmd_length; 
    Global_Struct(std::string i_cmd): cmd(i_cmd), curr_index(0), cmd_length(i_cmd.length()){}
} GLOBAL_STRUCT; 



// char_mapper will have the mappers. They will be initialized when the object for the 
// lexer is made. 
//
//
class Lexer {
    public:
    void iterate_cmd(GLOBAL_STRUCT *); 

    Token *make_token(std::string, Type); 
    std::vector<Token *> list_of_tokens; 


    char get_char(int); 
    Type get_char_type(int); 

    Lexer(); 
    ~Lexer(); 

    void reset(); 
    private: 
    friend class Token; 
    Type current_type, next_type;
    std::string current_value; 
    bool flagIden; 
    std::unordered_map<char, Type> char_mapper; 
}; 

extern GLOBAL_STRUCT *global_cmd_struct; 
extern Lexer *lexer_ptr; 
void cmd_to_struct(std::string); 
void clean_up(); 
    

/*
           if(current_type == SKIPPABLE) {
               flagIden = false; 
               continue; 
           } else if(current_type == IDENTIFIER) {
              flagIden = true;  
           } else if(current_type != IDENTIFIER || flagIden) {
              current_type = IDENTIFIER;  
           } else if(!flagIden && (current_type != next_type)) {
              make_token(current_value, current_type);  
              reset(); 
           }
*/
