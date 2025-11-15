/**
*\brief:  Luhn-Algoryhtmus
*\details: 
*\author: Jaspreet Singh Geord
*\date:   2023-01-31
*/

#include <stdio.h>
#include <stdlib.h>
 void luhn(int x, int y, int z, int a, int b);

int main() {
	system("COLOR 0F");
	system("CHCP 1250");
	system("CLS");
	
	luhn(18937, 17937, 19837, 13987, 78931);

	
	return EXIT_SUCCESS;
}

void luhn (int x, int y, int z, int a, int b){
	int first, second, c, e, g, f0dig, f1dig, f01dig, s1dig, s0dig, s01dig, luhn, luhn01;

		c = x/10000;
		first = (x-c*10000)/1000;
		e = (x-c*10000-first*1000)/100;
		second = (x-c*10000-first*1000-e*100)/10;
		g = (x-c*10000-first*1000-e*100-second*10)/1;
	
	
	first = first*2;
	second = second*2;
	
	if(first > 9){
		first = first-9;
		f0dig = first/10;
		f1dig = (first-f0dig*10)/1;
		f01dig = f0dig + f1dig;
	}else {
		f01dig = first;
	}	
	
	if(second > 9){

		second = second-9;
		s0dig = second/10;
		s1dig = (second-s0dig*10)/1;
		s01dig = s0dig + s1dig;
		}else {
			s01dig = second;
		}
	
	luhn01 = (c+f01dig+e+s01dig+g);

	if(luhn01 % 10 == 0){
		luhn = luhn01 % 10;
		printf("Die Zahl %d entspricht dem Luhn-Algorythmus.\n", x);
	} else {
		luhn = luhn01 % 10;
		printf("Die Zahl %d entspricht nicht dem Luhn-Algorythmus.\n", x);
	}
	
	
		int first1, second1, h, i, j, f0dig1, f1dig1, f01dig1, s1dig1, s0dig1, s01dig1, luhn1, luhn11;

		h = y/10000;
		first1 = (y-h*10000)/1000;
		i = (y-h*10000-first1*1000)/100;
		second1 = (y-h*10000-first1*1000-i*100)/10;
		j = (y-h*10000-first1*1000-i*100-second1*10)/1;
	

	first1 = first1*2;
	second1 = second1*2;
	
	if(first1 > 9){
		first1 = first1-9;
		f0dig1 = first1/10;
		f1dig1 = (first1-f0dig1*10)/1;
		f01dig1 = f0dig1 + f1dig1;
	}else {
		f01dig1 = first1;
	}	
	
	if(second1 > 9){

		second1 = second1-9;
		s0dig1 = second1/10;
		s1dig1 = (second1-s0dig1*10)/1;
		s01dig1 = s0dig1 + s1dig1;
		}else {
			s01dig1 = second1;
		}

	luhn11 = (h+f01dig1+i+s01dig1+j);

	if(luhn11 % 10 == 0){
		luhn1 = luhn11 % 10;
		printf("Die Zahl %d entspricht dem Luhn-Algorythmus.\n", y);
	} else {
		luhn1 = luhn11 % 10;
		printf("Die Zahl %d entspricht nicht dem Luhn-Algorythmus.\n", y);
	}
	

		int first2, second2, k, l, m, f0dig2, f1dig2, f01dig2, s1dig2, s0dig2, s01dig2, luhn2, luhn12;

		k = z/10000;
		first2 = (z-k*10000)/1000;
		l = (z-k*10000-first2*1000)/100;
		second2 = (z-k*10000-first2*1000-l*100)/10;
		m = (z-k*10000-first2*1000-l*100-second2*10)/1;
	
	
	first2 = first2*2;
	second2 = second2*2;
	
	if(first2 > 9){
		first2 = first2-9;
		f0dig2 = first2/10;
		f1dig2 = (first2-f0dig2*10)/1;
		f01dig2 = f0dig2 + f1dig2;
	}else {
		f01dig2 = first2;
	}	
	
	if(second2 > 9){

		second2 = second2-9;
		s0dig2 = second2/10;
		s1dig2 = (second2-s0dig2*10)/1;
		s01dig2 = s0dig2 + s1dig2;
		}else {
			s01dig2 = second2;
		}
	
	luhn12 = (k+f01dig2+l+s01dig2+m);

	if(luhn12 % 10 == 0){
		luhn2 = luhn12 % 10;
		printf("Die Zahl %d entspricht dem Luhn-Algorythmus.\n", z);
	} else {
		luhn2 = luhn12 % 10;
		printf("Die Zahl %d entspricht nicht dem Luhn-Algorythmus.\n", z);
	}

		int first3, second3, n, o, p, f0dig3, f1dig3, f01dig3, s1dig3, s0dig3, s01dig3, luhn3, luhn13;

		n= a/10000;
		first3 = (a-n*10000)/1000;
		o = (a-n*10000-first3*1000)/100;
		second3 = (a-n*10000-first3*1000-o*100)/10;
		p = (a-n*10000-first3*1000-o*100-second3*10)/1;
	
	
	first3 = first3*2;
	second3 = second3*2;
	
	if(first3 > 9){
		first3 = first3-9;
		f0dig3 = first3/10;
		f1dig3 = (first3-f0dig3*10)/1;
		f01dig3 = f0dig3 + f1dig3;
	}else {
		f01dig3 = first3;
	}	
	
	if(second3 > 9){

		second3 = second3-9;
		s0dig3 = second3/10;
		s1dig3 = (second3-s0dig3*10)/1;
		s01dig3 = s0dig3 + s1dig3;
		}else {
			s01dig3 = second3;
		}
	
	luhn1 = (n+f01dig3+o+s01dig3+p);

	if(luhn1 % 10 == 0){
		luhn3 = luhn13 % 10;
		printf("Die Zahl %d entspricht dem Luhn-Algorythmus.\n", a);
	} else {
		luhn3 = luhn13 % 10;
		printf("Die Zahl %d entspricht nicht dem Luhn-Algorythmus.\n", a);
	}

		int first4, second4, q, r, s, f0dig4, f1dig4, f01dig4, s1dig4, s0dig4, s01dig4, luhn4, luhn14;

		q = x/10000;
		first4 = (x-q*10000)/1000;
		r = (x-q*10000-first4*1000)/100;
		second4 = (x-q*10000-first4*1000-r*100)/10;
		s = (x-q*10000-first4*1000-r*100-second4*10)/1;
	
	
	first4 = first4*2;
	second4 = second4*2;
	
	if(first4 > 9){
		first = first4-9;
		f0dig4 = first4/10;
		f1dig4 = (first4-f0dig4*10)/1;
		f01dig4 = f0dig4 + f1dig4;
	}else {
		f01dig4 = first4;
	}	
	
	if(second4 > 9){

		second4 = second4-9;
		s0dig4 = second4/10;
		s1dig4 = (second4-s0dig4*10)/1;
		s01dig4 = s0dig4 + s1dig4;
		}else {
			s01dig4 = second4;
		}
	
	luhn14 = (q+f01dig4+r+s01dig4+s);

	if(luhn14 % 10 == 0){
		luhn4 = luhn14 % 10;
		printf("Die Zahl %d entspricht dem Luhn-Algorythmus.\n", b);
	} else {
		luhn4 = luhn14 % 10;
		printf("Die Zahl %d entspricht nicht dem Luhn-Algorythmus.\n", b);
	}
}
