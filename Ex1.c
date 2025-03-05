#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 500
#define COLUNAS 500
#define X 500

void preencherMatriz(int matriz[LINHAS][COLUNAS], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void multiplicarPorLinha(int A[LINHAS][COLUNAS], int B[COLUNAS][X], int C[LINHAS][X]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < X; j++) {
            C[i][j] = 0;
            for (int k = 0; k < COLUNAS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplicarPorColuna(int A[LINHAS][COLUNAS], int B[COLUNAS][X], int C[LINHAS][X]) {
    for (int j = 0; j < X; j++) {
        for (int i = 0; i < LINHAS; i++) {
            C[i][j] = 0;
        }
        for (int k = 0; k < COLUNAS; k++) {
            for (int i = 0; i < LINHAS; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int A[LINHAS][COLUNAS], B[COLUNAS][X], C[LINHAS][X];
    preencherMatriz(A, LINHAS, COLUNAS);
    preencherMatriz(B, COLUNAS, X);
    
    clock_t inicio, fim;
    double tempoGasto;
    
    if (argc > 1 && argv[1][0] == 'r') {
        inicio = clock();
        multiplicarPorLinha(A, B, C);
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Multiplicação por LINHA concluída em %.6f segundos.\n", tempoGasto);
    } else {
        inicio = clock();
        multiplicarPorColuna(A, B, C);
        fim = clock();
        tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Multiplicação por COLUNA concluída em %.6f segundos.\n", tempoGasto);
    }
    return 0;
}
