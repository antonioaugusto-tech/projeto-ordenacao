#include <iostream>
#include <vector>
#include <algorithm> // Para o std::sort
#include <ctime>     // Para o cronômetro

// Projeto: Benchmark de Performance em C++ (Ordenação de Alta Eficiência)
// Objetivo: Demonstrar o uso da STL (Standard Template Library) e containers dinâmicos.
// Autor: Antonio Augusto (Estudante de Ciência de Dados - PUC Minas)
using namespace std;

int main() {
    int n = 30000;

    // std::vector: Container dinâmico que gerencia automaticamente a alocação 
    // e desalocação de memória no Heap, reduzindo riscos de Memory Leaks.
    vector<int> dados;

    // Preenchendo o vetor (C++ gerencia a memória sozinho!)
    srand(time(0));
    for (int i = 0; i < n; i++) {
        // push_back: Método que insere elementos no final do vetor, 
        // redimensionando a capacidade do container de forma eficiente conforme necessário
        dados.push_back(rand() % 100000);
    }

    cout << "--- TESTE DE PERFORMANCE C++ ---" << endl;
    cout << "Ordenando " << n << " numeros com std::sort..." << endl;

    clock_t inicio = clock();
    
    // std::sort: Implementação híbrida (Introsort) altamente otimizada pela STL.
    // Possui complexidade garantida de O(n log n), superando implementações manuais em termos de segurança e velocidade.
    sort(dados.begin(), dados.end());
    
    clock_t fim = clock();

    // Cálculo do tempo total: Converte a diferença de ciclos de clock para segundos
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Concluido!" << endl;
    cout << "Tempo gasto no C++: " << tempo << " segundos." << endl;

    return 0;
}