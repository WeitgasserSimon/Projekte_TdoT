/*****************************************************************************************************************************************************************************************


													add all 8bit values
													and truncate the sum to 8bits



*****************************************************************************************************************************************************************************************/


#include <stdio.h>

int main()
{
	unsigned char checksum;
	
	
	unsigned char dataValue1 = 0x96;
	unsigned char dataValue2 = 0x67;
	unsigned char dataValue3 = 0xCA;
	
	
	checksum = dataValue1 + dataValue2 + dataValue3;
	
	
	printf("die Zahl lautet: %lX", checksum);
	
	return 0;
}
