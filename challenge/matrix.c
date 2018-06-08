#include "matrix.h"

#define seed 7

void SetMatrixZero(my_prec **A,unsigned int rows, unsigned int cols){
	int j,k;
	for( j = 0; j < rows; j++ )
		for( k = 0; k < cols; k++ )
			A[j][k] = 0;
}

void SetMatrixRandom(my_prec **A,unsigned int rows, unsigned int cols){
	int j,k;
	for( j = 0; j < rows; j++ )
		for( k = 0; k < cols; k++ )
			A[j][k] = normal_rand();
}
/**
 * Gets the a_opt or the coefficients of each x using y
 **/
double** getOptimalCoefficients (double** x, double** y, int samples,int numVar)
{
			printf("AA %d %d\n",samples,numVar);

	double** trans=Transpose(x,samples,numVar);
				printf("BB %d %d\n",samples,numVar);

	int i,j;
				printf("CC %d %d\n",samples,numVar);

	double** mult=multiply0(trans,x,numVar,samples,numVar);
		printf("A\n");
	double** inv=CREATE_MATRIX(numVar,numVar);
		printf("B\n");
	inverse(mult,inv,numVar,numVar);
	printf("LLEGa\n");
	return multiply0(multiply0(inv,trans,numVar,samples,numVar),y,numVar,samples,1);
}
/**
 * Gets the variance with the given list of coefficientes (a)
 **/
double variance(double** a,double* y,double** x,int N,int n)
{
	double sum=0;
	double temp=0;
	for(int i=0;i<N;i++)
	{
		temp=0;
		for(int j=0;j<n;j++)
		{
			temp+=x[i][j]*a[i][0];
		}
		sum+=(y[i]-temp)*(y[i]-temp);
	}
	temp=(double)N;
	return sum/(2*temp);
}


// Matrix Transpose Code
double** Transpose(double** A,int r,int c) {

  double** transpose=CREATE_MATRIX(c,r);
  for (int j = 0; j < c; j++) {
    for (int i = 0; i < r; i++) {
      transpose[j][i]=A[i][j];
    }
  }
  return transpose;

}
// Matrix Multiply Code
double** multiply0(double** a, double** b,int p,int q,int r)
{
	printf("MULT %d %d %d \n",p,q,r);
	double** c=CREATE_MATRIX(row,col);
    int i,j,k;
    #pragma omp parallel for
    for(i=0; i<p; i++) {
        for(j=0; j<r; j++) {
    	    for(k=0; k<q; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	} 
	return c;
}

// Perform Linear Regression


// Collect R^2, 



/*

	Python Friendly functions

*/
my_prec **treatMatrix(unsigned int samples, unsigned int size_X, unsigned int size_data){
	static int iter = 0;
	static SimpleTimer_t t;
	static my_prec **m;
	if(iter == 0)
	    srand(seed);
	if(iter % 2 == 0){
		m = CREATE_MATRIX(size_data,size_X);
		SimpleTimer_start( &t );
		SetMatrixRandom(m,size_data,size_X);
		// Collect stop time
		SimpleTimer_stop( &t );
		// Print duration
		printf("Create Matrix for Sample: %d -> ",iter/2+1);
		SimpleTimer_print( &t );

		iter++;
		return m;
	}
	printf("Destroying Matrix of Sample: %d\n",iter/2+1);
	iter++;
	free(m[0]);
	free(m), m = NULL;
	return NULL;
};
/*

	End of Python Friendly functions
*/

