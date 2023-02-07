# Castlevania 64 - Overlays Decompilation

This repository contains examples of decompiled source code of Castlevania (Nintendo 64) overlays.

These will compile into matching overlay binaries that can be found in the ROM (when decompressed).

The code in this repository corresponds to the USA v1.0 version of the game.

## Building (Ubuntu)
### Prerequisites
* [IDO 7.1](https://github.com/decompals/ido-static-recomp/releases) (place `cc` and all the other files in `tools/ido71`)
* [nOVL](https://github.com/Bsquo/nOVL/releases) (place `novl` in `tools/nOVL`)
* `mips64-ld`

### Build
* Run `make` to build all overlays in `src`. The final overlay binaries will be stored in `build/OVERLAY_NAME/OVERLAY_NAME.ovl`

* When each overlay is created, the sha1 of each .ovl file will be verified to see if it matches with the (decompressed) overlays from an original USA v1.0 ROM. If it does, `OK` will be printed.

## Credits:
* ZZT32, ariahiro64, z64me, sauraen: For [nOVL](https://github.com/z64tools/nOVL), which this repository uses to convert ELF to overlay binaries.

* CrookedPoe, z64me: For [z64ovl](https://github.com/CrookedPoe/z64ovl). Although intended for the Zelda 64 games, they provide examples for rebuilding overlays.

* Fluvian: For [LZKN64](https://github.com/Fluvian/lzkn64), which can decompress and compress back files in the Nagano format, used in several Konami N64 games.