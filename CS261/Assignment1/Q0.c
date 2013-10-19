/* CS261- Assignment 1 - Q. 0*/
/* Name:
	-Kamal Chaya
	-Cam Tu Vo
 * Date: 10.08.2013
 * Development Environment: Microsoft Visual Studio Ultimate 2012
 * Solution description:
	 -Declares an integer, prints its address, and passes
	 a pointer to the integer into a function which prints 
	 the pointers value, the value's address, and the
	 pointers address. Then, it prints the integers value.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*
 Prints the value pointed to by a pointer to an integer. 
 Also prints the address pointed to by said pointer, and
 the address of the pointer itself.

 Preconditions: There must be an integer pointer to pass
 into the function.
 Postconditons: None
*/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	 printf("Value pointed to by pointer: %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	 printf("Address pointed to by pointer: %p\n", iptr);
     
     /*Print the address of iptr itself*/
	 printf("Address of pointer itself: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 0;

    /*print the address of x*/
    printf("Address of x: %p\n", &x); 

    /*Call fooA() with the address of x*/
	fooA(&x);
    
    /*print the value of x*/
	printf("Value of x: %d\n", x);
    
    return 0;
}
