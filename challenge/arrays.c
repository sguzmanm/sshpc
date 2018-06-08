#include "defs.h"

my_prec *CREATE_ARRAY(const unsigned int a){
	// Creates a pointer v of aelements of size/precision my_prec
	// defined in defs.h
	my_prec *v = (my_prec*) malloc( a * sizeof(my_prec) );
	// If it cannot be allocated then return NULL. Remember NULL
	// is the default initialized value for a pointer.
	if (!v) return NULL;
	// Print some help to free memory adequately
	return v;
};

my_prec **CREATE_MATRIX(const unsigned int a,const unsigned int b){
	// We create a "pointer" of pointers to my_prec* with the 
	// number of rows. i.e. an array of pointers to the "first" element
	// in each row of the matrix
	my_prec **v = (my_prec**) malloc(a * sizeof(my_prec*));

	// Creates a pointer v of a*b elements of size/precision my_prec
	// defined in defs.h that represents the total number of items in
	// the matrix.
	v[0] = (my_prec*) malloc(a * b * sizeof(my_prec));
	// What are we doing? To create a contiguous memory matrix
	// it is often a good idea to first create an array with all 
	// the elements and then "convert" it to a matrix. So we need
	// the pointer of the first element to point to the array
	// of all ements!

	// This may present memory leaks!!

	// If they cannot be allocated then return NULL. Remember NULL
	// is the default initialized value for a pointer.
	if (!v) return NULL;

	// Now we assign accordingly pointers to each element
	// look at v[j-1]+b! Any questions?
	for( int j = 1; j < a; j++ )
		v[j] = v[j-1] + b;
	// Print some help to free memory adequately
	return v;
};

// Q: Can you draw a map of how the memory is allocated in memory?
