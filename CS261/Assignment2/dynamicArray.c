/* Cam Tu Vo and Kamal Chaya	10/16/2013
 * Assignment 2 dynamicArray.c
 * Visual studio 2012
 */

/*	dynamicArray.c: Dynamic Array implementation. */

//Stack overflow: Pushing a full stck
//Stack underflow: popping a empty stack
/*
Questions:
In the create dynarray function, if the conditions in the
if statements are not met, is it ok to return a null dynarr pointer?

I tried to use realloc in the set capacity function but I got an error
"invalid address specified to rtValue heap", why is this? (essentially a segfault).


*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dynamicArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	if (capacity > 0) {
		if (v != NULL) {
			v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
			if (v->data != NULL) {
				v->size = 0;
				v->capacity = capacity;	
			}
		}
	}
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* createDynArr(int cap)
{
	DynArr *x = NULL;
	if (cap > 0) {
		DynArr *r = (DynArr *)malloc(sizeof( DynArr));
		if (r != NULL) {
			initDynArr(r,cap);
			return r;
		}
	}

	
	//If the capacity is not > 0 or if r is null:
	printf("Error: Capacity not a positive int, or pointer to array is null\n");
	printf("Null pointer returned.\n");
	return x;

}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = NULL;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{	
	int i;
	/* FIXME: You will write this function */
	if(v != NULL)
	{
		/* Copy the existing data into a new array*/
		TYPE*newData = (TYPE *) malloc(sizeof(TYPE)*newCap);
		
		for (i = 0; i <= v->size - 1; i++) 
			newData[i] = v->data[i];
	
		/*Free old array*/
		free(v->data);

		/*Move pointer*/
		v->data = newData;
		v->capacity = newCap;
	}
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	/* Check to see if resize is necessary*/
	if (v != NULL) {
		if(v->size >= v->capacity)
			_dynArrSetCapacity(v, 2*v->capacity);
	}

	v->data[v->size] = val;
	v->size++;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: You will write this function */

	if((!isEmptyDynArr(v)) && (v != NULL) && (pos < v->size) && (pos >= 0)) 
		return v->data[pos]; /* FIXME: you must change this return value */
	
	printf("Error, data cannot be retrieved due to unsatisfied condition");
	return -1;
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
	if(!isEmptyDynArr(v) && (v != NULL) && (pos < v->size) && (pos >= 0)) 
		v->data[pos] = val; 
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	TYPE temp;
	/* FIXME: You will write this function */
	if((!isEmptyDynArr(v)) && (v != NULL) && 
		(((i >= 0) && (i < v->size)) && ((j >= 0) && (j < v->size)))) {
			temp = v->data[i];
			v->data[i] = v->data[j];
			v->data[j] = temp;
	}
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	int i;
	/* FIXME: You will write this function */
	if((!isEmptyDynArr(v)) && (v != NULL) && ((idx >= 0) && (idx < v->size)))
	{
		for(i = idx; i < v->size -1; i++)
			v->data[i] = v->data[i+1];

		/*
		Reduces size by 1 and since the last element is now a duplicate, it 
		must be popped off the stack.
		*/
		popDynArr(v); 
	}
}


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	/*If the DynArr pointer is not null, check if its size is 0 to
	see if it is empty.
	*/
	if (v != NULL) {
		if (v->size == 0)
			return 1;
	}
	/* FIXME:  You will change this return value*/
	return 0;
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	if (v != NULL) {
		if (v->size >= v->capacity) 
			_dynArrSetCapacity(v, 2*v->capacity);

		v->data[v->size] = val;
		v->size++;
	}
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	if(!isEmptyDynArr(v) && (v != NULL)) 
	{
	/* FIXME: You will change this return value*/
		return v->data[v->size-1];
	}
	
	printf("Error: could not access top element, pointer is null or stack is empty.\n");
	return -1;
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	if((!isEmptyDynArr(v)) && (v != NULL))
		v->size--;

	else
		printf("Error: Memory pointer is NULL or array is empty, cannot pop");
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	int i;
	/* FIXME: You will write this function */
	if(!isEmptyDynArr(v) && (v != NULL))
	{
		/* FIXME:  You will change this return value */
		for(i = 0; i < v->size; i++)
		{
			if(val == v->data[i])
				return 1;
		}
	}
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	int i;
	/* FIXME: You will write this function */
	if(!isEmptyDynArr(v) && (v != NULL))
	{
		for(i = 0; i < v->size; i++)
		{
			if(val == v->data[i])
				v->data[i] = v->data[i+1];
		}
		v->size--;
	}

	else
		printf("Error: pointer to dynamic array=null, or bag is empty, cannot remove\n");
}

