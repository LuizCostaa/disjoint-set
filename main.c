#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "MatrizDinamica_Lista.h"

// Alunos: John Eric Jahn && Luiz Guilherme

void mostra_inteiro( void *x ) {
	printf("%d\n", *(int *)x );
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
	
	MatrizDinamica_Lista matrizAjacencia, UniaoBusca;
	FILE *file;
	int tam, i, j;
	
	printf("           *DISJOINT-SET*            \n\n");
	
	file = fopen("grafos.txt", "r");
	
	if(file == NULL) {
		printf("Arquivo nao pode ser aberto\n");
		return 0;
	}
	
	fscanf(file, "%d", &tam);
	
	if(tam < 1) {		
		printf("O TAMANHO DA MATRIZ (1� LINHA DO ARQUIVO) DEVE SER MAIOR QUE 0");
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
	
	inicializa_uniao_busca(&UniaoBusca);
	
	int x;
	for(x=0; x<matrizAjacencia.lin; x++){
		cria_conjunto(&UniaoBusca, x, compara_inteiro);
	}	
	
	
	int k;
	Lista teste;
	
	for(k=0; k<UniaoBusca.m.qtd; k++){
		le_valor(UniaoBusca.m, &teste, k);
		mostra_lista_v2(teste, mostra_inteiro);
	}
	
	//le_valor(UniaoBusca.m, &teste, 2;
	//mostra_lista(teste, mostra_inteiro);
	
	//mostra_matriz(UniaoBusca);
	mostra_matriz(matrizAjacencia);
	desaloca_matriz(&matrizAjacencia);

	return 0;
}
