#include <stdio.h>
#include <string.h>
#include "vetor.h"

int main() {
    TipoVetor V;
    TipoItem x;
    char cmd[10];
    int pos;

    Inicializa(&V);

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "i") == 0) {
            scanf("%d", &x.Chave);
            if (!Insere(x, &V))
                printf("erro: chave %d ja existe\n", x.Chave);
        } else if (strcmp(cmd, "d") == 0) {
            scanf("%d", &x.Chave);
            if (Deleta(x.Chave, &V))
                printf("removido: %d\n", x.Chave);
            else
                printf("erro: %d nao encontrado\n", x.Chave);
        } else if (strcmp(cmd, "b") == 0) {
            scanf("%d", &x.Chave);
            pos = Busca(x.Chave, &V);
            if (pos != -1)
                printf("encontrado: %d [pos=%d]\n", x.Chave, pos);
            else
                printf("nao encontrado: %d\n", x.Chave);
        } else if (strcmp(cmd, "imp") == 0) {
            Imprime(&V);
        } else if (strcmp(cmd, "tam") == 0) {
            printf("tamanho: %d, capacidade: %d\n", V.Tamanho, V.Capacidade);
        }
    }

    Libera(&V);
    return 0;
}
