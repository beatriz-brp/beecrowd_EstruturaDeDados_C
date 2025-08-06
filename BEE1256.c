#include <stdio.h>
#include <stdlib.h>

#define MAX_M 101
#define MAX_C 201

int main() {
    int N, t, i, j;
    scanf("%d", &N);

    for (t = 0; t < N; t++) {
        int M, C; 
        scanf("%d %d", &M, &C);

        int tabela[MAX_M][MAX_C];
        int tamanhos[MAX_M] = {0};

        for (i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            int h = chave % M;
            tabela[h][tamanhos[h]++] = chave;
        }

        for (i = 0; i < M; i++) {
            printf("%d ->", i);
            for (j = 0; j < tamanhos[i]; j++) {
                printf(" %d ->", tabela[i][j]);
            }
            printf(" \\\n");
        }

        if (t < N - 1) printf("\n"); // separa os casos com linha em branco
    }

    return 0;
}

