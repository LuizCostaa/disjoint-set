#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "MatrizDinamica_Lista.h"

// Alunos: John Eric Jahn && Luiz Guilherme

void mostra_float( void *x ) {
	printf("%.2f\n", *(float *)x );
}


int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	MatrizDinamica_Lista m1;
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
		printf("O TAMANHO DA MATRIZ (1ª LINHA DO ARQUIVO) DEVE SER MAIOR QUE 0");
		exit(0);
	}
			
	inicializa_matriz(&m1, tam, tam);
	
	for(i=0; i<tam; i++) {
		for(j=0; j<tam; j++) {
			int valorCelula;
			fscanf(file, "%d", &valorCelula);
			if(valorCelula == 1) {
				modifica_valor_matriz(&m1, i, j, valorCelula);
			}
		}
	}
	
	mostra_matriz(m1);
	desaloca_matriz(&m1);

	return 0;
}
