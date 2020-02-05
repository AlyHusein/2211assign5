#ifndef bstree_h
#define bstree_h

#include <stdio.h>
#include "datatype.h"

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;

typedef BStree_node** BStree;

BStree bstree_ini(void);
//Allocate memory of type BStree_node*, set the value to NULL and return pointer to allocated memory

void insertion_helper(BStree_node *currentNode, BStree_node *insertionNode);

BStree_node *new_node(Key key, Data data);
//Helper function for btree_insert
//Creates a pointer to a node containing the key and data given for insertion

void bstree_insert(BStree bst, Key key, Data data);
//Insert data with key into bst
//If Key is in bst, do nothing
//May want to use helper funtion for insertion to create a pointer to tree node from key, data
//BStree_node *new_node(Key key, Data data);

Data search_helper(BStree_node *currentNode, Key key);
//Recursive helper function to search through the tree

Data bstree_search(BStree bst, Key key);
//If key is in bst, return key's associate data. If key is not in bst, return NULL

void bstree_traversal(BStree bst);
//In order traversal of bst and print each node's key and data

void traversal_helper(BStree_node *currentNode);
//Recursive function to help traverse the tree

void bstree_free_helper(BStree_node *bstNode);
//Helper function to free all the nodes in the tree

void bstree_free(BStree bst);
//Free all the dynamically allocated memory of bst

#endif /* bstree_h */
