#include "factorielle.h"

nombre factorielle(nombre number){
    if(number == 1) {
        return 1;
    }
    else {
        return factorielle(number-1)*number;
    }
}