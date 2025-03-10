#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplicacaoBlocada(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C, int tamanhoBloco) {
    int M = A.size();
    int N = A[0].size();
    int X = B[0].size();
    
    for (int i = 0; i < M; i += tamanhoBloco) {
        for (int j = 0; j < X; j += tamanhoBloco) {
            for (int k = 0; k < N; k += tamanhoBloco) {
                for (int ii = i; ii < min(i + tamanhoBloco, M); ii++) {
                    for (int jj = j; jj < min(j + tamanhoBloco, X); jj++) {
                        for (int kk = k; kk < min(k + tamanhoBloco, N); kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int M = 500, N = 500, X = 500;
    vector<vector<int>> A(M, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(X, 1));
    vector<vector<int>> C(M, vector<int>(X, 0));

    auto inicio = high_resolution_clock::now();
    multiplicacaoBlocada(A, B, C, 32);
    auto fim = high_resolution_clock::now();
    cout << "Tempo com blocagem: " << duration<double>(fim - inicio).count() << " s\n";
    
    return 0;
}
