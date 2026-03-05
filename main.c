#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
// Projeto: Benchmark de Algoritmos de Ordenação para Grandes Volumes de Dados
// Objetivo: Analisar a eficiência entre O(n²) e O(n log n) em ambiente Windows
// Autor: Antonio Augusto (Estudante de Ciência de Dados segundo periodo - PUC Minas)

// Algoritmo Bubble Sort: Complexidade O(n²).
//Realiza comparações sucessivas entre elementos vizinhos e trocas (swaps).
//Embora simples, é ineficiente para Big Data devido ao crescimento quadrático do tempo de processamento em relação ao volume de dados.
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Função Callback para o QuickSort (qsort):
//Utiliza ponteiros genéricos (void*) para garantir flexibilidade, realizando o 'typecasting' para inteiros. 
//O retorno baseado na subtração (a - b) define a precedência dos elementos, resultando em uma ordenação crescente.
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 30000;

    // Alocação dinâmica de memória no HEAP: 
   // Essencial para lidar com grandes volumes de dados (Big Data) sem sobrecarregar a Stack do sistema.
    int *dados1 = (int *)malloc(n * sizeof(int));
    int *dados2 = (int *)malloc(n * sizeof(int));

    // Verificação de segurança: Garante que o sistema operacional concedeu o espaço na memória.
    // Se o malloc retornar NULL, o programa encerra com erro para evitar falha de segmentação.
    if (dados1 == NULL || dados2 == NULL) {
        printf("Erro: Memoria insuficiente no sistema.\n");
        return 1;
    }

    // Semente baseada no clock do sistema (time):
   // Garante que a massa de dados seja diferente a cada execução, tornando o benchmark imparcial.
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 100000;
        dados1[i] = num;
        dados2[i] = num; // Mantém a massa de dados idêntica para um benchmark justo entre os algoritmos.
    }

    printf("--- DESAFIO DE PERFORMANCE ---\n");
    printf("Processando %d elementos...\n\n", n);

    // TESTE 1: BUBBLE SORT
    // Captura o ciclo de clock atual do processador antes de iniciar a execução do algoritmo.
    clock_t inicio = clock();
    bubbleSort(dados1, n);
    clock_t fim = clock();
    double tempoBubble = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("1. Bubble Sort: %.4f segundos\n", tempoBubble);

    // TESTE 2: QUICK SORT (Nativo)
    inicio = clock();
    qsort(dados2, n, sizeof(int), comparar);
    fim = clock();
    double tempoQuick = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("2. Quick Sort:  %.4f segundos\n", tempoQuick);

    printf("\nO Quick Sort foi %.0f vezes mais rapido!\n", tempoBubble / tempoQuick);

    free(dados1);
    free(dados2);
    return 0;
}