/* CS261- Assignment 1 - Q.2*/
/* Names: Kamal Chaya, Cam Tu Vo
 * Date: 10.9.2012
 * Solution description:
		-Passes 3 integers into foo(), where one is
		 halved, one is doubled, and the results are
		 added up and returned. The three integers
		 are printed to the screen before and after the 
		 call to foo(), as well as the return value
		 of foo().
 */
 
#include <stdio.h>
#include <stdlib.h>

/*
Doubles an integer, halves another
integer, and adds these two integers
and returns them.

Preconditions: That there be three integers to pass in
Postconditions: a will be twice its original amount,
b will be half its original amount, and the original 
value of c will not changed since it is not passed
by pointer.
*/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;
    
    /*Set b to half its original value*/
	*b /= 2;
    
    /*Assign a+b to c*/
	c = *a + *b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9, foo_result = 0;
    
    /*Print the values of x, y and z*/
	printf("x=%d, y=%d, z=%d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
	foo_result = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
	printf("Value returned by foo(): %d\n", foo_result);
    
    /*Print the values of x, y and z again*/
	printf("x=%d, y=%d, z=%d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?	
		Yes, because z is not passed in by pointer, but by
		value. Thus, a mere copy of the value of z is being passed in,
		not the value stored in the location in memory where z
		is. This "copy" of the value then has some mathematical operations
		performed on it, making it have a different value than
		z itself. If z was passed in by pointer, the values would
		not be different because the mathematical operations
		would have been done on the value of z itself, not a copy
		of the value.
	*/
	
    return 0;
}
    
    
