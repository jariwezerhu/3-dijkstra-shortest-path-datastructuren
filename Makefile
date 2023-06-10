CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

HEADERS = $(wildcard $(INCLUDE_DIR)/*.hpp)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BIN_DIR)/main.exe
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
    $(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^
clean:
    rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)
all: $(EXECUTABLE)