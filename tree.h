/* @File tree.h
 * @ Brief header file for tree.c
 * @ Author Ahmad Alwazzan
 */
#include "node.h"
#ifndef _TREE_h
#define _TREE_h

typedef struct tree * treeP;

/**
 * @Brief creates a new tree and allocates memory for it
 * @return pointer to the allocated tree struct 
 */
treeP newTree();

/**
 * @brief adds a node to a tree
 * @param tree tree to add a node to
 * @param root the root node of the tree
 * @param node the node to add
 */
void addNode2Tree(treeP tree, nodeP root, nodeP node);

/**
 * @brief returns the root of a given tree
 * @param tree pointer to the tree to access the root
 * @return tree->root pointer to the root 
 */
nodeP getRoot(treeP tree);

/**
 * @brief prints the content of the tree in order
 * @param root the root of the tree
 */
void printInOrder(nodeP root);

/*
 * @brief prints the content of the tree pre order
 * @param root the root of the tree
 */
void printPreOrder(nodeP root);

/*
 * @brief prints the content of the tree post order 
 * @param root the root of the tree
 */
void printPostOrder(nodeP root);

/**
 * @brief searches the tree for a given value
 * @param root the root of the tree
 * @param value the value to search for
 * @return true, if the value is found. false, if the value is not found
 */
int searchTree(nodeP root, char * value);

/*
 * @brief frees all the nodes associated with the root of the tree 
 * @param root the root of the tree
 */
void freeTreeNodes(nodeP root);

/*
 *@brief frees the tree structure along with all the nodes associated with it 
 * @param tree the tree pointer
 * @return NULL
 */
treeP freeTree(treeP tree);

/*
 * @brief deletes a certain node in the tree 
 * @param tree the pointer to the tree
 * @param root the root of the tree
 * @param value the value for the node to be deleted
 * @return returns the root of the tree
 */
nodeP _deleteNodeInTree(treeP tree, nodeP root, char* value);

/*
 * @brief uses _deleteNodeInTree() to set a new root for tree in case its deleted 
 * @param tree 
 * @param root
 * @param value
 * @return true on success. false on failure
 */
int deleteNodeInTree(treeP tree, nodeP root, char* value);

/*
 * @brief sets a root for the given tree 
 * @param tree
 * @param node
 */
void setRoot(treeP tree, nodeP node);

#endif