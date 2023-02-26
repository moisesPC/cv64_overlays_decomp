/*
 * File: overlay_7D.c
 * Description:
 * Associated modules: 0xA3, 0xA4, 0xA5
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x80095AD0 (0xA3), 0x80095AE0 (0xA4), 0x80095AF0 (0xA5), 
 * Associated files:
 *   0x7D (Overlay)
 */

#include "overlay_7D.h"

void moduleA3_calc(moduleA3* this) {
    s16 temp;
    
    temp = this->header.functionInfo_ID + 1;
    this->header.functionInfo_ID = temp,
    this->header.current_function[temp].timer++;
    (*modules_163_164_165_functions[this->header.current_function[temp].function])(this);
    this->header.functionInfo_ID--;
}

void moduleA4_calc(moduleA4* this) {
    s16 temp;
    
    temp = this->header.functionInfo_ID + 1;
    this->header.functionInfo_ID = temp,
    this->header.current_function[temp].timer++;
    (*modules_163_164_165_functions[this->header.current_function[temp].function])(this);
    this->header.functionInfo_ID--;
}

void moduleA5_calc(moduleA5* this) {
    s16 temp;
    
    temp = this->header.functionInfo_ID + 1;
    this->header.functionInfo_ID = temp,
    this->header.current_function[temp].timer++;
    (*modules_163_164_165_functions[this->header.current_function[temp].function])(this);
    this->header.functionInfo_ID--;
}

void func_0F000150(void* this) {}
