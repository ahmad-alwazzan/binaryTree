/*
 * @File tree.c
 * @Brief Implements a Binary Tree
 * @Author Ahmad Alwazzan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "node.h"

#define true 1
#define false 0

struct tree{
	nodeP root;
	int count;
};

treeP newTree(){
	treeP temp = (treeP) malloc(sizeof(struct tree));
	if (! temp){
		fprintf(stderr,"failed to allocate memory to tree\n");
		return NULL;
	}
	else{
		temp-> root = NULL;
		temp-> count = 0;
		return temp;
	}
}

nodeP getRoot(treeP tree)
{
	return tree->root;
}

void addNode2Tree(treeP tree, nodeP root, nodeP node)
{
	if (tree-> root == NULL){
		tree->root = node;
		tree->count++;
		return;
	}

	else{
		int x = compareNodes(root, node);
		if(x< 0){
			 if(getRight(root) == NULL){
			 	setRight(root,node);
			 	return;
			 }
			 else
			 	addNode2Tree(tree, getRight(root),node);
		}
		else if(x >= 0){
			if(! getLeft(root)){
				setLeft(root,node);
				return;
			}
			else
				addNode2Tree(tree, getLeft(root),node);
		}
	}
	return;
}


void printInOrder(nodeP root){
	if (root){
		printInOrder(getLeft(root));
		printNode(root);
		printInOrder(getRight(root));
	}
}

void printPreOrder(nodeP root){
	if(root){
		printNode(root);
		printPreOrder(getLeft(root));
		printPreOrder(getRight(root));
	}
}

void printPostOrder(nodeP root){
	if(root){
		printPostOrder(getLeft(root));
		printPostOrder(getRight(root));
		printNode(root);
	}
}

int searchTree(nodeP root, char *value)
{
	if (root){
		if(compareNode2Value(root,value) == 0){
			return true;
		}
		else if(compareNode2Value(root,value) > 0){
			return searchTree(getLeft(root),value);
		}
		else{
			return searchTree(getRight(root),value);
		}
	}
	else{
		return false;
	}
}

void freeTreeNodes(nodeP root){
	if (root){
		nodeP left = getLeft(root);
		nodeP right = getRight(root);
		freeNode(root);
		freeTreeNodes(left);
		freeTreeNodes(right);
	}
}

treeP freeTree(treeP tree){
	freeTreeNodes(tree->root);
	free(tree);
	return NULL;
}

nodeP _deleteNodeInTree(treeP tree, nodeP root, char * value){
	nodeP p,p2;
	if(!root) return root;
	if(compareNode2Value(root,value) == 0) {
		if(!getRight(root) && !getLeft(root)){
			freeNode(root);
			tree ->count --;
			return NULL;
		}
		else if(!getLeft(root)){
			p = getRight(root);
			freeNode(root);
			tree->count --;
			return p;
		}
		else if(!getRight(root)){
			p = getLeft(root);
			freeNode(root);
			tree ->count--;
			return p;
		}
		else {
			p2 = getRight(root);
			p = getRight(root);
			while(getLeft(p)) p = getLeft(p);
			setLeft(p,getLeft(root));
			freeNode(root);
			tree->count --;
			return p2;
		}
	}
	else if(compareNode2Value(root,value) < 0){
		setRight(root,_deleteNodeInTree(tree, getRight(root),value));
	}
	else{
		setLeft(root,_deleteNodeInTree(tree, getLeft(root), value));
	}
	return root;
}

int deleteNodeInTree(treeP tree, nodeP root, char* value)
{
	nodeP temp = _deleteNodeInTree(tree, root,value);
	if(!temp) return false;
	else{
		tree->root = temp;
		return true;
	}
	
}

void setRoot(treeP tree, nodeP node)
{
	tree->root = node;
}