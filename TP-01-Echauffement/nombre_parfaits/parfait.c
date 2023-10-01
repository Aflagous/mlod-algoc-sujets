#include "parfait.h"
#include <stdio.h>

int parfait(int nombre){
    int total = 0;
    for (int i =1; i <= nombre-1; i++) {
        if ((nombre%i) == 0) {
            total += i;
        }
    }
    if(total == nombre) {
        return 1;
    }
    else return 0;
}