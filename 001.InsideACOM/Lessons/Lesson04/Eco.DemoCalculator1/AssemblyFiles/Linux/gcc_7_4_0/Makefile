# source files.
SRC = \
../../../SourceFiles/EcoDemoCalculator1.c \
../../../SourceFiles/EcoDemoDialogX11.c


# include directories
INCLUDES = \
-I ../../../HeaderFiles \
-I ../../../../../Lesson02/Eco.CalculatorA/SharedFiles \
-I ../../../../../Lesson03/Eco.CalculatorB/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Core1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.InterfaceBus1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.FileSystemManagement1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.MemoryManager1/SharedFiles

# libraries directories
LIB_DIR = \
-L$(ECO_FRAMEWORK)/Eco.InterfaceBus1/BuildFiles/Linux/x64/StaticRelease \
-L$(ECO_FRAMEWORK)/Eco.FileSystemManagement1/BuildFiles/Linux/x64/StaticRelease \
-L$(ECO_FRAMEWORK)/Eco.MemoryManager1/BuildFiles/Linux/x64/StaticRelease \
-L$(ECO_FRAMEWORK)/Eco.System1/BuildFiles/Linux/x64/StaticRelease

OBJ = $(SRC:.c=.o)

OUT = DemoCalculator1
OUT_DIR = ../../../BuildFiles/Linux/x64/DynamicRelease

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -Wall -O3 -g -DLINUX -DECO_LINUX -DUGUID_UTILITY

# compiler
GNU =
CC = gcc
AR = gcc-ar

# library paths
LIBS = $(LIB_DIR) -lX11 -lm -lc -lgcc -ldl -l00000000000000000000000000000100 -l00000000000000000000000042757331 -l0000000000000000000000004D656D31 -l00000000000000000000000046534D31

# compile flags
LDFLAGS = -g $(LIBS)

.SUFFIXES: .c

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CC) ${LDFLAGS} -o $(OUT_DIR)/$(OUT) $(OBJ) $(LDFLAGS)
	rm $(OBJ)

clean:
	rm $(OBJ) $(OUT_DIR)/$(OUT)

