#ifndef MODEL_INFO_H
#define MODEL_INFO_H

#include "ultra64/ultratypes.h"
#include "game/math.h"

typedef struct {
    s16 field0_0x0;
    s16 field1_0x2;
    struct model_info* field2_0x4;
    struct model_info* field3_0x8;
    struct model_info* field4_0xc;
    struct model_info* field5_0x10;
    u32 ambient_color;                       // AKA primitive_color
    u32 environment_color;
    u32 blend_color;
    u32 fog_color;
    u16 texture;
    u16 color;
    u8 field12_0x28;
    u8 field13_0x29;
    u8 field14_0x2a;
    u8 field15_0x2b;
    u8 field16_0x2c;
    u8 field17_0x2d;
    u8 field18_0x2e;
    u8 field19_0x2f;
    void* a_display_list_ptr;                 // Gfx*
    u32 display_list_address;
    u32 field22_0x38;
    s32 assets_file_ID;
    vec3f position;
    angle angle;
    angle field26_0x52;
    vec3f size;
    u8 field28_0x64;
    u8 field29_0x65;
    u8 field30_0x66;
    u8 field31_0x67;
    MtxF field32_0x68;
} model_info;

extern model_info* D_8009B450;      // 0x8009B450

#endif
