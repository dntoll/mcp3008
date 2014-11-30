#include <iostream>
#include <stdlib.h>
#include "mcp3008.h"

using namespace std;

int main()
{
	mcp3008 inst;
	
	
	int value = inst.readValue(0);
	
	cout << "Read some value \n[" << value << "]";	
	
	return 0;
}
