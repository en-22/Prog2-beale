#include "libcifras.h"
//Retorna um número aleatório da lista de chaves da letra na lista cifras.
int codificaLetra(char letra, cifras *c);
//Codifica um arquivo. A codificação das letras é feita a partir da lista cifras, espaços são simbolizados com '-1', \n com '-2' e letras não presentes na lista cifras com '-3'.
void codifica_arq(cifras *c, FILE *original, FILE *codificada);

