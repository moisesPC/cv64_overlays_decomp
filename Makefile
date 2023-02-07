#### File and directory names ####

# Directory that contains the source code for each overlay
# Each overlay has its own directory with its source code
SRC_DIR := src

# Names of each overlay to build
# They're obtained from the directory names inside "src" $(SRC_DIR)
OVERLAYS := $(foreach dirs,$(shell find $(SRC_DIR) -mindepth 1 -maxdepth 1 -type d ),$(notdir $(dirs)))

#### Tools ####
# Compiler
CC   = tools/ido71/cc
# Linker
LD   = mips64-ld
# nOVL (ELF -> overlay conversion)
NOVL = tools/nOVL/novl
# Verifies sha1 of generated overlay to see if it matches with the one from the ROM
SHA1SUM := sha1sum
# Extracts ELF information
READELF = readelf

#### Options ####
# Includes
INCLUDES := -Iinclude

# Compiler flags
CFLAGS = -G0 -mips2 -non_shared -fullwarn -verbose -Xcpluscomm -Wab,-r4300_mul $(INCLUDES)
OPTFLAGS := -O2

#### Recipes ####

default: all
all: $(OVERLAYS)

# 1. Create build directory for each overlay
# 2. Create a list with all C source code files for each overlay, and put them in SRC_FILES
# 3. Compile overlay
# 4. Link overlay and generate the final ELF
# 5. Invoke nOVL for ELF -> overlay conversion
# 6. Dump ELF information
# 7. Verify hashes
$(OVERLAYS):
	@mkdir -p build/$@
	
	@echo "======= Compiling $@ ======="
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o build/$@/$@.o src/$@/$@.c

	@echo "\n== Linking =="
	$(LD) -o build/$@/$@.elf build/$@/$@.o -T src/$@/linker.ld

	@echo "\n== Converting ELF to overlay =="
	$(NOVL) -c -o build/$@/$@.ovl build/$@/$@.elf

	@echo "\n== Verifying =="
	@cd sha1
	@$(SHA1SUM) -c sha1/$@.sha1

	@echo "\n"

clean:
	rm -rf build

.PHONY: all clean
