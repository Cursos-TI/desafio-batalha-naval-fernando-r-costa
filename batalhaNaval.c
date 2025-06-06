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

    // Imprime o tabuleiro com os navios
    printf("Tabuleiro com navios:\n");
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

    // Implementação das matrizes de habilidade
    // Matriz de CONE
    int linhas_cone = 3;
int colunas_cone = 5;
int matriz_cone[linhas_cone][colunas_cone];

// Inicializa a matriz com zeros
for (int i = 0; i < linhas_cone; i++) {
    for (int j = 0; j < colunas_cone; j++) {
        matriz_cone[i][j] = 0;
    }
}

// Constrói o formato de cone com 3 linhas
// A largura aumenta na sequência: 1, 3, 5
for (int i = 0; i < linhas_cone; i++) {
    int largura = 2 * i + 1;
    int inicio_j = (colunas_cone - largura) / 2;
    
    for (int j = inicio_j; j < inicio_j + largura; j++) {
        if (j >= 0 && j < colunas_cone) {
            matriz_cone[i][j] = 1;
        }
    }
}
    
    // Matriz CRUZ
    int tamanho_cruz = 5;
    int matriz_cruz[tamanho_cruz][tamanho_cruz];
    
    // Inicializa a matriz com zeros
    for (int i = 0; i < tamanho_cruz; i++) {
        for (int j = 0; j < tamanho_cruz; j++) {
            matriz_cruz[i][j] = 0;
        }
    }
    
    // Constrói o formato de cruz
    int centro_cruz = tamanho_cruz / 2;
    
    // Marca a linha horizontal da cruz
    for (int j = 0; j < tamanho_cruz; j++) {
        matriz_cruz[centro_cruz][j] = 1;
    }
    
    // Marca a linha vertical da cruz
    for (int i = 0; i < tamanho_cruz; i++) {
        matriz_cruz[i][centro_cruz] = 1;
    }
    
    // Matriz OCTAEDRO (LOSANGO)
    int tamanho_octaedro = 3;
    int matriz_octaedro[tamanho_octaedro][tamanho_octaedro];
    
    // Inicializa a matriz com zeros
    for (int i = 0; i < tamanho_octaedro; i++) {
        for (int j = 0; j < tamanho_octaedro; j++) {
            matriz_octaedro[i][j] = 0;
        }
    }
    
    // Constrói o formato de losango
    int centro_octaedro = tamanho_octaedro / 2;
    
    for (int i = 0; i < tamanho_octaedro; i++) {
        int dist_vertical = (i > centro_octaedro) ? i - centro_octaedro : centro_octaedro - i;
        
        int largura = tamanho_octaedro - (2 * dist_vertical);
        int inicio_j = (tamanho_octaedro - largura) / 2;
        
        for (int j = inicio_j; j < inicio_j + largura; j++) {
            if (j >= 0 && j < tamanho_octaedro) {
                matriz_octaedro[i][j] = 1;
            }
        }
    }
    
    // Imprime as matrizes de habilidade    
    printf("Matriz de habilidade CONE:\n");
    for (int i = 0; i < linhas_cone; i++) {
        for (int j = 0; j < colunas_cone; j++) {
            printf("%d ", matriz_cone[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matriz de habilidade CRUZ:\n");
    for (int i = 0; i < tamanho_cruz; i++) {
        for (int j = 0; j < tamanho_cruz; j++) {
            printf("%d ", matriz_cruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matriz de habilidade OCTAEDRO:\n");
    for (int i = 0; i < tamanho_octaedro; i++) {
        for (int j = 0; j < tamanho_octaedro; j++) {
            printf("%d ", matriz_octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Pontos de origem das matrizes de habilidade no tabuleiro
    int linha_origem_cone = 1;
    int coluna_origem_cone = 2;

    int linha_origem_cruz = 4;
    int coluna_origem_cruz = 7;
    
    int linha_origem_octaedro = 8;
    int coluna_origem_octaedro = 4;
    
    // Função de sobreposição para a habilidade CONE
    int deslocamento_i_cone = 0;
    int deslocamento_j_cone = colunas_cone / 2;
    
    // Verifica se cabe no tabuleiro
    if (linha_origem_cone + linhas_cone <= linhas_tabuleiro && 
        coluna_origem_cone - deslocamento_j_cone >= 0 && 
        coluna_origem_cone + deslocamento_j_cone < colunas_tabuleiro) {
        
        // Sobrepõe a matriz de habilidade ao tabuleiro
        for (int i = 0; i < linhas_cone; i++) {
            for (int j = 0; j < colunas_cone; j++) {
                int linha_tab = linha_origem_cone + i - deslocamento_i_cone;
                int coluna_tab = coluna_origem_cone + j - deslocamento_j_cone;
                
                if (linha_tab >= 0 && linha_tab < linhas_tabuleiro && 
                    coluna_tab >= 0 && coluna_tab < colunas_tabuleiro) {
                    
                    if (matriz_cone[i][j] == 1) {
                        tabuleiro[linha_tab][coluna_tab] = 5;
                    }
                }
            }
        }
    } else {
        printf("Erro: a habilidade cone não cabe na posição especificada.\n");
    }
    
    // Função de sobreposição para a habilidade CRUZ
    int deslocamento_i_cruz = tamanho_cruz / 2;
    int deslocamento_j_cruz = tamanho_cruz / 2;
    
    // Verifica se cabe no tabuleiro
    if (linha_origem_cruz - deslocamento_i_cruz >= 0 && 
        linha_origem_cruz + deslocamento_i_cruz < linhas_tabuleiro && 
        coluna_origem_cruz - deslocamento_j_cruz >= 0 && 
        coluna_origem_cruz + deslocamento_j_cruz < colunas_tabuleiro) {
        
        // Sobrepõe a matriz de habilidade ao tabuleiro
        for (int i = 0; i < tamanho_cruz; i++) {
            for (int j = 0; j < tamanho_cruz; j++) {
                int linha_tab = linha_origem_cruz + i - deslocamento_i_cruz;
                int coluna_tab = coluna_origem_cruz + j - deslocamento_j_cruz;
                
                if (matriz_cruz[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    } else {
        printf("Erro: a habilidade cruz não cabe na posição especificada.\n");
    }
    
    // Função de sobreposição para a habilidade OCTAEDRO
    int deslocamento_i_octaedro = tamanho_octaedro / 2;
    int deslocamento_j_octaedro = tamanho_octaedro / 2;
    
    // Verifica se cabe no tabuleiro
    if (linha_origem_octaedro - deslocamento_i_octaedro >= 0 && 
        linha_origem_octaedro + deslocamento_i_octaedro < linhas_tabuleiro && 
        coluna_origem_octaedro - deslocamento_j_octaedro >= 0 && 
        coluna_origem_octaedro + deslocamento_j_octaedro < colunas_tabuleiro) {
        
        // Sobrepõe a matriz de habilidade ao tabuleiro
        for (int i = 0; i < tamanho_octaedro; i++) {
            for (int j = 0; j < tamanho_octaedro; j++) {
                int linha_tab = linha_origem_octaedro + i - deslocamento_i_octaedro;
                int coluna_tab = coluna_origem_octaedro + j - deslocamento_j_octaedro;
                
                if (matriz_octaedro[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5; // Marca como área afetada
                }
            }
        }
    } else {
        printf("Erro: a habilidade octaedro não cabe na posição especificada.\n");
    }
    
    printf("Tabuleiro com todas as habilidades aplicadas:\n");
    printf("   ");
    for (int j = 0; j < colunas_tabuleiro; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

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