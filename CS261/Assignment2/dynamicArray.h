/* 	dynamicArray.h : Dynamic Array implementation. */
#include<math.h>

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


# ifndef TYPE
# define TYPE     double 
# define TYPE_SIZE sizeof(double)
# endif

# ifndef EQ
# define EQ(A, B) (fabs(A - B) < 10e-7)
# endif

typedef struct DynArr DynArr;

/* Dynamic Array Functions */
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *v);

int sizeDynArr(DynArr *v);

void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int  j);
void removeAtDynArr(DynArr *v, int idx);

/* Stack interface. */
int isEmptyDynArr(DynArr *v);
void pushDynArr(DynArr *v, TYPE val);
TYPE topDynArr(DynArr *v);
void popDynArr(DynArr *v);

/* Bag Interface */
int containsDynArr(DynArr *v, TYPE val);
void removeDynArr(DynArr *v, TYPE val);

/* Testing functions */
/*
edge test cases:
adding when empty, partially full, and full
pop on empty stack, normal
top on empty stack, normal
push on full stack, normal, empty
contains when bag is empty
remove when bag is empty, regular

*/
void addDynArr_TEST(DynArr *v);
void popDynArr_TEST(DynArr *v);
void topDynArr_TEST(DynArr *v);
void pushDynArr_TEST(DynArr *v);
void containsDynArr_TEST(DynArr *v);
void removeDynArr_TEST(DynArr *v);
#endif