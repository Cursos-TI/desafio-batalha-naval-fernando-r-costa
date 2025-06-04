#include <stdio.h>

int main() {
    int linhas_tabuleiro = 10;
    int colunas_tabuleiro = 10;
    int tabuleiro[linhas_tabuleiro][colunas_tabuleiro];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < linhas_tabuleiro; i++) {
        for (int j = 0; j < colunas_tabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Imprime o cabeçalho com letras
    printf("   ");
    for (int j = 0; j < colunas_tabuleiro; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Imprime as linhas com números
    for (int i = 0; i < linhas_tabuleiro; i++) {
        printf("%-2d  ", i + 1);
        for (int j = 0; j < colunas_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
