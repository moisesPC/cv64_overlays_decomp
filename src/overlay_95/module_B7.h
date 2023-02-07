#ifndef MODULE_B7_H
#define MODULE_B7_H

#include "game/module.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[0x54];
} module_B7;

void moduleB7_calc(module_B7* this);                // 0x0F000000

#endif
