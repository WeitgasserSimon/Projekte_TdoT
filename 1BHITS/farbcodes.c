	/***********************************************************************************************************************************************
		Escape Codes, Farbcodes
		/n...new line 
		/r...carriage return
		/r /n... erste Position in neuer Zeile
		\x1b[35m... magenta foreground
		\x1b[46m...cyan background
		\x1b[0m...reset...setzt auf default zurück
	
	***********************************************************************************************************************************************/
	#include <stdio.h>

	int main()
	{
	system("CHCP 1250");
	system("CLS");
	
	printf("\x1b[32m Hello Robert\r\n");
	printf("\x1b[46m Mir geht es gut\r\n");
	printf("\x1b[0m Ich bin lesbar.\r\n");
	
	
	return 0;
	}
