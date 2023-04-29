#ifndef _fila_
#define _fila_
struct nodo_f{
    int elem;
    struct nodo_f *prox;
};
typedef struct nodo_f nodo_f_t;

struct fila{
    nodo_f_t *ini;
    nodo_f_t *fim;
    int tamanho;
};
typedef struct fila fila_t;

//Cria uma fila vazia e a retorna, se falhar retorna NULL.
fila_t *cria_fila ();
//Destroi a fila e devolve NULL.
fila_t *destroi_fila (fila_t *f);
//Retorna o numero de elementos da fila.
int tamanho_fila (fila_t *f);
//Insere um elemento na fila, em caso de sucesso, retorna 1, no contrário, retorna 0.
int insere_fila (fila_t *f, int elemento);
//Checa se um elemento pertence a fila, caso sim, retorna 1, caso não, retorna 0.
int pertence_fila(fila_t *f, int elemento);
//Retorna um elemento a partir de sua posição na fila.
int retorna_elemento_index(fila_t *f, int index);
//Retorna um elemento aleatório da fila.
int retorna_elemento_rand(fila_t *f);
//Imprime todos os elementos da fila, para depuração.
void imprime_fila (fila_t *f);
#endif //_fila_

