#include "bstree.h"

//Allocate memory of type BStree_node*, set the value to NULL an return pointer to allocated memory
BStree bstree_ini(void)
{
    BStree newTree;
    newTree = (BStree)malloc(sizeof(BStree_node*));
    *newTree = NULL;
    return newTree;
}

BStree_node *new_node(Key key, Data data)
{
    BStree_node *newNode; //Initialize new node
    newNode = (BStree_node*)malloc(sizeof(BStree_node));
    
    newNode->key = key; 
    newNode->data = data;
    
    return newNode;
}

//Insert data with key into bst
//If Key is in bst, do nothing
//May want to use helper funtion for insertion to create a pointer to tree node from key, data
//BStree_node *new_node(Key key, Data data);
void bstree_insert(BStree bst, Key key, Data data)
{
    
    BStree_node *insertionNode = new_node(key, data);
    
    if ((*bst) == NULL)
    {
        *bst = insertionNode;
        insertionNode->left = NULL;
        insertionNode->right = NULL;

    }
    else
    {
        insertion_helper(*bst, insertionNode);
    }
}

void insertion_helper(BStree_node *currentNode, BStree_node *insertionNode)
{
    
    if (currentNode == NULL)
    {
        currentNode = insertionNode;
    }
    
    int keyComp;
    
    keyComp = key_comp(currentNode->key, insertionNode->key);
    
    if (keyComp > 0) //If this is true, it'll be on the left side
    {
        if (currentNode->left == NULL)
        {
            currentNode->left = insertionNode;
            insertionNode->left = NULL;
            insertionNode->right = NULL;
        }
        else
        {
            insertion_helper(currentNode->left, insertionNode);
        }
    }
    else if (keyComp < 0) //If this is true it'll be on the right side
    {
            if ((currentNode->right) == NULL)
            {
                currentNode->right = insertionNode;
                insertionNode->left = NULL;
                insertionNode->right = NULL;
            }
            else
            {
                insertion_helper(currentNode->right, insertionNode);
            }
    }
    else;
}

Data search_helper(BStree_node *currentNode, Key key)
{
    int keyComp; //initialize variable to hold key_comp value
    
    if (currentNode == NULL) //
    {
        return NULL;
    }
    else
    {
        keyComp = key_comp(currentNode->key, key);
    
        if (keyComp == 0)
        {
            return (currentNode->data);
        }
        else if (keyComp > 0) //Left Side
        {
            if (currentNode->left == NULL)
            {
                return NULL;
            }
            else
            {
                //recursively call the function using the left node as the start
                return search_helper(currentNode->left, key);
            }
        }
        else if (keyComp < 0) //Right Side
        {
            if (currentNode->right == NULL)
            {
                return NULL;
            }
            else
            {
                //recursively call the function with the right node as the start
                return search_helper(currentNode->right, key);
            }
        }
        else
        {
            return NULL;
        }
    }
}



//If key is in bst, return key's associate data. If key is not in bst, return NULL
Data bstree_search(BStree bst, Key key)
{
    return search_helper((*bst), key);
}

//In order traversal of bst and print each node's key and data
void bstree_traversal(BStree bst)
{
    traversal_helper(*bst);
}

void traversal_helper(BStree_node *currentNode)
{
    if (currentNode == 0)
        ;
    else
    {
        traversal_helper(currentNode->left);
        keyData_print(currentNode->key, currentNode->data);
        traversal_helper(currentNode->right);
    }
}

void bstree_free_helper(BStree_node *bstNode)
{
    if (bstNode == NULL)
    {
        return;
    }
    bstree_free_helper(bstNode->left);
    bstree_free_helper(bstNode->right);
    key_free(bstNode->key);
    data_free(bstNode->data);
    free(bstNode);
}

//Free all the dynamically allocated memory of bst.
void bstree_free(BStree bst)
{
    bstree_free_helper(*bst);
    free(bst);
}

