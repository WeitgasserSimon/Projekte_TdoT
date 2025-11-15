#include <stdio.h> 

// globals
unsigned char IPv4Data[] = {0x12, 0x56, 0x7C, 0x0A};

unsigned char calcChecksum(unsigned char Data[], int len) {
	unsigned char summe;
	summe = 0;
	int i;
	for(i=0; i<len;i++){
		summe =summe + Data[i];
	}
	return summe;
}
int main() {
	
	unsigned char summe;
	summe = calcChecksum(IPv4Data,3);
	printf("Summe = %X",summe);
	
	return 0;
}
