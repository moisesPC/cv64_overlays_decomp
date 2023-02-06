#ifndef CV64_H
#define CV64_H

// Here go struct definitions and enumerations that don't have a proper header yet.

#include "ultra64/ultratypes.h"

typedef enum {
    MORI = 0,
    TOU = 1,
    TOUOKUJI = 2,
    NAKANIWA = 3,
    BEKKAN_1F = 4,
    BEKKAN_2F = 5,
    MEIRO_TEIEN = 6,
    CHIKA_KODO = 7,
    CHIKA_SUIRO = 8,
    HONMARU_B1F = 9,
    HONMARU_1F = 10,
    HONMARU_2F = 11,
    HONMARU_3F_MINAMI = 12,
    HONMARU_4F_MINAMI = 13,
    HONMARU_3F_KITA = 14,
    HONMARU_5F = 15,
    SHOKEI_TOU = 16,
    MAHOU_TOU = 17,
    KAGAKU_TOU = 18,
    KETTOU_TOU = 19,
    TURO_TOKEITOU = 20,
    TENSHU = 21,
    ENDING_DUMMY = 22,
    TOKEITOU_NAI = 23,
    DRACULA = 24,
    ROSE = 25,
    BEKKAN_BOSS = 26,
    TOU_TURO = 27,
    ENDING = 28,
    TEST_GRID = 29
} stage;

typedef struct {
    u8 R;
    u8 G;
    u8 B;
    u8 A;
} Color8;

extern u8 play_sound(u16 sound_ID);     // 0x80013EAC
extern void func_80040570();            // 0x80040570

#endif
