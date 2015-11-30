#include <stdlib.h>
#include <stdio.h>


void preencheMatriz(int M[9][9], int R[3][3]){
	int i, j;

	printf("Preencha a matriz M[9][9] e a R[3][3]\n");
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			scanf("%d", &M[i][j]);
		}
	}

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &R[i][j]);
		}
	}

}


void printaMatriz(int M[9][9], int R[3][3]){
	int i, j;

	printf("\n");

	printf("Matriz M:\n");
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Matriz R:\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Funcao auxiliar que percorre uma submatriz 3x3 da matriz M e vai
//comparando seus elementos com os elementos da matriz R.
//Se a submatriz for igual a matriz R retorna a posicao, senao -1.
int procuraRZeroZeroaux(int M[9][9], int R[3][3], int linIni, int colIni){
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
int procuraRZeroZero(int M[9][9], int R[3][3], int i, int j){
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
int achaR(int M[9][9], int R[3][3], int i, int j){
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
	int M[9][9], R[3][3];

	//preenche matrizes
	preencheMatriz(M, R);

	//mostra matrizes
	printaMatriz(M, R);

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
