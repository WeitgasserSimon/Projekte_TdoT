#include<stdio.h>
//suche text nach a
char dataText[]={"JKaHALLO"};
char newText[10];
int main(){
	
	int i,index,newCount;
	for(i=0;i<8;i++){
		if(dataText[i]=='a'){
			index=i;
			
		}
	}
	printf("%d",index);
	//Weiß ich wo der Wunschtext anfängt
	newCount=0;
	for(i=index+1;i<5;i++){
		newText[newCount] = dataText[i];
		newCount++;
		
	}
	return 0;
}


