#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include "prixTuring.h"

int numberOfWinners(FILE *fichier) {
    int nombreDeLignes = 0;
    int caractere;
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombreDeLignes++;
        }
    }
    rewind(fichier);
    return nombreDeLignes;
}

TuringWinner* readWinners(FILE* fichierSource) {
    int capacite = numberOfWinners(fichierSource);
    TuringWinner* listeGagnants = (TuringWinner*)malloc(capacite * sizeof(TuringWinner));
    for (int i = 0; i < capacite; i++) {
        readWinner(&listeGagnants[i], fichierSource);
    }
    return listeGagnants;
}

void readWinner(TuringWinner *winner, FILE *f) {
    fscanf(f, "%d;", &winner->annee);
    winner->nom = readStringFromFileUntil(f, ';');
    winner->invention = readStringFromFileUntil(f, '\n');
}

char* readStringFromFileUntil(FILE *f, char c) {
    int capacite = 64;
    int taille = 0;
    int caractere;
    char *resultat = (char *)malloc(capacite * sizeof(char));
    while ((caractere = fgetc(f)) != EOF && caractere != c) {
        resultat[taille++] = (char)caractere;
        if (taille >= capacite) {
            capacite *= 2;
            resultat = (char *)realloc(resultat, capacite * sizeof(char));
        }
    }
    resultat[taille] = '\0';
    return resultat;
}

void writeWinnersToFile(TuringWinner* winners, int count, const char* fileName) {
    FILE* fichierDestination = fopen(fileName, "w");
    for (int i = 0; i < count; i++) {
        fprintf(fichierDestination, "%d;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].invention); 
    }
    fclose(fichierDestination);
}

void infosAnnee(int year, TuringWinner* winners, int nombre) {
    for (int i = 0; i < nombre; i++) {
        if (winners[i].annee == year) {
            printf("L'année %d, le(s) gagnant(s) ont été : %s\n", winners[i].annee, winners[i].nom);
            printf("Nature des travaux : %s\n", winners[i].invention);
        }
    }
}

void sortTuringWinnersByYear(const char* outputFilename, int nombreGagnants, TuringWinner* winners) {
    qsort(winners, nombreGagnants, sizeof(TuringWinner), compareTuringWinners);
    FILE* outputFile = fopen(outputFilename, "w");
    for (int i = 0; i < nombreGagnants; i++) {
        fprintf(outputFile, "%d;%s;%s\n", winners[i].annee, winners[i].nom, winners[i].invention);
    }
    fclose(outputFile);
}

int compareTuringWinners(const void* a, const void* b) {
    return (((TuringWinner*)a)->annee - ((TuringWinner*)b)->annee);
}
