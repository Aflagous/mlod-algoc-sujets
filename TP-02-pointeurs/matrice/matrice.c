#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#define SIZE 5

#include "matrice.h"

void matrix_mult(int64_t mat1[][SIZE], int64_t mat2[][SIZE], int64_t result[][SIZE]) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrix_print(int64_t result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int64_t nombre = result[i][j];
            printf("%" PRId64 " ", nombre);
        }
        printf("\n");
    }
}

Date creerDateParCopie() {
    Date d;
    initialiseDate(&d);
    return d;
} 

void initialiseDate(Date *date) {
    printf("Entrez le jour, le mois et l'année (séparés par des espaces) : ");
    scanf("%d %d %hd", &(date->jour), (int *)&(date->mois), &(date->annee));
}

void afficheDate(Date *date) {
    printf("%d/%d/%hd\n", date->jour, date->mois, date->annee);
}

Date* newDate() {
    Date* d = (Date*)malloc(sizeof(Date));
    initialiseDate(&d);
    return d;
}