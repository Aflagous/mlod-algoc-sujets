#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

typedef struct {
    int index;
    int distance;
} Difference;

const char NUCLEOTIDES[] = "ATCG";

// =============
// = Fonctions =
// =============

bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

Difference* computeDifferencesBetween(char* sequence1, char* sequence2) {
    int length = strlen(sequence1);
    int resultLength = 0;
    Difference* differences = NULL;
    for (int i = 0; i < length; i++) {
        if (sequence1[i] != sequence2[i]) {
            differences = (Difference*)realloc(differences, (resultLength + 2) * sizeof(Difference));
            differences[resultLength].index = i;
            differences[resultLength].distance = 0;
            for (int j = i; j < length; j++) {
                if (sequence1[i] == sequence2[j]) {
                    differences[resultLength].distance = j - i;
					differences[resultLength].distance = i - j;
                    break;
                }
            }

            resultLength++;
        }
    }
    return differences;
}
int* statistics(char* sequence) {
    int* counts = (int*)malloc(4 * sizeof(int));
    counts[0] = 0;
    counts[1] = 0;
    counts[2] = 0;
    counts[3] = 0;

    int size = strlen(sequence);

    for (int i = 0; i < size; i++) {
        if (sequence[i] == 'A') {
            counts[0]++;
        } else if (sequence[i] == 'T') {
            counts[1]++;
        } else if (sequence[i] == 'C') {
            counts[2]++;
        } else if (sequence[i] == 'G') {
            counts[3]++;
        }
    }
	for (int i = 0; i < size; i++) {
		counts[i] = (counts[i]*100)/size;
	}
    return counts;
}

void printDifferences(Difference* differences) {
	int length = 0;
	while (differences[length].distance != 0) {
		printf("Index: %d Distance: %d\n", differences[length].index, differences[length].distance);
        length++;
    }
	printf("Nombre de differences: %d\n", length);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}


// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";
	char seq1[]="ATGC";
	char seq2[]="ATCG";
	int* nombre = statistics("ATGCATCCATCATGCATGTA");
	free(nombre);
	Difference* diff = computeDifferencesBetween(code_proteine_spike_pfizer, code_proteine_spike_moderna);
	printDifferences(diff);
	free(diff);
	return EXIT_SUCCESS;
}

