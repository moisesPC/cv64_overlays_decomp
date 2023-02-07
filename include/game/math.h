#ifndef MATH_H
#define MATH_H

#include "ultra64/ultratypes.h"

typedef struct {
    f32 x;
    f32 y;
} vec2f;

typedef struct {
    s16 x;
    s16 y;
} vec2s;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} vec3f;

typedef struct {
    s16 pitch;
    s16 yaw;
    s16 roll;
} angle;

#endif
