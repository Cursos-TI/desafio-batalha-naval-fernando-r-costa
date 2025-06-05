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

    // Define o navio horizontal
    int navio_horizontal[3] = {3, 3, 3};
    int linha_navio_horizontal = 2;
    int coluna_inicio_horizontal = 2;

    // Se couber, imprime o navio horizontal
    if (coluna_inicio_horizontal + 3 <= colunas_tabuleiro) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_navio_horizontal][coluna_inicio_horizontal + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: o navio está posicionado fora do tabuleiro");
    }

    // Define o navio vertical
    int navio_vertical[3] = {3, 3, 3};
    int linha_inicio_vertical = 5;
    int coluna_navio_vertical = 4;

    // Verifica se cabe e não sobrepõe para imprimir o navio vertical
    if (linha_inicio_vertical + 3 <= linhas_tabuleiro) {
        int pode_colocar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_inicio_vertical + i][coluna_navio_vertical] != 0) {
                pode_colocar = 0;
                break;
            }
        }

        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_inicio_vertical + i][coluna_navio_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: sobreposição detectada.\n");
        }
    } else {
        printf("Erro: o navio não cabe na posição especificada.\n");
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
