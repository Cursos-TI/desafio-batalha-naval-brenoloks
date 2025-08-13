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

   int tamanhoTabuleiro = 5;
    int tamanhoNavio = 3;
    int tabuleiro[5][5];
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Inicializa tabuleiro com 0 (água)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 1, colunaHorizontal = 2;
    int linhaVertical = 2, colunaVertical = 0;

    // Verifica se cabem no tabuleiro
    if (colunaHorizontal + tamanhoNavio <= tamanhoTabuleiro &&
        linhaVertical + tamanhoNavio <= tamanhoTabuleiro) {

        // Verifica se não há sobreposição
        int sobrepoe = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0 ||
                tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                sobrepoe = 1;
                break;
            }
        }

        if (sobrepoe == 0) {
            // Posiciona navio horizontal
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }
            // Posiciona navio vertical
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
        } else {
            printf("Erro: os navios se sobrepoem!\n");
            return 1;
        }
    } else {
        printf("Erro: coordenadas invalidas!\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}