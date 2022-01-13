#pragma once 
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

typedef struct Global_Struct{
    std::string cmd; 
    int curr_index; 
    int cmd_length; 
    Global_Struct(std::string i_cmd): cmd(i_cmd), curr_index(0), cmd_length(i_cmd.length()){}
} GLOBAL_STRUCT; 

typedef enum TYPE {
    IDENTIFIER, 
    NUMBER, 
    STRING, 
    OPERATOR,
    L_BRAK, 
    R_BRAK, 

} Type; 

// char_mapper will have the mappers. They will be initialized when the object for the 
// lexer is made. 
//
class Lexer {
    public:
    std::unordered_map<char, Type> char_mapper; 
    void iterate_cmd(GLOBAL_STRUCT *); 
    Lexer(); 
    ~Lexer(); 
}; 

extern GLOBAL_STRUCT *global_cmd_struct; 
extern Lexer *lexer_ptr; 
void cmd_to_struct(std::string); 
void clean_up(); 
    


