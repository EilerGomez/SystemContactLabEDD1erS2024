CKLAGS = -c
CXX = g++
TARGET = programa

#all
all: .all-post

.all-post: Menu.o Main.o Tokens.o Tokenizer.o FieldTable.o ContactGroups.o Date.o ArbolAVL.o Utilities.o#main es el principal o main
	$(CXX) Menu.o Main.o Tokens.o Tokenizer.o FieldTable.o ContactGroups.o Date.o ArbolAVL.o Utilities.o -o $(TARGET)



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
Date.o: Date.cpp Date.h
		$(CXX) -c Date.cpp
ArbolAVL.o: ArbolAVL.cpp ArbolAVL.h
		$(CXX) -c ArbolAVL.cpp
Utilities.o: Utilities.cpp Utilities.h
		$(CXX) -c Utilities.cpp
clean:
	$(RM) *.o saludo core