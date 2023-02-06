#ifndef ENDING_MESSAGE_EASY_H
#define ENDING_MESSAGE_EASY_H

#include "ultra64/ultratypes.h"
#include "game/module.h"
#include "game/textbox.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[28];
    textbox* ending_textbox;
    u32 active_time;
    u8 field_0x44[48];
} endingMessageEasy;

void endingMessageEasy_calc(endingMessageEasy* this);                // 0x0F000000
void endingMessageEasy_init(endingMessageEasy* this);                // 0x0F000070
void func_0F00018C();                                                // 0x0F00018C
void endingMessageEasy_loop(endingMessageEasy* this);                // 0x0F000194
void endingMessageEasy_destroy(endingMessageEasy* this);             // 0x0F0002E0

// 0x0F000350
/*
 *   You have completed
 *   the game in EASY mode.
 *   If you want to face
 *   the challenge
 *       of more stages,
 *   try NORMAL mode.
*/
u16 ending_text[120] = {
    0xA000, 0x003B, 0x0051, 0x0057, 0x0002, 0x004A, 0x0043, 0x0058,
    0x0047, 0x0002, 0x0045, 0x0051, 0x004F, 0x0052, 0x004E, 0x0047,
    0x0056, 0x0047, 0x0046, 0x0001, 0x0056, 0x004A, 0x0047, 0x0002,
    0x0049, 0x0043, 0x004F, 0x0047, 0x0002, 0x004B, 0x0050, 0x0002,
    0x0027, 0x0023, 0x0035, 0x003B, 0x0002, 0x004F, 0x0051, 0x0046,
    0x0047, 0x0010, 0x0001, 0x002B, 0x0048, 0x0002, 0x005B, 0x0051,
    0x0057, 0x0002, 0x0059, 0x0043, 0x0050, 0x0056, 0x0002, 0x0056,
    0x0051, 0x0002, 0x0048, 0x0043, 0x0045, 0x0047, 0x0002, 0x0001,
    0x0056, 0x004A, 0x0047, 0x0002, 0x0045, 0x004A, 0x0043, 0x004E,
    0x004E, 0x0047, 0x0050, 0x0049, 0x0047, 0x0002, 0x0001, 0x0002,
    0x0002, 0x0002, 0x0002, 0x0002, 0x0051, 0x0048, 0x0002, 0x004F,
    0x0051, 0x0054, 0x0047, 0x0002, 0x0055, 0x0056, 0x0043, 0x0049,
    0x0047, 0x0055, 0x000E, 0x0001, 0x0056, 0x0054, 0x005B, 0x0002,
    0x0030, 0x0031, 0x0034, 0x002F, 0x0023, 0x002E, 0x0002, 0x004F,
    0x0051, 0x0046, 0x0047, 0x0010, 0xA300, 0xFFFF
};

// 0x0F000440
void (*endingMessageEasy_functions[3])(endingMessageEasy* this) = 
{
    endingMessageEasy_init,
    endingMessageEasy_loop,
    endingMessageEasy_destroy
};

extern void* file_buffer;       // 0x803880A4. Buffer where the overlay file is stored.

#endif
