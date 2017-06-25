SRC_DIR := ./src
OBJ_DIR := ./build
TEST_DIR := ./test
INCLUDE_DIR := ./include
CC := g++ -std=c++11 -g -O2 -I$(INCLUDE_DIR)

$(OBJ_DIR)/brain.o: $(SRC_DIR)/brain.cpp $(INCLUDE_DIR)/state.h $(INCLUDE_DIR)/brain.h
	$(CC) -c $(SRC_DIR)/brain.cpp -o $(OBJ_DIR)/brain.o
$(OBJ_DIR)/state.o: $(SRC_DIR)/state.cpp $(INCLUDE_DIR)/state.h 
	$(CC) -c $(SRC_DIR)/state.cpp -o $(OBJ_DIR)/state.o
$(OBJ_DIR)/test-puzzle: $(OBJ_DIR)/brain.o $(OBJ_DIR)/state.o $(TEST_DIR)/main.cpp
	$(CC) $(TEST_DIR)/main.cpp $(OBJ_DIR)/brain.o $(OBJ_DIR)/state.o -o $(OBJ_DIR)/test-puzzle
run-test-puzzle: $(OBJ_DIR)/test-puzzle
	$(OBJ_DIR)/test-puzzle 8