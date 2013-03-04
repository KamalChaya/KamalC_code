/*****************************************************************************
**Program Filename: GradeCalc.cpp
**Author: Kamal Chaya
**Date: DUE 3.3.2013
**Description: 
	-Calculates a students average grade in this class. Uses command line
	 arguments to determine the number of quizzes, tests, etc.
	-The user should be able to supply the command line arguments in any 
	 order
**Input: 
	-Command line options for tests, quizzes, assignments, labs, and a final 
	 (optional), in any order.
	-Score for each number of items.
	-If the –f option is supplied, then read a score for final exam
**Output: 
	-Proper error message for each case listed above.
	-Class average for the student 
*****************************************************************************/

//QUESTIONS:
//OK to exit if invalid cmd line args entered?
//OK to put multiple statements on 1 line? Saves lines, since we are only allowed 20/function
//OK to put end of braces on statements?
//DO we only need 1 error message for all 5 error handling conditions or do we need 5 specialized ones?

/*
ERROR HANDLING TASKS:
-Print an error message if the user doesn’t supply all the command line arguments,
excluding the –f option, which is optional [DONE]
-Print an error message if the user doesn’t supply a number value for any one of the
options, this excludes the –f option, which doesn’t have a number value
-Print an error message if the user enters a zero for any of the command line
arguments.
-Print an error message if the user doesn’t enter an integer value for the command
line arguments.
-Print an error message if the user doesn’t supply a number for the scores for the
items.
*/

//FOR errorhandling(2): Look at the size of the array; If it is not a certain size (2 cases; with and w/o -f), then a flag or number is missing. 

#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using std::cout;
using std::cin;

#define ERROR_1 "You didn't enter integer values for the cmd line args."
#define ERROR_2 "Invalid cmd line args entered; program terminating."
#define ERROR_3 "Wrong amt of cmd line args; program terminating."

void check_args(int size, char *arg[], char flg[], bool &finalTaken, int flagCount = 0);
void check_size(int size);

int main(int argc, char *argv[]) {
	char flags[] = {'q', 'l', 'a', 't'}; bool finalTaken = false; 
	check_size(argc); check_args(argc, argv, flags, finalTaken);
	return 0; }


void check_size(int size) {
	if ((size != 9) || (size != 10)) {
		cout << "\n" << ERROR_1;
		exit(EXIT_FAILURE); //Numbers ommited, so exit with failure code.
	}
}

void check_args(int size, char *arg[], char flg[], bool &finalTaken, int flagCount) {
		for (int i = 1; i <= size - 1; i += 2) {
			if (arg[i][0] == '-') {		
				for (int j = 0; j <= 3; j++)  {
					if (arg[i][1] == 'f') {
						finalTaken = true; break; }
					else if (('1' <= *arg[i+1] <= '9') && (arg[i][1] == flg[j])) {
						flagCount++; cout << "Arg Correct.\n"; break; } } }
			else { cout << "\n" << ERROR_2;
				   exit(EXIT_FAILURE); /*Invalid input entered; exit w/ fail code*/ } } 
		if (flagCount != 4) {cout << "\n" << ERROR_3;
			exit(EXIT_FAILURE); /*Invalid input entered; exit w/ fail code*/} }
			 