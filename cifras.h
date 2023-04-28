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
//Cria uma lista de cifra vazia e a retorna
cifras *cria_cifras();
//Destroi a lista de cifras e retorna NULL
cifras *destroi_cifras(cifras *c);
//Imprime as letras da lista e suas respectivas chaves, para depuração
void imprime_cifras(cifras *c);
//Escreve as letras da lista cifras e suas correspondentes chaves em um arquivo
void escreve_cifras(cifras *c, FILE *arq);
//Lê as cifras de um arquivo e as transfere para uma lista cifras
int le_cifras(cifras *c, FILE *arq);
//Cria uma lista cifras a partir de um arquivo
int faz_cifras(cifras *c, FILE *arq);
//Adiciona um numero para a fila de chaves de uma letra, caso possível. Em caso de erro em malloc, não insere o elemento e imprime uma mensagem de erro.
int adiciona_chave(cifras *c, char letra, int posicao);
#endif //_cifras_
