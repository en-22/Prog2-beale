#ifndef _cifras_
#define _cifras_
#include "libfila.h"
typedef struct nodo_cifras{
    char letra;
    fila_t *chaves;
    struct nodo_cifras *prox;
} nodo_cifras;

typedef struct cifras{
    nodo_cifras *primeiro;
} cifras;

//Cria uma lista de cifras vazia e a retorna, se falhar retorna NULL.
cifras *cria_cifras();
//Destroi a lista de cifras e retorna NULL.
cifras *destroi_cifras(cifras *c);
//Imprime as letras da lista cifras e suas respectivas chaves, para depuração.
void imprime_cifras(cifras *c);
//Escreve as letras da lista cifras e suas correspondentes chaves em um arquivo.
void escreve_cifras(cifras *c, FILE *arq);
//Lê as cifras de um arquivo e as transfere para uma lista cifras. Retorna 1 em caso de sucesso, 0 caso contrario.
int le_cifras(cifras *c, FILE *arq);
//Cria uma lista cifras a partir de um arquivo. Retorna 1 em caso de sucesso, 0 caso contrario.
int faz_cifras(cifras *c, FILE *arq);
//Adiciona um número para a fila de chaves de uma letra. Caso a letra não esteja na lista, primeiro a adiona em ordem alfabética. Retorna 1 em caso de sucesso ou, caso a letra seja acentuada, retorna 1 sem adiciona-la, e 0 caso contrario.
int adiciona_chave(cifras *c, char letra, int posicao);
#endif //_cifras_

