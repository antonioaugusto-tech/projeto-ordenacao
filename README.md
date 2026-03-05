# Benchmark de Algoritmos de Ordenação: C vs C++

Este projeto realiza uma análise comparativa de performance entre algoritmos de ordenação clássicos, explorando as diferenças entre complexidades quadráticas $O(n^2)$ e logarítmicas $O(n \log n)$. O objetivo é demonstrar como a escolha do algoritmo e a gestão de memória impactam diretamente a eficiência em Ciência de Dados.

## Resultados do Benchmark
Os testes foram executados num ambiente **Ambiente Windows (CPU i7)** processando uma massa de **30.000 elementos** gerados aleatoriamente.

| Algoritmo | Linguagem | Complexidade | Tempo Médio |
| :--- | :--- | :--- | :--- |
| **Bubble Sort** | C | $O(n^2)$ | ~1.8720s |
| **Quick Sort (Nativo)** | C | $O(n \log n)$ | ~0.0020s |
| **std::sort (STL)** | C++ | $O(n \log n)$ | ~0.0020s |

> **Conclusão:** O Quick Sort demonstrou ser aproximadamente **936 vezes mais rápido** que o Bubble Sort para este volume de dados.

## Tecnologias e Conceitos Aplicados

### Linguagem C
* **Alocação Dinâmica:** Uso de `malloc` e `free` para gestão manual de memória no Heap.
* **Ponteiros:** Manipulação de endereços e uso de funções *callback* para o `qsort`.
* **Arquitetura de Computadores:** Medição de ciclos de clock da CPU para análise de performance.

### Linguagem C++
* **STL (Standard Template Library):** Uso de containers dinâmicos (`std::vector`).
* **Abstração:** Implementação de algoritmos otimizados (`std::sort`) com foco em produtividade e segurança de memória.

## Estrutura do Repositório
* `main.c`: Implementação em C com foco em manipulação de baixo nível.
* `main.cpp`: Implementação em C++ utilizando recursos modernos da linguagem.

## Autor
**Antonio Augusto**
Estudante de Ciência de Dados (2º Período) na **PUC Minas**.
Interessado em Engenharia de Dados, Performance e Arquitetura de Sistemas.