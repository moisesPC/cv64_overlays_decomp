#ifndef MODULE_H
#define MODULE_H

#include "ultra64/ultratypes.h"

enum ModuleHeader_flags {
    PAUSE      = (1 << 14),
    TOP_MODULE = (1 << 15)
};

typedef struct {
    u8 timer;                      // Could also be "number of accesses to function"
    u8 function;                   // ID within the functions array
} functionInfo;                    // Size = 0x2

typedef struct {
    s16 ID;
    s16 flags;
    s16 field_0x04;
    s16 field_0x06;
    functionInfo current_function[3];
    s16 functionInfo_ID;
    void (*destroy)(void*);
    struct ModuleHeader* parent;
    struct ModuleHeader* next;
    struct ModuleHeader* child;
} ModuleHeader;                    // Size = 0x20

extern void goToNextFunc(s8* functionInfo, s16* functionInfo_ID);       // 0x80001448

#endif
