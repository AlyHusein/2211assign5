#include <stdio.h>
#include <string.h>
#include "matrix.h"

int main(void)
{
    int addAnother = 1;
    char in1[256];
    char in2[256];
    char contQ;
    Matrix testMatrix;
    
    testMatrix = matrix_construction();
    
    while (addAnother == 1)
    {
        
        printf("\nPlease enter the two key indices you'd like to add\n ");
        scanf("%s %s", in1, in2);
        //Creates new Key
        //Inserts new Node into Tree
        
        bstree_insert(testMatrix, key_gen(in1, in2), data_gen(1));
        
        printf("\nWould you like to add another?:\n");
        printf("Type N for no\n");
        printf("Type anything else for Yes:\n");
        scanf("%s", &contQ);
        
        if (contQ == 'N') //If they put N, they'd like to quit
        {
            addAnother = 0; //Stops while function
        }
    }
    matrix_list(testMatrix);
    
    printf("\nThanks for using my program!, Goodbye.\n");
    
    bstree_free(testMatrix);
}

