#include "Transpose.h"
#include <cstdlib>

double[][] Transpose(double[][] A) {

  int r=A.length;
  int c=a[0].length;
  double[][] transpose=new double[c][r];
  for (int j = 0; j < r; j++) {
    for (int i = 0; i < c; i++) {
      transpose[j][i]=A[i][j];
    }
  }
  return transpose;

}
