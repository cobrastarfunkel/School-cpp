CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = question.o question_bank.o game.o
HEADERS = $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJECTS) -o main

question.o: question.cpp question.hpp
	$(CXX) $(CXXFLAGS) -c question.cpp

question_bank.o: question_bank.cpp question_bank.hpp question.o
	$(CXX) $(CXXFLAGS) -c question_bank.cpp 

game.o: game.hpp game.cpp question_bank.o
	$(CXX) $(CXXFLAGS) -c game.cpp 

$(OBJECTS): $(HEADERS)

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/TestCase $(OBJECTS) test/TestCase.cpp

test: clean testBuild
	test/TestCase --success

clean:
	$(RM) *.o *.gch core main test/TestCase
