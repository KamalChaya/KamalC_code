#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 
# define ERROR "Null pointer encountered or list empty, program terminating"

/*
For add link after:
	Does the order in which we perform the operations matter?
*/


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */	 
	if (q != NULL) {
		q->size = 0;
		q->Sentinel = (struct DLink *) malloc(sizeof(struct DLink));
		if (q->Sentinel != NULL) {
			q->Sentinel->next = q->Sentinel;
			q->Sentinel->prev = q->Sentinel;
		}
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = (struct cirListDeque*) malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink * link = (struct DLink *) malloc(sizeof(struct DLink));

	if (link != NULL) 
		link->value = val;
	
	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}

	/*temporary return value..you may need to change it*/
	return(link);	 

}

/* Adds a link after another link
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */	 

	if ((q != NULL) && (lnk != NULL) && (lnk->next != NULL) && (lnk->prev != NULL)) {

		//Create new link with the value v:
		struct DLink * newlnk = _createLink(v);

		/*
		Step1:
		Make the previous pointer of the node after lnk point to the new link

		BEFORE: node after lnk's prev points to lnk, new link is not connected yet
		|lnk|   ->     |lnk->nxt|
		|   |   <-     |        |

		     |newlnk|
			 |      |

		AFTER: lnk->next prev's pointer points to new node
		|lnk|     ->       |lnk->nxt|
		|   |  |newlnk| <- |        | 
		*/

		lnk->next->prev = newlnk;

		/*
		Step2: newlnk's next pointer has to point to lnk->next
		|lnk|     ->       |lnk->nxt|
		|   |  |newlnk| <- |        | 
		|   |  |      | -> |        |

		*/
		newlnk->next = lnk->next;

		/*
		Step3: lnk's next ptr points to newlnk:
		|lnk|     ->       |lnk->nxt|
		|   |->|newlnk| <- |        | 
		|   |  |      | -> |        |
		*/
		lnk->next = newlnk;

		/*
		Step4: newlnk's prev' pointer has to point to lnk:
		|lnk|     ->       |lnk->nxt|
		|   |->|newlnk| <- |        | 
		|   |<-|      | -> |        |
		*/
		newlnk->prev = lnk;

		//Since a new link has been added, we must increment size
		q->size++;
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */
	if (q != NULL)
		_addLinkAfter(q, q->Sentinel->prev, val);

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	
	//To add to the front, we must add a link AFTER the sentinel node
	if (q != NULL) 
		_addLinkAfter(q, q->Sentinel, val);

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}

}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */	 
	if ((q != NULL) && (q->size != 0)) 
		return q->Sentinel->next->value;

	else {
		printf("\n");
		printf(ERROR);
		return -1;
		exit(EXIT_FAILURE);
	}	
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
	if (q != NULL) 
		return q->Sentinel->prev->value;

	else {
		printf("\n");
		printf(ERROR);
		return -1;
		exit(EXIT_FAILURE);
	}
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	
	if ((q != NULL) && (q->size != 0)) {

		/*
		Step 1:
		Make the link before lnk point to the link after
		lnk (Make lnk->prev point to lnk->next)

		|lnk->prev|       |lnk|   ->    |lnk->next|
		|         |   <-  |   |   <-    |         |
		-----------       -----         -----------
		       |                            ^
		       |____________________________|

		*/

		lnk->prev->next = lnk->next;

		/*
		Step 2:
		Make link->next's previous pointer point to lnk->prev:
		
			
		lnk (Make lnk->prev point to lnk->next)


		       ______________________________
		      |                             |
		     \/                             |
		|lnk->prev|       |lnk|   ->    |lnk->next|
		|         |   <-  |   |         |         |
		-----------       -----         -----------
		       |                            ^
		       |____________________________|

		*/

		lnk->next->prev = lnk->prev;

		//Step3: remove lnk
		free(lnk);

		//Decrement the size:
		q->size--;

	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */	 
	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	//Start our temp link at the first node
	struct DLink * tmp = q->Sentinel->next;

	//Keep on freeing while the deque is not empty:
	while (!isEmptyCirListDeque(q)) {
		printf("Freeing link w/ value: %g\n", frontCirListDeque(q));
		removeFrontCirListDeque(q);
	}

	//After all the normal nodes are free, free up the sentinel
	free(q->Sentinel);

	//Make the sentinel a null ptr:
	q->Sentinel = NULL;
}

/* 	Deallocate all the links and the deque itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
	if (q != NULL) {
		freeCirListDeque(q);
		free(q);
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	if (q != NULL) {
		if (q->size == 0)
			return 1;
		else
			return 0;
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	if ((q != NULL) && (!isEmptyCirListDeque(q))) {
		printf("Current size of the deque is: %d\n", q->size);

		//Make a current pointer
		struct DLink * curr = (struct DLink *) malloc(sizeof(struct DLink));

		//Make the current pointer point to the front of the list
		curr = q->Sentinel->next;

		while (curr != q->Sentinel) {
			printf("%g ", curr->value);
			curr = curr->next;
		}
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	
	if ((q != NULL) && (!isEmptyCirListDeque(q))) {
		//Temp links
		struct DLink * idx = q->Sentinel->next;
		struct DLink * tmp;
		q->Sentinel->prev = idx;

		do {
			tmp = idx->next;

			if (tmp->next == q->Sentinel) 
				q->Sentinel->next = tmp;

			idx->next = idx->prev;	
			idx->prev = tmp;
			
			idx = tmp;
		} while (idx != q->Sentinel);
	}

	else {
		printf("\n");
		printf(ERROR);
		exit(EXIT_FAILURE);
	}
}