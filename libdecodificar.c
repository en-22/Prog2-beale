#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdecodificar.h"
#include "libfila.h"

void decodifica_arq(cifras *c, FILE *codificada, FILE *decodificada){
	int i;
    int flag = 0;
    char letra_decodificada;

	while(fscanf(codificada, "%d ", &i) != EOF){
        letra_decodificada = decodificaLetra(i, c);
        fprintf(decodificada, "%c", letra_decodificada);
        if(letra_decodificada == '?')
            flag = 1;
    }
    if(flag == 1)
        printf("Não foi possível decodificar algumas letras.\n");
}

char decodificaLetra(int num, cifras *c){
    nodo_cifras* nodoaux = c->primeiro;
	nodo_cifras* nodo = nodoaux->prox;

	if(nodoaux == NULL || num == -1)
		return ' ';

    if(num == -2)
        return '\n';

    if(num == -3)
        return '?';

    while(nodo != NULL && !pertence_fila(nodoaux->chaves, num)){
		nodoaux = nodo;
		nodo = nodo->prox;		
	}

    if(nodoaux == NULL || !pertence_fila(nodoaux->chaves, num))
        return ' ';

    return nodoaux->letra;
}

