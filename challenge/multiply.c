#include "multiply.h"

void multiply0(int msize, int tidx, int numt, TYPE a[][NUM], TYPE b[][NUM], TYPE c[][NUM], TYPE t[][NUM])
{
    int i,j,k;
    #pragma omp parallel for
    for(i=0; i<msize; i++) {
        for(j=0; j<msize; j++) {
    	    for(k=0; k<msize; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	} 
}
