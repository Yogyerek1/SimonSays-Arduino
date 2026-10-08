#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define NUM_ELEMENTS 5

const uint8_t BUTTON_PINS[NUM_ELEMENTS]   = { 2, 3, 4, 5, 6 };
const uint8_t LED_PINS[NUM_ELEMENTS]      = { 8, 9, 10, 11, 12 };
const uint8_t BUZZER_PIN                  = 7;

const uint16_t BUTTON_TONES[NUM_ELEMENTS] = { 262, 330, 392, 494, 523 };

#endif