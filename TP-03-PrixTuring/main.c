#include "prixTuring.c"

int main(int argc, char** argv) {
    char* fichierSourceNom = "turingWinners.csv";
    char* fichierDestinationNom = "out.csv";
    int infoYear = 0;
    int shouldSort = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            fichierDestinationNom = argv[i + 1];
            if (i + 2 < argc) {
                fichierSourceNom = argv[i + 2];
            }
            i += 2; 
        } else if (strcmp(argv[i], "--info") == 0 && i + 1 < argc) {
            infoYear = atoi(argv[i + 1]);
            i++; 
        } else if (strcmp(argv[i], "--sort") == 0) {
            shouldSort = 1;
            fichierDestinationNom = argv[i + 1];

            if (i + 2 < argc) {
                fichierSourceNom = argv[i + 2];
            }
            i += 2;
        }
    }
    FILE *fichierSource = fopen(fichierSourceNom, "r");
    FILE *fichierDestination = fopen(fichierDestinationNom, "w");
    int nombreGagnants = numberOfWinners(fichierSource);
    TuringWinner* listeGagnants = readWinners(fichierSource);
    writeWinnersToFile(listeGagnants, nombreGagnants, fichierDestinationNom);

    if (infoYear > 0) {
        infosAnnee(infoYear, listeGagnants, nombreGagnants);
        return EXIT_SUCCESS;
    }
    if (shouldSort) {
        sortTuringWinnersByYear(fichierDestinationNom, nombreGagnants, listeGagnants);
        return EXIT_SUCCESS;
    }
    fclose(fichierSource);
    fclose(fichierDestination);

    for (int i = 0; i < nombreGagnants; i++) {
        free(listeGagnants[i].nom);
        free(listeGagnants[i].invention);
    }
    free(listeGagnants);
    return EXIT_SUCCESS;
}
