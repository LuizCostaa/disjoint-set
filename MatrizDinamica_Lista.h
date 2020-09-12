#include "Lista.h"

#define ERRO_COORDENADA_INVALIDA -1
#define ERRO_MATRIZES_INCOMPATIVEIS -2

typedef struct{
	Lista m;
	int lin, col;
} MatrizDinamica_Lista;

void inicializa_matriz(MatrizDinamica_Lista *p, int l, int c);
void desaloca_matriz(MatrizDinamica_Lista *p);
void mostra_matriz(MatrizDinamica_Lista x);
int modifica_valor_matriz(MatrizDinamica_Lista *p, int i, int j, int valor);
int le_valor_matriz(MatrizDinamica_Lista x, int i, int j, int *pValor);
int compara_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y);
int soma_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y, MatrizDinamica_Lista *p);
int multiplica_matrizes(MatrizDinamica_Lista x, MatrizDinamica_Lista y, MatrizDinamica_Lista *p);

