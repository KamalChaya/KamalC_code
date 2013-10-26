#include <stdio.h>
#include "cirListDeque.h"

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};

int main() {
	printf("Testing 'createCirListDeque'...\n");
	struct cirListDeque * q = createCirListDeque();
	
	printf("Testing the 'add to back/add to front' functionality...\n");
	addBackCirListDeque(q, 6);
	addBackCirListDeque(q, 5);
	addBackCirListDeque(q, 4);
	addFrontCirListDeque(q, 7);
	addFrontCirListDeque(q, 8);
	addFrontCirListDeque(q, 9);

	printf("Testing the print list function.. given what was added, it should print:\n");
	printf("9 8 7 6 5 4 if the add front/back worked correctly..\n");
	printf("Printing list...\n");
	printCirListDeque(q);
	printf("\n");

	printf("Testing the remove front/back functionality.. afterwards it should print:\n");
	printf("8 7 6 5 if the remove front/back worked correctly..\n");
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printf("Printing list...\n");
	printCirListDeque(q);
	printf("\n");
	
	printf("Removing the front and back, and testing the functions frontCirListDeque() and backCirListDeque()\n");
	printf("These functions should return 7 and 6 respectively\n");
	removeBackCirListDeque(q);
	removeFrontCirListDeque(q);
	
	if ((frontCirListDeque(q) == 7) && (backCirListDeque(q) == 6)) 
		printf("Front and back value returning functions working correctly!\n");
	else
		printf("Front and back value returning functions not working correctly!\n");
	
	
	printf("Testing the reverse functionality..it should print 6 7 if working correctly:\n");
	reverseCirListDeque(q);
	printCirListDeque(q);

	printf("Empty out the deque..\n");
	while(!isEmptyCirListDeque(q)) 
		removeFrontCirListDeque(q);
	
	printf("Remove from front should return an error: \n");
	removeFrontCirListDeque(q);
	
	printf("Using the delete function..\n");
	deleteCirListDeque(q);

	return 0;
}