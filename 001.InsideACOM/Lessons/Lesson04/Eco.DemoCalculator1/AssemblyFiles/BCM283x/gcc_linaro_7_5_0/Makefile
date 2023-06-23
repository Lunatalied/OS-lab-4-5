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

INCLUDES = \
-I ..\..\..\HeaderFiles \
-I ..\..\..\SharedFiles \
-I ..\..\..\..\..\Lesson02\Eco.CalculatorA\SharedFiles \
-I ..\..\..\..\..\Lesson03\Eco.CalculatorB\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.IPCC.Mailbox1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.BIOSExtensions1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.Core1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.InterfaceBus1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.System1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.MemoryManager1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.FileSystemManagement1\SharedFiles \
-I $(ECO_FRAMEWORK)\Eco.String1\SharedFiles

LIB = \
-L ..\..\..\BuildFiles\BCM283x \
-L ..\..\..\..\..\Lesson02\Eco.CalculatorA\BuildFiles\BCM283x \
-L ..\..\..\..\..\Lesson03\Eco.CalculatorB\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.IPCC.Mailbox1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.BIOSExtensions1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.InterfaceBus1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.System1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.FileSystemManagement1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.MemoryManager1\BuildFiles\BCM283x \
-L $(ECO_FRAMEWORK)\Eco.String1\BuildFiles\BCM283x

Pi3-64: CFLAGS = -Wall -O3 -Wno-missing-braces -march=armv8-a+simd -mtune=cortex-a53 -mstrict-align -fno-tree-loop-vectorize -fno-tree-slp-vectorize -DECO_BCM283X -DECO_LIB -DUGUID_UTILITY $(INCLUDES)
Pi3-64: IMGFILE = kernel8.img
Pi3-64: ARMGNU  = $(ECO_TOOLCHAIN)/gcc-linaro-7.5.0/bin/
Pi3-64: LINKERFILE = startup.ld
Pi3-64: PISTART = ..\..\..\SourceFiles\entry.S


LDFLAGS = -nostartfiles -ffreestanding -fno-asynchronous-unwind-tables -fomit-frame-pointer 

LIBFLAGS=-static $(LIB) -l00000000000000000000000000000100 -l00000000000000000000000042757331 -l0000000000000000000000004D656D31 -l00000000000000000000000042494F53 -l00000000000000000000000046534D31 -lF10BC39A4F2143CF8A1E104650A2C302 -l4828F6552E4540E78121EBD220DC360E -lAE202E543CE54550899603BD70C62565 -lc -lm -lgcc 

LINKERFLAGS=-Wl,-Map,kernel.map
ASMFLAGS=-nostartfiles -ffreestanding -fno-asynchronous-unwind-tables -fomit-frame-pointer -Wa,-a>list.txt"

# The directory in which source files are stored.
SOURCE = \
..\..\..\SourceFiles\EcoDemoCalculator1.c \
..\..\..\SourceFiles\EcoDemoDialogRPi.c

# The name of the assembler listing file to generate.
LIST = kernel.list

# The name of the map file to generate.
MAP = kernel.map

# The names of all object files that must be generated. Deduced from the 
# assembly code files in source.
C_FILES := $(filter-out $(SOURCE), $(wildcard *.c))

# Rule to make everything.
Pi3-64: $(LIST)
	
# Rule to remake everything. Does not include clean.
all: Pi3-64

# Rule to make the image & listing files.
$(LIST) : kernel.elf
	$(ARMGNU)aarch64-elf-objdump -d kernel.elf > $(LIST)
	$(ARMGNU)aarch64-elf-objcopy kernel.elf -O binary $(IMGFILE)
	$(ARMGNU)aarch64-elf-nm -n kernel.elf > $(MAP)

OBJDIR := build
target = ${OBJDIR}/$(patsubst %.c,%.o,$(notdir ${1}))
obj.c :=
define obj
  $(call target,${1}) : ${1} | 
  obj$(suffix ${1}) += $(call target,${1})
endef

define SOURCES
  $(foreach src,${1},$(eval $(call obj,${src})))
endef

$(eval $(call SOURCES,${C_FILES}))

main.c : ${obj.c}

 ${obj.c} : % :
	$(ARMGNU)aarch64-elf-gcc $(CFLAGS) $(ASMFLAGS) $(LDFLAGS) -c $^ -o $@
# Uncomment this if you want the assembler output of each object file
#	$(ARMGNU)aarch64-elf-gcc $(CFLAGS) $(LDFLAGS) -S $^ -o $(patsubst %.o,%.s,$(@))

kernel.elf : main.c
	$(ARMGNU)aarch64-elf-gcc $(CFLAGS) $(LDFLAGS) $(LINKERFLAGS) -Wl,-T,$(LINKERFILE) $(wildcard $(OBJDIR)/*.o)  -o $@ $(SOURCE) $(PISTART) $(LIBFLAGS) 

# Control silent mode  .... we want silent in clean
.silent:clean

# cleanup temp files
clean:
	$(RM) $(MAP) $(SWALLOW_OUTPUT)
	$(RM) kernel.elf $(SWALLOW_OUTPUT)
	$(RM) $(LIST) $(SWALLOW_OUTPUT)
	$(RM) $(OBJDIR)$(SLASH)*.o $(SWALLOW_OUTPUT)
	$(RM) $(OBJDIR)$(SLASH)*.s $(SWALLOW_OUTPUT)
	echo CLEAN COMPLETED
