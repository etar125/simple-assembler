# Directory Structure
DIR_BIN = bin
DIR_INC = include
DIR_OBJ = obj
DIR_SRC = src

# Compiler Options
CC      = g++
CFLAGS  = -Wall -iquote $(DIR_INC) -g
BINARY  = main
BINAR   = test

# Make Options
.PHONY: default main
default: main

# Main Command
main: $(DIR_SRC)/main.cpp $(DIR_SRC)/assembler.cpp $(DIR_INC)/assembler.hpp
	$(CC) $(DIR_SRC)/main.cpp $(DIR_SRC)/assembler.cpp -o $(DIR_BIN)/$(BINARY) $(CFLAGS)

tests: $(DIR_SRC)/test.cpp $(DIR_INC)/tests.hpp $(DIR_SRC)/assembler.cpp $(DIR_INC)/assembler.hpp
	$(CC) $(DIR_SRC)/test.cpp $(DIR_SRC)/assembler.cpp -o $(DIR_BIN)/$(BINAR) $(CFLAGS)
