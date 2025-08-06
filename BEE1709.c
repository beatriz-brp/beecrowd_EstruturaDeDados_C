#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	int temp;
	while(b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
} 

int lcm(int a, int b) {
    int g = gcd(a, b);
    return (a / g) * b;
}

int main() {
    int P, i;
    scanf("%d", &P);
    int *visitado = calloc(P, sizeof(int));
    int resposta = 1;

    for (i = 0; i < P; i++) {
        if (!visitado[i]) {
            int atual = i, count = 0;
            do {
                int novo;
                if (atual < P / 2)
                    novo = 2 * atual + 1;
                else
                    novo = 2 * (atual - P / 2);
                atual = novo;
                count++;
                visitado[atual] = 1;
            } while (atual != i);
            resposta = lcm(resposta, count);
        }
    }

    printf("%d\n", resposta);
    free(visitado);
    return 0;
}
