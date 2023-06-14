#include "screen.h"

#include "hardware/gpio.h"
#include "pico/stdlib.h"


Screen::Screen() {
    ledRow.insert(ledRow.end(), {ledA, ledB, ledC, ledD, ledE, ledF}); // 0
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledB, ledC}); // 1
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledB, ledG, ledE, ledD}); // 2
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledB, ledG, ledC, ledD}); // 3
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledB, ledG, ledC, ledD}); // 4
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledF, ledG, ledC, ledD}); // 5
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledC, ledD, ledE, ledF, ledG}); // 6
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA, ledB, ledC}); // 7
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA,ledB, ledC, ledD, ledE, ledF, ledG}); // 8
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    ledRow.insert(ledRow.end(), {ledA,ledB, ledC, ledD, ledF, ledG}); // 9
    ledNumbers.push_back(ledRow);
    ledRow.clear();

    for (auto i : ledNumbers) {
        for (int j : i) {
            printf(" %d ",j);
        }
        printf("\n");
    }
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
}

void Screen::showNumber(int display, int numberToShow, int enableDot) {
    gpio_set_dir(display, true);
    int counter = 0;
    for (auto i: ledNumbers) {
        if (counter == numberToShow) {
            for (int j: i) {
                gpio_set_dir(j, true);
                sleep_us(50);
                gpio_set_dir(j, false);
            }
            break;
        }
        counter++;
    }

    if (enableDot) {
        gpio_set_dir(dotLed, true);
        sleep_us(50);
        gpio_set_dir(dotLed, false);
    }

    gpio_set_dir(display, false);
}

void Screen::showTemperature(float temperature) {
    char string[4];
    sprintf(string,"%3.1f", temperature);
    int numberOne = int(string[0] - '0');
    int numberTwo = int(string[1] - '0');
    int numberThree = int(string[3] - '0');

    // printf("%d %d , %d\n", numberOne, numberTwo, numberThree);
    
    this->showNumber(toggle1, numberOne, false);
    this->showNumber(toggle2, numberTwo, true);
    this->showNumber(toggle3, numberThree, false);

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