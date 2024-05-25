# pico_binary_counter
8-bit binary counter for the Raspberry Pi Pico using 8 LEDs and a button
![Raspberry Pi Pico on breadboard, with connected LEDs and a button showing the project working](https://github.com/wbr8/pico_binary_counter/blob/main/example_setup.JPEG?raw=true)

# Configure
- Connect 8 LEDs to GPIO pins 15 - 8 with 50 - 330 Ohm resistors
- Pin 8 LED will be the right-most bit; pin 15 LED will be the left-most
- GPIO pin 7 is used for the button, connect it to the 3.3V pin

# Build
Build using the Pico SDK, where instructions can be found at the [official Getting Started guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf 'Getting Started with Pico')
