#include "multiply.h"

double[][] multiply0(double** a[][], double** b[][])
{
	int row=a.length;
	int col=b[0].lemgth;
	double[][] c=new double[row][col];
    int i,j,k;
    #pragma omp parallel for
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
    	    for(k=0; k<row; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	} 
}
