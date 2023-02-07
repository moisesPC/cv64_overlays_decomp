/*
 * File: overlay_95.c
 * Description: 
 *   This file is related to the Demon Dracula boss, since it's loaded before the battle begins,
 *   and the module associated to this overlay (ID 0xB7) also loads the file ID 0x2B,
 *   which contains the assets for the Demon Dracula enemy.
 *
 *   It's unknown what its actual purpose is. Either it used to contain some additional code
 *   related to Demon Dracula, or its only purpose is to be a placeholder so that the game
 *   can load the Demon Dracula's assets file.
 * Module ID = 0xB7
 * 
 * osMapTLB'd? = Yes
 * Entrypoint address = 0x0F000000
 * Associated files ptr = 0x80095C10
 * Associated files:
 *   0x95 (Overlay)
 *   0x2B (Dracula's assets)
 */

#include "module_B7.h"

/* Entrypoint function.
 */
void moduleB7_calc(module_B7* this) {}
