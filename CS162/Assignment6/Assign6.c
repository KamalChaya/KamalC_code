/*
Author: Kamal Chaya
Filename: assignment6.c
Description: Uses linked lists to sort user inputted integers in ascending order
Input: The integers the user wishes to sort
Output: The integers sorted.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

typedef struct node * nodePtr;

int main() {
	//tp is the pointer that iterates through the list, it is used when we rearrange nodes.
	nodePtr head = NULL, cur, tp, tmp, prev;
	
	char yOrN = 'y';
	int num, cnt = 0, i, swapcnt = 0;
	
	//making the linked list and populating it
	while (yOrN == 'y') {
		cur = (nodePtr) malloc(sizeof(struct node)); //make a new node on the heap every time they want to add a number.
		printf("\nDo you want to input an integer? ");
		/*
		 Earlier I was having a problem where there was no space before the %c, and this
		 was causing my program to exit before I would have the chance to enter the 
		 character (this happened on the 2nd iteration). Now that I have added the space
		 this is no longer an issue, but why? I know it has something to do with the 
		 input buffer but I don't know exactly why.
		*/
		
		scanf(" %c", &yOrN);
		
		if (yOrN == 'y') {
			printf("\nEnter the integer: ");
			scanf("%d", &num);
			cnt++;
			cur->val = num;
			
			/*
			 This makes the current node's
			 next ptr
			 point to the beggining of the
			 linked list, which is what head
			 is at the moment.
			 ---    ----
			 CUR -> NULL
			 ---    ----
			*/
			cur->next = head;
			/*
			 At this moment, curr is pointing 
			 to the newly made node, so it
			 is at the front of the list. Because
			 the head node should always be the
			 first node in the list, we make head
			 point to the same thing CURR points to
			 ---    ----
			 CUR -> NULL
			 ---    ----
			  ^
			  |
			 ----
			 HEAD
			 ----
			*/
			head = cur;
		}
		
		else
			break;
	}
	
	//Initialize pointers. 
	tp = head;
	prev = head;
	tmp = tp->next;
	
	/* Printing occurs in the reverse order.
	   If I enter:   We print:
	        1            3 < tp->val
	        2            2 < tp2->val
	        3            1
	        --------------
	        3            1 < tp-> val
	        2            2 < tp2-> val
	        1            3
	     (eg. entering numbers in ascending order will 
	      result of a print in descending order.)
	      
	   
	 */
	// * * * * * *
	
	//tmp = head, tmp2 = head;
	//nodePtr tmp = NULL;
	//Sort the numbers. 
	//while (tp->next->next != NULL) {
	for (i = 1; i <= cnt*cnt; i++) {
		if (tp->val > tmp->val) {
			swapcnt++;
			/*
			 If we are at the beggining, (nodes are like this initially),
			 -----    -----    -----    -----      
			 | 4 | -> | 3 | -> | 2 | -> | 1 | ->NULL
			 -----    -----    -----    -----     
			tp/prev    tmp

			 First swap:
			 1st rearrange:
			 -----  -----    -----    -----      
			 | 4 |  | 3 | -> | 2 | -> | 1 | ->NULL   (tp->next = tmp->next)
			 -----  -----    -----    -----                                   
			   |_______________^

			 2nd rearrange:
			   _______
			   V      |
			 -----  -----    -----    -----      
			 | 4 |  | 3 |    | 2 | -> | 1 | ->NULL   (tmp->next = prev->next)
			 -----  -----    -----    -----                                   
			   |_______________^

			  "straightened":
			  -----    -----    -----    -----
			  | 3 | -> | 4 | -> | 2 | -> | 1 | -> NULL  
			  -----    -----    -----    -----
			 */
			if (tp == head) {
				//Rearrange nodes
				tp->next = tmp->next;
				tmp->next = prev;

				//Reset head to beggining
				head = tmp;
				prev = head;
			}

			/*
			 
			 -----    -----    -----    -----
			 | 3 | -> | 4 | -> | 2 | -> | 1 | -> NULL
			 -----    -----    -----    -----
			 */
			else if (tp != head) { 
				//Rearrange nodes
				tp->next = tmp->next;
				tmp->next = prev->next;
				prev->next = tmp;

				//increment
				prev = prev->next;
			}	

			
			tmp = tp->next;
		}

		else if (!(tp->val > tmp->val))	 {
			if (tp == head) {
				tmp = tmp->next;
				tp = tp->next;
			}

			else {
				prev = prev->next;
				tmp = tmp->next;
				tp = tp->next;
			}
			

		}

		if (tmp == NULL) {
			if (swapcnt == 0) 
				break;
	
			//reinit pointers
			tp = head;
			prev = head;
			tmp = tp->next;
			swapcnt = 0;
		}
	}

	printf("\nYour numbers in ascending order are: ");

	//Print out the linked list
	tp = head; //tp must be rest to head since we are starting at the beggining of hte list
	for (i = 0; i <= cnt - 1; i++) {
		printf("%d ", tp->val);
		tp = tp->next; //increment traversal pointer
	}

	printf("\n");
	return 0;
}