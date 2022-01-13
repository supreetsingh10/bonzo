#include "../include/user_input.hpp"
#include "../include/lexer.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    while(true) {
        std::string cmd = read_input(); 
        cmd_to_struct(cmd); 
        lexer_ptr->iterate_cmd(global_cmd_struct); 
        clean_up(); 
    }
    return 0; 
}
