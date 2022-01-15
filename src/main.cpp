#include "../include/user_input.hpp"
#include "../include/lexer.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    // initialize the char_mappers 
    while(true) {
        std::string cmd = read_input(); 
        cmd_to_struct(cmd); 
        lexer_ptr->iterate_cmd(global_cmd_struct); 
        for(auto v : lexer_ptr->list_of_tokens) {
            v->show(); 
            std::cout<<std::endl; 
        }
        clean_up(); 
    }
    return 0; 
}
