# Benchmark de Performance: Análise Estatística de Algoritmos

Este projeto realiza uma análise comparativa entre algoritmos de ordenação ($O(n^2)$ vs $O(n \log n)$), aplicando rigor científico para medir o impacto da complexidade algorítmica no processamento de volumes massivos de dados.

## Metodologia Experimental
Diferente de testes simples, este benchmark utiliza:
- **Aostragem Estatística:** Execução de múltiplas rodadas para cálculo de tempo médio, eliminando variações aleatórias do processador.
- **Data Quality (Integridade):** Validação automática pós-processamento para garantir que o dataset foi ordenado corretamente.
- **Engenharia de Memória:** Alocação dinâmica no **Heap** para simular manipulação de Big Data sem sobrecarga da Stack.
- **Persistência de Dados:** Exportação automática dos resultados para arquivo `.csv` para análise em Python/Pandas.

## Resultados Médios (n = 30.000)
| Algoritmo | Complexidade | Tempo Médio |
| :--- | :--- | :--- |
| **Bubble Sort** | $O(n^2)$ | ~1.8700s |
| **Quick Sort** | $O(n \log n)$ | ~0.0020s |

**Conclusão:** O Quick Sort apresentou uma performance aproximadamente **900x superior**, validando a importância da escolha de estruturas de dados eficientes para escalabilidade.

## Tecnologias e Ambiente
- **Linguagem:** C (ISO C11)
- **Compilador:** GCC (GNU Compiler Collection)
- **Sistemas Operacionais:** macOS / Windows
- **Ferramentas:** VS Code & Git

---
**Autor:** Antonio Augusto - Estudante de Ciência de Dados (PUC Minas)