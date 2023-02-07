#ifndef MODULE_A5_H
#define MODULE_A5_H

#include "game/module.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[0x54];
} moduleA5;

void moduleA5_calc(moduleA5* this);    // 0x0F0000E0

#endif
