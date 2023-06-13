#include "relais.h"
#include "hardware/gpio.h"

Relais::Relais() {

}

Relais::~Relais() {

}

void Relais::init() {
    gpio_init(relaisPin);
    gpio_set_dir(relaisPin,true);
}

void Relais::setState(int state) {
    gpio_put(relaisPin, state);
}