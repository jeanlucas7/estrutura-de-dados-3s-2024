#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

void inserir_no(No **H, char valor) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(1);
    }

    novo_no->valor = valor;
    if (*H == NULL) {
        novo_no->proximo = novo_no;
        *H = novo_no;
    } else {
        novo_no->proximo = (*H)->proximo;
        (*H)->proximo = novo_no;
        *H = novo_no;
    }
}

void imprimir_lista(No *H) {
    if (H == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No *atual = H->proximo;
    do {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    } while (atual != H->proximo);
    printf("\n");
}

void remover_no(No **H, char valor) {
    if (*H == NULL) {
        printf("Erro: lista vazia\n");
        return;
    }

    No *atual = (*H)->proximo;
    No *anterior = *H;

    do {
        if (atual->valor == valor) {
            anterior->proximo = atual->proximo;
            if (atual == *H) {
                *H = anterior;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != (*H)->proximo);

    printf("Erro: elemento não encontrado\n");
}

void liberar_lista(No **H) {
    if (*H == NULL) {
        return;
    }

    No *atual = (*H)->proximo;
    No *temp;
    do {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != (*H)->proximo);

    free(*H);
    *H = NULL;
}
