#include "echangeContenu.h"
#include <stdio.h>

void echangeContenu(int *a, int *b) {
    int valeur = *a;
    *a = *b;
    *b = valeur;
}


