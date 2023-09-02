/*
 * File: overlay_BA.c
 * Description: 
 *   This actor can be found in the main area of Castle Wall, and its purpose
 *   is to play sound 0x2E9 when falling off the platform where you encounter Dracula.
 * 
 *   Sound 0x2E9 appears to be silent, so it's unknown how it would have sound like.
 *   For some reason, it's grouped under the "Menu" modules.
 * Associated modules: 0x213F
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x800963B8
 * Associated files:
 *   0xBA (Overlay)
 */

#include "menus/module13F.h"
#include "player/player.h"
#include "unknown_struct.h"
#include "sound.h"

void module13F_entrypoint(module13F* self) {
    ENTER(self, module13F_functions);
}

void module13F_isDraculaCutsceneWatched(module13F* self) {
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    model_info* player_model;

    if ((ptr_playerData != NULL) && (D_80383AB8.SaveStruct_gameplay.event_flags[10] & 0x100)) {
        player_model = ptr_playerData->visualData.model;
        
        if (300.0f < player_model->position.y) {
            ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
        }
    }
}

void module13F_isPlayerDroppingDown(module13F* self) {
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    model_info* model = ptr_playerData->visualData.model;

    if (model->position.y < 300.0f) {
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

void module13F_playSound(module13F* self) {
    u8 (*ptr_play_sound)(u16) = play_sound;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;

    ptr_play_sound(0x2E9);
    ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
}

void module13F_destroy(module13F* self) {
    self->header.destroy(self);
}
