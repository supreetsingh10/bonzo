#include "../include/user_input.hpp"
#include <cctype>
#include <string> 
#include <iostream>

//    sudo pacman -Syu

char prompt(int lnprompt) {
    switch(lnprompt) {
        case 1:
           return '$'; 
        case 2:
            return '>'; 
        default:
            return '$'; 
    }
}

std::string read_input() {
    std::string cmd; 
    std::cout<< prompt(1) << " "; 
    while(true) {
        char c = getchar(); 
        if(c == '\n' && cmd[cmd.length()-1] == '\\') {
            std::cout<< prompt(2) << " "; 
            cmd += c; 
        } else if(c == '\n' && cmd[cmd.length()-1] != '\\') {
            cmd += c; 
            return cmd; 
        } else {
            cmd += c; 
        }
    }
}
