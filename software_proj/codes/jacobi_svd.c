#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  this function is correct and working properly
// Transpose a matrix a
void transpose_mat(int m, int n, double a[m][n], double at[n][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            at[j][i] = a[i][j];
        }
    }
    return;
}

// this function is correct and working properly
// Multiply two mats at and a with a[m][n]
void mult_at_a(int m, int n, double res[n][n], double a[m][n], double at[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                res[i][j] += at[i][k] * a[k][j];
            }
        }
    }
}

// implementing jacobi for singualr values and V matrix
//  working fine
void jacobi_eigen(int n, double a[n][n], double V[n][n], double singular_vals[n])
{
    // initializing V as an identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            V[i][j] = (i == j) ? 1.00 : 0.00;
        }
    }

    // changing the matrix a till all the non-diagonal elems get close to or zero
    int comp = 1;
    while (comp)
    {
        comp = 0;

        // getting only non-diagonal elems
        for (int i = 0; i < n - 1; i++) // iterating on a row
        {
            for (int j = i + 1; j < n; j++) // iterating over each column
            {
                double Aij = a[i][j];
                if (fabs(Aij) > 1e-9)
                {
                    double Aii = a[i][i], Ajj = a[j][j];
                    double theta = 0.5 * atan2(2 * Aij, Ajj - Aii);
                    double c = cos(theta), s = sin(theta);
                    // applying to rows
                    for (int k = 0; k < n; k++)
                    {
                        double Aki = c * a[i][k] - s * a[j][k];
                        double Akj = s * a[i][k] + c * a[j][k];
                        a[i][k] = Aki;
                        a[j][k] = Akj;
                    }

                    // apllying to columns
                    for (int k = 0; k < n; k++)
                    {
                        double Aki = a[k][i];
                        double Akj = a[k][j];
                        a[k][i] = c * Aki - s * Akj;
                        a[k][j] = s * Aki + c * Akj;
                    }

                    // updating V
                    for (int k = 0; k < n; k++)
                    {
                        double Vki = V[k][i];
                        double Vkj = V[k][j];
                        V[k][i] = c * Vki - s * Vkj;
                        V[k][j] = s * Vki + c * Vkj;
                    }
                    comp = 1;
                }
            }
        }
    }
    // storing the singular vals
    for (int i = 0; i < n; i++)
    {
        singular_vals[i] = sqrt(a[i][i]);
    }
    return;
}

// sorting SVD result to descending order
void sort_svd(int n, double S[n], double V[n][n])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (S[j] > S[i])
            {
                // Swap singular values
                double temp = S[i];
                S[i] = S[j];
                S[j] = temp;

                // Swap corresponding columns in V
                for (int k = 0; k < n; k++)
                {
                    temp = V[k][i];
                    V[k][i] = V[k][j];
                    V[k][j] = temp;
                }
            }
        }
    }
}

// computing U=1/(simga[i])*A*v_i
void compute_U(int m, int n, double a[m][n], double U[m][n], double S[n], double V[n][n])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            U[i][j] = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (S[i] < 1e-9)
            continue;

        for (int row = 0; row < m; row++)
        {
            U[row][i] = 0.0;
            for (int col = 0; col < n; col++)
                U[row][i] += a[row][col] * V[col][i];
            U[row][i] /= S[i];
        }
    }
}

// reconstructing A_k matrix for different values of k
void reconstruct_matrix(int m, int n, int k, double U[m][n], double S[n],
                        double V[n][n], double A_reconstructed[m][n])
{
    // Initialize result to zero
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A_reconstructed[i][j] = 0.0;
        }
    }

    // Use only the top k singular values
    int rank = (k < n) ? k : n;

    // A = sum from i=0 to k-1 of: sigma_i * u_i * v_i^T
    for (int i = 0; i < rank; i++)
    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                A_reconstructed[row][col] += S[i] * U[row][i] * V[col][i];
            }
        }
    }
}

int main()
{
    int m = 3, n = 2;
    double a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    double U[m][n];                          // intializing U matrix
    double at[n][m];                         // initializing transpose of a matrix
    transpose_mat(m, n, a, at);              // performing the transpose function
    double ata[n][n];                        // intializing A^T A
    mult_at_a(m, n, ata, a, at);             // performing A^T A
    double V[n][n];                          // intializing V matrix
    double singular_vals[n];                 // intializing the singular values matrix
    jacobi_eigen(n, ata, V, singular_vals);  // performing jacobi for singular values and the eigenvalues matrix
    sort_svd(n, singular_vals, V);           // sorting the singular values and changes the V accordingly
    compute_U(m, n, a, U, singular_vals, V); // computing the U matrix

    printf("Singular values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lf ", singular_vals[i]);
    }

    printf("\nV matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", V[i][j]);
        }
        printf("\n");
    }

    printf("\nU matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }

    double A_k[m][n];
    printf("\nV matrix\n");
    reconstruct_matrix(m, n, 16, U, singular_vals, V, A_k);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", A_k[i][j]);
        }
        printf("\n");
    }
    return 0;
}