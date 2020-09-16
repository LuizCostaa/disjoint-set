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

void uniao_conjuntos(UniaoBusca *p, Lista *x, Lista *y) {
	
}

int busca_conjunto(UniaoBusca *p, int *info) {
	
}

void mostra_conjuntos(UniaoBusca *p, void (*mostra)(void *)) {
		
}

void desaloca_uniao_busca(UniaoBusca *p) {
	int i;
	Lista sub;
	for(i=0; i < p->m.qtd; i++) {
		le_valor(p->m, &sub, i);
		desaloca_lista(&sub);
	}
	desaloca_lista(&p->m);	
}




