#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "ultra64/ultratypes.h"
#include "game/math.h"

enum textbox_flags {
    SLOW_TEXT_TRANSITION = (1 << 20),
    FAST_TEXT_TRANSITION = (1 << 21),
    CLOSE_TEXTBOX        = (1 << 26),
    OPEN_TEXTBOX         = (1 << 27),
    TEXTBOX_IS_ACTIVE    = (1 << 30)
};

typedef struct {
    u32 flags;
    void* field1_0x4;
    void* text;
    s32 field3_0xc;
    s32 field4_0x10;
    vec2s position;
    vec3f scale;
    s32 field7_0x24;
    u8 field8_0x28;
    u8 field9_0x29;
    u8 field10_0x2a;
    u8 field11_0x2b;
    s16 width;
    u8 field13_0x2e;
    u8 field14_0x2f;
    u8 height;
    u8 field16_0x31;
    u8 character_spacing;
    u8 field18_0x33;
    u8 color_palette;
    u8 field20_0x35;
    u8 field21_0x36;
    u8 field22_0x37;
    u8 field23_0x38;
    u8 field24_0x39;
    u8 field25_0x3a;
    u8 textbox_display_time;
    u8 field27_0x3c;
    u8 field28_0x3d;
    u8 field29_0x3e;
    u8 field30_0x3f;
    s32 field31_0x40;
    u8 field32_0x44;
    u8 field33_0x45;
    u8 field34_0x46;
    u8 field35_0x47;
    u8 field36_0x48;
    u8 field37_0x49;
    u8 field38_0x4a;
    u8 field39_0x4b;
    u8 field40_0x4c;
    u8 field41_0x4d;
    u8 field42_0x4e;
    u8 field43_0x4f;
    u8 field44_0x50;
    u8 field45_0x51;
    u8 field46_0x52;
    u8 field47_0x53;
    u32 textbox_appearence_flags;
    f32 textbox_frame_closing_speed;
    struct textbox* field50_0x5c;
    u8 field51_0x60;
    u8 field52_0x61;
    u8 field53_0x62;
    u8 field54_0x63;
    vec3f field55_0x64;
    u8* field56_0x70;
} textbox;

extern textbox* textbox_create(void* parent_module, void* param_2, u32 flags);              // 0x8012cb88
extern void textbox_setDimensions(textbox* this, s8 height, s16 width, u8 param_4, u8 character_spacing);       // 0x8012cd14
extern void textbox_setPos(textbox* this, u16 text_X_pos, u16 text_Y_pos, s32 unused);      // 0x8012ccfc
extern void textbox_setMessagePtr(textbox* this, u16* text, s32 param_3, s16 param_4);      // 0x8012cd38
extern void textbox_8012cda4(textbox* this, u32 param_2, f32 closing_speed);                // 0x8012cda4
extern void* text_getMessageFromPool(u16* message_pool_base_ptr, s32 id);                   // 0x8012ce7c

#endif
