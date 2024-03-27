CKLAGS = -c
CXX = g++
TARGET = programa

#all
all: .all-post

.all-post: Menu.o Main.o Tokens.o Tokenizer.o#main es el principal o main
	$(CXX) Menu.o Main.o Tokens.o Tokenizer.o -o $(TARGET)



Menu.o: Menu.cpp Menu.h
		$(CXX) -c Menu.cpp
Tokens.o: Tokens.cpp Tokens.h
		$(CXX) -c Tokens.cpp
Tokenizer.o: Tokenizer.cpp Tokenizer.h
		$(CXX) -c Tokenizer.cpp
clean:
	$(RM) *.o saludo core