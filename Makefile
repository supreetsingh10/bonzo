CC=g++
CXXFLAGS= -Wall -O2 -g

all: bonzo

bonzo: src/user_input.o src/lexer.o src/token.o src/main.o 
	$(CC) src/user_input.o  src/lexer.o src/main.o src/token.o  -o bonzo

token.o: src/token.cpp
	$(CC) $(CXXFLAGS) -c src/token.cpp

lexer.o: src/lexer.cpp
	$(CC) $(CXXFLAGS) -c src/lexer.cpp

user_input.o: src/user_input.cpp
	$(CC) $(CXXFLAGS) -c src/user_input.cpp

main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp

clean: 
	rm src/*.o bonzo
