
// Programa: programa para ordenação de um vetor

// Manipulação de tempo em c,c++
// Programa: programa que usa manipuladores de tempo para 
// medir o desempenho de algoritmos de ordenação


#include <cstdlib>   //qsort
#include  <time.h>   // clock(),time()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()


//Vetores usados pelos métodos de ordenação
int *vetorQuickSort;
int *vetorBubbleSort;
int tamanho;

//Função usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}

//Algoritmos de ordenação bubble sort
void bubbleSort(int *vetor, int tamanho) {
	int aux;
	for (int i = 0; i < tamanho-1; i++) {
		for (int j = 0; j < tamanho-1; j++) {
			if (vetor[j] > vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}


//Observe que os números são gerados aleatoriamente baseados
//em uma semente. Se for passado a mesma semente, os 
//números aleatórios serão os mesmos
void criarVetor(int tamanhoVetor, int semente){
	srand (semente);
	vetorQuickSort = new int[tamanhoVetor];
	vetorBubbleSort = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++){
		vetorQuickSort[i] =  rand()%100000;
        vetorBubbleSort[i] = vetorQuickSort[i]; // utilizar os mesmos valores
		//vetorBubbleSort[i] = rand()%100000;
	}
}

void ordenacaoFunction(int n){
	clock_t clock_1, clock_2, clock_3, clock_4;

	//Criar vetor com elementos aleatorios[0,100000] 
	criarVetor(n,23);

	clock_1 = clock();
	qsort (vetorQuickSort, n, sizeof(int), compare_ints);
	clock_2 = clock();

    printf("Tempo %d qsort: %f \n", n, (double)(clock_2-clock_1)/(double) CLOCKS_PER_SEC);

	//Ordenar utilizando bubleSort
	clock_3 = clock();
	bubbleSort(vetorBubbleSort,n);
	clock_4 = clock();

    printf("Tempo %d bubbleSort: %f \n", n, (double)(clock_4-clock_3)/(double) CLOCKS_PER_SEC);
}


int main (){
	ordenacaoFunction(1000);
	ordenacaoFunction(5000);
	ordenacaoFunction(10000);
	ordenacaoFunction(50000);
	ordenacaoFunction(100000);

	exit(0);
}


