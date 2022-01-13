CC=g++
CXXFLAGS= -Wall -O2 -g

all: shell

shell: src/user_input.o src/lexer.o src/main.o 
	$(CC) src/user_input.o  src/lexer.o src/main.o  -o shell

lexer.o: src/lexer.cpp
	$(CC) $(CXXFLAGS) -c src/lexer.cpp

user_input.o: src/user_input.cpp
	$(CC) $(CXXFLAGS) -c src/user_input.cpp

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

clean: 
	rm src/*.o shell
