CXX = g++
CXXFLAGS = -std=c++11 -Wall -g # --coverage # used to check test coverage

OBJECTS = card.o deck.o hand.o player.o game.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/test $(OBJECTS) test/test.cpp

test: testBuild
	test/test --success

clean:
	$(RM) *.o *.gc* core main test/test
