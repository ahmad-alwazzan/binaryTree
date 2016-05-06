#include "tree.h"

#ifndef _TREEINTERFACE_h
#define _TREEINTERFACE_h
/*
 * @brief creates a new tree and returns a pointer to it
 */
treeP createNewTree();

/*
 * @brief inserts a string into the tree
 * @param tree pointer to the tree
 * @param str pointer to the string
 */
void insertString(treeP tree, char * str);

/*
 * @brief searches for a string in the tree
 * @param tree pointer to the tree
 * @param str pointer to the string
 * @return 1 if true, 0 if false
 */
int searchForString(treeP tree, char * str);

/*
 * @brief deletes a string from the tree
 * @param tree pointer to the tree
 * @param str pointer to the string you want to delete
 * @return 1 if true, 0 if false
 */
int deleteString(treeP tree, char * str);

/*
 * @brief prints the binary tree in order
 * @param tree pointer to the tree
 */
void printTreeInOrder(treeP tree);

/*
 * @brief prints the binary tree pre order
 * @param tree pointer to the tree
 */
void printTreePreOrder(treeP tree);

/*
 * @brief prints the binary tree post order
 * @param tree pointer to the tree
 */
void printTreePostOrder(treeP tree);

/*
 * @brief deletes the entire tree
 * @param tree pointer to the tree
 */
void freeEntireTree(treeP tree);

#endif