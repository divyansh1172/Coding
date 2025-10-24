#include <stdio.h>
#include <math.h>

#define N 6

// Function to get cofactor of matrix[p][q] in temp[][]. n is current dimension
void getCofactor(double matrix[N][N], double temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copy only those elements which are not in given row and column
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                
                // Row is filled, so increase row index and reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function to find determinant of matrix
double determinant(double matrix[N][N], int n) {
    double det = 0;
    
    // Base case: if matrix is 1x1
    if (n == 1)
        return matrix[0][0];
    
    double temp[N][N]; // To store cofactors
    int sign = 1; // To store sign multiplier
    
    // Iterate for each element of first row
    for (int f = 0; f < n; f++) {
        // Get cofactor of matrix[0][f]
        getCofactor(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        
        // Alternate sign
        sign = -sign;
    }
    
    return det;
}

// Function to display the matrix
void displayMatrix(double matrix[N][N]) {
    printf("\nMatrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example 6x6 matrix
    double matrix[N][N] = {
        {4, 3, 2, 2, 0, 1},
        {0, 1, 0, 3, 1, 2},
        {0, -1, 0, 1, 2, 3},
        {2, 3, 0, 0, 4, 1},
        {0, 1, 2, 3, 0, 2},
        {1, 0, 1, 2, 1, 0}
    };
    
    displayMatrix(matrix);
    
    double det = determinant(matrix, N);
    
    printf("\nDeterminant of the matrix: %.2f\n", det);
    
    return 0;
}