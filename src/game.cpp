#include "game.h"
#include "hardware.h"

enum GAME_STATUS {
    MENU,
    START_GAME,
    GUESS,
    WIN_GAME,
    LOSE_GAME
};

static void start_game(void);
static void guess(void);
static void win(void);
static void lose(void);
static void generate_sequence(void);
static void play_sequence(void);

static GAME_STATUS status = MENU;

static const uint8_t INITIAL_SEQUENCE_LENGTH = 2;
/* Maximum sequence length also represents a completed game. */
static const uint8_t MAX_SEQUENCE_LENGTH = 32;

static uint8_t sequence_length = INITIAL_SEQUENCE_LENGTH;
static uint8_t sequence[MAX_SEQUENCE_LENGTH] = {};

static uint8_t guess_index = 0;

/*
 * Main game state machine.
 * It is called continuously from main.cpp.
*/
void game() {
    switch(status) {
        case MENU:
            if (is_any_button_pressed()) {
                status = START_GAME;
                return;
            }
            break;
        case START_GAME:
            start_game();
            status = GUESS;
            break;
        case GUESS:
            guess();
            break;
        case WIN_GAME:
            win();
            break;
        case LOSE_GAME:
            lose();
            break;
        default:
            break;
    }
}

static void start_game(void) {
    blink_all_led(3);

    delay(500);

    generate_sequence();
    play_sequence();

    guess_index = 0;
    status = GUESS;
}

static void guess(void) {
    for (uint8_t i = 0; i < NUM_ELEMENTS; i++) {
        if (is_button_pressed(i)) {
            set_led(i, true);
            play_buzzer(BUTTON_TONES[i], 0);

            delay(100);

            while (is_button_pressed(i)) {
                delay(10);
            }

            set_led(i, false);
            stop_buzzer();

            delay(80);

            if (i == sequence[guess_index]) {
                guess_index++;

                if (guess_index == sequence_length) {
                    if (sequence_length < MAX_SEQUENCE_LENGTH) {
                        sequence_length++;
                    } else {
                        /* The player completed the game. Start the next game from level 1. */
                        sequence_length = INITIAL_SEQUENCE_LENGTH;
                    }

                    status = WIN_GAME;
                }
            } else {
                status = LOSE_GAME;
            }

            break;
        }
    }
}

static void win(void) {
    play_buzzer(523, 150);
    delay(150);
    play_buzzer(659, 150);
    delay(150);
    play_buzzer(784, 150);
    delay(150);
    play_buzzer(1046, 300);
    delay(300);

    blink_all_led(1);
    set_all_led(true);

    play_buzzer(1000, 100);
    delay(120);
    play_buzzer(1200, 150);
    delay(150);

    status = MENU;
}

static void lose(void) {
    play_buzzer(300, 200);
    delay(200);
    play_buzzer(200, 200);
    delay(200);
    play_buzzer(130, 400);
    delay(400);

    blink_all_led(3);
    sequence_length = INITIAL_SEQUENCE_LENGTH;
    set_all_led(true);

    play_buzzer(400, 150);
    delay(150);

    status = MENU;
}

static void generate_sequence(void) {
    for (uint8_t i = 0; i < sequence_length; i++) {
        sequence[i] = random(0, NUM_ELEMENTS);
    }
}

static void play_sequence(void) {
    for (uint8_t i = 0; i < sequence_length; i++) {
        set_led(sequence[i], true);
        play_buzzer(BUTTON_TONES[sequence[i]], 350);
        delay(400);
        set_led(sequence[i], false);
        delay(400);
    }
}