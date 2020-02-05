#include "matrix.h"

//Matrix construction using bstree(ini);
Matrix matrix_construction(void)
{
    BStree newMatrix = bstree_ini();
    return newMatrix;
}

//If location (index1, index2) is defined in Matrix m, then return 1, otherwise return 0
unsigned char matrix_isin(Matrix m, Index index1, Index index2)
{
   if (bstree_search(m, key_gen(index1, index2)) == NULL)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}

//If location (index1, index2) is defined in Matrix m, then return a pointer to associate value
//Otherwise return NULL
Value *matrix_get(Matrix m, Index index1, Index index2)
{
    Key newkey = key_gen(index1, index2); //Generate key using given indices
    if (bstree_search(m, newkey) == NULL) //Check if key is in the matrix
    {
        return NULL;
    }
    else
    {
        return data_gen(*bstree_search(m, newkey)); //return pointer to data/value
    }
}
//Assign value to Matrix m at location (index1, index2)
//If that location already has value, then overwrite
void matrix_set(Matrix m, Index index1, Index index2, Value value)
{
    bstree_insert(m, key_gen(index1, index2), data_gen(value));
}
//Use Matrix get, change value
//If location (index1, index2) is defined in Matrix m, then increase the associated value by value.
//Otherwise, report error.
void matrix_inc(Matrix m, Index index1, Index index2, Value value)
{
    if (matrix_get(m, index1, index2) != NULL)
    {
        Data newData = matrix_get(m, index1, index2);
        *newData = *newData + value;
    }
    else
    {
        printf("Doesn't exist, sorry");
    }
}
//Use matrix_isin to check if location is defined
//If so, make value = value + newValue

//Print indices and values in the Matrix m (with bstree_traversal())
void matrix_list(Matrix m)
{
    bstree_traversal(m);
}

//Free allocated space (with bstree_free())
void matrix_destruction(Matrix m)
{
    bstree_free(m);
}
