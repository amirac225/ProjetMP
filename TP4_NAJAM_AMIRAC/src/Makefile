# Options de compilation :
CXX = g++
O3 = #-O3 
CXXFLAGS = -Wall -Wextra -g $(O3) 
LDFLAGS = #-lm -pg
SRC = $(wildcard main*.cpp)
SRC2 = $(wildcard *.cpp)
BIN = $(patsubst %.cpp, bin/%, $(SRC))


all : $(BIN)

bin/main% : main%.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY : clean
clean :
	rm -f *.o *~ gmon.out \#* $(BIN) obj/*.o bin/*
