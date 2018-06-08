#ifndef __INCLUDED_TRANSPOSE_H__
#define __INCLUDED_TRANSPOSE_H__

// Allow compile with single or double precision
// by specifying the compiler flag -DSINGLE or -DDOUBLE
#ifdef SINGLE
#define FTYPE float
#elif defined DOUBLE
#define FTYPE double
#endif

double** Transpose(double** A);

#endif
