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
INC_DIR = $(PWD)

#ROOTCINT     = $(ROOTSYS)/bin/rootcint
#ROOTCONFIG   = $(ROOTSYS)/bin/root-config
ROOTCINT     = rootcint
ROOTCONFIG   = root-config
ROOTCXXFLAGS = $(shell $(ROOTCONFIG) --cflags)
ROOTLIBS     = $(shell $(ROOTCONFIG) --libs) -lTreePlayer -lTMVA #-lBoost
BOOSTFLAGS   = -I/afs/cern.ch/sw/lcg/external/Boost/1.50.0_python2.7/x86_64-slc5-gcc43-opt/include/boost-1_50

COREINC = -I$(WorkArea)/TreeFilter/Core/
COREOBJ = $(WorkArea)/TreeFilter/Core/obj/AnalysisBase.o

# we need to link against an additional library if using root>5.24
NEWROOTVERSION  = $(shell $(ROOTCONFIG) --version | grep -c "5.24" )
ifeq ($(NEWROOTVERSION),1)
	ROOTLIBS +=  -lRIO
endif
LIBS         = $(ROOTLIBS) $(BOOSTFLAGS)
DEBUG        = false
INCLUDE      = $(ROOTCXXFLAGS) $(BOOSTFLAGS) $(COREINC)



# do something like 
#  make DEBUG=true
# to activate the debug options
ifeq ($(DEBUG),true)
	CXXFLAGS     = -O0 -Wall -ggdb -fPIC -I$(INC_DIR) $(INCLUDE)
	LDFLAGS      = -O0 -Wall -ggdb -I$(INC_DIR) $(INCLUDE) 
else
	CXXFLAGS     = -O2 -Wall -fPIC -I$(INC_DIR) $(INCLUDE)
	LDFLAGS      = -O2 -I$(INC_DIR) $(INCLUDE) 
endif

OBJECT_RUNANA = $(OBJ_DIR)/RunAnalysis.o 
BRANCH_INIT = $(OBJ_DIR)/BranchInit.o

RUN_MERGE           = $(BIN_DIR)/RunAnalysis

# Main targets

all:   $(RUN_MERGE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(CXX) $(CXXFLAGS) -c $^ -o $@ -I$(INC_DIR)

$(RUN_MERGE): $(OBJECT_RUNANA) $(BRANCH_INIT)
	$(CXX) $(CXXFLAGS) -o $@ -g $^ $(COREOBJ) $(LIBS) -I$(INC_DIR)
clean:
	@echo -e "\n\n===> cleaning directories"
	rm -f $(OBJ_DIR)/*.o 
