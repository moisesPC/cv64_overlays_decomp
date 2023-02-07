#ifndef MODULE_A4_H
#define MODULE_A4_H

#include "game/module.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[0x54];
} moduleA4;

void moduleA4_calc(moduleA4* this);    // 0x0F000070

#endif
