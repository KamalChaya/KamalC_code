/********************************************************************************
 ** Filename: assign1-2.c
 ** Author: Kamal Chaya
 ** Date: DUE 4.14.2013
 ** Description: Has a function which takes 2 10x10 arrays as args and 
    stores the matrix product of the arrays in the third arg.
 ** Input: 2 10x10 arrays
 ** Output: Matrix product of the 2 10x10 arrays, stored in the third arg
(also a 10x10 array).
 *******************************************************************************/
#include <stdio.h>
#include <iostream>

using std::cout;

void calcMatrixProd(int array1[10][10], int array2[10][10], int prod[10][10]);
void displayProd(int prod[10][10]);

int main() {
    //Initialize the 10X10 arrays
	int array1[10][10] = {
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

    int array2[10][10] = {
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

    //
    int prod[10][10];

	//Call the function to calculate the matrix product.
    calcMatrixProd(array1, array2, prod);

	//Display the function by calling the displayProd function.
	displayProd(prod);
    
	return 0;
}

/*********************************************************************
** Function: calcMatrixProd
** Description: calculates the matrix product of the 2 10X10 arrays
** Parameters: int array1[10][10], int array2[10][10]
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void calcMatrixProd(int array1[10][10], int array2[10][10], int prod[10][10]) {

	/*
	  In matrix multiplication, we multiply the nth element of the first
	  matrix's first row with the nth element of the second matrix's 
	  first column (we repeat this for all the columns). 
	*/

	//i iterates through each row in array1
	//j iterates through each column in array2
	//k iterates through the elements of each row in array1
	//l iterates through the elements of each column in array2
	int i = 0, j, k, l, elementSum = 0;
	
	for (i = 0; i <= 9;) {
		k = 0, l = 0, j = 0;
		while ((j >= 0) && (j <= 9)) {
			for (j = 0; j <= 9; j++) {
				k = 0, l = 0;
				while (((k >= 0) && (k <= 10)) && ((l >= 0) && (l <= 10))) {
					for (k = 0, l = 0; k <= 9, l <= 9; k++, l++) { 
						elementSum += (array1[i][k]*array2[l][j]);		  		  
					}
				
					if ((k == 10) && (l == 10)) {
						prod[i][j] = elementSum;
						//k++;
						//l++;
						elementSum = 0;
						break;
					}
					break;
				}
			}
		}
	}
}

/*********************************************************************
** Function: displayProd
** Description: Iterates through the prod array to display the
	resulting multiplied matrix.
** Parameters: int prod[10][10]
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void displayProd(int prod[10][10]) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			cout << prod[i][j] << " ";

			if (j == 9)
				printf("\n");
		}
	}
}



