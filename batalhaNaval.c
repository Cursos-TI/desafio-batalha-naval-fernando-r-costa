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

    // Define o navio diagonal descendente (↘)
    int navio_diagonal_desc[3] = {3, 3, 3};
    int linha_inicio_diag_desc = 1;
    int coluna_inicio_diag_desc = 6;

    // Verifica se cabe e não sobrepõe para imprimir o navio diagonal descendente
    if (linha_inicio_diag_desc + 3 <= linhas_tabuleiro && coluna_inicio_diag_desc + 3 <= colunas_tabuleiro) {
        int pode_colocar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_inicio_diag_desc + i][coluna_inicio_diag_desc + i] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_inicio_diag_desc + i][coluna_inicio_diag_desc + i] = navio_diagonal_desc[i];
            }
        } else {
            printf("Erro: sobreposição detectada no navio diagonal descendente.\n");
        }
    } else {
        printf("Erro: o navio diagonal descendente não cabe na posição especificada.\n");
    }

    // Define o navio diagonal ascendente (↗)
    int navio_diagonal_asc[3] = {3, 3, 3};
    int linha_inicio_diag_asc = 8;
    int coluna_inicio_diag_asc = 0;

    // Verifica se cabe e não sobrepõe para imprimir o navio diagonal ascendente
    if (linha_inicio_diag_asc - 2 >= 0 && coluna_inicio_diag_asc + 3 <= colunas_tabuleiro) {
        int pode_colocar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_inicio_diag_asc - i][coluna_inicio_diag_asc + i] != 0) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_inicio_diag_asc - i][coluna_inicio_diag_asc + i] = navio_diagonal_asc[i];
            }
        } else {
            printf("Erro: sobreposição detectada no navio diagonal ascendente.\n");
        }
    } else {
        printf("Erro: o navio diagonal ascendente não cabe na posição especificada.\n");
    }

    // Implementação das habilidades especiais
    // Define a habilidade em forma de cone (ponto de origem no topo)
    int linha_origem_cone = 1;
    int coluna_origem_cone = 2;
    int altura_cone = 3;
    
    // Verifica se o cone cabe completamente no tabuleiro (vertical e horizontalmente)
    int largura_maxima_cone = 2 * altura_cone - 1;
    int meio_cone = largura_maxima_cone / 2;
    
    if (linha_origem_cone + altura_cone <= linhas_tabuleiro && 
        coluna_origem_cone - meio_cone >= 0 && 
        coluna_origem_cone + meio_cone < colunas_tabuleiro) {
        
        // Aplica a habilidade cone no tabuleiro
        for (int i = 0; i < altura_cone; i++) {
            int largura = 2 * i + 1;
            int coluna_inicio = coluna_origem_cone - i;
            
            for (int j = 0; j < largura; j++) {
                int coluna_atual = coluna_inicio + j;
                tabuleiro[linha_origem_cone + i][coluna_atual] = 5;
            }
        }
    } else {
        printf("Erro: a habilidade cone não cabe na posição especificada.\n");
    }

    // Define a habilidade em forma de cruz (ponto de origem no centro)
    int linha_origem_cruz = 4;
    int coluna_origem_cruz = 7;
    int tamanho_cruz = 5;
    
    // Aplica a habilidade cruz no tabuleiro
    int raio_cruz = tamanho_cruz / 2;
    // Verifica se cabe no tabuleiro
    if (linha_origem_cruz - raio_cruz >= 0 && linha_origem_cruz + raio_cruz < linhas_tabuleiro &&
        coluna_origem_cruz - raio_cruz >= 0 && coluna_origem_cruz + raio_cruz < colunas_tabuleiro) {
        
        // Marca a linha horizontal da cruz
        for (int j = coluna_origem_cruz - raio_cruz; j <= coluna_origem_cruz + raio_cruz; j++) {
            tabuleiro[linha_origem_cruz][j] = 5;
        }
        
        // Marca a linha vertical da cruz
        for (int i = linha_origem_cruz - raio_cruz; i <= linha_origem_cruz + raio_cruz; i++) {
            tabuleiro[i][coluna_origem_cruz] = 5;
        }
    } else {
        printf("Erro: a habilidade cruz não cabe na posição especificada.\n");
    }

    // Define a habilidade em forma de octaedro (losango) (ponto de origem no centro)
    int linha_origem_octaedro = 8;
    int coluna_origem_octaedro = 4;
    int tamanho_octaedro = 3;
    
    // Aplica a habilidade octaedro no tabuleiro
    int raio_octaedro = tamanho_octaedro / 2;
    // Verifica se cabe no tabuleiro
    if (linha_origem_octaedro - raio_octaedro >= 0 && linha_origem_octaedro + raio_octaedro < linhas_tabuleiro &&
        coluna_origem_octaedro - raio_octaedro >= 0 && coluna_origem_octaedro + raio_octaedro < colunas_tabuleiro) {
        
        for (int i = linha_origem_octaedro - raio_octaedro; i <= linha_origem_octaedro + raio_octaedro; i++) {
            int dist_vertical = i - linha_origem_octaedro;
            if (dist_vertical < 0) dist_vertical = -dist_vertical;
            
            int largura = tamanho_octaedro - 2 * dist_vertical;
            int coluna_inicio = coluna_origem_octaedro - largura / 2;
            
            for (int j = 0; j < largura; j++) {
                int coluna_atual = coluna_inicio + j;
                tabuleiro[i][coluna_atual] = 5;
            }
        }
    } else {
        printf("Erro: a habilidade octaedro não cabe na posição especificada.\n");
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