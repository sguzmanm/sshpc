// PYTHON FRIENDLY HEADER DECLARATION
#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"
#include "inverse.h"

#define seed 7

void SetMatrixZero(my_prec **A,unsigned int rows, unsigned int cols);
void SetMatrixRandom(my_prec **A,unsigned int rows, unsigned int cols);
my_prec **treatMatrix(unsigned int samples, unsigned int size_X, unsigned int size_data);

double** getOptimalCoefficients (double** x, double** y, int samples,int numVar);

double variance(double** a,double* y,double** x,int N,int n);

// Matrix Transpose Code
double** Transpose(double** A,int r,int c);
// Matrix Multiply Code
double** multiply0(double** a, double** b,int p,int q, int r);
