#pragma once
#include <wiringPiSPI.h>
#include <wiringPi.h>

class mcp3008 {

public:
	mcp3008();

	int readValue(unsigned int adcnum);
private:
	//# SPI connection, these are only for documentation...
	static const unsigned char SCE  = 11;// # gpio pin  = wiringpi no. 11 (CE1 BCM 7) 
	static const unsigned char SCLK = 14;// # gpio pin 23 = wiringpi no. 14 (SCLK BCM 11)
	static const unsigned char DIN  = 12;// # gpio pin 19 = wiringpi no. 12 (MOSI BCM 10)


	static const int spiChannel = 1;
	static const int spiSpeed = 1000000;

};
