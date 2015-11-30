#include <stdlib.h>
#include <stdio.h>


int **criaMatriz(int **matriz, int tam){
	int i, j;

	//cria a matriz
	matriz = (int**) malloc(tam*sizeof(int*));

	for(i = 0; i < tam; i++){
		matriz[i] = (int*) malloc(tam*sizeof(int));
	}


	//preenche a matriz
	if(tam == 9){									//caso seja matriz M
		printf("Preencha a matriz\n");
		
		for(i = 0; i < tam; i++){
			for(j = 0; j < tam; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
	
	} else if(tam == 3){								//caso seja matriz R
		for(i = 0; i < tam; i++){
			for(j = 0; j < tam; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
	}

	return matriz;
}


void printaMatriz(int **matriz, int tam){
	int i, j;

	printf("\n");
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Funcao auxiliar que percorre uma submatriz 3x3 da matriz M e vai
//comparando seus elementos com os elementos da matriz R.
//Se a submatriz for igual a matriz R retorna a posicao, senao -1.
int procuraRZeroZeroaux(int **M, int **R, int linIni, int colIni){
	int linR=0, colR=0, linM, colM, result;

	for(linM = linIni; linM < linIni+3; linM++){
		colR=0;

		for(colM = colIni; colM < colIni+3; colM++){

			if(M[linM][colM] != R[linR][colR]){
				return -1;
			}

			colR++;
		}

		linR++;
	}

	result = (10*linIni)+colIni;

	return result;
}


//Percorre a matriz M procurando uma posiçao que o conteudo seja igual
//ao conteudo do primeiro elemento da matriz R. Se achado esse elemento
//entao eh chamada a funcao auxiliar.
//Retorna 0 se não achou sumatriz igual a matriz R, senao retorna a posicao.
int procuraRZeroZero(int **M, int **R, int i, int j){
	int linha, coluna, result;

	for(linha = i; linha < 7; linha++){
		for(coluna = j; coluna < 7; coluna++){
			
			if(M[linha][coluna] == R[0][0]){

				result = procuraRZeroZeroaux(M, R, linha, coluna);

				if(result != -1){
					return result;
				}
			}

		}
	}

	return 0;
}


//Utilizada a funcao procuraRZeroZeroaux para conferir se no local indicado
//tem uma matriz R
int achaR(int **M, int **R, int i, int j){
	int result;

	result = procuraRZeroZeroaux(M, R, i, j);

	if(result == -1){
		printf("Nao tem uma matriz R aqui! :( \n");
		return 0;
	}

	printf("olha so! Tem uma matriz R aqui. :D \n");
	return 1;
}


int main(){
	int i, j, pos, achaRreturn;
	int **M = NULL;
	int **R = NULL;

	//cria matrizes
	M = criaMatriz(M, 9);
	R = criaMatriz(R, 3);

	//mostra matrizes
	printf("Matriz M: ");
	printaMatriz(M, 9);
	printf("Matriz R: ");
	printaMatriz(R, 3);

	//le a posicao inicial da analise
	printf("\nInsira i e j do ponto inicial de busca: ");
	scanf("%d %d", &i, &j);
	
	//faz a procura
	pos = procuraRZeroZero(M, R, i, j);

	//faz o calcula da posicao e mostra
	j = pos%10;
	i = (pos - j)/10;
	printf("pos: %d   i:%d   j:%d\n", pos, i, j);


	//acha R
	printf("\nInsira i e j para conferir R: ");
	scanf("%d %d", &i, &j);
	achaRreturn = achaR(M, R, i, j);

	return 0;
}
