#include "screen.h"

#include "hardware/gpio.h"
#include "pico/stdlib.h"


Screen::Screen() {

}

Screen::~Screen() {

}

void Screen::init() {
    gpio_init(toggle1);
    gpio_init(toggle2);
    gpio_init(toggle3);
    gpio_init(ledA);
    gpio_init(ledB);
    gpio_init(ledC);
    gpio_init(ledD);
    gpio_init(ledE);
    gpio_init(ledF);
    gpio_init(ledG);
    gpio_init(dotLed);

    gpio_set_dir(toggle1, false);
    gpio_set_dir(toggle2, false);
    gpio_set_dir(toggle3, false);
    gpio_set_dir(ledA, false);
    gpio_set_dir(ledB, false);
    gpio_set_dir(ledC, false);
    gpio_set_dir(ledD, false);
    gpio_set_dir(ledE, false);
    gpio_set_dir(ledF, false);
    gpio_set_dir(ledG, false);
    gpio_set_dir(dotLed, false);

    gpio_set_pulls(toggle1, false, false);
    gpio_set_pulls(toggle2, false, false);
    gpio_set_pulls(toggle3, false, false);
    gpio_set_pulls(ledA, false, false);
    gpio_set_pulls(ledB, false, false);
    gpio_set_pulls(ledC, false, false);
    gpio_set_pulls(ledD, false, false);
    gpio_set_pulls(ledE, false, false);
    gpio_set_pulls(ledF, false, false);
    gpio_set_pulls(ledG, false, false);
    gpio_set_pulls(dotLed, false, false);

    gpio_set_dir(toggle1, true);
    gpio_set_dir(ledA, true);
}

void Screen::showOn() {
    gpio_set_dir(toggle1, true);

    gpio_set_dir(ledA, true);
    sleep_ms(1);
    gpio_set_dir(ledA, false);

    gpio_set_dir(ledB, true);
    sleep_ms(1);
    gpio_set_dir(ledB, false);

    gpio_set_dir(ledC, true);
    sleep_ms(1);
    gpio_set_dir(ledC, false);

    gpio_set_dir(ledD, true);
    sleep_ms(1);
    gpio_set_dir(ledD, false);

    gpio_set_dir(ledE, true);
    sleep_ms(1);
    gpio_set_dir(ledE, false);

    gpio_set_dir(ledF, true);
    sleep_ms(1);
    gpio_set_dir(ledF, false);

    gpio_set_dir(toggle1, false);
    sleep_ms(1);
    gpio_set_dir(toggle2, true);

    gpio_set_dir(ledA, true);
    sleep_ms(1);
    gpio_set_dir(ledA, false);

    gpio_set_dir(ledB, true);
    sleep_ms(1);
    gpio_set_dir(ledB, false);

    gpio_set_dir(ledC, true);
    sleep_ms(1);
    gpio_set_dir(ledC, false);

    gpio_set_dir(ledE, true);
    sleep_ms(1);
    gpio_set_dir(ledE, false);

    gpio_set_dir(ledF, true);
    sleep_ms(1);
    gpio_set_dir(ledF, false);

    gpio_set_dir(toggle2, false);
}

void Screen::showOff() {
    gpio_set_dir(toggle1, true);

    gpio_set_dir(ledA, true);
    sleep_ms(1);
    gpio_set_dir(ledA, false);

    gpio_set_dir(ledB, true);
    sleep_ms(1);
    gpio_set_dir(ledB, false);

    gpio_set_dir(ledC, true);
    sleep_ms(1);
    gpio_set_dir(ledC, false);

    gpio_set_dir(ledD, true);
    sleep_ms(1);
    gpio_set_dir(ledD, false);

    gpio_set_dir(ledE, true);
    sleep_ms(1);
    gpio_set_dir(ledE, false);

    gpio_set_dir(ledF, true);
    sleep_ms(1);
    gpio_set_dir(ledF, false);

    gpio_set_dir(toggle1, false);
    sleep_ms(1);
    gpio_set_dir(toggle2, true);

    gpio_set_dir(ledA, true);
    sleep_ms(1);
    gpio_set_dir(ledA, false);

    gpio_set_dir(ledG, true);
    sleep_ms(1);
    gpio_set_dir(ledG, false);

    gpio_set_dir(ledE, true);
    sleep_ms(1);
    gpio_set_dir(ledE, false);

    gpio_set_dir(ledF, true);
    sleep_ms(1);
    gpio_set_dir(ledF, false);

    gpio_set_dir(toggle2, false);
    sleep_ms(1);
    gpio_set_dir(toggle3, true);

    gpio_set_dir(ledA, true);
    sleep_ms(1);
    gpio_set_dir(ledA, false);

    gpio_set_dir(ledG, true);
    sleep_ms(1);
    gpio_set_dir(ledG, false);

    gpio_set_dir(ledE, true);
    sleep_ms(1);
    gpio_set_dir(ledE, false);

    gpio_set_dir(ledF, true);
    sleep_ms(1);
    gpio_set_dir(ledF, false);

    gpio_set_dir(toggle3, false);

}