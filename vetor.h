#ifndef VETOR_H
#define VETOR_H

#define TAM_INICIAL 4

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
} TipoItem;

typedef struct {
    TipoItem *Item;
    int       Tamanho;     /* quantidade de elementos armazenados */
    int       Capacidade;  /* tamanho alocado do vetor */
} TipoVetor;

void Inicializa(TipoVetor *V);
void Libera(TipoVetor *V);
void Aumenta(TipoVetor *V);
int  Busca(TipoChave chave, TipoVetor *V);
int  Insere(TipoItem x, TipoVetor *V);
int  Deleta(TipoChave chave, TipoVetor *V);
void Imprime(TipoVetor *V);

#endif
