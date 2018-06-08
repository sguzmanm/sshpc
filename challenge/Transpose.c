#include "Transpose.h"
#include <cstdlib>

void Transpose(FTYPE* const A, const int n) {

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < j; i++) {
      const FTYPE c = A[i*n + j];
      A[i*n + j] = A[j*n + i];
      A[j*n + i] = c;
    }
  }

}
