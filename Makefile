INCLUDE_DIR:=include/
SRC_DIR:=src/
BIN_DIR:=bin/
OBJ_DIR:=obj/
SQL_DIR:=sql/
BOOST_DIR=/usr/local/boost_1_58_0/lib/
CC:=g++
CPP := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(CPP:.cpp=.o)))
CCFLAGS := -Wall -Wno-unknown-pragmas -pedantic -std=c++11 -g -I $(INCLUDE_DIR)  
LDFLAGS := -lodb-mssql  -lodb  -lodb-boost  -lboost_date_time -lpthread 
SQL:= $(INCLUDE_DIR)/ClosingPrice.h\
		$(INCLUDE_DIR)/EsteeMaster.h\
		$(INCLUDE_DIR)/EsteeMasterArchive.h
		
ODB_OBJ= $(addprefix obj/,$(notdir $(SQL:.h=-odb.o)))
GEN_FILES:= $(INCLUDE_DIR)/*.hxx $(INCLUDE_DIR)/*.ixx $(SRC_DIR)/*.cxx $(SQL_DIR)/*.sql
all:TestMain

clean:
	rm -f $(GEN_FILES)
	rm -f $(ODB_OBJ) $(OBJ)
	 
TestMain:$(ODB_OBJ) $(OBJ) 
	$(CC) $(CCFLAGS) -o $@ $(ODB_OBJ) $(OBJ) $(LDFLAGS) 

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) -c  $< -o $@ 

$(OBJ_DIR)%-odb.o: $(SRC_DIR)/%-odb.cxx
	$(CC) $(CCFLAGS) -c  $< -o $@ 

$(SRC_DIR)/%-odb.cxx:$(INCLUDE_DIR)%.h
	odb -d mssql --profile boost --generate-schema --generate-query  $<
	mv *-odb.cxx $(SRC_DIR)/ 
	mv *.sql $(SQL_DIR)/ 
	mv *.hxx *.ixx $(INCLUDE_DIR)/ 