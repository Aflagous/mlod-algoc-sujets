// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>


void afficheElement(Element e){
	printf("%s ",(char*) e);
}

extern void detruireElement(Element e) {}

bool equalsElement(Element e1, Element e2){
	return strcmp((char*) e1, (char*) e2) == 0;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("!",l);
	l = ajoutTete("!",l);
	l = ajoutTete("!",l);
	l = ajoutTete("Jedi",l);
	l = ajoutTete("est",l);

	afficheListe_i(l);

	detruire_r(l);
	

	return EXIT_SUCCESS;
}