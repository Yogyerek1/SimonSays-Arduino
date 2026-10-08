# Simon Says

A simple Simon Says memory game built with an Arduino Uno.

This is my first embedded systems project. The goal of the project was to learn the basics of microcontroller programming, digital inputs and outputs, LEDs, buttons, sound generation, and project organization with PlatformIO.

## Features

- Five buttons with five corresponding LEDs
- Increasing sequence difficulty
- Different tones for each button
- Win and lose sound effects
- Maximum sequence length of 32
- Automatic game reset after losing or completing the game

## Hardware

- Arduino Uno
- 5 push buttons
- 5 LEDs
- 5 current-limiting resistors
- 1 buzzer
- Breadboard and jumper wires

## Pin Configuration

| Component | Arduino pin |
|---|---:|
| Button 1 | D2 |
| Button 2 | D3 |
| Button 3 | D4 |
| Button 4 | D5 |
| Button 5 | D6 |
| Buzzer | D7 |
| LED 1 | D8 |
| LED 2 | D9 |
| LED 3 | D10 |
| LED 4 | D11 |
| LED 5 | D12 |

The buttons use the Arduino's internal pull-up resistors. A button is considered pressed when the input reads `LOW`.

## How to Play

1. Press any button to start the game.
2. Watch and listen to the sequence played by the Arduino.
3. Repeat the sequence using the buttons.
4. Each successful round adds one more step to the sequence.
5. The sequence resets after a mistake or after completing the maximum difficulty.

## Building and Uploading

This project uses [PlatformIO](https://platformio.org/).

1. Open the project in Visual Studio Code with the PlatformIO extension installed.
2. Connect an Arduino Uno.
3. Build the project.
4. Upload the firmware to the board.

The project is configured for the Arduino Uno in `platformio.ini`.

## Project Structure

```text
include/
    config.h
    game.h
    hardware.h

src/
    game.cpp
    hardware.cpp
    main.cpp

platformio.ini
