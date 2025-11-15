#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Anlegen eines Datentypes für einen Punkt
struct punkt {
	int x;	// die X-Koordintate des Punkts
	int y;	// die Y-Koordintate des Punkts
};

struct punkt move(struct punkt p);

// Anlegen einer Datenstruktur für ein Haustier
struct haustier {
	char name[128];
	int alter;
};
int main(){
	//Deklaration eines Punkts mit x-& y-Koordinaten
	struct punkt p, q;
	p.x = 10;
	p.y = 20;
	
	printf("Der Punkt P(%i/%i)\n",p.x,p.y);
	q = move(p);
	printf("Der Punkt Q(%i/%i)\n",q.x,q.y);
	
	
	//Deklaration eines Haustieres
	struct haustier tier;
	tier.alter = 3;
	strcpy(tier.name, "Otto");
	
	printf("Das Haustier %s ist %i Jahre alt!\n",tier.name, tier.alter);
	return EXIT_SUCCESS;
}

struct punkt move(struct punkt p){
	struct punkt q;
	q.x = 2*p.x;
	q.y = 2*p.y;
	return q;
}
