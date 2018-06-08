

void getCofactor(double** A, double** temp, int p, int q, int n);
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
int determinant(double** A, int n);
 
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double** A,double** adj,int N);
}
 
// Function to calculate and store inverse, returns false if
// matrix is singular
void inverse(double** A, double** inverse,int n,int m);
