		
	#include <stdio.h>
	
	int main()
	{
	unsigned char Datavalue1 = 'H';
	unsigned char Datavalue2 = 'a';
	unsigned char Datavalue3 = 'l';
	unsigned char Datavalue4 = 'l';
	unsigned char Datavalue5 = 'o';
	unsigned char Datavalue6 = ' ';
	unsigned char Datavalue7 = 'D';
	unsigned char Datavalue8 = 'u';
	unsigned char Datavalue9 = '!';
	unsigned char CheckSum;
	
	CheckSum =  Datavalue1+ Datavalue2+ Datavalue3+ Datavalue4+ Datavalue5+ Datavalue6+ Datavalue7+ Datavalue8+ Datavalue9;
	
	printf("CheckSum ist %X",CheckSum);
		
	return 0;	
		
		
		
		
		
	}
	
	 
