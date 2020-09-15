#include "UniaoBusca.h"

#include <stdio.h>
#include <stdlib.h>

void inicializa_uniao_busca(UniaoBusca *p, int l, int c){
    Lista sub;
    
    inicializa_lista( &p->m, sizeof(Lista) );
    
	p->lin = l;
	p->col = c;
}

void desaloca_uniao_busca(UniaoBusca *p){
	int i;
	Lista sub;
	for( i = 0 ; i < p->lin; i++){
		le_valor( p->m, &sub, i );
		desaloca_lista( &sub );
	}
	desaloca_lista( &p->m );
}

void mostra_uniao_busca(UniaoBusca x){
	int i, j, valor;
	Lista sub;
	printf("Dados da matriz:\n\n");
	for( i = 0 ; i < x.lin ; i++ ){
		le_valor( x.m, &sub, i );
		for( j = 0 ; j < x.col ; j++ ){
			le_valor( sub, &valor, j );
			printf("%4d ", valor);
		}
		printf("\n");
	}
	printf("_________________________________\n\n");
}

int le_valor_uniao_busca(UniaoBusca x, int i, int j, int *pValor){
	if(i >= x.lin || j >= x.col)
		return ERRO_COORDENADA_INVALIDA;
	
	Lista sub;
	le_valor( x.m, &sub, i );
	le_valor( sub, pValor, j );

	return 1; // Sucesso;
}

int cria_conjunto( UniaoBusca *conjunto, int info ) {
	
	
	
}

int uniao( UniaoBusca *u, Lista *x, Lista *y) {
	
}

int busca_conjunto(UniaoBusca *u, int info) {
	
}

