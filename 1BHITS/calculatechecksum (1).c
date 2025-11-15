// ZIEL FÜR HEUTE

#include <stdio.h>
#include <stdlib.h>

calculateIPv4_HeaderChecksum(unsigned char *pData, int len) {
	int i;
	int sum = 0;
	for(i = 0; i < len; i++) {
		sum = ~pData[i] + sum;
	}
	sum = ~sum;
	return sum;
}

int main() {
	unsigned char myIPHeader[] = {0x43,0x48,0xE3,0x5F};
	int mylen = 4;
	unsigned char checksum;
	checksum = calculateIPv4_HeaderChecksum(myIPHeader, mylen);
	printf("%X", checksum);
	
	return EXIT_SUCCESS;
}
