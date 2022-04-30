# katstudios/split58

![view of the board with lighting](https://imgur.com/1EusNmA.jpeg)

a super low-profile split ortho ergo keyboard designed to have a minimal format and per key lighting

![view of the board from the top](https://imgur.com/LVEoUPA.jpeg)

* Keyboard Maintainer: [Kat](https://github.com/vampjaz)
* Hardware Supported: kat studios "two of them" prototype pcb rev 03
* Hardware Availability: not currently for sale, but gauging interest

### Considerations

- this board is very short on RAM with the rgb enabled, adding other rgb animations or disabling optimization options may cause it to crash at runtime
- in theory the lack of cc resistors on the split ports should protect it from causing any trouble if you accidentally plug those into a computer, though in practice it's still a good idea to never plug those into anything but the other half
- rev 03 of the pcb has traces that got cut during the manufacturing process, the led data line needs to be bridged on the right side


Make example for this keyboard (after setting up your build environment):

    make katstudios/split58:default

Flashing example for this keyboard:

    make katstudios/split58:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset**: Briefly short the pads on the back of the PCB 
* **Keycode in layout**: fn + R + esc on left side or fn + U + del on right side
