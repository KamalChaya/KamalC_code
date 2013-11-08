#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

//number compare
/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data2 *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */


int compare(TYPE left, TYPE right) {
	struct data2 * Ldata2 = (struct data2 *) left;
	struct data2 * Rdata2 = (struct data2 *) right;
	
	if (Ldata2->number < Rdata2->number)
		return -1;

	else if (Ldata2->number > Rdata2->number)
		return 1;

	else 
		return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
	struct data2 * curdata2 = (struct data2 *) curval;
	printf("\nnumber: %d", curdata2->number);
}


/************************************************************************************************************************
from here to the end of this file are a set of fucntions for testing the fucntions of the BST
***************************************************************************************************************************/
/*
function to built a Binary Search Tree (BST) by adding numbers in this specific order
the graph is empty to start: 50, 13, 110 , 10

*/
struct BSTree *buildBSTTree() {
    /*     50
         13  110
        10 
    */
    struct BSTree *tree	= newBSTree();		
		
	/*Create value of the type of data2 that you want to store*/
	
	
		struct data2 *myData1 = (struct data2 *) malloc(sizeof(struct data2));
		struct data2 *myData2 = (struct data2 *) malloc(sizeof(struct data2));
		struct data2 *myData3 = (struct data2 *) malloc(sizeof(struct data2));
		struct data2 *myData4 = (struct data2 *) malloc(sizeof(struct data2));
			
		myData1->number = 50.0;
		myData2->number = 13.0;
		myData3->number = 110.0;
		myData4->number = 10.0;
	
	/*add the values to BST*/
	addBSTree(tree, myData1);
	addBSTree(tree, myData2);
	addBSTree(tree, myData3);
	addBSTree(tree, myData4);
    
    return tree;
}

/*
function to print the result of a test function
param: predicate:  the result of the test 
       nameTestFunction : the name of the function that has been tested
	   message

*/
void printTestResult(int predicate, char *nameTestFunction, char *message){
	if (predicate)
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	   printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

/*
fucntion to test each node of the BST and their children

*/
void testAddNode() {
    struct BSTree *tree	= newBSTree();
	
		struct data2 myData1, myData2, myData3, myData4;
			
		myData1.number = 50.0;
		myData2.number = 13.0;
		myData3.number = 110.0;
		myData4.number = 10.0;
	
    addBSTree(tree, &myData1);
    //check the root node
    if (compare(tree->root->val, (TYPE *) &myData1) != 0) {
		
        printf("addNode() test: FAIL to insert 50.0 as root\n");
        return;
    }
	//check the tree->cnt value after adding a node to the tree
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50.0 as root\n");
        return;
    }
	
    else printf("addNode() test: PASS when adding 50.0 as root\n");
    addBSTree(tree, &myData2);
    
    //check the position of the second element that is added to the BST tree
    if (compare(tree->root->left->val, (TYPE *) &myData2) != 0) {
        printf("addNode() test: FAIL to insert 13.0 as left child of root\n");
        return;
    }
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13.0 as left of root\n");
        return;
    }
	
    else printf("addNode() test: PASS when adding 13.0 as left of root\n");
	
    
    addBSTree(tree, &myData3);
        
    //check the position of the third element that is added to the BST tree    
    if (compare(tree->root->right->val, (TYPE *) &myData3) != 0) {
        printf("addNode() test: FAIL to insert 110.0 as right child of root\n");
        return;
    }
    else if (tree->cnt != 3) {
		
        printf("addNode() test: FAIL to increase count when inserting 110.0 as right of root\n");
        return;
    }
	
    else printf("addNode() test: PASS when adding 110.0 as right of root\n");
	addBSTree(tree, &myData4);
    
	//check the position of the fourth element that is added to the BST tree
    if (compare(tree->root->left->left->val, (TYPE *) &myData4) != 0) {
		
        printf("addNode() test: FAIL to insert 10.0 as left child of left of root\n");
        return;
    }
    else if (tree->cnt != 4) {
		
        printf("addNode() test: FAIL to increase count when inserting 10.0 as left of left of root\n");
        return;
    }
	
    else printf("addNode() test: PASS when adding 10.0 as left of left of root\n");
}

/*
fucntion to test that the BST contains the elements that we added to it

*/
void testContainsBSTree() {
    struct BSTree *tree = buildBSTTree();
    
	
		struct data2 myData1,  myData2,  myData3,  myData4, myData5;
		
		myData1.number = 50.0; //root
		myData2.number = 13.0; //left
		myData3.number = 110.0; //right
		myData4.number = 10.0; //left of left
		myData5.number = 111.0; //not in tree
		
		printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50.0 as root");
			
		printTestResult(containsBSTree(tree, &myData2), "containsBSTree", "when test containing 13.0 as left of root");
		
		printTestResult(containsBSTree(tree, &myData3), "containsBSTree", "when test containing 110.0 as right of root");
			
		printTestResult(containsBSTree(tree, &myData4), "containsBSTree", "when test containing 10.0 as left of left of root");

		 //check containsBSTree fucntion when the tree does not contain a node    
		printTestResult(!containsBSTree(tree, &myData5), "containsBSTree", "when test containing 111.0, which is not in the tree");	
}


/*
fucntion to test the left_Most_element 

*/
void testLeftMost() {
    struct BSTree *tree = buildBSTTree();
    
	
		struct data2 myData3, myData4;

		myData3.number = 110.0;
		myData4.number = 10.0;
    
	printTestResult(compare(_leftMost(tree->root), &myData4) == 0, "_leftMost", "left most of root");
    
	printTestResult(compare(_leftMost(tree->root->left), &myData4) == 0, "_leftMost", "left most of left of root");
    
	printTestResult(compare(_leftMost(tree->root->left->left), &myData4) == 0, "_leftMost", "left most of left of left of root");
    
	printTestResult(compare(_leftMost(tree->root->right), &myData3) == 0, "_leftMost", "left most of right of root");

}

void testRemoveLeftMost() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    
    cur = _removeLeftMost(tree->root);

	printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 1st try");
    
    cur = _removeLeftMost(tree->root->right);
    printTestResult(cur == NULL, "_removeLeftMost", "removing leftmost of right of root 1st try");
   
 	cur = _removeLeftMost(tree->root);
    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 2st try");
}

/*
Change to 1 when you want to use the below functions
*/

#if 1

void testRemoveNode() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
	
	
		struct data2 myData1,  myData2,  myData3,  myData4;
			
		myData1.number = 50.0;
		myData2.number = 13.0;
		myData3.number = 110.0;
		myData4.number = 10.0;
    
    _removeNode(*tree, tree->root, &myData4);
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL, "_removeNode", "remove left of left of root 1st try");
	        
    _removeNode(*tree, tree->root, &myData3);
	 printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL, "_removeNode", "remove right of root 2st try");
	   
    _removeNode(*tree, tree->root, &myData2);
	printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left == 0, "_removeNode", "remove right of root 3st try");
        
    cur = _removeNode(*tree, tree->root, &myData1);
    printTestResult(cur == NULL, "_removeNode", "remove right of root 4st try");       
}
#endif