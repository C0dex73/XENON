#~constants
SRC_DIR=./src
BIN_DIR=./bin
BUILD_DIR=./build
EXEC=assembler.exe
CPP=g++
CPPFLAGS=-std=c++17
C2OFLAGS=-W
O2EXEFLAGS=
RAW_SRC_FILES_PATH=$(wildcard $(SRC_DIR)/*.cpp)
SOURCE_FILES=$(RAW_SRC_FILES_PATH:$(SRC_DIR)/%=%)
SRC=$(foreach file, $(SOURCE_FILES), $(SRC_DIR)/$(file))
OBJ=$(foreach file, $(SOURCE_FILES), $(BIN_DIR)/$(file:.cpp=.o))

#~run command arguments parsing into RUN_ARGS
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

#~MAKEFILE

all: $(BIN_DIR)_dir $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $@ $^ $(O2EXEFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	$(CPP) $(CPPFLAGS) -c -o $@ $< $($@) $(C2OFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $< $(C2OFLAGS)

#~UTILS

.PHONY: clean reset build fullauto rbin rbuild run

clean:
	rm -rf $(BIN_DIR)/*.o

reset:
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)

build: all $(BUILD_DIR)_dir
	cp $(BIN_DIR)/*.exe $(BUILD_DIR)

fullauto: build
	$(BUILD_DIR)/$(EXEC) $(RUN_ARGS)

rbin:
	rm -rf $(BIN_DIR)

rbuild:
	rm -rf $(BUILD_DIR)

run: $(BUILD_DIR)/$(EXEC) | build
	$(BUILD_DIR)/$(EXEC) $(RUN_ARGS)

#~DIRECTORIES

$(BUILD_DIR)_dir:
	mkdir $(BUILD_DIR) -p

$(BIN_DIR)_dir :
	mkdir $(BIN_DIR) -p

#~DEBUG
debug:
	@echo There is no debug script written in $(CURDIR)/makefile