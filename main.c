/* @file main.c
 * @brief tests the tree functions
 * @Author Ahmad Alwazzan
 */
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "tree.h"
#include  "treeInterface.h"

int main(int argc, char ** argv)
{

	char temp[300][32];
	int i;
	treeP t1 = createNewTree();

	//adding list of names
	FILE * fp = fopen("./names.txt", "r");

	for(i=0;i<300;i++){
		fscanf(fp, "%s 	", &temp[i]);
		//fprintf(stdout, "%s\n", temp[i]);
		insertString(t1,temp[i]);
	}

	//testing functions
	insertString(t1,"Fatema");
	insertString(t1,"Ahmad");
	insertString(t1,"Essa");
	printTreeInOrder(t1);
	
	deleteString(t1,"Ahmad");
	deleteString(t1,"Jason");
	deleteString(t1,"Notinlist"); //name not in list
	deleteString(t1,"Fatema");
	

	printf("\n\n\n");
	printTreeInOrder(t1);

	if(searchForString(t1,"Essa")){
		fprintf(stdout, "Found 'Essa using searchForString()' \n");
	}

	//freeing the whole tree
	freeEntireTree(t1);

	return 0;

}