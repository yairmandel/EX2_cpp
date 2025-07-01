# yair340@gmail.com

# Makefile for SquareMat

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
VALGRIND = valgrind --leak-check=full

SRC = SquareMat.cpp
HDR = SquareMat.hpp

MAIN = main.cpp
TEST = test.cpp

OBJS_MAIN = $(MAIN:.cpp=.o) $(SRC:.cpp=.o)
OBJS_TEST = $(TEST:.cpp=.o) $(SRC:.cpp=.o)

TARGET_MAIN = main
TARGET_TEST = test

all: $(TARGET_MAIN)

$(TARGET_MAIN): $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $<

# Run the Main demo
makeMain: $(TARGET_MAIN)
	./$(TARGET_MAIN)

# Run unit tests
makeTest: $(TARGET_TEST)
	./$(TARGET_TEST)

# Run valgrind memory check
makeValgrind: $(TARGET_TEST)
	$(VALGRIND) ./$(TARGET_TEST)

# Clean all build files
makeClean:
	rm -f *.o $(TARGET_MAIN) $(TARGET_TEST)
