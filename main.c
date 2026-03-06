#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/** * VALIDACAO DE INTEGRIDADE:
 * Em Data Science, a limpeza e validacao dos dados (Data Quality) e fundamental.
 * Esta funcao garante que o algoritmo realmente entregou o dado ordenado antes da medicao.
 */
bool estaOrdenado(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

/** * GERACAO DE MASSA DE DADOS (DATASET):
 * Criamos um dataset sintetico de inteiros aleatorios para simular 
 * cenarios reais de processamento de Big Data.
 */
void gerarDados(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

/** * CALLBACK DE COMPARACAO:
 * Necessario para o algoritmo QuickSort nativo. Implementa a logica de precedencia
 * para tipos de dados especificos (neste caso, inteiros).
 */
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// BUBBLE SORT: Exemplo classico de algoritmo O(n^2). 
// Ineficiente para grandes escalas devido ao crescimento quadratico do tempo.
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 30000;          // Volume da amostra (Sample Size)
    int repeticoes = 3;     // Amostragem estatistica para calculo de media
    srand(time(NULL));      // Inicializacao da semente para aleatoriedade real

    // ALOCACAO NO HEAP:
    // Pratica essencial em Engenharia de Dados para evitar o estouro da Stack (Stack Overflow)
    // ao lidar com arrays massivos que nao caberiam na memoria de execucao rapida.
    int *dados1 = (int *)malloc(n * sizeof(int));
    int *dados2 = (int *)malloc(n * sizeof(int));

    if (dados1 == NULL || dados2 == NULL) {
        printf("Falha critica: Memoria insuficiente no sistema.\n");
        return 1;
    }

    double somaBubble = 0, somaQuick = 0;

    printf("--- EXPERIMENTO CIENTIFICO DE PERFORMANCE ---\n");
    printf("Amostra: %d elementos | Repeticoes: %d\n\n", n, repeticoes);

    for (int r = 1; r <= repeticoes; r++) {
        gerarDados(dados1, n);
        // Garantimos que ambos os algoritmos enfrentem exatamente o mesmo desafio (Bias Control)
        for(int i=0; i<n; i++) dados2[i] = dados1[i];

        printf("Execucao %d: ", r);

        // BENCHMARK BUBBLE SORT (Baseline Ineficiente)
        clock_t inicio = clock();
        bubbleSort(dados1, n);
        clock_t fim = clock();
        double tB = (double)(fim - inicio) / CLOCKS_PER_SEC;
        somaBubble += tB;

        // BENCHMARK QUICK SORT (Baseline Eficiente)
        inicio = clock();
        qsort(dados2, n, sizeof(int), comparar);
        fim = clock();
        double tQ = (double)(fim - inicio) / CLOCKS_PER_SEC;
        somaQuick += tQ;

        printf("Bubble: %.4fs | Quick: %.4fs\n", tB, tQ);
        
        // DATA VALIDATION: Verificacao de sucesso da operacao
        if (!estaOrdenado(dados1, n) || !estaOrdenado(dados2, n)) {
            printf("ERRO DE INTEGRIDADE: Dados nao ordenados.\n");
            return 1;
        }
    }

    // ANALISE ESTATISTICA: Calculo de Medias Aritmeticas
    double mediaB = somaBubble / repeticoes;
    double mediaQ = somaQuick / repeticoes;

    printf("\n--- RESULTADO FINAL (MEDIAS ESTATISTICAS) ---\n");
    printf("Media Bubble Sort: %.4f segundos\n", mediaB);
    printf("Media Quick Sort:  %.4f segundos\n", mediaQ);
    printf("Fator de Ganho: %.0fx de performance\n", mediaB / mediaQ);

    // PERSISTENCIA DE DADOS:
    // Exportamos para CSV para que o Cientista possa analisar em Python (Pandas/Matplotlib)
    FILE *f = fopen("resultados_benchmark.csv", "w");
    fprintf(f, "Algoritmo,TempoMedio\n");
    fprintf(f, "BubbleSort,%.4f\n", mediaB);
    fprintf(f, "QuickSort,%.4f\n", mediaQ);
    fclose(f);

    printf("\n[Output: resultados_benchmark.csv gerado com sucesso]\n");

    // GESTAO DE RECURSOS: Libera memoria para evitar Memory Leaks
    free(dados1);
    free(dados2);
    return 0;
}