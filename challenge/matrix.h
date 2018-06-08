// PYTHON FRIENDLY HEADER DECLARATION
#include "defs.h"
#include "arrays.h"
#include "timer.h"
#include "randn.h"

#define seed 7

void SetMatrixZero(my_prec **A,unsigned int rows, unsigned int cols);
void SetMatrixRandom(my_prec **A,unsigned int rows, unsigned int cols);
my_prec **treatMatrix(unsigned int samples, unsigned int size_X, unsigned int size_data);

double** getOptimalCoefficients (double** x, double** y, int samples,int numVar);

double variance(double** a,double* y,double** x,int N,int n);