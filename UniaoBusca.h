#include "Lista.h"

#define ERRO_INDICE_NAO_ENCONTRADO -1
#define ERRO_VALOR_JA_INSERIDO -2

typedef struct {
	Lista m;
} UniaoBusca;

void inicializa_uniao_busca(UniaoBusca *p);
int cria_conjunto(UniaoBusca *p, int info, int (*compara)(void*, void*));
void uniao_conjuntos(UniaoBusca *p, Lista *x, Lista *y);
int busca_conjunto(UniaoBusca *p, int *info, int (*compara)(void*, void*));
void mostra_conjuntos(UniaoBusca *p, void (*mostra)(void *));
void desaloca_uniao_busca(UniaoBusca *p);
