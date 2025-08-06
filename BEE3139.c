#include <stdio.h>
#include <math.h>

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);

    int dias[30];
    int i;
    for (i = 0; i < 30; i++) {
        scanf("%d", &dias[i]);
    }

    int dias_passados = 0;
    long long total_seguidores = N;

    long long somar_ultimos_30 = 0;
    for (i = 0; i < 30; i++) {
        somar_ultimos_30 += dias[i];
    }

    while (total_seguidores < M) {
        double media = somar_ultimos_30 / 30.0;
        
        int novos = (int)ceil(media);

        total_seguidores += novos;
        somar_ultimos_30 = somar_ultimos_30 - dias[0] + novos;

        for (i = 0; i < 29; i++) {
            dias[i] = dias[i + 1];
        }
        dias[29] = novos;

        dias_passados++;
    }

    printf("%d\n", dias_passados);

    return 0;
}
