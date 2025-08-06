#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // ordem crescente
}

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // ordem decrescente
}

int main() {
    int N, i;
    scanf("%d", &N);

    int pares[N], impares[N];
    int p = 0, imp = 0;

    for (i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        if (valor % 2 == 0)
            pares[p++] = valor;
        else
            impares[imp++] = valor;
    }

    // Ordenacao ordem crescente
    qsort(pares, p, sizeof(int), compare_asc);
    // Ordenacao ordem decrescente
    qsort(impares, imp, sizeof(int), compare_desc);

    for (i = 0; i < p; i++)
        printf("%d\n", pares[i]);

    for (i = 0; i < imp; i++)
        printf("%d\n", impares[i]);

    return 0;
}
