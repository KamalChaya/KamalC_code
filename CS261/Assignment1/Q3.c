/* CS261- Assignment 1 - Q.3*/
/* Names: Kamal Chaya, Cam Tu Vo
 * Date: 10.9.2013
 * Development Environment: Microsoft Visual Studio 2012 Ultimate Ed.
 * Solution description: 
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Do we sort in ascending order?
*/

/*
Sorts an array of integers of size n using the
optimized version of the bubble sort algorithm.

Preconditions: That there be an array
and an integer with that arrays size to 
pass into the function.
Postconditions: The array will be s
*/
void sort(int* number, int n){
     /*Sort the given array number, of length n*/    

	//Variables to compare 2 numbers at a time.
	/*We need 3 temp variables, because 3 variables 
	 are required to swap values of variables.*/

	int i = 0, j = 0, temp = 0, swaps = 0;

	/*We have to make n^2 passes through the array
	because bubble sort is O(n^2).
	*/
	for (j = 0; j <= n*n; j++) {
		swaps = 0;
		for (i = 0; i <= n - 2; i++) {
			if (number[i] > number[i+1]) {
				swaps++;
				temp = number[i+1];
				number[i+1] = number[i];
				number[i] = temp;
			}
		}

		/*
		This optimizes the bubble sort; If one pass is made
		without any swaps occuring, then the sorting can 
		stop earlier.
		*/
		if (swaps == 0)
			break;
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20, i = 0;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int * arr = (int *) malloc(n * sizeof(int));
    
	//Seed rand number generator.
	srand(time(NULL));

	/*Fill this array with random numbers between 0 and n, using rand().*/
	for (i = 0; i <= n - 1; i++) 
		arr[i] = rand() % n;
	
    /*Print the contents of the array.*/
	printf("Prior to sorting array: \n");
	for (i = 0; i <= n - 1; i++)
		printf("%d\n", arr[i]);

    /*Pass this array along with n to the sort() function.*/
	sort(arr, n);

    /*Print the contents of the array.*/ 
	printf("After sorting array: \n");
   for (i = 0; i <= n - 1; i++)
		printf("%d\n", arr[i]);

    return 0;
}
