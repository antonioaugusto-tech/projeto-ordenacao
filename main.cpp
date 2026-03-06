#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include <numeric>

using namespace std;

// VALIDAÇÃO: Garante a integridade do processo de ordenação
bool estaOrdenado(const vector<int>& v) {
    return adjacent_find(v.begin(), v.end(), greater<int>()) == v.end();
}

int main() {
    const int n = 30000;
    const int rodadas = 5; // Amostragem para análise estatística
    vector<double> tempos;

    // Motor de aleatoriedade moderno (Mersenne Twister)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);

    cout << "--- BENCHMARK C++ (MODERN STL) ---" << endl;
    cout << "Dataset: " << n << " elementos | Amostras: " << rodadas << endl << endl;

    for (int r = 1; r <= rodadas; r++) {
        vector<int> dados;
        dados.reserve(n); // Otimização de memória: evita reallocs

        for (int i = 0; i < n; i++) {
            dados.push_back(dis(gen));
        }

        // Medição com precisão de nanosegundos
        auto inicio = chrono::high_resolution_clock::now();
        
        // std::sort: Otimizado (Introsort)
        sort(dados.begin(), dados.end());
        
        auto fim = chrono::high_resolution_clock::now();
        
        chrono::duration<double> diff = fim - inicio;
        tempos.push_back(diff.count());

        if (estaOrdenado(dados)) {
            cout << "Rodada " << r << ": " << diff.count() << " segundos [OK]" << endl;
        }
    }

    // Cálculos Estatísticos
    double soma = accumulate(tempos.begin(), tempos.end(), 0.0);
    double media = soma / rodadas;

    cout << "\n--- RESULTADO FINAL ---" << endl;
    cout << "Media de execucao: " << media << " segundos" << endl;

    // Persistência para Análise de Dados
    ofstream arquivo("benchmark_cpp.csv");
    arquivo << "Linguagem,MediaTempo\n";
    arquivo << "C++, " << media << "\n";
    arquivo.close();

    cout << "\n[Dados exportados para benchmark_cpp.csv]" << endl;

    return 0;
}