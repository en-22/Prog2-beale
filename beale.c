#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libfila.h"
#include "libcifras.h"
#include "libcodificar.h"
#include "libdecodificar.h"
#include "libfile.h"
#include <getopt.h>
#include <time.h>

int main(int argc, char **argv){
	int option;
	char *arq_dest;
    FILE *livrocifra, *msgor, *msgcod, *arqchaves, *msgdecod;
	int flag_arqchaves = 0, flag_e = 0, flag_d = 0, flag_b = 0, flag_i = 0, flag_m = 0, flag_o = 0, flag_c = 0;
    opterr = 0;
	cifras* cifras = cria_cifras();
	srand(time(NULL));//Para a escolha aleatória das chaves na codificação.

	if(argc < 8 || argc > 11)
		msg_erro();

    while((option = getopt(argc, argv, ":edb:i:m:o:c:")) != -1)
			switch(option){
                case 'd':
					if(flag_e == 1)
						msg_erro();
					flag_d++;
					break;
                case 'e':	
					if(flag_d == 1)
						msg_erro();
					flag_e++;
					break;
				case 'b':
					teste_flag(&flag_b);
					livrocifra = fopen(optarg, "r");
					testa_arq_r(livrocifra, optarg);
                    if(!(faz_cifras(cifras, livrocifra)))
						msg_erro_cifras();
                    fclose(livrocifra);
					break;
				case 'm':
					teste_flag(&flag_m);
                    if(flag_d == 0){
						msgor = fopen(optarg, "r");
						testa_arq_r(msgor, optarg);
					}
                    else
						msg_erro();
					break;
				case 'o':
					teste_flag(&flag_o);
 	                arq_dest = optarg;
                    testa_arq_w(arq_dest);
					break;
				case 'c':
					teste_flag(&flag_c);

                    if(flag_d == 0){
					    flag_arqchaves = 1;
						testa_arq_w(optarg);
						arqchaves = fopen(optarg, "w");
                    }else{
						arqchaves = fopen(optarg, "r");
						testa_arq_r(arqchaves, optarg);      
                        if(!(le_cifras(cifras, arqchaves)))
							msg_erro_cifras();
					    fclose(arqchaves);
                    }
					break;
                case 'i':
					teste_flag(&flag_i);

                    if(flag_e == 0){
						msgcod = fopen(optarg, "r");
						testa_arq_r(msgcod, optarg);
					}
                    else
						msg_erro();
					break;
				case '?':
					msg_erro();
				default:
                    msg_erro();
		}
    if(flag_e == 1){
		msgcod = fopen(arq_dest, "w");
        if(flag_arqchaves == 1){
			escreve_cifras(cifras, arqchaves);
			fclose(arqchaves);
		}
        codifica_arq(cifras, msgor, msgcod);
		fclose(msgor);
		fclose(msgcod);
    }else if(flag_d == 1){
		msgdecod = fopen(arq_dest, "w");
        decodifica_arq(cifras, msgcod, msgdecod);
		fclose(msgcod);
		fclose(msgdecod);
    }else{
        msg_erro();
	}
	destroi_cifras(cifras);
	return 0;
}
