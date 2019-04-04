CXX = g++
CXXFLAGS = -g -Wall

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

DEP_FLAGS=-MMD -MP
CXXFLAGS+=$(DEP_FLAGS)

EXE = StudentGrades

$(EXE): $(OBJ)
	$(CXX) $(LFLAGS) $? -o $@

run: $(EXE)
	./$(EXE)
	@valgrind ./$(EXE) >val 2>&1
	@if grep -q 'definitely lost: 0' val ; then echo 'OK'; else echo 'Wyciek!'; fi
	@rm val

all: clean $(EXE) run

gdb:
	gdb ./$(EXE)

val:
	valgrind --leak-check=full ./$(EXE)
	
clean:
	rm *.o *.d $(EXE)

-include $(DEP)
