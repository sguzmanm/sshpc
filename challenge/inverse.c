#include "inverse.h"
#include "arrays.h"

// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(double** A, double** temp, int p, int q, int n, int m)
{
    int i = 0, j = 0;
    int row =0, col=0;
    // Looping for each element of the matrix
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < m; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
int determinant(double** A, int n,int m)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
 
    double temp[n][m]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, m);
        D += sign * A[0][f] * determinant(temp, n - 1,m);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
 
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double** A,double** adj,int n, int m)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    // temp is used to store cofactors of A[][]
    int sign = 1;
    double** temp=CREATE_MATRIX(n,m);
 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, n.m);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, n-1,m));
        }
    }
}
 
// Function to calculate and store inverse, returns false if
// matrix is singular
void inverse(double** A, double** inverse,int n,int m)
{
    // Find determinant of A[][]
    double det = (double)determinant(A, n,m);
    if (det == 0)
    {
        return;
    }
 
    // Find adjoint
    double** adj;
    adjoint(A, adj,n,m);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            inverse[i][j] = adj[i][j]/det;
 }
