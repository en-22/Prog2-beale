#include "cifras.h"
//Decodifica um arquivo a partir de uma lista cifras
void decodifica_arq(cifras *c, FILE *codificada, FILE *decodificada);
//Retorna a letra correspondente ao número da chave dada
char decodificaLetra(int num, cifras *c);
