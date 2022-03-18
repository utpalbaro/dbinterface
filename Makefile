SRC_DIR := src
OBJ_DIR := out
LIB_DIR := lib
INC_DIR := ./include
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
STD := -std=c++14
CPPFLAGS := -fPIC

dbf: $(OBJ_FILES)
	ar cr $(LIB_DIR)/lib$@.a $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -c -o $@ $< -I$(INC_DIR)
