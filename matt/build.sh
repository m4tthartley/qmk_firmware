##
##	Created by Matt Hartley on 06/11/2025.
##	Copyright 2025 GiantJelly. All rights reserved.
##

# QMK="$HOME/code/qmk"
keymapDir="../keyboards/keychron/k8_pro/iso/rgb/keymaps/custom"

mkdir -p $keymapDir

cp ./keymap.c $keymapDir/
cp ./rules.mk $keymapDir/

qmk compile -kb keychron/k8_pro/iso/rgb -km custom
