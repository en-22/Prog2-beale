#include "libcifras.h"
//Retorna a letra correspondente na lista cifras ao número da chave dada.
char decodificaLetra(int num, cifras *c);
//Decodifica um arquivo a partir de uma lista cifras. Os '-1' viram espaços, os '-2' viram \n, e os '-3', simbolizando letras fora da lista, viram '?'.
void decodifica_arq(cifras *c, FILE *codificada, FILE *decodificada);
