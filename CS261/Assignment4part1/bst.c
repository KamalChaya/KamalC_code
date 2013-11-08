/*
 File: bst.c
 Implementation of the binary search tree data structure.
 Kamal Chaya, Song Ge
 11.04.2013
 Microsoft Visual Studio 2012

 */

/*
If the user enters a value thats equal to a value already in the tree,
none of the recursive calls are triggered and the tree is returned as is.

For the removeNode function, dont we have to change the function signature 
so that we pass in the BSTree (the contains function needs this paramter).
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

#define ERROR "Error: Mem ptr is null, program terminating..."



/*
Function to display error message due to null pointers or other issues
pre: none
post: program terminates
*/

void errorEndProg() {
	printf(ERROR);
	printf("\n");
	exit(EXIT_FAILURE);
}

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	if (tree != NULL) {
		initBSTree(tree);
		return tree;
	}

	else 
		errorEndProg();
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	struct Node * newNode;
	if (val != NULL) {
		if (cur == NULL) {
			newNode = (struct Node *) malloc(sizeof(struct Node));
			if (newNode != NULL) {
				newNode->val = val;
				newNode->left = newNode->right = NULL;
				return newNode;
			}

			else
				errorEndProg();
		}

		//If the value is less than cur's, recursive call left
		else if (compare(val, cur->val) < 1) 
			cur->left = _addNode(cur->left, val);

		//If the value is greater than cur's, recursive call right
		else if (compare(val, cur->val) == 1)
			cur->right = _addNode(cur->right, val);

		return cur;
	}

	else
		errorEndProg();
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	
		struct BSTree * subTree;
		if ((tree != NULL) && (val != NULL)) {
			subTree = (struct BSTree *) malloc (sizeof(struct BSTree));
			//Base case
			if (compare(tree->root->val, val) == 0)
				return 1;

			//If val is less than the current node's value
			else if (compare(val, tree->root->val) == -1) {

				//IF we have not yet reached the end of the tree..
				if (tree->root->left != NULL) {
					subTree->root = tree->root->left;
					return containsBSTree(subTree, val);
				}

				//At this point we have reached the end of the tree and the value has not been found
				else 
					return 0;
			}

			//If val is greater than current node's value
			else if (compare(val, tree->root->val) == 1) {
				//IF we have not yet reached the end of the tree..
				if (tree->root->right != NULL) {
					subTree->root = tree->root->right;
					return containsBSTree(subTree, val);
				}

				//At this point we have reached the end of the tree and the value has not been found
				else 
					return 0;
			}

			return 0;
		}
	
		else
			errorEndProg();
	
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	if ((cur != NULL) && (cur->left != NULL)) 
		return (_leftMost(cur->left));

	return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	if (cur != NULL) {
		if (cur->left != NULL) {
			cur->left = _removeLeftMost(cur->left);
			return cur;
		}

		else {
			struct Node * tmp = cur->right;
			free(cur->right);
			return tmp;
		}
	}

	else
		errorEndProg();
}


/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
		tree the BST tree with the alleged value to remove in it, so that
		we can use the contains function to check if val is in the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct BSTree tree, struct Node *cur, TYPE val)
{
	if ((cur != NULL) && (val != NULL)) {
		if (containsBSTree(&tree, val)) {
			struct Node * tmp = NULL;
			//Base Case
			if (compare(val, cur->val) == 0) { //If the value is found
				//If the node has 2 children
				if ((cur->left != NULL) && (cur->right != NULL)) {
					tmp = cur;
					tmp->val = _leftMost(cur->right);
					cur->right = _removeLeftMost(cur->right);
				}

				//If the node has less than 2 children:
				else {
					tmp = cur;
					if (cur->left == NULL) 
						return cur->right;
				
					else if (cur->right == NULL)
						return cur->left;

					free(tmp);
				}
			}

			else if (compare(val, cur->val) == -1)
				cur->left = _removeNode(tree, cur->left, val);

			else if (compare(val, cur->val) == 1)
				cur->right = _removeNode(tree, cur->right, val);

			return cur;
		}

		else
			printf("Error: node with specified not inside BST, cannot remove\n");
	}

	else
		errorEndProg();
}


/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(*tree, tree->root, val);
		tree->cnt--;
	}
}


/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
  in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);	 
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree) {
	 if (tree == 0) return;	 
	 printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif

/*

Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){	

   //After implementing your code, please uncommnet the following calls to the test functions and test your code 
	
	/*
	printf("\nTesting first struct using the first compare function...");

	mydata1->name = "ann";
	mydata1->number = 6;
	mydata2->name = "bob";
	mydata2->number = 5;
	mydata3->name = "jill";
	mydata3->number = 7;
	mydata4->name = "jack";
	mydata4->number = 7;

	printf("\nPopulating tree: 6, 5, 7, 7");
	addBSTree(tree, mydata1);
	addBSTree(tree, mydata2);
	addBSTree(tree, mydata3);
	addBSTree(tree, mydata4);

	printf("\nTesting compare() on nodes 6(root) and 5(root->left), should return 1");
	printf("\nbecause 6 > 5");
	if (compare(tree->root->val, tree->root->left->val) == 1)
		printf("\ncompare() works correctly on nodes 6 and 5");
	 
	else 
		printf("\ncompare() doesnt work correctly with nodes 6 and 5");

	printf("\nTesting compare() on nodes 5(root->left), and 7(root->right), should return -1");
	printf("\nbecause 5 < 7");
	if (compare(tree->root->left->val, tree->root->right->val) == -1)
		printf("\ncompare() works correctly on nodes 5 and 7");
	
	else
		printf("\ncompare() doesnt work correctly with nodes 5 and 7");

	printf("\nTesting compare() on nodes 7(root->right) and duplicate 7 (root->right->left), should return 0");
	printf("\nbecause 7 = 7");
	if (compare(tree->root->right->left->val, tree->root->right->val) == 0)
		printf("\ncompare() works correctly on nodes 7 and 7 duplicate");

	else
		printf("\ncompare() does not work correctly on nodes 7 and 7 duplicate"); */

	printf("\nTesting first struct using the already given functions\n");
    testAddNode();
	
	printf("\n");
    testContainsBSTree();
	
	printf("\n");
    testLeftMost();
	
	printf("\n");
    testRemoveLeftMost();
	
	printf("\n");
    testRemoveNode();
    
	
	return 0;
}