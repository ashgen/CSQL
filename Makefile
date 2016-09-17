
INCLUDE_DIR:=include/
SRC_DIR:=src/
BIN_DIR:=bin/
OBJ_DIR:=obj/
CC:=g++
CPP := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(CPP:.cpp=.o)))
CCFLAGS := -Wall -pedantic -std=c++11 -g -I $(INCLUDE_DIR) 
LDFLAGS := -lodb-mssql -lodb-boost -lodb
all:TestMain

TestMain:$(OBJ)
	$(CC)  $(LDFLAGS) -o $@ $<

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

