CKLAGS = -c
CXX = g++
TARGET = programa

#all
all: .all-post

.all-post: Menu.o Main.o Tokens.o Tokenizer.o FieldTable.o ContactGroups.o#main es el principal o main
	$(CXX) Menu.o Main.o Tokens.o Tokenizer.o FieldTable.o ContactGroups.o -o $(TARGET)



Menu.o: Menu.cpp Menu.h
		$(CXX) -c Menu.cpp
Tokens.o: Tokens.cpp Tokens.h
		$(CXX) -c Tokens.cpp
Tokenizer.o: Tokenizer.cpp Tokenizer.h
		$(CXX) -c Tokenizer.cpp
FieldTable.o: FieldTable.cpp FieldTable.h
		$(CXX) -c FieldTable.cpp
ContactGroups.o: ContactGroups.cpp ContactGroups.h
		$(CXX) -c ContactGroups.cpp
clean:
	$(RM) *.o saludo core