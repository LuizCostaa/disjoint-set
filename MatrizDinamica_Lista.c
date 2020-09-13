#include "MatrizDinamica_Lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_matriz(MatrizDinamica_Lista *p, int l, int c){
    int i, j;
    Lista sub;
    
    inicializa_lista( &p->m, sizeof(Lista) );
    for( i=0 ; i < l ; i++ ){
    	inicializa_lista( &sub, sizeof(int) );	
		for( j = 0 ; j < c; j++ ){
			int valor = 0;
			insere_fim( &sub, &valor );
		}
		insere_fim( &p->m, &sub );
	}
    
	p->lin = l;
	p->col = c;
}

void desaloca_matriz(MatrizDinamica_Lista *p){
	int i;
	Lista sub;
	for( i = 0 ; i < p->lin; i++){
		le_valor( p->m, &sub, i );
		desaloca_lista( &sub );
	}
	desaloca_lista( &p->m );
}

void mostra_matriz(MatrizDinamica_Lista x){
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

int modifica_valor_matriz(MatrizDinamica_Lista *p, int i, int j, int valor){
	if(i >= p->lin || j >= p->col)
		return ERRO_COORDENADA_INVALIDA;
	
	Lista sub;
	le_valor( p->m, &sub, i );
	modifica_valor( sub, &valor, j );

	return 1; // Sucesso;
}

int le_valor_matriz(MatrizDinamica_Lista x, int i, int j, int *pValor){
	if(i >= x.lin || j >= x.col)
		return ERRO_COORDENADA_INVALIDA;
	
	Lista sub;
	le_valor( x.m, &sub, i );
	le_valor( sub, pValor, j );

	return 1; // Sucesso;
}

int compara_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y){
	if(x.lin != y.lin || x.col != y.col)
		return 0;

	Lista sub1, sub2;
	int valor1, valor2;
	
	int i, j;
	for(i=0; i<x.lin; i++){
		le_valor( x.m, &sub1, i );
		le_valor( y.m, &sub2, i );
	
		for(j=0; j<x.col; j++){
			le_valor( sub1, &valor1, j );
			le_valor( sub2, &valor2, j );		
			if(valor1 != valor2)
				return 0;
		}
	}
	return 1;
}

int soma_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y, MatrizDinamica_Lista *p){
	if(x.lin != y.lin || x.col != y.col)
		return ERRO_MATRIZES_INCOMPATIVEIS;
	
	inicializa_matriz(p, x.lin, x.col);
	int i, j;
	
	Lista sub1, sub2;
	int valor1, valor2;
	
	for(i=0; i<x.lin; i++){
		le_valor( x.m, &sub1, i );
		le_valor( y.m, &sub2, i );
		for(j=0; j<x.col; j++){
			le_valor( sub1, &valor1, j );
			le_valor( sub2, &valor2, j );
			modifica_valor_matriz( p, i, j, valor1 + valor2 );
		}
	}
	return 1; // Sucesso.
}

int multiplica_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y, MatrizDinamica_Lista *p){
	if(x.col != y.lin) // num. de colunas de x deve ser igual a num, de linhas de y!
		return ERRO_MATRIZES_INCOMPATIVEIS;
		
	inicializa_matriz(p, x.lin, y.col);
	int i, j, k;
	Lista sub1, sub2;
	int valor1, valor2;
	
	for(i=0; i<x.lin; i++){
		le_valor( x.m, &sub1, i );
		for(j=0; j<x.col; j++){
			int soma = 0;
			for(k=0; k<x.col; k++){
				le_valor( sub1, &valor1, k );
				le_valor( y.m, &sub2, k );
				le_valor( sub2, &valor2, j );
				soma += valor1 * valor2;
			}
			modifica_valor_matriz( p, i, j, soma );
		}
	}
	return 1;	
}



