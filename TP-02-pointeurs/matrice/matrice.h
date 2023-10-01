#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#define SIZE 5

typedef double Element;

typedef enum {
    JANVIER,   
    FEVRIER,   
    MARS,      
    AVRIL,     
    MAI,       
    JUIN,      
    JUILLET,   
    AOUT,      
    SEPTEMBRE, 
    OCTOBRE,   
    NOVEMBRE,  
    DECEMBRE   
} Mois;

typedef struct {
    int jour;
    Mois mois;
    unsigned short annee;
} Date;


void matrix_mult(int64_t mat1[][SIZE], int64_t mat2[][SIZE], int64_t result[][SIZE]);
void matrix_print(int64_t result[][SIZE]);
void initialiseDate(Date *date);
void afficheDate(Date *date);
Date creerDateParCopie();
Date* newDate();