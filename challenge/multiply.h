*/

#ifdef __MIC__
#define MAXTHREADS 240
#define NUM 3840
#define MATRIX_BLOCK_SIZE 16
#else
#define MAXTHREADS 16
#define NUM 1024
#define MATRIX_BLOCK_SIZE 64
#endif

typedef double TYPE;
typedef TYPE array[NUM];

// Select which multiply kernel to use via the following macro so that the
// kernel being used can be reported when the test is run.
#define MULTIPLY multiply0

extern void multiply0(int msize, int tidx, int numt, TYPE a[][NUM], TYPE b[][NUM], TYPE c[][NUM], TYPE t[][NUM]);
