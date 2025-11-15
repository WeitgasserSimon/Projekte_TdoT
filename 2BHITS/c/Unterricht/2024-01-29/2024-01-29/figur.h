/**
 * @brief   Methoden des objects
 * @author  Lothar Schäfer
 * @date    15.01.2024

 */

#ifndef FIGUR_H
#define FIGUR_H

// Die Klasse Figur
struct figur {
	float Flaeche;
	float Umfang;
	float (*getFlaeche)(struct figur*);
	float (*getUmfang)(struct figur*);
};

// Prototyp des Konstruktors
struct figur* newFigur();

// Prototyp des Destruktors
void destroyFigur(struct figur* this);

// Prototypen der Getter-Methoden
float getFlaeche(struct figur* this);
float getUmfang(struct figur* this);

#endif
