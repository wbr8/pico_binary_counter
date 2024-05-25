#include "pico/stdlib.h"

char extract_bit_for_position(uint8_t num, int pos) {
    char bit = (num >> pos) & 0b00000001;   // performs right bit-shift by set number and AND operates on it with 1, as to extract the current bit in the position of the number
    return bit;
}

int main()
{
    // constant values for all LEDs and button
    const uint8_t LED_PIN[8] = {8, 9, 10, 11, 12, 13, 14, 15};
    const uint8_t BUTTON = 7;

    // initialise GPIO for all declared LED pins
    for (int i = 0; i < 8; i++) {
        gpio_init(LED_PIN[i]);
        gpio_set_dir(LED_PIN[i], GPIO_OUT);
    }

    // initialise GPIO for button and pull down voltage
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_down(BUTTON);
    
    // declare variables for the counter and each bit
    uint8_t counter = 0;
    unsigned char bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    while (true) {
        // get input from button 
        if (gpio_get(BUTTON)) {
            counter++;    // increment the counter value
            sleep_ms(150);
        }

        for (int i = 0; i < 8; i++) {
            bits[i] = extract_bit_for_position(counter, i);    // sets current bit value to extracted bit from counter variable for correct position
        }

        for (int i = 0; i < 8; i++) {
            gpio_put(LED_PIN[i], bits[i]);    // sets LED state to the bit array
        }
    }
}
