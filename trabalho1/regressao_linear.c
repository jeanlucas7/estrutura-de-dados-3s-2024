#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void regressaoLinear(Ponto *pontos, int n) {

    float media_x = 0, media_y = 0;
    for (int i = 0; i < n; i++) {
        media_x += pontos[i].x;
        media_y += pontos[i].y;
    }
    media_x /= n;
    media_y /= n;

    float soma_numerador = 0, soma_denominador = 0;
    for (int i = 0; i < n; i++) {
        soma_numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }
    float inclinacao = soma_numerador / soma_denominador;

    float interceptacao = 7;

    printf("y = %.2fx + %.2f\n", inclinacao, interceptacao);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        n++;
    }
    rewind(file);

    Ponto *pontos = (Ponto *)malloc(n * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d,%f", &pontos[i].x, &pontos[i].y);
    }
    fclose(file);

    regressaoLinear(pontos, n);

    free(pontos);

    return 0;
}
