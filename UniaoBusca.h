#include "Lista.h"

typedef struct {
	Lista m;
} UniaoBusca;

void inicializa_uniao_busca(UniaoBusca *p);
int cria_conjunto(UniaoBusca *p, int info, int (*compara)(void*, void*));
