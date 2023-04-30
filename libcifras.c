#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcifras.h"

#define SIZE 1024

cifras *cria_cifras(){
	cifras* cifras;

	if(!(cifras = malloc(sizeof(cifras))))
		return NULL;
    cifras->primeiro = NULL;
	return cifras;
}

cifras *destroi_cifras(cifras *c){
    nodo_cifras* nodoaux;

    while(c->primeiro != NULL){
        nodoaux = c->primeiro;
        c->primeiro = nodoaux->prox;
        destroi_fila(nodoaux->chaves);
        free(nodoaux);
    }
    free(c);
    return NULL;
}

void imprime_cifras(cifras *c){
    nodo_cifras* nodoaux = c->primeiro;

    while(nodoaux != NULL){
        printf("%c:", nodoaux->letra);
        imprime_fila(nodoaux->chaves);
        printf("\n");
        nodoaux = nodoaux->prox;
    }
}


void escreve_cifras(cifras *c, FILE *arq){
    nodo_cifras* nodoaux = c->primeiro;

    while(nodoaux != NULL){
        fprintf(arq, "%c:", nodoaux->letra);
		for(int i = 0; i < tamanho_fila(nodoaux->chaves); i++)
			fprintf(arq, " %d", retorna_elemento_index(nodoaux->chaves, i));
       	fprintf(arq, "\n");
        nodoaux = nodoaux->prox;
	}
}

int le_cifras(cifras *c, FILE *arq){
	int chave;
	char letra, aux;

	while(fscanf(arq, "%c:", &letra) != EOF){
		aux = fgetc(arq);
		while(aux != '\n'){
			fscanf(arq, "%d", &chave);
			aux = fgetc(arq);
			if(!(adiciona_chave(c, letra, chave)))
				return 0;
		}
	}
	return 1;
}

int faz_cifras(cifras *c, FILE *arq){
	int i = 0;
	char *palavra = malloc(sizeof(char)*SIZE);

    while(fscanf(arq, "%s", palavra) != EOF)
        if(!(adiciona_chave(c, palavra[0], i++)))
			return 0;

    free(palavra);
	return 1;
}

int adiciona_inicio_cifras(cifras *c, char letra, int posicao){
	nodo_cifras* novonodo;

	if(!(novonodo = malloc(sizeof(nodo_cifras))))
        return 0;
    novonodo->letra = letra;
    if(!(novonodo->chaves = cria_fila()))
		return 0;
    if(!(insere_fila(novonodo->chaves, posicao)))
		return 0;

	if(c->primeiro == NULL){
		c->primeiro = novonodo;
        c->primeiro->prox = NULL;
		return 1;
	}

	nodo_cifras* nodoaux = c->primeiro;
	c->primeiro = novonodo;
	c->primeiro->prox = nodoaux;
	return 1;
}

int adiciona_ordem_cifras(cifras *c, char letra, int posicao){
	if(c->primeiro == NULL || c->primeiro->letra > letra)
		return adiciona_inicio_cifras(c, letra, posicao);

	nodo_cifras *novonodo, *nodoaux = c->primeiro;

	if(!(novonodo = malloc(sizeof(nodo_cifras))))
		return 0;
    novonodo->letra = letra;     
    if(!(novonodo->chaves = cria_fila()))
		return 0;
    if(!(insere_fila(novonodo->chaves, posicao)))
		return 0;

    while(nodoaux->prox != NULL && (nodoaux->prox->letra < letra))
	    nodoaux = nodoaux->prox;		

    novonodo->prox = nodoaux->prox;
    nodoaux->prox = novonodo;
	return 1;
}

int adiciona_chave(cifras *c, char letra, int posicao){
    if(letra < 0)//caso a letra seja acentuada.
        return 1;

    nodo_cifras* nodoaux = c->primeiro;

    if(letra <='Z' && letra >= 'A')//transforma uma letra maiúscula em minúscula.
        letra = letra + 32;

    while(nodoaux != NULL && nodoaux->letra != letra)
        nodoaux = nodoaux->prox;

    if(nodoaux == NULL){
        if(!(adiciona_ordem_cifras(c, letra, posicao)))
			return 0;
	}else{
        if(!(insere_fila(nodoaux->chaves, posicao)))
			return 0;
	}

	return 1;
}
