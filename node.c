/*
 * @File node.c
 * @Brief Implements a simple node holding a string and two pointers to other nodes
 * @Author Ahmad Alwazzan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct node{
	char * name;
	nodeP right;
	nodeP left;
};

nodeP newNode(char *str, nodeP rNode,nodeP lNode){
	nodeP temp = (nodeP) malloc(sizeof(struct node));
	if (!temp){
		fprintf(stderr, "Failed to allocate memory for Node\n");
		return NULL;
	}
	else{
		temp->name = str;
		temp->right = rNode;
		temp->left = lNode;
	}
	return temp;
}

void setName(nodeP node, char * str){
	if (node && str) node->name = str;
}

char* getName(nodeP node){
	if(node)
		return node->name;
	else
		return NULL;
}

void setRight(nodeP parentNode, nodeP childNode ){
	parentNode->right = childNode;
}

void setLeft(nodeP parentNode, nodeP childNode){
	parentNode->left = childNode;
}

nodeP getRight(nodeP temp){ 
	return temp-> right;
	
}

nodeP getLeft(nodeP temp){
	return temp->left;
}

int compareNodes(nodeP first, nodeP second){
	
	if(first && second) return strcmp(first->name, second->name);
	else{
		fprintf(stderr,"invalid pointers passed to compareNodes(nodeP , nodeP)\n");
		return -1;
	}
}

nodeP freeNode(nodeP node){
	if(node){
		free(node);
		return NULL;
	}

	else{
		fprintf(stderr,"invalid pointer passed to freeNode(nodeP )\n");
		return node;
	}
}

int compareNode2Value(nodeP node, char* value)
{
	return strcmp(node->name,value);
}

void printNode(nodeP node){
	if(node){
		fprintf(stdout,"%s\n",node->name);
	}
}
