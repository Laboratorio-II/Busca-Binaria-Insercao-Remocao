#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void Inicializa(TipoVetor *V) {
    V->Item = (TipoItem *)malloc(TAM_INICIAL * sizeof(TipoItem));
    if (V->Item == NULL) {
        printf("Erro: falha na alocacao de memoria\n");
        exit(1);
    }
    V->Tamanho = 0;
    V->Capacidade = TAM_INICIAL;
}

void Libera(TipoVetor *V) {
    free(V->Item);
    V->Item = NULL;
    V->Tamanho = 0;
    V->Capacidade = 0;
}

/* Dobra a capacidade do vetor */
void Aumenta(TipoVetor *V) {
    V->Capacidade *= 2;
    V->Item = (TipoItem *)realloc(V->Item, V->Capacidade * sizeof(TipoItem));
    if (V->Item == NULL) {
        printf("Erro: falha na realocacao de memoria\n");
        exit(1);
    }
}

/* Busca binaria recursiva no trecho entre as posicoes ini e fim */
static int BuscaRec(TipoChave chave, TipoVetor *V, int ini, int fim) {
    if (ini > fim)
        return -1;

    int meio = (ini + fim) / 2;
    if (V->Item[meio].Chave == chave)
        return meio;
    else if (V->Item[meio].Chave < chave)
        return BuscaRec(chave, V, meio + 1, fim);
    else
        return BuscaRec(chave, V, ini, meio - 1);
}

int Busca(TipoChave chave, TipoVetor *V) {
    return BuscaRec(chave, V, 0, V->Tamanho - 1);
}

int Insere(TipoItem x, TipoVetor *V) {
    /* IMPLEMENTAR: insere x mantendo o vetor ordenado.
       Retorna 1 se inseriu ou 0 se a chave ja existe. */
    return 0;
}

int Deleta(TipoChave chave, TipoVetor *V) {
    /* IMPLEMENTAR: remove o elemento com a chave informada.
       Retorna 1 se removeu ou 0 se a chave nao existe. */
    return 0;
}

void Imprime(TipoVetor *V) {
    if (V->Tamanho == 0) {
        printf("vetor vazio\n");
        return;
    }
    for (int i = 0; i < V->Tamanho; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", V->Item[i].Chave);
    }
    printf("\n");
}
