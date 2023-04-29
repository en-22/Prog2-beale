#include "cifras.h"
//Retorna um número aleatório da lista de chaves da letra
int codificaLetra(char letra, cifras *c);
//Codifica um arquivo a partir de uma lista cifras
void codifica_arq(cifras *c, FILE *original, FILE *codificada);
