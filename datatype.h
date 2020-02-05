#ifndef datatype_h
#define datatype_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int * Data;

typedef struct
{
    char *skey1;
    char *skey2;
} Key_struct;

typedef Key_struct* Key;

char * string_dup(char *str);
//Duplicate string pointed to by str with dynamic memory allocation

Key key_gen(char *skey1, char *skey2);
//Generate a key with dynamic memory allocation

int key_comp(Key key1, Key key2);
//Use strcmp() to do comparison. If key1->skey1 and key2->skey2 are different,
//then they determine the comparison result.
//If key1->skey1 and key2->skey1 are the same, then key1->skey2 and key2->skey2 determine
//the comparison result

void key_print(Key key);
//Print a key

void key_free(Key key);
//Free memory allocated for the key

Data data_gen(int idata);
//Generate a data with dynamic memory allocation

void data_set(Data data, int idata);
//Assign data with idata

void data_print(Data data);
//Print a data

void keyData_print(Key key, Data data);

void data_free(Data data);
//Free memory allocated for data

#endif /* datatype_h */
