ifeq ($(OS), Windows_NT)
	#WINDOWS USE THESE DEFINITIONS
	RM = -del /q /f
	SLASH = \\
	SWALLOW_OUTPUT = >nul 2>nul
else
	#LINUX USE THESE DEFINITIONS
	RM = -rm -f
	SLASH = /
	SWALLOW_OUTPUT =
endif 

# include directories
INC = \
-I D:\\OS-lab-4-5\\Eco.Lab4\\BubleSort\\HeaderFiles \
-I D:\\OS-lab-4-5\\Eco.Lab4\\BubleSort\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.Core1\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.InterfaceBus1\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.BIOSExtensions1\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.MemoryManager1\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.System1\\SharedFiles \
-I D:\\OS-lab-4-5\\001.InsideACOM\\Lessons\\Lesson02\\Eco.CalculatorA\\SharedFiles \
-I D:\\OS-lab-4-5\\001.InsideACOM\\Lessons\\Lesson03\\Eco.CalculatorB\\SharedFiles \
-I D:\\OS-lab-4-5\\001.InsideACOM\\Lessons\\Lesson06\\Eco.CalculatorD\\SharedFiles \
-I D:\\OS-lab-4-5\\001.InsideACOM\\Lessons\\Lesson07\\Eco.CalculatorE\\SharedFiles \
-I $(ECO_FRAMEWORK)\\Eco.List1\\SharedFiles

# source files.
SRC = \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CBubleSort.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoLab1ConnectionPoint.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoLab1EnumConnectionPoints.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoLab1EnumConnections.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CBubleSortFactory.c

OBJ = $(SRC:.c=.o)

OUT = lib680786EC2FB742F2A3C6C9D4B4ED74BE.a
OUT_DIR = ..$(SLASH)..$(SLASH)..$(SLASH)BuildFiles$(SLASH)BCM283x$(SLASH)arm64-v8a$(SLASH)StaticRelease

 
# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -Wall -Wno-missing-braces -march=armv8-a+simd -mtune=cortex-a53 -mstrict-align -fno-tree-loop-vectorize -fno-tree-slp-vectorize -DECO_BCM283X -DECO_LIB -DUGUID_UTILITY
 
# compiler
ARMGNU  = $(ECO_TOOLCHAIN)/gcc-linaro-7.5.0/bin/
CCC = $(ARMGNU)aarch64-elf-gcc
 
# library paths
LIBS = -lc -lm -lgcc
 
# compile flags
LDFLAGS = -g
 
.SUFFIXES: .c

all: $(OUT)

.c.o:
	$(CCC) $(INC) $(CCFLAGS) -c $< -o $@
 
$(OUT): $(OBJ)
	$(ARMGNU)aarch64-elf-ar -rcs $(OUT_DIR)$(SLASH)$(OUT) $(OBJ)
 

clean:
	$(RM) $(OBJ) $(OUT_DIR)$(SLASH)$(OUT)
