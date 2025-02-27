#include <iostream>

using namespace std;

int** transpose(int** matrice, int n, int m) {
    int** transpose = new int*[m];
    for (int i = 0; i < m; i++) {
        transpose[i] = new int[n];
        for (int j = 0; j < n; j++) {
            transpose[i][j] = matrice[j][i];
        }
    }
    return transpose;
}

void printMatrix(int** matrice, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

void freeMatrix(int** matrice, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrice[i];
    }
    delete[] matrice;
}

int main() {
    int n = 3, m = 3;

    // Allocate memory for rows
    int** matrice = new int*[n];

    // Allocate memory for columns and initialize values
    int values[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < n; i++) {
        matrice[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrice[i][j] = values[i][j];
        }
    }

    // Print initial matrix
    cout << "Matrice initiale :" << endl;
    printMatrix(matrice, n, m);

    // Transpose the matrix
    int** transposeMatrice = transpose(matrice, n, m);

    // Print transposed matrix
    cout << "Matrice transposee :" << endl;
    printMatrix(transposeMatrice, m, n);

    // Free allocated memory for the original matrix
    freeMatrix(matrice, n);

    // Free allocated memory for the transposed matrix
    freeMatrix(transposeMatrice, m);

    return 0;
}
