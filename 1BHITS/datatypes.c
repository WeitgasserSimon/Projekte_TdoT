/*Datatypes
int Ganzzahlen

unsigned char   	8bit ganzzahlig
					0...0xFF
					0...255d

(signed)char        8bit ganzzahlig
					-128d...+127d

unsigned short 		16bit ganzzahlig
					0...0xFFFF
					0...65535d

short				-32768d...+32767d
unsigned long        32bit
					0...0xFFFFFFFF*/

	#include <stdio.h>
	
	
int main()
{
	unsigned long y;
	
	y = 0xFFFFFFFF;
	printf("Die Zahl lautet: %lX",y);
	

	return 0;
}
