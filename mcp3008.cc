#include "mcp3008.h"
#include <unistd.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */

mcp3008::mcp3008() {
	int fileDescriptor = wiringPiSPISetup(spiChannel, spiSpeed);
        if (fileDescriptor <= -1) {
             printf ("Error wiringPiSPISetup");
	    exit (EXIT_FAILURE);
        }
	wiringPiSetup();
}

int mcp3008::readValue() {
	unsigned char data[100];
	unsigned char *p = (unsigned char *)&data;
	if (wiringPiSPIDataRW(spiChannel, p, 100) == -1) {
		printf("spi failed lcd_data");
	}

	for (int i = 0; i< 100; i++) {
		printf("data read %d", data[i]);
	}
	
	return data[0];
}

