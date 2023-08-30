import sys
import os

## File and directory names ##
ROM_vanilla = sys.argv[1]
ROM_patched = sys.argv[2]
overlay_dir = sys.argv[3]

## Addresses ##
# This is the start of the free space in the ROM
overlay_injection_offset = 0x00BB2D88

## Other global variables ##
new_entrypoint = 0x0F000000
new_module_ID = 0x2141

## Functions ##

def getFileSize(file):
    file.seek(0, os.SEEK_END)
    file_size = file.tell()
    file.seek(0)
    return file_size


# We need to tell the game what file to load for the overlay
# In order for the game to know what file it is,
# we need to write the overlay file ID
def writeFileInfo(ROM_out, fileInfo):
    fileinfo_read_ptr = 0x94530         # Address where the "new_fileinfo_ptr" is read from
    new_fileinfo_ptr_ROM = 0x10F290     # New ROM address to store the file info struct. This part of memory contains some unused strings
    new_fileinfo_ptr_RAM = 0x8018c0a0   # RAM address of the above

    # Write RAM address to the "file info" structure
    ROM_out.seek(fileinfo_read_ptr)
    ROM_out.write(new_fileinfo_ptr_RAM.to_bytes(4, 'big'))

    # Write "file info" data in ROM
    ROM_out.seek(new_fileinfo_ptr_ROM)
    ROM_out.write(fileInfo.to_bytes(8, 'big'))



# Write overlay file to ROM at overlay_injection_offset
def writeOverlay(ROM_in, ROM_out, overlay_file):
    # Pointer in the Nisitenma Ichigo table to the overlay file
    # We will replace file ID 0x71 (unused Smiley Face texture)
    # Its start address is 0x95FBC
    file_start_ptr = 0x95FBC
    overlay_file_end_ptr = overlay_injection_offset + getFileSize(overlay_file)

    # Write overlay data
    ROM_out.seek(overlay_injection_offset)
    ROM_out.write(overlay_file.read())

    # Write pointers to file in Nisitenma Ichigo table
    ROM_out.seek(file_start_ptr)
    ROM_out.write(overlay_injection_offset.to_bytes(4, 'big'))   # Start address. We're inserting the file decompressed, so we don't need to write a 0x80 at the beginning of the address
    ROM_out.write(overlay_file_end_ptr.to_bytes(4, 'big'))       # End address



# Patch misc. data
def updateInfo(ROM_out):
    entrypoint_read_ptr = 0x93374   # Address where the game reads the Stage Select code entrypoint
    module_ID_read_ptr = 0x92C3E    # Address where the game reads the Stage Select module ID

    # Patch module ID from 0x0141 -> 0x2141
    # This way the game knows that it has to map the overlay in the entrypoint (0x0F000000)
    ROM_out.seek(module_ID_read_ptr)
    ROM_out.write(new_module_ID.to_bytes(2, 'big'))

    # Replace entrypoint address from 0x8012A520 -> 0x0F000000
    ROM_out.seek(entrypoint_read_ptr)
    ROM_out.write(new_entrypoint.to_bytes(4, 'big'))



if __name__ == "__main__":
    # Open files
    overlay_file = open(overlay_dir, 'r+b')
    ROM_in = open(ROM_vanilla, 'r+b')
    ROM_out = open(ROM_patched, 'w+b')

    # "File info" data structure
    # It tells what files to load for the Stage Select module
    # In this case, only the overlay will be needed (we chose file 0x71 for our example, see above)
    # The 0x40 part of the address tells the game to only load that single file
    # The last 4 bytes I'm not sure what they mean
    fileInfo = 0x4000007100001000

    # Init ROM output file by copying ROM input data -> ROM output
    # Then, write the overlay data, file info, and other necessary data for the overlay to work
    ROM_out.write(ROM_in.read())
    writeOverlay(ROM_in, ROM_out, overlay_file)
    updateInfo(ROM_out)
    writeFileInfo(ROM_out, fileInfo)

    # Close files
    overlay_file.close()
    ROM_in.close()
    ROM_out.close()
