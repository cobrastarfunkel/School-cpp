# the compiler: gcc for C program, define as g++ for C++
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -std=c++11 -g -Wall

OBJECTS =  passage.o room.o player.o maze.o game.o 
HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/TestCase $(OBJECTS) test/TestCase.cpp

test: clean testBuild
	test/TestCase --success

clean:
	$(RM) *.o *.gch core main test/TestCase
