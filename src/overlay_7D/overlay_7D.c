/*
 * File: overlay_7D.c
 * Description:
 * Associated modules: 0x20A3, 0x20A4, 0x20A5
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x80095AD0 (0xA3), 0x80095AE0 (0xA4), 0x80095AF0 (0xA5), 
 * Associated files:
 *   0x7D (Overlay)
 */

#include "overlay_7D.h"

void moduleA3_entrypoint(moduleA3* self) {
    ENTER(self, modules_163_164_165_functions);
}

void moduleA4_entrypoint(moduleA4* self) {
    ENTER(self, modules_163_164_165_functions);
}

void moduleA5_entrypoint(moduleA5* self) {
    ENTER(self, modules_163_164_165_functions);
}

void func_0F000150(void* self) {}
