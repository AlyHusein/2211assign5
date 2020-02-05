#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include "bstree.h"


typedef BStree Matrix;
typedef char* Index;
typedef int Value;

Matrix matrix_construction(void);
//Matrix construction using bstree(ini);

unsigned char matrix_isin(Matrix m, Index index1, Index index2);
//If location (index1, index2) is defined in Matrix m, then return 1, otherwise return 0

Value *matrix_get(Matrix m, Index index1, Index index2);
//If location (index1, index2) is defined in Matrix m, then return a pointer to associate value
//Otherwise return NULL

void matrix_set(Matrix m, Index index1, Index index2, Value value);
//Assign value to Matrix m at loation (index1, index2)
//If that location already has value, then overwrite

void matrix_inc(Matrix m, Index index1, Index index2, Value value);
//If loation (index1, index2) is defined in Matrix m, then increase the associated value by value.
//Otherwise, report error.

void matrix_list(Matrix m);
//Print indices and values in the Matrix m (with bstree_traversal())

void matrix_destruction(Matrix m);
//Free allocated space (with bstree_free())


#endif /* matrix_h */
