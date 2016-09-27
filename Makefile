INCLUDE_DIR:=include/
ESTEE_EXT_DIR=$(HOME)/Linux/References/EsteeAPI/Includes/External
ESTEE_INT_DIR=$(HOME)/Linux/References/EsteeAPI/Includes/Internal
ESTEE_LIBS_DIR=$(HOME)/Linux/References/EsteeAPI/Libs
STRATEGY_COMMON_DIR= $(HOME)/Linux/Strategy/Estee.Linux/Estee.Strategy/Estee.Strategy.Common/
OPTION_COMMON_DIR= $(HOME)/Linux/Strategy/Estee.Linux/Estee.Strategy/Estee.Options/Estee.Options.Common/
MM_COMMON_DIR= $(HOME)/Linux/Strategy/Estee.Linux/Estee.Strategy/Estee.Options/Estee.MarketMaking.Common/
ESTEE_STRATEGY_LIB_DIR= $(HOME)/Linux/Platform/Estee.Linux/Estee_LD_LIBRARY
SRC_DIR:=src/
BIN_DIR:=bin/
OBJ_DIR:=obj/
SQL_DIR:=sql/
BOOST_DIR=/usr/local/boost_1_58_0/lib/
CC:=g++
CPP := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(CPP:.cpp=.o)))
CCFLAGS := -Wall -Wno-unknown-pragmas -pedantic -std=c++11 -g3 -I $(INCLUDE_DIR) -I $(ESTEE_EXT_DIR) -I $(ESTEE_INT_DIR) -I $(STRATEGY_COMMON_DIR)include -I $(OPTION_COMMON_DIR)include -I $(MM_COMMON_DIR)include -DDATABASE_SQLLITE -DDATABASE_MSSQL
LDFLAGS :=   -L $(ESTEE_STRATEGY_LIB_DIR) -lEstee.OptionsMM -L $(ESTEE_LIBS_DIR) -lEstee.Strategy.Common  -L $(ESTEE_LIBS_DIR) -lEsteeAPI -lactivemq-cpp -lEstee.QuickFix -lonetick -lOtqQueryProcessor -lodb-mssql  -lodb  -lodb-boost -lboost_date_time -lboost_system -lboost_thread -lpthread -lrt -lxml2
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
	$(CC) $(CCFLAGS) -o $(BIN_DIR)$@ $(ODB_OBJ) $(OBJ) $(LDFLAGS) 

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) -c  $< -o $@ 

$(OBJ_DIR)%-odb.o: $(SRC_DIR)/%-odb.cxx
	$(CC) $(CCFLAGS) -c  $< -o $@ 

$(SRC_DIR)/%-odb.cxx:$(INCLUDE_DIR)%.h
	odb --multi-database dynamic -d common -d mssql -d sqlite --profile boost --generate-schema --generate-query  $<
	mv *-odb.cxx $(SRC_DIR)/ 
	mv *.sql $(SQL_DIR)/ 
	mv *.hxx *.ixx $(INCLUDE_DIR)/ 
