/*
 * File: endingMessageEasy.c
 * Description: Displays the ending message when you beat Easy Mode
 * Associated modules: 0x2140
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x800963C0
 * Associated files:
 *   0xBB (Overlay)
 */

#include "unknown_struct.h"
#include "gfx/model_info.h"
#include "gfx/camera.h"
#include "sound.h"
#include "atari_work.h"
#include "menus/endingMessageEasy.h"

/* Entrypoint function.
 * This function is used to access a specific function in the "endingMessageEasy_functions" array,
 * by referencing its ID within said array.
 */
void endingMessageEasy_entrypoint(endingMessageEasy* self) {
    ENTER(self, endingMessageEasy_functions);
}

// Initializes the textbox
// https://decomp.me/scratch/Gr6E6
void endingMessageEasy_init(endingMessageEasy* self) {
    mfds_state* new_textbox;
    s32 text_ptr;
    
    u8 (*ptr_play_sound)(u16) = play_sound;
    mfds_state* (*ptr_textbox_create)(void*, void*, u32) = textbox_create;
    void (*ptr_textbox_setDimensions)(mfds_state*, s8, s16, u8, u8) = textbox_setDimensions;
    void (*ptr_textbox_setPos)(mfds_state*, u16, u16, s32) = textbox_setPos;
    void (*ptr_textbox_setMessagePtr)(mfds_state*, u16*, s32, s16) = textbox_setMessagePtr;
    void (*ptr_textbox_8012cda4)(mfds_state*, u32, f32) = textbox_8012cda4;
    void* (*ptr_text_getMessageFromPool) (u16*, s32) = text_getMessageFromPool;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    
    // Sound ID "10" is silent in the final game
    ptr_play_sound(10);
    // Create textbox and initialize variables
    new_textbox = ptr_textbox_create(self, common_cameras_array.HUD, (OPEN_TEXTBOX | FAST_TEXT_TRANSITION));
    self->ending_textbox = new_textbox;
    ptr_textbox_setPos(new_textbox, 30, 110, 1);
    ptr_textbox_setDimensions(new_textbox, 6, 250, 0, 0);
    new_textbox->color_palette = 0;
    new_textbox->display_time = 0;
    /* Get the offset within the overlay where the text is located.
     * Don't grab the most significant byte (& 0xFFFFFF). self removes the "0x0F" part from the address.
     */
    text_ptr = (s32)ptr_text_getMessageFromPool(ending_text, 0) & 0xFFFFFF;
    ptr_textbox_setMessagePtr(new_textbox, (s32) endingMessage_fileBuffer + text_ptr, 0, 0);
    ptr_textbox_8012cda4(new_textbox, 0x40035, 30);
    ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
}

// Unused
void func_0F00018C() {}

/* After the textbox structure is initialized, the game loops in self function
 * until the player presses the A button to close the textbox
 */
void endingMessageEasy_loop(endingMessageEasy* self) {
    s16 i;
    u32* textbox_flags = &self->ending_textbox->flags;
    
    void (*ptr_atari_work_table_init)() = atari_work_table_init;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;

    self->active_time++;
    /* After 120 frames have passed (the time it takes for the red cursor to appear),
     * if the player presses the A button, close the textbox, reset most variables
     * in the gameplay's save struct, and destroy self module.
     */
    if ((self->active_time > 120) && (D_80383AB8.controllers[0].buttons_pressed & BTN_A)) {
        *textbox_flags |= CLOSE_TEXTBOX;
        D_80383AB8.SaveStruct_gameplay.money = 0;
        D_80383AB8.SaveStruct_gameplay.time_saved_counter = 0;
        D_80383AB8.SaveStruct_gameplay.death_counter = 0;
        D_80383AB8.SaveStruct_gameplay.field55_0xbc = 0;
        D_80383AB8.SaveStruct_gameplay.field59_0xc0 = 0;
        D_80383AB8.SaveStruct_gameplay.field63_0xc4 = 0;
        D_80383AB8.SaveStruct_gameplay.field67_0xc8 = 0;
        D_80383AB8.SaveStruct_gameplay.field69_0xca = 0;
        D_80383AB8.SaveStruct_gameplay.field71_0xcc = 0;
        D_80383AB8.SaveStruct_gameplay.field75_0xd0 = 0;
        D_80383AB8.SaveStruct_gameplay.field77_0xd2 = 0;
        D_80383AB8.SaveStruct_gameplay.field79_0xd4 = 0;
        D_80383AB8.SaveStruct_gameplay.field83_0xd8 = 0;
        D_80383AB8.SaveStruct_gameplay.money_spent_on_Renon = 0;
        D_80383AB8.SaveStruct_gameplay.player_status = 0;
        D_80383AB8.SaveStruct_gameplay.life = 100;
        D_80383AB8.SaveStruct_gameplay.field13_0x5c = 100;
        D_80383AB8.SaveStruct_gameplay.subweapon = 0;
        D_80383AB8.current_PowerUp_level = 0;
        D_80383AB8.SaveStruct_gameplay.health_depletion_rate_while_poisoned = 0;
        D_80383AB8.SaveStruct_gameplay.current_hour_VAMP = 0;
        D_80383AB8.SaveStruct_gameplay.week = 0;
        D_80383AB8.SaveStruct_gameplay.day = 0;
        D_80383AB8.SaveStruct_gameplay.hour = 0;
        D_80383AB8.SaveStruct_gameplay.minute = 0;
        D_80383AB8.SaveStruct_gameplay.seconds = 0;
        D_80383AB8.SaveStruct_gameplay.milliseconds = 0;
        // Clear event flags (doesn't appear to match with a 'for' loop)
        i = 0;
        do {
            D_80363AB8[1].SaveStruct_gameplay.event_flags[i] = 0,
            i++;
        } while (i < 16);
        // Remove inventory items
        for (i = 0; i < 64; i++) {
            D_80363AB8[1].SaveStruct_gameplay.inventory_items_amount[i] = 0;
        }
        ptr_atari_work_table_init();
        self->active_time = 0;
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// Destroy the module
void endingMessageEasy_destroy(endingMessageEasy* self) {
    u32 textbox_flags;
    
    self->active_time++;
    // When the textbox closes (after 30 frames), destroy the module
    if (self->active_time > 30) {
        textbox_flags = self->ending_textbox->flags;
        if (!(textbox_flags & 0x20000000) && !(textbox_flags & 0x10000000) && !(textbox_flags & 0x02000000)) {
            if (!(textbox_flags & TEXTBOX_IS_ACTIVE)) {
                self->ending_textbox->flags = textbox_flags | CLOSE_TEXTBOX;
            }
            self->header.destroy(self);
        }
    }
}
