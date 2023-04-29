//Testa se um arquivo de leitura existe, caso não, imprime uma mensagem de erro e termina o programa.
void testa_arq_r(FILE* arq, char *nome);
//Testa se um arquivo de escrita existe, caso sim, imprime uma mensagem de erro e termina o programa.
void testa_arq_w(char *nome);
//Imprime uma mensagem de erro em relação a formatação da linha de execução e termina o programa.
void msg_erro();
//Imprime uma mensagem de erro em relação a alocação de memória das cifras e termina o programa.
void msg_erro_cifras();
//Testa se o valor de uma flag é maior que zero, significando que ela ja foi utilizada, caso seja, imprime uma mensagem de erro e termina o programa. Caso contrário, adiciona um ao valor da flag. As flags devem ser inicializadas em zero no programa principal.
void teste_flag(int *flag);

