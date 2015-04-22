#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define N 3

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};
// Definisci studente come struct s_studente
struct s_studente v[N];

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    FILE *puntaFile;
     
    // Codice per l'inserimento, da parte dell'utente, dei dati in un array
    for(i = 0; i < N; i++) {
        printf("Nome elemento %d : ", i);
        scanf("%s", v[i].nome);
        printf("Cognome elemento %d : ", i);
        scanf("%s", v[i].cognome);
        printf("Eta' elemento %d : ", i);
        scanf("%d", &(v[i].eta));
        printf("Classe elemento %d : ", i);
        scanf("%s", v[i].classe);
    }
    
    // Codice per la scrittura dell'elenco su file
    puntaFile = fopen("elenco.dat", "wb");
    if(puntaFile != NULL) {
        fwrite(&v, sizeof(v), N, puntaFile);
        fclose(puntaFile);
    }
    else
        printf("Il file non puo' essere aperto\n");
    
    return (EXIT_SUCCESS);
}
