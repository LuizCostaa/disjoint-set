#include "UniaoBusca.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_int( void *x ) {
	printf("%d\n", *(int *)x );
}

void inicializa_uniao_busca(UniaoBusca *p) {
	
	inicializa_lista( &p->m, sizeof(Lista) );
}

int cria_conjunto(UniaoBusca *p, int info, int (*compara)(void*, void*)) {
	int i;
	
	Lista sub, aux;
	inicializa_lista( &sub, sizeof(Lista) );
	
	if(busca_conjunto(p, &info, compara) != -1) {
		return ERRO_VALOR_JA_INSERIDO;
	}
	
	insere_fim( &sub, &info );
	insere_fim( &p->m, &sub );
	
	return 1;
}

void uniao_conjuntos(UniaoBusca *p, int a, int b) {
	Lista aux_a, aux_b, aux_return;
	
	le_valor(p->m, &aux_a, a);
	le_valor(p->m, &aux_b, b);
		
	concatena(&aux_a, &aux_b);
	
	insere_fim(&p->m, &aux_a);
	
	remove_pos(&p->m, &aux_a, a);
	remove_pos(&p->m, &aux_b, b-1);	
}

int busca_conjunto(UniaoBusca *p, int *info, int (*compara)(void*, void*)) {
	int i;
	Lista aux;
	
	for(i=0; i<p->m.qtd; i++) {
		le_valor(p->m, &aux, i);
		if(busca(aux, info, compara) != -1) {
			return i;
		}
	}
	
	return ERRO_INDICE_NAO_ENCONTRADO;
}

void mostra_conjuntos(UniaoBusca *p, void (*mostra)(void *)) {
	int k;
	Lista aux;
	
	printf("/* DADOS DO CONJUNTO */ \n");
	for(k=0; k<p->m.qtd; k++){
		le_valor(p->m, &aux, k);
		Elemento *p;
		int i;
		for( p = aux.cabeca, i = 0 ; p != NULL ; p = p->proximo, i++ ){
			mostra( p->info ); // Invocação por callback
		}
		printf("\n");
	}
	printf("\n\n");
		
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




