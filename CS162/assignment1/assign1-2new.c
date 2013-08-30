/********************************************************************
 ** Filename: assign1-2new.c
 ** Author: Kamal Chaya
 ** Date: DUE 4.14.2013
 ** Description: Multiplies 2 10x10 predefined matrices, stores the
result in another matrix (there is a function to do this task; it 
takes the first 2 matrices as the first 2 args, and the third arg
is the product matrix).
 ** Input: None
 ** Output: The resulting multiplied matrix. 
 *******************************************************************/

#include <stdio.h>

void calcMatrixProd(int arg1[10][10], int arg2[10][10], int prod[10][10]);
void displayProd(int prod[10][10]);

int main() {
	int arg1[10][10] = {
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, //10
		{ 2, 3, 6, 7, 8, 10, 12, 14, 4, 5 }, //10
		{ 3, 5, 6, 10, 15, 19, 32, 22, 9, 0 }, //10
		{ 2, 4, 9, 13, 22, 10, 33, 44, 3, 2 }, //10
		{ 3, 4, 9, 10, 11, 12, 10, 2, 3, 4 }, //10
		{ 3, 9, 10, 11, 10, 32, 1, 8, 9, 10 }, //10
		{ 2, 10, 11, 3, 4, 2, 4, 5, 6, 9 }, //10
		{ 9, 10, 13, 12, 2, 3, 3, 4, 5, 6 }, //10
		{ 2, 3, 10, 1, 2, 4, 5, 7, 8, 9 }, //10
		{ 2, 3, 6, 7, 10, 11, 2, 3, 9, 10 } //10
	};

	int arg2[10][10] = {
	   	{ 3, 4, 12, 14, 15, 2, 3, 4, 5, 6 },
		{ 2, 9, 10, 2, 3, 34, 35, 21, 13, 19 },
		{ 2, 9, 10, 2, 3, 3, 4, 5, 6, 7 },
		{ 2, 1, 2, 8, 9, 13, 14, 15, 19, 20 },
		{ 3, 4, 1, 0, 1, 2, 3, 10, 13, 24 },
		{ 4, 45, 13, 12, 14, 44, 45, 46, 90, 0 },
		{ 3, 10, 9, 19, 23, 35, 15, 6, 7, 8 },
		{ 2, 1, 13, 12, 10, 3, 2, 10, 9, 9 }, 
		{ 3, 10, 9, 19, 23, 35, 15, 6, 7, 8 }, 
		{ 4, 45, 13, 12, 14, 44, 45, 46, 90, 0 }
	};

	//Create the matrix to hold the product, init to all 0's.
	int prod[10][10] = {0};

	//Call the function to multiply the 2 matrices
	calcMatrixProd(arg1, arg2, prod);

	//Call the function to print the product matrix
	displayProd(prod);

	return 0;
}

void calcMatrixProd(int arg1[10][10], int arg2[10][10], int prod[10][10]) {
	/*
	  i iterates through the rows for prod and arg1 
	  j iterates through columns for prod and arg2
	  k iterates through the columns for arg 1 and the rows for arg2.
	 */

	int i, j, k;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				prod[i][j]+=arg1[i][k]*arg2[k][j];
			}
		}
	}
}

void displayProd(int prod[10][10]) {
	printf("Product Matrix: \n");
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf(" %d", prod[i][j]);

			//Every 10th element we need to start printing on a new line.
			if (j == 9)
				printf("\n");
		}
	}
}
