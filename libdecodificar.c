#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdecodificar.h"
#include "libfila.h"

char decodificaLetra(int num, cifras *c){
	if(num == -1)
		return ' ';

    if(num == -2)
        return '\n';
    
    nodo_cifras* nodoaux = c->primeiro;

    if(nodoaux == NULL || num == -3)
        return '?';

    while(nodoaux->prox != NULL && !pertence_fila(nodoaux->chaves, num))
		nodoaux = nodoaux->prox;

    if(nodoaux == NULL || !pertence_fila(nodoaux->chaves, num))
        return ' ';

    return nodoaux->letra;
}

void decodifica_arq(cifras *c, FILE *codificada, FILE *decodificada){
	int i, flag = 0;
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

