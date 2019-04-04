CXX = g++
CXXFLAGS = -g -Wall -std=c++11

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

DEP_FLAGS=-MMD -MP
CXXFLAGS+=$(DEP_FLAGS)

EXE = qCPU

$(EXE): $(OBJ)
	$(CXX) $(LFLAGS) $? -o $@

run:
	./$(EXE)
	@valgrind ./$(EXE) >val 2>&1
	@if grep -q 'no leaks are possible' val ; then echo 'OK'; else echo 'Wyciek!'; fi
	@rm val

all: clean $(EXE) run

gdb:
	gdb ./$(EXE)

val:
	valgrind --leak-check=full ./$(EXE)
	
clean:
	rm *.o *.d $(EXE)

-include $(DEP)
