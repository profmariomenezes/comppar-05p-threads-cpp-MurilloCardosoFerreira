#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplicacaoLinha(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) {
    int M = A.size();
    int N = A[0].size();
    int X = B[0].size();
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < X; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
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
    multiplicacaoLinha(A, B, C);
    auto fim = high_resolution_clock::now();
    cout << "Tempo percorrendo por linha: " << duration<double>(fim - inicio).count() << " s\n";
    
    return 0;
}
