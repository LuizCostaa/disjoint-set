#include "Lista.h"

#define ERRO_COORDENADA_INVALIDA -1

typedef struct{
	Lista m;
	int lin, col;
} UniaoBusca;

void inicializa_uniao_busca(UniaoBusca *p, int l, int c);
void desaloca_uniao_busca(UniaoBusca *p);
void mostra_uniao_busca(UniaoBusca x);
int le_valor_uniao_busca(UniaoBusca x, int i, int j, int *pValor);
int cria_conjunto( UniaoBusca *conjunto, int info );
int uniao( UniaoBusca *u, Lista *x, Lista *y);
int busca_conjunto(UniaoBusca *u, int info);
