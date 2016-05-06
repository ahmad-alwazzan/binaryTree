/*
 * @File node.h
 * @Brief Header file for node.c
 * @Author Ahmad Alwazzan
 */
#ifndef _NODE_h
#define _NODE_h

/* defines a pointer to the node structs*/
typedef struct node * nodeP;

/*
 * @Brief creates a new node and initializes values for it
 * @Param str string to assign the name in the node to
 * @Param lNode left node pointer
 * @Param rNode right node pointer
 * @Return temp pointer to the allocated and initialized node
 */
nodeP newNode(char *str, nodeP rNode,nodeP lNode);

/* 
 * @Brief sets the name in the node
 * @Param node The node to set the name in
 * @Param str the string to assign the name to
 * @Return nothing
 */
void setName(nodeP node, char * str);

/*
 * @Brief returns the name inside a given node
 * @Param node the node to access the name in
 * @Return node->name the name pointer in the node
 */
char * getName(nodeP node);

/*
 * @Brief sets the right node pointer a given node
 * @Param parent Node the parent node to set the pointer in
 * @Param child Node the node that the right pointer points to
 * @Return nothing
 */
void setRight(nodeP parentNode, nodeP childNode );

/*
 * @Brief sets the left node pointer a given node
 * @Param parent Node the parent node to set the left pointer in
 * @Param child Node the node that the left pointer points to
 * @Return nothing
 */
void setLeft(nodeP parentNode, nodeP childNode);

/* 
 * @Brief returns the right node pointer in a given node
 * @Param temp the pointer to the node to access the right pointer
 * @Return node->right the pointer to the right node
 */
nodeP getRight(nodeP temp);

/* 
 * @Brief returns the left node pointer in a given node
 * @Param temp the pointer to the node to access the left pointer
 * @Return node->left the pointer to the right node
 */
nodeP getLeft(nodeP temp);

/*
 * @Brief compares the the values inside two nodes and returns an integer based 
 		  on strcmp()
 * @Param first
 * @param second
 * return strcmp(first, second)
 */
int compareNodes(nodeP first, nodeP second);
/*
 * @Brief frees the memory allocated for the node structure
 * @Param node the node the be freed
 * @Return NULL
 */
nodeP freeNode(nodeP node);

/*
 * @Brief compares the node's content to a given value based on strcmp()
 * @Param node the node to compare to the value
 * @Param the value to compare to the node
 * @Return strcmp(node->name, value)
 */
int compareNode2Value(nodeP node,char* value);

/*
 * @Brief prints the content of the node to stdout
 */
void printNode(nodeP node);

#endif