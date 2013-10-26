#include "LinkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR "Null pointer encountered, terminating program."


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
param: none
pre: none
post: none
*/

/* Prints out error message and terminates program */

void terminate() {
	printf("\n");
	printf(ERROR);
	printf("\n");
	exit(EXIT_FAILURE);
}

/*
initList
param: lst the linkedList
pre: lst is not null
post: lst size is 0
*/

void _initList(struct linkedList *lst) {
	/* FIXME: you must write this */
	if (lst != NULL) {
		lst->size = 0;
		lst->firstLink = (struct DLink *) malloc(sizeof(struct DLink));
		lst->lastLink = (struct DLink *) malloc(sizeof(struct DLink));

		/* Check to see if firstlink and lastlink  are not NULL */
		if (lst->firstLink != NULL && lst->lastLink != NULL) {
			/* Set up empty linked list with front and back sentinel pointing to each other */
			lst->firstLink->next = lst->lastLink;
			lst->lastLink->prev = lst->firstLink;
		}
		else
			/* Calling error message */
			terminate();
	}
}

/*
createList
param: none
pre: none
post: firstLink and lastLink reference sentinels
*/

struct linkedList *createLinkedList()
{
	struct linkedList *newList = (struct linkedList *) malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
_addLinkBeforeBefore
param: lst the linkedList
param: l the  link to add before
param: v the value to add
pre: lst is not null
pre: l is not null
post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */

	/* Checking to see that lst and l are not null*/
	if (lst != NULL && l != NULL) {
		/* Must create new link to add before link l */
		struct DLink * newlnk = (struct DLink*) malloc(sizeof(struct DLink));
		if(newlnk != NULL) {
			newlnk->value = v;
			/* Set new link's next pointer to point to l*/
			newlnk->next = l;
			/* Set new link's previous pointer to point to l's previous */
			newlnk->prev = l->prev;
			/* Set l->prev's next pointer to point to new link */
			l->prev->next = newlnk;
			/* Set l's previous pointer to point to new link*/
			l->prev = newlnk;
			/*Increment list size by one to keep trank of added link*/
			lst->size++;
		}
		else 
			terminate();
	}
	else 
		terminate();
}

/*
_removeLink
param: lst the linkedList
param: l the link to be removed
pre: lst is not null
pre: l is not null
post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	if (lst != NULL && l != NULL) {
		/* Set l->prev's next pointer to point to l's next*/
		l->prev->next = l->next;
		/* Set l->next's previous pointer to point to l's previous*/
		l->next->prev = l->prev;
		/* Decrement list size by one to keep track of deleted link */
		lst->size--;
		/* Must free l's memory space once removed */
		free(l);
	}
	else
		terminate();
}

/*
isEmptyList
param: lst the linkedList
pre: lst is not null
post: none
*/
int isEmptyList(struct linkedList *lst) {
	/* FIXME: you must write this */
	if (lst != NULL) {
		/*Checking list size to see if list is empty by compaing size to 0*/
		if (lst->size == 0)
			return (1);
		else {
			/*temporary return value...you may need to change this */
			return (0);
		}
	}
	else 
		terminate();
}

/* De-allocate all links of the list

param: 	lst		pointer to the linked list
pre:	none
post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while (!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);
}

/* 	Deallocate all the links and the linked list itself.

param: 	v pointer to the dynamic array
pre:	v is not null
post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	if (lst != 0){
		freeLinkedList(lst);
		free(lst);
	}
	else
		terminate();
}


/* Function to print list
Pre: lst is not null
*/
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
	/*Check if list is not NULL*/
	if (lst != NULL) {
		/* Must make a new link to keep track of current position */
		struct DLink * current = (struct DLink*) malloc(sizeof(struct DLink));
		/* Set current link to list's first link's next */
		current = lst->firstLink->next;
		/* Print each value of a link in linked list through while loop*/
		while (current != lst->lastLink){
			/* Set current to current's next*/
			printf("%d\n", current->value);
			current = current->next;
		}
	}
	else
		terminate();
}

/* ************************************************************************
Deque Interface Functions
************************************************************************ */

