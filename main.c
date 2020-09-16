#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "MatrizDinamica_Lista.h"
#include "UniaoBusca.h"

// Alunos: John Eric Jahn && Luiz Guilherme

void mostra_inteiro( void *x ) {
	printf("%d ", *(int *)x + 1 );
}

int compara_inteiro( void *x, void* y ) {
	int *a = x, *b = y;
	
	if ( *a > *b )
		return 1;
	
	if ( *a < *b )
		return -1;
		
	return 0;
}


int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	MatrizDinamica_Lista matrizAjacencia;
	UniaoBusca uniao_busca;
	FILE *file;
	int tam, i, j, x, y;
	
	printf("           *DISJOINT-SET*            \n\n");
	
	file = fopen("grafos.txt", "r");
	
	if(file == NULL) {
		printf("Arquivo nao pode ser aberto\n");
		return 0;
	}
	
	fscanf(file, "%d", &tam);
	
	if(tam < 1) {		
		printf("O TAMANHO DA MATRIZ (1ª LINHA DO ARQUIVO) DEVE SER MAIOR QUE 0");
		exit(0);
	}
			
	inicializa_matriz(&matrizAjacencia, tam, tam);
	
	for(i=0; i<tam; i++) {
		for(j=0; j<tam; j++) {
			int valorCelula;
			fscanf(file, "%d", &valorCelula);
			if(valorCelula == 1) {
				modifica_valor_matriz(&matrizAjacencia, i, j, valorCelula);
			}
		}
	}
	
	mostra_matriz(matrizAjacencia);
	
	inicializa_uniao_busca(&uniao_busca);
	for(x=0; x<matrizAjacencia.lin; x++){
		cria_conjunto(&uniao_busca, x, compara_inteiro);
	}
	
	
	for(x=0; x<matrizAjacencia.lin; x++){
		for(y=0; y<matrizAjacencia.col; y++) {
			int aux;
			le_valor_matriz(matrizAjacencia, x, y, &aux);
			if(aux == 1) {
				int ret_x, ret_y;
				ret_x = busca_conjunto(&uniao_busca, &x, compara_inteiro);
				ret_y = busca_conjunto(&uniao_busca, &y, compara_inteiro);
				if(ret_x != ret_y) {
					uniao_conjuntos(&uniao_busca, x, y, compara_inteiro);
				}
			}
		}
	}
				
	mostra_conjuntos(&uniao_busca, mostra_inteiro);
	
	desaloca_matriz(&matrizAjacencia);
	desaloca_uniao_busca(&uniao_busca);	

	return 0;
}
