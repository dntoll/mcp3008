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


int mcp3008::readValue(unsigned int adcnum)
{
 	uint8_t buff[3];
	int adc;
	if ((adcnum > 7) || (adcnum < 0))
		return -1;
	buff[0] = 1;
	buff[1] = (8+adcnum)<<4;
	buff[2] = 0;
	wiringPiSPIDataRW(spiChannel, buff, 3);
	adc = ((buff[1]&3) << 8) + buff[2];
 	return adc;
}
/*
int mcp3008::readValue() {
	unsigned char data[16];
	unsigned char *p = (unsigned char *)&data;
	if (wiringPiSPIDataRW(spiChannel, p, 16) == -1) {
		printf("spi failed lcd_data");
	}

	for (int i = 0; i< 16; i++) {
		printf("%d,", data[i]);
	}
	
	return data[0];
}
*/
