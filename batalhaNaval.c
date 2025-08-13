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
    int navio[3] = {3, 3, 3}; // Todos os navios iguais (3 representa parte do navio)

    // 1️⃣ Inicializa tabuleiro com água (0)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Função simples para verificar se cabe e não sobrepõe
    int podePosicionar(int linha, int coluna, int direcaoLinha, int direcaoColuna) {
        for (int i = 0; i < tamanhoNavio; i++) {
            int novaLinha = linha + i * direcaoLinha;
            int novaColuna = coluna + i * direcaoColuna;

            // Fora dos limites
            if (novaLinha < 0 || novaLinha >= tamanhoTabuleiro ||
                novaColuna < 0 || novaColuna >= tamanhoTabuleiro) {
                return 0;
            }
            // Já tem navio
            if (tabuleiro[novaLinha][novaColuna] != 0) {
                return 0;
            }
        }
        return 1;
    }

    // Função para posicionar navio
    void posicionar(int linha, int coluna, int direcaoLinha, int direcaoColuna) {
        for (int i = 0; i < tamanhoNavio; i++) {
            int novaLinha = linha + i * direcaoLinha;
            int novaColuna = coluna + i * direcaoColuna;
            tabuleiro[novaLinha][novaColuna] = 3;
        }
    }

    // 2️⃣ Definir coordenadas e direções
    // Horizontal (direção 0,1)
    if (podePosicionar(2, 4, 0, 1)) {
        posicionar(2, 4, 0, 1);
    }

    // Vertical (direção 1,0)
    if (podePosicionar(5, 1, 1, 0)) {
        posicionar(5, 1, 1, 0);
    }

    // Diagonal ↘ (direção 1,1)
    if (podePosicionar(0, 0, 1, 1)) {
        posicionar(0, 0, 1, 1);
    }

    // Diagonal ↙ (direção 1,-1)
    if (podePosicionar(0, 9, 1, -1)) {
        posicionar(0, 9, 1, -1);
    }

    // 3️⃣ Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}