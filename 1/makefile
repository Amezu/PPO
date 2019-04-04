CXX=g++
CXXFLAGS = -g -Wall -O0

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

DEP_FLAGS=-MMD
CXXFLAGS+=$(DEP_FLAGS)

EXE = main

$(EXE): $(OBJ)
	$(CXX) $(LFLAGS) $? -o $@

.PHONY: run all gdb val clean

run:
	./$(EXE)

all: clean main run

gdb:
	gdb ./$(EXE)

val:
	valgrind --leak-check=full ./$(EXE)
	
clean:
	rm *.o *.d $(EXE)

-include $(DEP)
