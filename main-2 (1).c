#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

int main() {
    srand(time(NULL));
    int M, Ti, suditos[N], nSuditos = N;
    int *p = &suditos;

    printf("Digite o numero de turnos: ");
    scanf("%d", &M);

    //suditos de 1 ate N
    for (int i = 0; i < N; i++) {
        *(p + i) = i + 1;
    }

    printf("Suditos\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", *(p + i));
    }

    printf("\nSorteios\n");
    for (int turnos = 0; turnos < M; turnos++) {
        //numero aleatorio de 1 ate N
        Ti = 1 + (rand() % N);
        printf("Numero Sorteado: %d\n", Ti);
        for (int i = 0; i < nSuditos; i++) {
            if (*(p + i) % Ti == 0) {
                for (int j = i; j < nSuditos - 1; j++) {
                    *(p + j) = *((p + j) + 1);
                }
                nSuditos--;
                i--;
            }
        }
    }

    printf("\nLista Final:\n");
    if(nSuditos > 10000){
        nSuditos = 10000;
    }
    for (int i = 0; i < nSuditos; i++) {
        printf("%d\n",*(p + i));
    }

return 0;}
