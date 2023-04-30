#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"

fila_t * cria_fila(){
	fila_t* fila;	
	if(!(fila = malloc(sizeof(fila_t))))
		return NULL;
	fila->tamanho = 0;
	return fila;
}

fila_t * destroi_fila (fila_t *f){
	nodo_f_t* nodoaux;

	for(int i = 0; i < f->tamanho; i++){
        nodoaux = f->ini;
		f->ini = nodoaux->prox;
		free(nodoaux);
	}
	free(f);
	return NULL;
}

int tamanho_fila(fila_t *f){
	return f->tamanho;
}

int insere_fila(fila_t *f, int elemento){
	nodo_f_t* novonodo;

	if(!(novonodo = malloc(sizeof(nodo_f_t))))
        return 0;
    novonodo->elem = elemento;

	if(f->tamanho == 0){       
		f->ini = novonodo;
		f->fim = novonodo;
		f->tamanho++;
		return 1;
	}

    (f->fim)->prox = novonodo;
    f->fim = novonodo;
    f->tamanho++;
	return 1;
}

int pertence_fila(fila_t *f, int elemento){
    nodo_f_t* nodoaux = f->ini;

	for(int i = 0; i < f->tamanho; i++){
        if(nodoaux->elem == elemento)
           return 1; 
		nodoaux = nodoaux->prox;
	}
	return 0;
}

int retorna_elemento_rand(fila_t *f){
    nodo_f_t* nodoaux = f->ini;

    for(int i = 0; i < (rand() % f->tamanho); i++){
        nodoaux = nodoaux->prox;
    }
    return nodoaux->elem;
}

int retorna_elemento_index(fila_t *f, int index){
    nodo_f_t* nodoaux = f->ini;

    for(int i = 0; i < index; i++){
        nodoaux = nodoaux->prox;
    }
    return nodoaux->elem;
}

void imprime_fila(fila_t *f){
    nodo_f_t* nodoaux = f->ini;

	for(int i = 0; i < f->tamanho; i++){
		printf(" %d", nodoaux->elem);
        nodoaux = nodoaux->prox;
	}
}
