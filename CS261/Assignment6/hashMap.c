/*
Author(s): Kamal Chaya, Song Ge
Development Environment: Visual Studio 2012
Created: 11.23.2013, 1:32 AM
Description: Implementation of functions for hash map

*/

//Is the empty buckets one correct

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
   struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	hashMap *ht;
	assert(tableSize > 0);
	ht = (hashMap *) malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	hashLink * temp, * temp2;
	int i;
	assert(ht != NULL);
	assert(ht->table != NULL);
	for (i = 0; i < ht->tableSize; i++) {
		temp = ht->table[i];
		while (temp != NULL) {
			//Free all the links in the chain
			temp2 = temp;
			temp = temp->next;
			free(temp2->key);
			free(temp2->value);
			free(temp2);
		}
	}

	free(ht->table);
	//clear the hash table data
	ht->tableSize = 0;
	ht->count = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	//
	struct hashMap * oldMap = (struct hashMap *) malloc (sizeof(struct hashMap *));
	struct hashLink ** newTable = (struct hashLink**) malloc (sizeof(struct hashLink *) * newTableSize);
	struct hashLink * cur;
	int i, hashVal;
	oldMap = ht;
	ht->table = newTable;
	for (i = 0; i < oldMap->tableSize; i++) {
		cur = oldMap->table[i];
		//Go through every bucket of the table, put in new table
		while (cur != NULL) {
			insertMap(ht, cur->key, cur->value);
			cur = cur->next;
		}
	}
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	int hashVal;
	hashLink * cur, * tmp, * newlink;
	assert(ht != NULL);
	//if the load factor threshold is exceeded resize the table
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) 
		_setTableSize(ht, 2*ht->tableSize);

	newlink = (hashLink *) malloc (sizeof(hashLink));

	if (HASHING_FUNCTION == 1)
			hashVal = stringHash1(k) % ht->tableSize;
	else
			hashVal = stringHash2(k) % ht->tableSize;

	cur = tmp = ht->table[hashVal];

	//If there is no bucket at the hashvalue currently
	if (ht->table[hashVal] == NULL) {
		//fill hashlink with data
		newlink->key = k;
		newlink->value = v;
		newlink->next = NULL;

		//add new link to the table
		ht->table[hashVal] = newlink; 
		ht->count++;
		return;
	}
	
	//If a bucket exists at the hashval
	else {
		//If the first link is the one that already has a key 'k', replace it
		if (strcmp(cur->key, k) == 0) {
			tmp = cur;
			free(tmp->value);
			cur->value = v;
			return;
		}

		/*
		If there is a link after the first one that already has a key 'k', 
		replace it with new value
		*/
		while (cur->next != NULL) {
			if (strcmp(cur->next->key, k) == 0) {
				tmp = cur->next;
				free(tmp->value);
				cur->next->value = v;
				return;
			}
			cur = cur->next;
		}

		/*
		If the earlier loop was traversed fully and there is no link with a key 'k'
		that means a new link with the value v and key k must be inserted
		*/
		newlink->key = k;
		newlink->value = v;
		newlink->next = NULL;
		cur->next = newlink;
		ht->count++;
	}
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{ 
	hashLink * cur;
	int hashVal;
	assert(ht != NULL);
	if (!containsKey(ht, k))
		return NULL;

	else {
		if (HASHING_FUNCTION == 1)
			hashVal = stringHash1(k) % ht->tableSize;
		else if (HASHING_FUNCTION == 2)
			hashVal = stringHash2(k) % ht->tableSize;

		cur = ht->table[hashVal];

		while (cur != NULL) {
			if (strcmp(cur->key, k) == 0)
				return cur->value;

			cur = cur->next;
		}
	}
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	int hashVal;
	hashLink * cur;
	assert(ht != NULL);

	//Get the index of the bucket using the hash function
	if (HASHING_FUNCTION == 1)
		hashVal = stringHash1(k) % ht->tableSize;
	else
		hashVal = stringHash2(k) % ht->tableSize;

	//ensure the index is positive
	if (hashVal < 0)
		hashVal += ht->tableSize;

	//Set cur equal to the proper bucket (the one at the index from the hash function
	cur = ht->table[hashVal];

	//traverse the bucket to find the key
	while (cur != NULL) {
		//If the key is found return 1
		if (strcmp(cur->key, k) == 0)
			return 1;

		cur = cur->next;
	}
	/*
	if the entire bucket is traversed and the key is not found return 0
	*/
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{ 
	hashLink * cur, * temp;
	assert(ht != NULL);
	if (containsKey(ht, k)) {
		int hashVal;
		if (HASHING_FUNCTION == 1)
			hashVal = stringHash1(k) % ht->tableSize;
		else if (HASHING_FUNCTION == 2)
			hashVal = stringHash2(k) % ht->tableSize;

		if (hashVal < 0)
			hashVal += ht->tableSize;

		cur = ht->table[hashVal];
		 
		//See if the key is at the parent link
		if (strcmp(cur->key, k) == 0) {
			temp = cur->next;
			free(cur->key);
			free(cur);
			ht->table[hashVal] = temp;
			ht->count--;
			return;
		}

		//see if the key is at one of the child links
		while (cur->next != NULL) {
			if (strcmp(cur->next->key, k) == 0) {
				temp = cur->next->next;
				free(cur->next->key);
				free(cur->next);
				cur->next = temp;
				ht->count--;
				return;
			}
			cur = cur->next;
		}
	}
	
	else {
		printf("\nError: tried to remove a kew that is not in the map.");
		return;
	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	assert(ht != NULL);
	return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	assert(ht != NULL);
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	/*
	The amount of total tables - the amount of tables
	filled gives the amount of empty tables
	*/
	assert(ht != NULL);
	return ht->tableSize - ht->count;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	assert(ht != NULL);
	return ((float)(ht->count) / (float)(ht->tableSize));
}

/* print the hashMap */
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	assert(ht != NULL);
	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}