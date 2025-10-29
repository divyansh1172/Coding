#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// allocates memory for a matrix in a heap
double **allocate_matrix(int m, int n)
{
    double **mat = malloc(m * sizeof(double *));
    mat[0] = malloc(m * n * sizeof(double));
    for (int i = 0; i < m; i++)
    {
        mat[i] = mat[0] + i * n;
    }
    return mat;
}

// free a allocated matrix
void free_matrix(double **mat)
{
    free(mat[0]);
    free(mat);
}

//  this function is correct and working properly
// Transpose a matrix a
void transpose_mat(int m, int n, double **a, double **at)
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
void mult_at_a(int m, int n, double **res, double **a, double **at)
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
void jacobi_eigen(int n, double **a, double **V, double *singular_vals)
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
void sort_svd(int n, double *S, double **V)
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

// computing U=(1/simga[i])*A*v_i
void compute_U(int m, int n, double **a, double **U, double *S, double **V)
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

// printing a matrix
// working properly
// checked
void print_matrix(int m, int n, double **a)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    return;
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
    int m, n;
    scanf("%d %d", &m, &n);
    // leave matric allocation for now i'll add it afterwards
    //  allocating memmory for all the matrices
    double **a = allocate_matrix(m, n);   // a matrix
    double **at = allocate_matrix(n, m);  // transpose of a
    double **ata = allocate_matrix(n, n); // matrix prod of ata
    double **V = allocate_matrix(n, n);   // eigenvector matrix
    double **U = allocate_matrix(m, n);   // left multiplaction matrix
    double *singular_vals = malloc(n * sizeof(double));

    transpose_mat(m, n, a, at);              // taking transpose of  a
    mult_at_a(m, n, ata, a, at);             // multiplying at and a
    jacobi_eigen(n, ata, V, singular_vals);  // computing singular values and V
    sort_svd(n, singular_vals, V);           // sorting ascending
    compute_U(m, n, a, U, singular_vals, V); // computing U from the formula SVD decomposition

    free_matrix(a);
    free_matrix(at);
    free_matrix(ata);
    free_matrix(V);
    free_matrix(U);
    free(singular_vals);
    return 0;
}