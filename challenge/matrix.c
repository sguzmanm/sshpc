#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"
#include "inverse.h"
#include "multiply.h"
#include "Transpose.h"

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

void SetArrayRandom(my_prec *A,unsigned int rows){
	int j,k;
	for( j = 0; j < rows; j++ )
		A[j] = normal_rand();
}
/**
 * Gets the a_opt or the coefficients of each x using y
 **/
double** getOptimalCoefficients (double** x, double** y, int samples,int numVar)
{
	double** trans=Transpose(x,samples,numVar);
	int i,j;
	for(i=0;i<samples;i++)
	{
		for(j=0;j<numVar;j++)
		{
			printf("%f",trans[i][j]);
		}
		printf("\n");
	}
	double** mult=multiply0(x,trans,samples,numVar);
	double** inv=CREATE_MATRIX(samples,numVar);
	inverse(mult,inv);
	for(int i=0;i<samples;i++)
	{
		for(int j=0;j<numVar;j++)
		{
			printf("%f",inv[i][j]);
		}
		printf("\n");
	}
	return multiply0(multiply0(inv,trans,samples,numVar),y,numVar,samples);
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

