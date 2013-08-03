###############################################################################
#
# 
# Makefile       (RPB2010088)
#
# Targets: 
# - main executables  
# - library (which can be loaded within root: gSystem->Load("lib/hwwLib.so") )
# 
#
################################################################################


CXX     = g++
LD      = g++

BIN_DIR = ./
OBJ_DIR = ./
SRC_DIR = src/
INC_DIR = FilterWgamgam

#ROOTCINT     = $(ROOTSYS)/bin/rootcint
#ROOTCONFIG   = $(ROOTSYS)/bin/root-config
ROOTCINT     = rootcint
ROOTCONFIG   = root-config
ROOTCXXFLAGS = $(shell $(ROOTCONFIG) --cflags)
ROOTLIBS     = $(shell $(ROOTCONFIG) --libs) -lTreePlayer -lTMVA

# we need to link against an additional library if using root>5.24
NEWROOTVERSION  = $(shell $(ROOTCONFIG) --version | grep -c "5.24" )
ifeq ($(NEWROOTVERSION),1)
	ROOTLIBS +=  -lRIO
endif
LIBS         = $(ROOTLIBS)
DEBUG        = false


# do something like 
#  make DEBUG=true
# to activate the debug options
ifeq ($(DEBUG),true)
	CXXFLAGS     = -O0 -Wall -ggdb -fPIC -I$(INC_DIR) $(ROOTCXXFLAGS)
	LDFLAGS      = -O0 -Wall -ggdb -I$(INC_DIR) $(ROOTCXXFLAGS)
else
	CXXFLAGS     = -O2 -Wall -fPIC -I$(INC_DIR) $(ROOTCXXFLAGS)
	LDFLAGS      = -O2 -I$(INC_DIR) $(ROOTCXXFLAGS)
endif

OBJECT_RUNANA = $(OBJ_DIR)/RunAnalysis.o

RUN_MERGE           = $(BIN_DIR)/RunAnalysis

# Main targets

all:   $(RUN_MERGE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(CXX) $(CXXFLAGS) -c $^ -o $@ -I../FilterWgamgam

$(RUN_MERGE): $(OBJECT_RUNANA) $(OBJECT_CONFIG)
	$(CXX) $(CXXFLAGS) -o $@ -g $^ $(LIBS) -I../FilterWgamgam
clean:
	@echo -e "\n\n===> cleaning directories"
	rm -f $(OBJ_DIR)/*.o 
