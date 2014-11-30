#include "mcp3008.h"
#include <unistd.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */

mcp3008::mcp3008() {
	fileDescriptor = wiringPiSPISetup(spiChannel, spiSpeed);
        if (fileDescriptor <= -1) {
             printf ("Error wiringPiSPISetup");
	    exit (EXIT_FAILURE);
        }
	wiringPiSetup();
}

int mcp3008::readValue() {
	unsigned char data[100];

	if (wiringPiSPIDataRW(spiChannel, &data, 100) == -1) {
		printf("spi failed lcd_data");
	}
	return data[0];
}

