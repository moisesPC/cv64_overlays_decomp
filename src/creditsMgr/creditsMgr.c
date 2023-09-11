/*
 * File: creditsMgr.c
 * Description: Creates the credits cutscene and resets the game once it's over
 * Associated modules: 0x201B
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x80096328
 * Associated files:
 *   0xAE (Overlay)
 */

#include "engine/game_states/credits/creditsMgr.h"
#include "atari_work.h"
#include "fade.h"
#include "engine/DMAMgr.h"
#include "gamestate.h"
#include "module_ID.h"
#include "unknown_struct.h"

void creditsMgr_entrypoint(creditsMgr* self) {
    ENTER(self, creditsMgr_functions);
}

// https://decomp.me/scratch/JvchH
void creditsMgr_init(creditsMgr* self) {
    u8 i;

    void (*ptr_atari_work_table_init)() = atari_work_table_init;
    u32 (*ptr_fade_isFading)() = fade_isFading;
    void (*ptr_fade_setSettings)(u16, u16, u8, u8, u8) = fade_setSettings;
    void* (*ptr_moduleList_findFirstModuleByID)(u16) = moduleList_findFirstModuleByID;
    void* (*ptr_module_createAndSetChild)(void*, s32) = module_createAndSetChild;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;

    if ((ptr_fade_isFading() == FALSE) && (D_80383AB8.file_load_array_ID == 0) && (ptr_DMAMgr->DMAChunkMgr != NULL)) {
        ptr_fade_setSettings(FADE_IN, 30, 0, 0, 0);
        D_80383AB8.cutscene_flags = 0;
        // Both variables have to be assigned the value like this so that
        // it can match (which prevents a t1 vs t0 regswap)
        D_80383AB8.cutscene_ID = D_80383AB8.entrance_cutscene_ID = 0x00;
        ptr_atari_work_table_init();
        for (i = 0; i < 16; i++) {
            self->field_0x34[i] = 0;
        }
        if (ptr_moduleList_findFirstModuleByID(CUTSCENE_CUTSCENE_MGR) == NULL) {
            ptr_module_createAndSetChild(self, CUTSCENE_CUTSCENE_MGR);
        }
        D_80383AB8.field25453_0x644c = 0;
        D_80383AB8.cutscene_ID = 0x63;
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// https://decomp.me/scratch/AgrnA
void creditsMgr_loop(creditsMgr* self) {
    void (*ptr_fade_setSettings)(s16, u16, u8, u8, u8) = fade_setSettings;
    void* (*ptr_moduleList_findFirstModuleByID)(u16) = moduleList_findFirstModuleByID;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    
    if (D_80383AB8.cutscene_ID == 0 && ptr_moduleList_findFirstModuleByID(CUTSCENE_CUTSCENE_CREDITS) == NULL) {
        self->field_0x34[3] = 2;
        if (1) {}                   // Needed for matching

        if (self->field_0x34[3] == 2) {
            ptr_fade_setSettings(FADE_OUT, 30, 0, 0, 0);
            ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
        }
    }
}

void creditsMgr_exit(creditsMgr* self) {
    u32 (*ptr_fade_isFading)() = fade_isFading;
    void (*ptr_changeGameState)(u32) = changeGameState;
    
    if (ptr_fade_isFading() == FALSE) {
        ptr_changeGameState(KONAMI_LOGO);
    }
}
