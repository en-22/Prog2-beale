#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libfile.h"

void testa_arq_r(FILE* arq, char *nome){
   	if(!arq){
   		printf("Erro ao abrir arquivo %s\n", nome);
   		exit (1) ;
   	}
}

void testa_arq_w(char *nome){
   	if(access(nome, F_OK) == 0){
      printf("Arquivo de escrita %s já existente\n", nome);
      exit (1) ;
   	}
}

void msg_erro(){
	printf("Formatação invalida\n");
	exit(1);
}

void msg_erro_cifras(){
	printf("Erro ao alocar cifras.\n");
	exit(1);
}

void teste_flag(int *flag){
	if(*flag > 0)
		msg_erro();
	*flag = *flag + 1;
}