/*	Tests the addDynArr() function to make sure it works
	properly under 3 conditions:
	-When adding to an empty array
	-When adding to a partially filled array
	-When adding to a full array

	param: v, the pointer to the dynamic array
	pre: pointer to dynamic array not null
	post: none
*/
void addDynArr_TEST(DynArr *v) {
	float oldCap;
	int initSize;

	if (v != NULL) {
		//Adding to the array when it is partially full
		if ((!isEmptyDynArr(v)) && (v->size < v->capacity)) {
			initSize = v->size;

			//Add to the array until it is full 
			while (v->size < v->capacity) {
				//Add alternating 5's and 2's
				if (v->size % 2 == 0)
					addDynArr(v, 2);
				else
					addDynArr(v, 5);
			}

			/*See if the elements were added correctly, and
			print a message everytime they are*/
			while (initSize < v->capacity) {
				if (initSize % 2 == 0) {
					printf("Test if element %d is 2\n", initSize);
					if (getDynArr(v, initSize) == 2)
						printf("element %d was added correctly.\n", initSize);
				}

				else {
					printf("Test if element %d is 5\n", initSize);
					if (getDynArr(v, initSize) == 5)
						printf("element %d was added correctly.\n", initSize);
				}
				initSize++;
			}
		}

		/*Empty the array so we can test adding to the array
		when it is empty (just use pop until size = 0)*/
		while (v->size != 0) 
			popDynArr(v);
	
		//Adding to the array when it is empty:
		if (isEmptyDynArr(v)) {
			initSize = v->size;
			/*Add to the array until it is full*/
			while (v->size < v->capacity) {
				addDynArr(v, 5);
			}
		 
			//Check if they were added correctly
			while (initSize < v->capacity) {
				printf("Test if element %d is 5\n", initSize);
				if (getDynArr(v, initSize) == 5) 
					printf("element %d was added correctly\n", initSize);
				initSize++;
			}
		}

		/*Now the array is full, so we will see if the capacity
		doubles like it is supposed to*/
		if (v->size == v->capacity) {
			oldCap = v->capacity;
			addDynArr(v, 5);
			if (v->capacity == 2*oldCap) 
				printf("Capacity doubles like it is supposed to\n");
		}
	}

}

/*
This function will test the popDynArr() function to make sure
it works when the stack is empty, and when the stack is not
empty.

param: v, pointer to the dynamic array
pre: pointer to dynamic array not null
post: none
*/
void popDynArr_TEST(DynArr *v) {
	if (v != NULL) {
		//Empty out the stack first 
		printf("Stack emptying..\n");
		while (v->size > 0) 
			popDynArr(v);
	
		//Now try to pop the stack when it is empty, there should be an error message
		printf("Upon popping the currently empty stack, there should be an error message\n");
		popDynArr(v);

		//Now, fill up the stack with some stuff
		printf("Add 2, 3, 4(top) to the stack\n");
		addDynArr(v, 2);
		addDynArr(v, 3);
		addDynArr(v, 4);

		/*
		Now, pop off the last element (4). When we get the value
		at the top of the stack, it should be equal to 3 since that
		is the value that was added before 4.
		*/
		printf("Popping off top of stack (4), top should now be 3\n");
		popDynArr(v);
	
		if (getDynArr(v, v->size-1) == 3)
			printf("New top is 3, 4 was popped correctly.\n");
	}

	else
		printf("Error: pointer to dynamic array is null\n");
}

/*
This function will test the topDynArr() function to see if
it correctly returns what the element at the top of the stack
is. It will also test to see that it returns a proper error message 
when the top function is used to inspect an empty stack. 

pre: mem pointer not null
post: none
param: v, pointer to dynamic array
*/

