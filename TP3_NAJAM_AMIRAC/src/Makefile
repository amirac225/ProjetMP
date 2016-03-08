# Options de compilation :
CXX = g++
O3 = #-O3 
CXXFLAGS = -Wall -Wextra -g $(O3) 
LDFLAGS = #-lm -pg
SRC = $(wildcard main*.cpp)
SRC2 = $(wildcard *.cpp)
BIN = $(patsubst %.cpp, bin/%, $(SRC))
OBJ =  $(patsubst %.cpp, obj/%.o, $(SRC2))

all : $(OBJ) bin

bin : $(BIN)

bin/main% : obj/Darray.o  obj/main%.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

obj/%.o : %.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY : clean
clean :
	rm -f *.o *~ gmon.out \#* $(BIN) obj/*.o bin/*
