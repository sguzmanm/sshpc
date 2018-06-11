#include "matrix.h"
#include "probability.h"

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
    srand(seed);

	// Setting the problem size!
	samples = 2048; size_X = 3; size_data = 2;
	printf("a\n");
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

		printf("b\n");

	printf("DATA MATRIX \n");
	for(int i=0;i<size_data;i++)
		for (int j=0;j<size_X;j++)
			printf("%f ",dataMatrix[i][j]);
	double**y=CREATE_MATRIX(size_data,1);
	
	SetMatrixRandom(y,size_data,1);
	printf("y \n");
	for(int i=0;i<size_data;i++)
		for (int j=0;j<1;j++)
			printf("%f ",y[i][j]);

	double** trans=Transpose(dataMatrix,size_data,size_X);
	printf("\n TRANS \n");
	for(int i=0;i<size_X;i++)
	{
		for(int j=0;j<size_data;j++)
			printf("%f ",trans[i][j]);
		printf("\n");

	}
	double** inverseTrans=getInverseTrans(trans,dataMatrix,size_data,size_X);
	printf("\n INV TRANS \n");
	for(int i=0;i<size_X;i++)
	{
		for(int j=0;j<size_X;j++)
			printf("%f ",inverseTrans[i][j]);
		printf("\n");

	}
	/*double** a=getOptimalCoefficients(trans,inverseTrans,y,size_data,size_X);
	printf("\n OPTIMAL \n");
	for(int i=0;i<size_X;i++)
		printf("%f ",a[i][0]);
	//
	// Check out the Times!
	//

	double var=variance(a,y,dataMatrix,size_X,size_data);
	printf("VAR: %f \n",var);

	double* p_val=getPValue(var, inverseTrans,a,size_X,size_data-size_X-1);

	*/
	double** A=CREATE_MATRIX(2,2);
	A[0][0]=-1.0;
	A[0][1]=0.0;
	A[1][0]=3.0;
	A[1][1]=-5.0;
	printf("DETER %d",determinant(A,2));
	free(A[0]);
	free(A),A=NULL;

	// Finally, we clean the memory stack as suggested
	// from arrays.c
	free(dataMatrix[0]);
	free(dataMatrix), dataMatrix = NULL;
	free(y[0]);
	free(y), y=NULL;
//	free(a[0]);
//	free(a),a=NULL;

	// End
	return 0;
}