/*
addFrontList
param: lst the linkedList
param: e the element to be added
pre: lst is not null
post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{

	/* FIXME: you must write this */
	/* Checking to see that lst and l are not null*/
	if (lst != NULL) {
		/* Calls add link before function and increment size by one */
		_addLinkBefore(lst, lst->firstLink->next, e);
	}
	else
		terminate();
}

/*
addBackList
param: lst the linkedList
param: e the element to be added
pre: lst is not null
post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
	if (lst != NULL) {
		/* Calls add link before function and increment size by one */
		_addLinkBefore(lst, lst->lastLink, e);
	}
	else
		terminate();
}

/*
frontList
param: lst the linkedList
pre: lst is not null
pre: lst is not empty
post: none
*/
TYPE frontList(struct linkedList *lst) {
	/* FIXME: you must write this */
	/* Checking to see if list is not NULL or empty*/
	if (lst != NULL && !isEmptyList(lst)) {
		/* Returns the first link's value*/
		return (lst->firstLink->next->value);
	}
	else
		terminate();
}

/*
backList
param: lst the linkedList
pre: lst is not null
pre: lst is not empty
post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/* Checking to see if list is not NULL or empty*/
	if (lst != NULL && !isEmptyList(lst)) {
		/* Returns the last link's value*/
		return (lst->lastLink->prev->value);
	}
	else
		terminate();
}


/*
removeFrontList
param: lst the linkedList
pre:lst is not null
pre: lst is not empty
post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {
	/* FIXME: you must write this */
	/* Checking to see if list is not NULL or empty*/
	if (lst != NULL && !isEmptyList(lst)) {
		/* Removes the first link from linked list*/
		_removeLink(lst, lst->firstLink->next);
	}
	else
		terminate();
}

/*
removeBackList
param: lst the linkedList
pre: lst is not null
pre:lst is not empty
post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/* Checking to see if list is not NULL or empty*/
	if (lst != NULL && !isEmptyList(lst)) {
		/* Removes the last link from linked list*/
		_removeLink(lst, lst->lastLink->prev);
	}
	else
		terminate();
}


/* ************************************************************************
Bag Interface Functions
************************************************************************ */

/*
Add an item to the bag
param: 	lst		pointer to the bag
param: 	v		value to be added
pre:	lst is not null
post:	a link storing val is added to the bag
*/
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
	/* Checking to see if list is pointing to NULL*/
	if (lst != NULL)
		/* Since this is a back it does not matter when we add a link */
		_addLinkBefore(lst, lst->firstLink->next, v);
	else
		terminate();
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
the specified value is in the collection
true = 1
false = 0

param:	lst		pointer to the bag
param:	e		the value to look for in the bag
pre:	lst is not null
pre:	lst is not empty
post:	no changes to the bag
*/
int containsList(struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */

	if (lst != NULL && !isEmptyList(lst)){
		/* Make a current link to search for value e in bag */
		struct DLink * current = (struct DLink*) malloc(sizeof(struct DLink));
		if(current != NULL){
			/* Set current link to first link in back */
			current = lst->firstLink;
			/* Repeat search in bag until find value e */
			while (current->next != lst->lastLink) {
				/* Compare value of current link to value of e */
				if (current->value == e) {
					/* Returns true once values match and breaks from loop */
					return (1);
					break;
				}
			/* Set current link to current's next*/
			current = current->next;
			}
		}
		return (0);
	}
}

/*	Removes the first occurrence of the specified value from the collection
if it occurs

param:	lst		pointer to the bag
param:	e		the value to be removed from the bag
pre:	lst is not null
pre:	lst is not empty
post:	e has been removed
post:	size of the bag is reduced by 1
*/
void removeList(struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	if (lst != NULL && !isEmptyList(lst)) {
		/* Make a current link to search for value e in bag */
		struct DLink * current = (struct DLink*) malloc(sizeof(struct DLink));
		if(current != NULL) {
			/* Set current link to first link in back */
			current = lst->firstLink;
			/* Repeat search in bag until find value e */
			while (current->next != lst->lastLink) {
				/* Compare value of current link to value of e */
				if (current->value == e) {
					/* If find e in bag, then link contains value e is removed */
					_removeLink(lst, current);
					break;
				}
			/* Set current link to current's next*/
			current = current->next;
			}
		}
		else 
			terminate();
	}
	else
		terminate();
}