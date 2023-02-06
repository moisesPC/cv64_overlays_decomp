# Overlay info
OVERLAY_NAME = endingMessageEasy
OVERLAY_OUT = $(OVERLAY_NAME).bin
OBJECT = $(OVERLAY_NAME).o
BUILD = build/$(OVERLAY_NAME)

# Tools
CC   = tools/ido71/cc
LD   = mips64-ld
NOVL = tools/nOVL/novl
SHA1SUM := sha1sum
READELF = readelf

# Includes
INCLUDES := -Iinclude

# Source files
SRC_FILES = src/$(OVERLAY_NAME)/$(OVERLAY_NAME).c

# Compiler flags
CFLAGS = -G0 -mips2 -non_shared -fullwarn -verbose -Xcpluscomm -Wab,-r4300_mul $(INCLUDES)
OPTFLAGS := -O2

# Linker flags
LDFLAGS = -T src/$(OVERLAY_NAME)/linker.ld

# nOVL flags
NOVL_ENTRYPOINT = 0x0F000000
NOVLFLAGS = -v -c -A $(NOVL_ENTRYPOINT) -o $(BUILD)/$(OVERLAY_OUT)

default: compile $(OVERLAY_OUT) readelf verify

compile:
	@echo "===== Compiling ====="
	mkdir -p $(BUILD)
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $(BUILD)/$(OBJECT) $(SRC_FILES)

$(OVERLAY_OUT):
	@echo "\n===== Linking ====="
	$(LD) -o $(BUILD)/$(OVERLAY_NAME).elf $(BUILD)/$(OBJECT) $(LDFLAGS)
	@echo "\n===== Executing nOVL... ====="
	$(NOVL) $(NOVLFLAGS) $(BUILD)/$(OVERLAY_NAME).elf

readelf:
	@echo "\n===== Saving ELF information ====="
	$(READELF) -all $(BUILD)/$(OVERLAY_NAME).elf > $(BUILD)/$(OVERLAY_NAME).txt
    
verify:
	@echo "\n===== Veryfing checksums ====="
	@cd sha1
	@$(SHA1SUM) -c sha1/$(OVERLAY_NAME).sha1

clean:
	rm -rf build