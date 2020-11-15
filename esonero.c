#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char M[128], C[128], K[128];
int len_m, len_k;
int scelta;
time_t t;

int main() {

  printf("Inserisca una stringa di testo con lunghezza minore o uguale a 128 caratteri\n");
  fgets(M, 128, stdin);
  fflush(stdin);
  len_m = strlen(M);
  printf("Lunghezza di M: %d\n", len_m );
  printf("Ora scelga un' opzione:\n -1 per inserire una stringa con la quale cifrare il testo M (Attenzione! La stringa deve essere lunga almeno quanto M, se verrà inserita una chiave di lunghezza minore le verrà chiesto di inserirne una nuova).\n -2 per generare una stringa casuale con la quale cifrare M.\n");

/* Dopo aver chiesto all'utente una stringa di testo
lo si fa scegliere tra due opzioni. 1 inserire una chiave manualmente
2 generarne una casuale */

  scelta = getchar();
  switch (scelta)
    {
    case '1': printf("Inserisca una chiave di codifica\n");
            do {
              fgets(K, 128, stdin);
              len_m = strlen(M);
              len_k = strlen(K);
              }

            while (len_k < len_m); {
              printf("Lunghezza di K: %d\n", len_k);
              for (int i=0; i < len_k; i++)
                C[i] = M[i] ^ K[i];
              printf("Stringa codificata: %s\n", C);
              for (int i = 0; i < 128; i++)
                M[i] = C[i] ^ K[i];
              printf("Rieseguendo lo Xor tra C e K verrà calcolata di nuovo la chiave M: %s\n", M); }

/* eseguo un do while per essere certo che l'utente inserisca
una chiave di lunghezza uguale o maggiore di quella del testo da cifrare */

    break;
    case '2': len_m = strlen(M);
              srand((unsigned) time(&t));
              for (int i=0; i < len_m; i++)
              K[i]=32+rand()%96;
              printf("Stringa casuale generata: %s\n", K);

/* per generare una stringa casuale utilizzo il tempo */

              for (int i = 0; i < len_m; i++)
                C[i] = M[i] ^ K[i];
              printf("Stringa codificata: %s\n", C );

              int len_c = strlen(C);
              for (int i = 0; i < len_c; i++)
                M[i] = C[i] ^ K[i];
              printf("Rieseguendo lo Xor tra C e K verrà calcolata di nuovo la chiave M: %s", M);

    break;
    default: printf("La scelta era solo tra 1 e 2\n" ); }

}
