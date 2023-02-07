#ifndef MODULE_A3_H
#define MODULE_A3_H

#include "game/module.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[0x54];
} moduleA3;

void moduleA3_calc(moduleA3* this);    // 0x0F000000

#endif
