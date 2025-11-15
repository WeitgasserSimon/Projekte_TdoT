#include <stdio.h>
#include <stdlib.h>

	int main(){
		
		int a= 1;
		int b = 2;
		int c = 3;
		
		//Die adresse mit dem adresse operator & bestimmen
		
		int * adresse_von_a = &a;
		int * adresse_von_b = &b;
		int * adresse_von_c = &c;
		printf("a= %i liegt an 0x%p\n",a,adresse_von_a);
		printf("b= %i liegt an 0x%p\n",b,adresse_von_b);
		printf("c= %i liegt an 0x%p\n",c,adresse_von_c);
		
		int array[3]={1,2,3};
		
		//Die Adresse des Arrays bestimmen
		int* adresse_von_array = array;
		
		int i;
		for(i = 0; i<3;i++){
			printf("array[%i] = %i liegt an 0x %p \n",i,*(array+i),(array+i));
		}
		
		
		return 0;
	}