void topDynArr_TEST(DynArr *v) {
	if (v != NULL) {
		//Empty out the stack first
		printf("Stack emptying..\n");
		while (v->size > 0) 
			popDynArr(v);

		//See if it returns an error message when you use top on the empty stack
		printf("Stack currently empty, using top function should result in error.. \n");
		topDynArr(v);

		//Add some stuff on the stack, see if it returns correct top:
		printf("Add 4, 3, and 10(top) to the stack\n");
		addDynArr(v, 4);
		addDynArr(v, 3);
		addDynArr(v, 10);

		//Top should return 10 now if its working correctly
		printf("top should return 10..\n");
		if (topDynArr(v) == 10)
			printf("Top returns 10, top functions correctly.\n");
	}

	else
		printf("Error: pointer to dynamic array is null\n");
}

/*
This function tests the push function when the stack is empty,
partially full, and full. When the stack is full, the capacity 
should double prior to pushing. 

pre: none
post: none
param: v, pointer to dynamic array
*/
void pushDynArr_TEST(DynArr *v) {
	if (v != NULL) {
		int oldCap;
		//Empty the stack:
		printf("Stack emptying..\n");
		while (v->size > 0) 
			popDynArr(v);

		/*Push one thing onto the stack and then check to see
		that it is located there
		*/
		printf("Pushing 1 onto empty stack\n");
		pushDynArr(v, 1);

		if (topDynArr(v) == 1)
			printf("1 is on the stack's top\n");

		/*push some more stuff on the stack, check to see
		that it is in the right place
		*/
		printf("pushing 3, and 2 onto the stack\n");
		pushDynArr(v, 3);
		pushDynArr(v, 2);

		if ((getDynArr(v, v->size-1) == 2) 
		 && (getDynArr(v, v->size-2) == 3)) {
			 printf("3 and 2 were sucessfully pushed onto the stack\n");
		}

		/*
		Fill up the stack to its capacity and check to see that in the 
		event of a stack overflow, the capacity doubles
		*/
		printf("Stack being filled up, cap should double\n");
		while (v->size < v->capacity) 
			pushDynArr(v, 5);

		oldCap = v->capacity;

		//Push something else on the stack to see if it will double
		pushDynArr(v, 2);
		if (v->capacity == 2 * oldCap)
			printf("Capacity doubles correctly in the event of stack overflow\n");
	}

	else
		printf("Error: pointer to dynamic array is null\n");
}

/*
This function tests the containsDynArr() function for the bag ADT
when the bag is empty and is not empty. When the bag is empty, the function 
should return an appropriate error message

pre: pointer to dynamic array not null
post: none
param: v, pointer to dynamic array
*/
void containsDynArr_TEST(DynArr *v) {
	if (v != NULL) {
		//Empty the bag:
		printf("Bag is emptying..\n");
		while (v->size > 0) 
			popDynArr(v);
		
		//contains should return false
		printf("Contains should return false since the bag is empty;\n");
		if (!containsDynArr(v, 0))
			printf("Contains returns false ;contains works correctly\n");

		//Put some stuff in the bag:
		printf("Add 2 and 4 into the bag\n");
		addDynArr(v, 4);
		addDynArr(v, 2);
		
		//Contains should return true for 2 and 4:
		printf("Contains should return true for 2 and 4..\n");
		if (containsDynArr(v, 2) && containsDynArr(v, 4))
			printf("Contains returns true for 2 and 4\n");

	}
	else
		printf("Error: pointer to dynamic array is null\n");
}

/*
This function tests the removeDynArr() function when the bag
is empty and when it is not empty.

pre: pointer to dynamic array not null
post: none
param:  v, pointer to dynamic array
*/
void removeDynArr_TEST(DynArr *v) {
	if (v != NULL) {
		//Empty the bag:
		printf("Bag is emptying..\n");
		while (v->size > 0) 
			popDynArr(v);

		//Try to remove something when bag is empty, should give error.
		printf("Trying to remove something when bag is empty, should give error.\n");
		removeDynArr(v, 0);

	}

	else
		printf("Error: pointer to dynamic array is null\n");
}