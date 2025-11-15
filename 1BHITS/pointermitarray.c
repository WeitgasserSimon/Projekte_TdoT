#include <stdio.h>
#include <stdlib.h>
int len;int mylen; 
int main(){
	unsigned char myIPHeader[]={0x43,0x48,0xE3,0x5F};
	int len = 4;
	unsigned char checksum;
	checksum=calculateIPv4HeaderChecksum(myIPHeader,mylen);

}
	unsigned char data[]={15,18,254,128};
	unsigned char* pointerAufData;
	pointerAufData = &data[0];//Der Name des Arrays ist gleichzeitig der Pointer auf das erste Element
	//Besser:
	pointerAufData=data;
	unsigned char calculateIPv4HeaderChecksum(unsigned char *pData,int len);
	printf("%X",checksum);
	{
		
	int i;
		for(i = 0;i<len;i++){
		sum = ~pData[i] + sum;
		}
		sum=~sum;
		return sum;
	}

	
	return 0;

