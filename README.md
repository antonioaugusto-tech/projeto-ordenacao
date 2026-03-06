# Benchmark de Performance: Análise Multi-Linguagem (C vs C++)

Este projeto evoluiu para um estudo comparativo de performance, analisando como diferentes linguagens e algoritmos gerenciam o processamento de grandes volumes de dados.

##  Metodologia Experimental
O benchmark agora cobre duas frentes tecnológicas:
1. **Implementação em C:** Foco em alocação dinâmica manual (`malloc/free`) e algoritmos clássicos ($O(n^2)$ vs $O(n \log n)$).
2. **Implementação em C++:** Uso de **STL (Standard Template Library)**, containers dinâmicos (`std::vector`) e o algoritmo híbrido **Introsort** (`std::sort`).

### Diferenciais Técnicos:
- **Rigor Estatístico:** Múltiplas rodadas com cálculo de média aritmética.
- **Modernidade:** Uso de `std::chrono` para precisão de nanossegundos e `std::mt19937` para aleatoriedade de alta qualidade.
- **Data Pipeline:** Exportação de resultados para `.csv`, permitindo análise integrada de dados.

##  Resultados Médios (n = 30.000)
| Linguagem | Algoritmo | Complexidade | Tempo Médio |
| :--- | :--- | :--- | :--- |
| **C** | Bubble Sort | $O(n^2)$ | ~1.8700s |
| **C** | Quick Sort | $O(n \log n)$ | ~0.0020s |
| **C++** | std::sort (STL) | $O(n \log n)$ | ~0.0015s |

##  Tecnologias e Ambiente
- **Linguagens:** C (ISO C11) e C++ (ISO C++17)
- **Compilador:** GCC / G++
- **Ambiente:** Workstation Local (Ambiente Cross-platform)

---
**Autor:** Antonio Augusto - Estudante de Ciência de Dados (PUC Minas)