#include "UniaoBusca.h"

#include <stdio.h>
#include <stdlib.h>

void inicializa_uniao_busca(UniaoBusca *p) {
	
	inicializa_lista( &p->m, sizeof(Lista) );
}

int cria_conjunto(UniaoBusca *p, int info, int (*compara)(void*, void*)) {
	int i;
	
	Lista sub, aux;
	inicializa_lista( &sub, sizeof(Lista) );
	for(i=0; i<p->m.qtd; i++) {
		le_valor(p->m, &aux, i);
		if(busca(aux, &info, compara) != -1) {
			printf("VALOR JA ADICIONADO");
			return -1;
		}
	}
	
	insere_fim( &sub, &info );
	insere_fim( &p->m, &sub );
	
	return 1;
}
