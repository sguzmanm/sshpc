#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"
#include "inverse.h"
#include "multiply.h"
#include "Transpose.h"


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
double** getOptimalCoefficients (double** x, double* y, int samples,int numVar)
{
	double[][] trans=Transpose(x);
	int i,j;
	for(i=0;i<samples;i++)
	{
		for(j=0;j<numVar;j++)
		{
			printf("%d",trans[i][j]);
		}
		printf("\n");
	}
	double[][] mult=multiply0(x,trans);
	double[][] inv=CREATE_MATRIX(mult.length,mult.length);
	inverse(mult,inv);
	for(int i=0;i<inv.length;i++)
	{
		for(int j=0;j<inv[0].length;j++)
		{
			printf("%d",inv[i][j]);
		}
		printf("\n");
	}
	return multiply0(multiply0(inv,trans),y);
}
/**
 * Gets the variance with the given list of coefficientes (a)
 **/
double variance(double[][] a,double[] y,double[][] x)
{
	double N=a.length;
	int n=x[0].length;
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
	return sum/(2*N);
}
// Perform Linear Regression


// Collect R^2, 


// Run Matrix Calculations
int main(int argc, char** argv){
	// We create the problem initial conditions (positive integers)
	unsigned int samples;
	unsigned int size_X;
	unsigned int size_data;
	// Iterator variables
	unsigned int j,k;
	// Matrix Object
	my_prec **dataMatrix;
	// Timer example
	SimpleTimer_t t1,t2;
	// Random seed, set the seed to the random number generator
	int seed = 7;
    srand(seed);

	// Setting the problem size!
	samples = 2048; size_X = 128; size_data = 1024;

	// Creating the Matrix
	dataMatrix = CREATE_MATRIX(size_data,size_X);
/*
	// Collect start time for this snippet
	SimpleTimer_start( &t1 );
	// Set all values of the matrix to 1
	for( j=0; j < size_data; j++ )
		for( k=0; k < size_X; k++ )
			dataMatrix[j][k] = 0.0;
	// Collect stop time
	SimpleTimer_stop( &t1 );
	// Print duration
	SimpleTimer_print( &t1 );


	// BEGIN: DEBUG SNIPPET
	// Why this snippet of code?
	// ANS: To make a quick revision of the timer
	// Collect start time for this snippet
	SimpleTimer_start( &t1 );
	// Set all values of the matrix to 1
	for( j=0; j < size_data; j++ )
		for( k=0; k < size_X; k++ )
			dataMatrix[j][k] = 2.0;
	// Collect stop time
	SimpleTimer_stop( &t1 );
	// Print duration
	SimpleTimer_print( &t1 );
	// END: DEBUG SNIPPET
	// Why does it take shorter time to run this loop?
	//ANS: It is already on memory
	//
	// Reset the matrix elements to zero
	//
	SimpleTimer_start( &t2 );
	// Set all values of the matrix to 0
	SetMatrixZero(dataMatrix,size_data,size_X);
	// Collect stop time
	SimpleTimer_stop( &t2 );
	// Print duration
	SimpleTimer_print( &t2 );
*/
	//
	// Place random elements!
	//
	SimpleTimer_start( &t2 );
	// Set all values of the matrix to 0
	SetMatrixRandom(dataMatrix,size_data,size_X);
	// Collect stop time
	SimpleTimer_stop( &t2 );
	// Print duration
	SimpleTimer_print( &t2 );

	double*y=CREATE_ARRAY(samples);
	SetArrayRandom(y,samples);
	getOptimalCoefficients(dataMatrix,y,samples,size_X);
	//
	// Check out the Times!
	//

	// Finally, we clean the memory stack as suggested
	// from arrays.c
	free(dataMatrix[0]);
	free(dataMatrix), dataMatrix = NULL;

	// End
	return 0;
}
