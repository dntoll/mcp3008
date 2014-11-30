all: mcp3008

mcp3008: src/main.cc src/mcp3008.h src/mcp3008.cc
	g++ src/main.cc src/mcp3008.cc -o mcp3008  -lwiringPi

clean: 
	rm *.o mcp3008
