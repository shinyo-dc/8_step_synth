Based on [the_synth](https://github.com/dzlonline/the_synth) library:

## Functionality:
- Envelope setup (should we use switches or a pot for this?)
- Waveform setup [Value from 0-5] → ~~maybe using button~~ (pot now)
- Delay between notes [Value from 10-350ms]
- Pitch change (Pot) [Value from 0-127]
- Length change (Pot) [Value from 0-127]
- Mod change (Pot) [Value from 0-1023]

P.S. maybe setup to change the current voice later.

## To build the project:
- Use platformIO for convinient.
- The `.vscode` folder will change depends on the `$PATH` so you should create an empty project that use `nanoatmega328` as your board or equivalent Arduino Atmega328 board. 
- Add the files in the `include/` to your project's `include/`
- Currently the based on project [bitsynth](https://github.com/akosturi/bitsynth) are using the library to filter the analog signal's value, me don't do that here but just include it, maybe me will use it sometime.
Add this to your `platformio.ini` file:
```
lib_deps =
  dndubins/QuickStats @ ^1.2
```
- You can now manage to use the `main.cpp` file in the `src/` folder without any warning.
- Build your project with `platiformio`

## Hardware connections
- The output is at pin 11, setup your hardware using [dzlonline](https://github.com/dzlonline)'s diagram:
```
//                    +10µF 
//PIN 11 ---[ 1k ]--+---||--->> Audio out
//                  |
//                 === 10nF
//                  |
//                 GND
```
- Analog pins A0, A1, A2, A3, A4 is used, the details about what the signal is used for are includes in the `src/main.cpp` file. The pins are connected respectively with the potentiometers. 

Note (hopefully this is helpful):
 - Don't use the VCC and GND source used on the audio out filter circuit for the potentiometers.

## Demo:
Will do later.


## To-do

- [x]  Setup the pot according to the values ~~(currently 3 pots with 2 sets of values)~~ its 5 pots with 4 sets of values
- [x]  Apply the pot to the setup
- [x]  Update github's repository
- [ ]  Create state and stuff, maybe buy more materials
