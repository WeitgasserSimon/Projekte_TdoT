#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char IP_Address[100];
    int i;
    int dotIndices[3] = {-1, -1, -1};

    printf("Bitte geben Sie die IP-Adresse ein:\n");
    scanf("%s", IP_Address);
    printf("%s\n", IP_Address);

    // Suche nach den Indizes der Punkte
    int dotCount = 0;
    int addressLength = strlen(IP_Address);
    for (i = 0; i < addressLength; i++) {
        if (IP_Address[i] == '.') {
            dotIndices[dotCount] = i;
            dotCount++;
            if (dotCount >= 3) {
                break;
            }
        }
    }

    // Extrahiere die vier Zahlen aus der IP-Adresse als Integer
    int num1 = atoi(strtok(IP_Address, "."));
    int num2 = atoi(strtok(NULL, "."));
    int num3 = atoi(strtok(NULL, "."));
    int num4 = atoi(strtok(NULL, "."));

    printf("Nummern der IP-Adresse: %d %d %d %d\n", num1, num2, num3, num4);
    
    int IPMask[]={255,255,252,0};
    
    int NetAddress[4];
    int BCA[4];
    NetAddress[0]=num1&IPMask[0];
	NetAddress[1]=num2&IPMask[1];
	NetAddress[2]=num3&IPMask[2];
	NetAddress[3]=num4&IPMask[3];
	
	BCA[0] = num1 | ~IPMask[0];
	BCA[1] = num2 | ~IPMask[1];
	BCA[2] = num3 | ~IPMask[2];
	BCA[3] = num4 | ~IPMask[3];
	for(i=0;i<4;i++){
		
		printf("%d",BCA[i]);	
	}
	printf("\n");
		for(i=0;i<3;i++){
		
		printf("%d.",NetAddress[i]);	
	}
	printf("%d",NetAddress[i]);
    return 0;
}

