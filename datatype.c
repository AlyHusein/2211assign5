#include "datatype.h"

//Duplicate string pointed to by str with dynamic memory allocation
char * string_dup(char *str)
{
    char *newP;
    
    newP = malloc(sizeof(char)*(strlen(str)+1));
    for (int i = 0; i < (strlen(str)+1); i++)
    {
        *(newP+i) = *(str+i);
    }
    return newP;
}

//Generate a key with dynamic memory allocation
Key key_gen(char *skey1, char *skey2)
{
    Key newKey;

    newKey = (Key_struct*)malloc(sizeof(Key_struct));
    
    newKey->skey1 = string_dup(skey1);
    newKey->skey2 = string_dup(skey2);
    
    return newKey;
}

//Use strcmp() to do comparison. If key1->skey1 and key2->skey1 are different,
//then they determine the comparison result.
//If key1->skey1 and key2->skey1 are the same, then key1->skey2 and key2->skey2 determine
//the comparison result
int key_comp(Key key1, Key key2)
{
    int keyComp;
    int keyComp2;
    
    keyComp = strcmp(key1->skey1, key2->skey1);
    
    if (keyComp == 0)
    {
        keyComp2 = strcmp(key1->skey2, key2->skey2);
        return keyComp2;
    }
    else
    {
        return keyComp;
    }
    
}

//Print a key
void key_print(Key key)
{
    printf("%s     %s\n", key->skey1, key->skey2);
}

//Free memory allocated for the key
void key_free(Key key)
{
    free(key->skey1);
    free(key->skey2);
    free(key);
}

//Generate a data with dynamic memory allocation
Data data_gen(int idata)
{
    int newD = idata;
    Data newData;
    newData = (Data)malloc(sizeof(Data));
    *newData = newD;
    
    return newData;
}

//Assign data with idata
void data_set(Data data, int idata)
{
    int newD = idata;
    *data = newD;
}

//Print a data
void data_print(Data data)
{
    printf("%d\n", *data);
}

void keyData_print(Key key, Data data)
{
    printf("String 1    String 2    Occurence\n");
    printf("%s           %s           %d\n", key->skey1, key->skey2, *data);
}

//Free memory allocated for data
void data_free(Data data)
{
    free(data);
}
