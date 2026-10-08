#ifndef HARDWARE_H
#define HARDWARE_H

#include "config.h"

void hardware_init(void);

void set_led(uint8_t index, bool state);
void set_all_led(bool state);
void blink_all_led(uint8_t amount);

bool is_button_pressed(uint8_t index);
bool is_any_button_pressed(void);

void play_buzzer(uint16_t frequency_hz, uint16_t duration_ms);
void stop_buzzer(void);

#endif