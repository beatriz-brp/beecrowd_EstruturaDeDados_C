#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, pontos, marcados, sofridos;
} Time;

int comparar(const void *a, const void *b) {
    Time *t1 = (Time *)a;
    Time *t2 = (Time *)b;

    if (t2->pontos != t1->pontos)
        return t2->pontos - t1->pontos;

	double avg1, avg2;

	if (t1->sofridos == 0)
    	avg1 = t1->marcados;
	else
    	avg1 = (double)t1->marcados / t1->sofridos;

	if (t2->sofridos == 0)
    	avg2 = t2->marcados;
	else
   		 avg2 = (double)t2->marcados / t2->sofridos;

	if (avg1 != avg2) {
    	if (avg2 > avg1)
        return 1;
    else
        return -1;
}

	if (t2->marcados != t1->marcados)
    	return t2->marcados - t1->marcados;

	return t1->id - t2->id;
}

int main() {
    int n, i, h = 1;
    while (scanf("%d", &n), n) {
    	if (h > 1) printf("\n");
    	
        Time times[101] = {0};
        for (i = 1; i <= n; i++) 
		times[i].id = i;

        for (i = 0; i < n * (n - 1) / 2; i++) {
            int x, y, z, w;
            scanf("%d %d %d %d", &x, &y, &z, &w);

            times[x].marcados += y;
            times[x].sofridos += w;
            times[z].marcados += w;
            times[z].sofridos += y;

            if (y > w) {
                times[x].pontos += 2;
                times[z].pontos += 1;
            } else {
                times[z].pontos += 2;
                times[x].pontos += 1;
            }
        }

        qsort(times + 1, n, sizeof(Time), comparar);

        printf("Instancia %d\n", h++);
        for (i = 1; i <= n; i++) {
            printf("%d", times[i].id);
            if(i < n){
            	printf(" ");
			}
        }
        printf("\n");
    }
    return 0;
}

