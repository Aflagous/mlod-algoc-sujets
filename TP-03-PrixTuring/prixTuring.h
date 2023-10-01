typedef struct {
    int annee;
    char *nom;
    char *invention;
} TuringWinner;

int numberOfWinners(FILE *fichier);
TuringWinner* readWinners(FILE* fichierSource);
void readWinner(TuringWinner *winner, FILE *f);
char* readStringFromFileUntil(FILE *f, char c);
void writeWinnersToFile(TuringWinner* winners, int count, const char* fileName);
void infosAnnee(int year, TuringWinner* winners, int nombre);
void sortTuringWinnersByYear(const char* outputFilename, int nombreGagnants, TuringWinner* winners);
int compareTuringWinners(const void* a, const void* b);