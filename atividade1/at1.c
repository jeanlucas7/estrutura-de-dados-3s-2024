#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int N;
    int numeros[N];
    double soma = 0.0;
    int menor;
    int maior;
    
    printf("Digite a quantidade de números a serem inseridos: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Nenhum número foi inserido.\n");
        return 0;
    }

    printf("Digite os números:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Quantidade de números: %d\n", N);

    for (int i = 0; i < N; i++) {
        soma += numeros[i];
    }

    double media = soma / N;
    printf("Valor médio: %.2f\n", media);

    menor = numeros[0];
    for (int i = 1; i < N; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    printf("Menor número: %d\n", menor);


    maior = numeros[0];
    for (int i = 1; i < N; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }
    printf("Maior número: %d\n", maior);


    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    printf("Números em ordem crescente:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}