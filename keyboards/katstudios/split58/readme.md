# katstudios/split58

![view of the board with lighting](https://imgur.com/1EusNmA)

a super low-profile split ortho ergo keyboard designed to have a minimal format and per key lighting

![view of the board from the top](https://imgur.com/LVEoUPA)

* Keyboard Maintainer: [Kat](https://github.com/vampjaz)
* Hardware Supported: kat studios "two of them" prototype pcb rev 03
* Hardware Availability: not currently for sale, but gauging interest

Make example for this keyboard (after setting up your build environment):

    make katstudios/split58:default

Flashing example for this keyboard:

    make katstudios/split58:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: fn + r + esc on left side or fn + u + del on right side
