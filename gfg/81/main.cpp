#include<bits/stdc++.h>

using namespace std;

/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

void callDFS(vector<int> A[], int i, int j, int N, int M) {
    if (i < 0 || i >= N || j < 0 || j >= M || A[i][j] == 0) return;
    A[i][j] = 0;
    callDFS(A, i + 1, j, N, M);
    callDFS(A, i - 1, j, N, M);
    callDFS(A, i, j + 1, N, M);
    callDFS(A, i, j - 1, N, M);
    callDFS(A, i + 1, j + 1, N, M);
    callDFS(A, i + 1, j - 1, N, M);
    callDFS(A, i - 1, j + 1, N, M);
    callDFS(A, i - 1, j - 1, N, M);
}

int findIslands(vector<int> A[], int N, int M) {
    int count = 0; 

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if (A[i][j] == 1) ++count;
            callDFS(A, i, j, N, M);
        }
    }
    return count;
}

int main() {
    return 0;
}