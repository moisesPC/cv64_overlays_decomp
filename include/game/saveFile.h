#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "ultra64/ultratypes.h"

typedef enum {
    GAME_WAS_SAVED_MID_PLAY =       (1 << 0),
    EASY =                          (1 << 4),
    NORMAL =                        (1 << 5),
    HARD =                          (1 << 6),
    HARD_MODE_ENABLED =             (1 << 8),
    CAN_USE_ALT_COSTUME_REINDHART = (1 << 9),
    CAN_USE_ALT_COSTUME_CARRIE =    (1 << 10),
    GOOD_ENDING_REINDHART =         (1 << 17),
    GOOD_ENDING_CARRIE =            (1 << 18),
    BAD_ENDING_REINDHART =          (1 << 19),
    BAD_ENDING_CARRIE =             (1 << 20),
    COSTUME_IS_BEING_USED =         (1 << 30),
    CAN_EXPLODE_ON_JUMPING =        (1 << 31)
} saveFile_flags;

typedef struct {
    u32 event_flags[16];
    saveFile_flags flags;
    u16 weeks_passed;
    u16 day;
    u16 hour;
    u16 minute;
    u16 seconds;
    u16 milliseconds;
    u32 field8_0x50;
    s16 field9_0x54;
    s16 field10_0x56;
    u16 character;
    u16 life;
    u16 field13_0x5c;                           // Maybe related to the scrapped Magic meter?
    u16 subweapon;
    u32 money;
    u8 inventory_items_amount[42];
    u8 field22_0x8e;
    u8 field23_0x8f;
    u8 field24_0x90;
    u8 field25_0x91;
    u8 field26_0x92;
    u8 field27_0x93;
    u8 field28_0x94;
    u8 field29_0x95;
    u8 field30_0x96;
    u8 field31_0x97;
    u8 field32_0x98;
    u8 field33_0x99;
    u8 field34_0x9a;
    u8 field35_0x9b;
    u8 field36_0x9c;
    u8 field37_0x9d;
    u8 field38_0x9e;
    u8 field39_0x9f;
    u8 field40_0xa0;
    u8 field41_0xa1;
    u8 field42_0xa2;
    u8 field43_0xa3;
    u32 player_flags;
    u16 health_depletion_rate_while_poisoned;
    u16 current_hour_VAMP;                      // If greater than 24, you turn into vampire
    s16 map_ID;
    s16 map_entrance_ID;
    u8 save_crystal_number;
    u8 field50_0xb1;
    u8 field51_0xb2;
    u8 field52_0xb3;
    u32 time_saved_counter;
    u32 death_counter;
    s32 field55_0xbc;
    s32 field59_0xc0;
    s32 field63_0xc4;
    s16 field67_0xc8;
    s16 field69_0xca;
    s32 field71_0xcc;
    s32 field75_0xd0;
    s16 field77_0xd2;
    s16 field79_0xd4;
    s32 field83_0xd8;
    u32 money_spent_on_Renon;
} SaveStruct;

typedef struct {
    SaveStruct main;
    SaveStruct beginning_of_stage;               // Used when pressing the "Restart Stage" option on Game Over
    u32 first_checksum;
    u32 second_checksum;
    u8 field4_0x1c8;
    u8 field5_0x1c9;
    u8 field6_0x1ca;
    u8 field7_0x1cb;
    u8 field8_0x1cc;
    u8 field9_0x1cd;
    u8 field10_0x1ce;
    u8 field11_0x1cf;
    u8 field12_0x1d0;
    u8 field13_0x1d1;
    u8 field14_0x1d2;
    u8 field15_0x1d3;
    u8 field16_0x1d4;
    u8 field17_0x1d5;
    u8 field18_0x1d6;
    u8 field19_0x1d7;
    u8 field20_0x1d8;
    u8 field21_0x1d9;
    u8 field22_0x1da;
    u8 field23_0x1db;
    u8 field24_0x1dc;
    u8 field25_0x1dd;
    u8 field26_0x1de;
    u8 field27_0x1df;
    u8 field28_0x1e0;
    u8 field29_0x1e1;
    u8 field30_0x1e2;
    u8 field31_0x1e3;
    u8 field32_0x1e4;
    u8 field33_0x1e5;
    u8 field34_0x1e6;
    u8 field35_0x1e7;
    u8 field36_0x1e8;
    u8 field37_0x1e9;
    u8 field38_0x1ea;
    u8 field39_0x1eb;
    u8 field40_0x1ec;
    u8 field41_0x1ed;
    u8 field42_0x1ee;
    u8 field43_0x1ef;
    u8 field44_0x1f0;
    u8 field45_0x1f1;
    u8 field46_0x1f2;
    u8 field47_0x1f3;
    u8 field48_0x1f4;
    u8 field49_0x1f5;
    u8 field50_0x1f6;
    u8 field51_0x1f7;
    u8 field52_0x1f8;
    u8 field53_0x1f9;
    u8 field54_0x1fa;
    u8 field55_0x1fb;
    u8 field56_0x1fc;
    u8 field57_0x1fd;
    u8 field58_0x1fe;
    u8 field59_0x1ff;
} SaveFileSlot;

#define SAVE_STRUCT_SIZE sizeof(SaveStruct)
#define SAVE_SLOT_SIZE sizeof(SaveFileSlot)

#endif
