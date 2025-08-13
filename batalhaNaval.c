#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

   int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
    int tabuleiro[10][10];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==== POSICIONA ALGUNS NAVIOS (exemplo) ====
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[2][4 + i] = 3; // horizontal
        tabuleiro[5 + i][1] = 3; // vertical
    }
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[0 + i][0 + i] = 3; // diagonal ↘
        tabuleiro[0 + i][9 - i] = 3; // diagonal ↙
    }

    // ==== MATRIZES DE HABILIDADES ====
    int tamanhoHabilidade = 5; // todas serão 5x5

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // CONE (ponta no topo, abre em direção à base)
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (j >= (tamanhoHabilidade / 2 - i) && j <= (tamanhoHabilidade / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ (linha + coluna central)
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (i == tamanhoHabilidade / 2 || j == tamanhoHabilidade / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO (losango)
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (abs(i - tamanhoHabilidade / 2) + abs(j - tamanhoHabilidade / 2) <= tamanhoHabilidade / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ==== FUNÇÃO PARA SOBREPOR HABILIDADE ====
    void aplicarHabilidade(int origemLinha, int origemColuna, int habilidade[5][5]) {
        int offset = tamanhoHabilidade / 2;
        for (int i = 0; i < tamanhoHabilidade; i++) {
            for (int j = 0; j < tamanhoHabilidade; j++) {
                if (habilidade[i][j] == 1) {
                    int linhaTab = origemLinha + (i - offset);
                    int colunaTab = origemColuna + (j - offset);

                    // Garantir que não sai do tabuleiro
                    if (linhaTab >= 0 && linhaTab < tamanhoTabuleiro &&
                        colunaTab >= 0 && colunaTab < tamanhoTabuleiro) {
                        if (tabuleiro[linhaTab][colunaTab] == 0) {
                            tabuleiro[linhaTab][colunaTab] = 5; // marca habilidade
                        }
                    }
                }
            }
        }
    }

    // ==== POSICIONA AS HABILIDADES ====
    aplicarHabilidade(4, 4, cone);
    aplicarHabilidade(7, 2, cruz);
    aplicarHabilidade(6, 7, octaedro);

    // ==== EXIBIR TABULEIRO ====
    printf("Tabuleiro com Navios e Habilidades:\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // área de habilidade
            }
        }
        printf("\n");
    }

    return 0;
}