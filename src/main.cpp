#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../modules/pico-onewire/api/one_wire.h"
#include "screen.h"
#include "relais.h"

int main() {
	stdio_init_all();
	sleep_ms(5000);

	One_wire one_wire(1);
	one_wire.init();
	rom_address_t address{};

	Screen screen;
	screen.init();

	Relais relais;
	relais.init();

	int timer = 750;
	int last_relay_time = 60000;
	int status = 0;
	float temperature = -5.2;
	while (1) {
		timer++;
		last_relay_time++;

		screen.showTemperature(temperature);

		// if (status) {
		// 	screen.showOn();
		// } else {
		// 	screen.showOff();
		// }
		
		// if (timer >= 750) {
			// timer = 0;
        	// one_wire.convert_temperature(address, true, false);
			// float temperature = one_wire.temperature(address);
			// printf("Temperature: %3.1foC\n", one_wire.temperature(address));
		// }

		// if (last_relay_time >= 750) {
		// 	last_relay_time = 0;
		// 	// one_wire.convert_temperature(address, true, false);
		// 	float temperature = one_wire.temperature(address);
		// 	printf("Temperature: %3.1f C\n", one_wire.temperature(address));
		// 	if (temperature <= 4) {
		// 		relais.setState(false);
		// 		status = 0;
		// 	} else if (temperature >= 6) {
		// 		relais.setState(true);
		// 		status = 1;
		// 	}
		// }

        sleep_ms(1);
	}
	return 0;
}
