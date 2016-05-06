/* @file treeInterface.c
 * @brief  	- implements and interface to  a binary tree
 			- uses node.h and tree.c as ADTs to implement a binary tree
 			- this ties the functionality of node.c and tree.c into one
 * @Author Ahmad Alwazzan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeInterface.h"
#include "tree.h"
#include "node.h"

treeP createNewTree()
{
	treeP temp = newTree();
	return temp;
}

void insertString(treeP tree, char * str)
{
	 nodeP temp = newNode(str, NULL, NULL);
	 addNode2Tree(tree, getRoot(tree), temp);
}

int searchForString(treeP tree, char * str){
	return  searchTree(getRoot(tree), str);
}

int deleteString(treeP tree, char * str){
	return deleteNodeInTree(tree, getRoot(tree), str);
}

void printTreeInOrder(treeP tree){
	printInOrder(getRoot(tree));
}

void printTreePreOrder(treeP tree){
	printPreOrder(getRoot(tree));
}

 void printTreePostOrder(treeP tree){
	printPostOrder(getRoot(tree));
}

void freeEntireTree(treeP tree){
	tree =  freeTree(tree);
}
