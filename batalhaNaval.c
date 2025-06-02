#include <stdio.h>

// Função para aplicar habilidades
void aplicarHabilidade(char tabuleiro[10][10], int *habilidade, int linhas, int cols, int linha_centro, int coluna_centro, char marca) {
    int inicio_linha = linha_centro - (linhas / 2);
    int inicio_coluna = coluna_centro - (cols / 2);
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(habilidade + i*cols + j) == 1) {
                if ((inicio_linha + i) >= 0 && (inicio_linha + i) < 10 &&
                    (inicio_coluna + j) >= 0 && (inicio_coluna + j) < 10) {
                    tabuleiro[inicio_linha + i][inicio_coluna + j] = marca;
                }
            }
        }
    }
}

int main() {
    char tabuleiro[10][10];
    
    // Inicializa com água
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Define as habilidades
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    int octaedro[3][3] = {
        {0,1,0},
        {1,1,1},
        {0,1,0}
    };

    // Aplica as habilidades em posições separadas
    aplicarHabilidade(tabuleiro, (int *)cone, 3, 5, 2, 3, '1');    // Cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, (int *)cruz, 5, 5, 6, 6, '2');    // Cruz no centro-direito
    aplicarHabilidade(tabuleiro, (int *)octaedro, 3, 3, 8, 8, '4'); // Octaedro no canto inferior direito

    // Mostra o tabuleiro
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
