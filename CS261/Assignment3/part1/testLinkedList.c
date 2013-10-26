#include "LinkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//in _printList, should we be freeing current?

int main() {
	
	printf("Testing createLinkedList()...\n");
	struct linkedList * q = createLinkedList();
	
	printf("Testing deque functions..\n");
	printf("Testing add to back/front..\n");
	addBackList(q, 6);
	addBackList(q, 5);
	addBackList(q, 4);
	addFrontList(q, 7);
	addFrontList(q, 8);
	addFrontList(q, 9);
	
	
	printf("Testing printlist function...if working correctly it should print:\n");
	printf(" 9 8 7 6 5 4 \n");
	printf(" printing list..\n");
	_printList(q);
	printf("\n");
	
	printf("Testing remove from front/back functionality, should print 8 7 6 5\n");
	removeFrontList(q);
	removeBackList(q);
	
	
	printf("Printing list..\n");
	_printList(q);
	printf("\n");
	
	printf("Testing frontList() and backList() functions after removing front and back,\n");
	printf("the functions should return 7 and 6, respectively\n");	
	removeBackList(q);
	removeFrontList(q);
	
	if ((frontList(q) == 7) && (backList(q) == 6))
		printf("frontList() and backList() return correct values!\n");
	else
		printf("frontList() and backList() do not return correct values!\n");	
		
	printf("Testing bag functions..\n");
	printf("testing addList... Adding 2 and 3 to bag..\n");
	addList(q, 2);
	addList(q, 3);
	
	printf("Testing contains, should return true for 2 and 3, and false for 1 (1 was not added) \n");
	if (containsList(q, 2) && containsList(q, 3) && !containsList(q, 1)) 
		printf("Contains and add functions working correctly..\n");
	
	else
		printf("Contains and add functions not working correctly..\n");
	
	printf("Testing removeList function... Removing 2, contains should not return true for 2.\n");
	printf("However, contains should still return true for 3 since it has not been removed and is still in the bag.\n");
	removeList(q, 2);
	
	if (containsList(q, 3) && !containsList(q, 2)) 
		printf("remove function working correctly..\n");	
	
	else
		printf("remove function not working correctly..\n");		

		
	printf("Empty out the bag..\n");
	while(!isEmptyList(q)) 
		removeFrontList(q);
	
	printf("Remove from front should return an error because bag is empty: \n");
	removeFrontList(q);
	
	return 0;
}