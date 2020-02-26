CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = dictionary.o die.o gameboard.o word_find.o game.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch *.dSYM test/01_dictionary test/02_gameboard test/03_dice_roll test/04_word_find test/05_game core main

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/01_dictionary $(OBJECTS) test/01_dictionary.cpp
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/02_gameboard $(OBJECTS) test/02_gameboard.cpp
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/03_dice_roll $(OBJECTS) test/03_dice_roll.cpp
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/04_word_find $(OBJECTS) test/04_word_find.cpp
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/05_game $(OBJECTS) test/05_game.cpp

test: testBuild
	test/01_dictionary
	test/02_gameboard
	test/03_dice_roll
	test/04_word_find
	test/05_game
