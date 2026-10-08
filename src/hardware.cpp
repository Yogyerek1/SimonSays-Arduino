#include "hardware.h"

void hardware_init(void) {
    for (uint8_t i = 0; i < NUM_ELEMENTS; i++) {
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);
        pinMode(LED_PINS[i], OUTPUT);

        digitalWrite(LED_PINS[i], HIGH);
    }

    pinMode(BUZZER_PIN, OUTPUT);
}

void set_led(uint8_t index, bool state) {
    if (index < NUM_ELEMENTS) {
        digitalWrite(LED_PINS[index], state ? HIGH : LOW);
    }
}

void set_all_led(bool state) {
    for (uint8_t i = 0; i < NUM_ELEMENTS; i++) {
        digitalWrite(LED_PINS[i], state ? HIGH : LOW);
    }
}

void blink_all_led(uint8_t amount) {
    for (uint8_t times = 0; times < amount; times++) {
        set_all_led(true);

        play_buzzer(440, 80);
        delay(300);

        set_all_led(false);
        delay(300);
    }
}

/* Buttons use INPUT_PULLUP, so LOW means pressed. */
bool is_button_pressed(uint8_t index) {
    if (index < NUM_ELEMENTS) {
        return digitalRead(BUTTON_PINS[index]) == LOW;
    }

    return false;
}

bool is_any_button_pressed(void) {
    for (uint8_t i = 0; i < NUM_ELEMENTS; i++) {
        if (digitalRead(BUTTON_PINS[i]) == LOW) {
            return true;
        }
    }

    return false;
}


void play_buzzer(uint16_t frequency_hz, uint16_t duration_ms) {
    tone(BUZZER_PIN, frequency_hz, duration_ms);
}

void stop_buzzer(void) {
    noTone(BUZZER_PIN);
}