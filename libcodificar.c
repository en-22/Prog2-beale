#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcodificar.h"
#include "libfila.h"

int codificaLetra(char letra, cifras *c){
    nodo_cifras* nodoaux = c->primeiro;
	nodo_cifras* nodo = nodoaux->prox;

    if(nodoaux == NULL || letra == ' ')
		return -1;

	if(letra <='Z' && letra >= 'A')
        letra = letra + 32; 

	while(nodo != NULL && (nodoaux->letra < letra)){
		nodoaux = nodo;
		nodo = nodo->prox;		
	}
    
    if(nodoaux == NULL || nodoaux->letra != letra)
        return -3;
    return retorna_elemento_rand(nodoaux->chaves);
}

void codifica_arq(cifras *c, FILE *original, FILE *codificada){
	char letra, letra_codificada;
    int flag = 0;

	while(fscanf(original, "%c", &letra) != EOF){
		if(letra == '\n')
			fprintf(codificada, "%s", "-2 ");
		else{
            if(letra < 0){
                fscanf(original, "%c", &letra);// e se for o fim do arquivo.?
                flag = 1;
                }
            letra_codificada = codificaLetra(letra, c);
            fprintf(codificada, "%d ", codificaLetra(letra, c));
            if(letra_codificada == -3)
                flag = 1;
        }
    }
    if(flag == 1)
        printf("Não foi possível codificar algumas letras.\n");
}
