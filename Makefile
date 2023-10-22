# Name of the project
PROJ_NAME=simulador

# .cpp files
CPP_SOURCE=$(wildcard ./src/*.cpp)

# .h files
H_SOURCE=$(wildcard ./src/*.h)

# Object files
OBJ=$(subst .cpp,.o,$(subst src,objects,$(CPP_SOURCE)))

# Compiler and linker
CPP=g++

# Flags for compiler
CPP_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic  \
         -std=c++20  # Add C++20 standard flag

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using G++ linker: $@'
	$(CPP) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./src/%.cpp ./src/%.h
	@ echo 'Building target using G++ compiler: $<'
	$(CPP) $< $(CPP_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./src/main.cpp $(H_SOURCE)
	@ echo 'Building target using G++ compiler: $<'
	$(CPP) $< $(CPP_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

run: $(PROJ_NAME)
	@ echo 'Running $(PROJ_NAME) with arguments: $(ARGS)'
	./$(PROJ_NAME) $(ARGS) < referencias.txt
	@ echo ' '

.PHONY: all clean run
