/*
Kamal Chaya, Cam Tu Vo
10.15.2013
Microsoft Visual Studio 2012 Ultimate Ed.

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"
#define ERROR "Mem Ptr is NULL"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	int i = 0;
	int decimalPoints = 0;
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		/*
		Make sure there is only one decimal point
		*/
		for (i = 0; i <= strlen(s) - 1; i++) {
				if (s[i] == '.') 
					decimalPoints++;
		}

		//Exit the program if there is more than one decimal point
		if (decimalPoints > 1) {
			printf("Error: Illegal input, terminating program\n");
			exit(EXIT_FAILURE);
		}

		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 2) {
			//Add the operands
			ans = stack->data[stack->size-1] + stack->data[stack->size-2];
		
			//pop off the 2 operands 
			popDynArr(stack);
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 2 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 2) {
			//subtract the operands
			ans = stack->data[stack->size-2] - stack->data[stack->size-1];
		
			//pop off the 2 operands 
			popDynArr(stack);
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 2 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 2) {
			//divide the operands
			if (stack->data[stack->size-2] != 0)
				ans = stack->data[stack->size-2] / stack->data[stack->size-1];

			//If denominator is 0, exit program
			else {
				printf("Error: attempted division by 0, terminating program\n");
				exit(EXIT_FAILURE);
			}
		
			//pop off the 2 operands 
			popDynArr(stack);
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 2 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 2) {
			//multiply the operands
			ans = stack->data[stack->size-2] * stack->data[stack->size-1];
		
			//pop off the 2 operands 
			popDynArr(stack);
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 2 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	the result is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 2) {
			ans = pow(stack->data[stack->size-2], stack->data[stack->size-1]);
		
			//pop off the 2 operands 
			popDynArr(stack);
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 2 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			ans = pow(stack->data[stack->size-1], 2);
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 element in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			ans = pow(stack->data[stack->size-1], 3);
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 element in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void absoluteVal(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			ans = abs(stack->data[stack->size-1]);
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void sqrRoot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			if (stack->data[stack->size-1] >= 0)
				ans = sqrt(stack->data[stack->size-1]);

			//exit the program if the argument is negative
			else {
				printf("Error: Cannot take square root of negative number, terminating program\n");
				exit(EXIT_FAILURE);
			}
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			ans = exp(stack->data[stack->size-1]);
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void natLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			if (stack->data[stack->size-1] > 0)
				ans = log(stack->data[stack->size-1]);

			else {
				printf("Error: Argument is not within natural log's domain, terminating program.\n");
				exit(EXIT_FAILURE);
			}
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 elements in the stack\n");
	}

	else
		printf(ERROR);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element are popped and 
	the result is pushed back onto the stack.
*/
void Log(struct DynArr *stack)
{
	/* FIXME: You will write this function */
		if (stack != NULL) {
		
		double ans = 0;
		/* FIXME: You will write this function */
		if (stack->size >= 1) {
			if (stack->data[stack->size-1] > 0)
				ans = log10(stack->data[stack->size-1]);

			else {
				printf("Error: Argument is not within log's domain, terminating program.\n");
				exit(EXIT_FAILURE);
			}
		
			//pop off the operand
			popDynArr(stack);
		
			//Push answer on stack
			pushDynArr(stack, ans);
		}

		else 
			printf("Error: less than 1 elements in the stack\n");
	}

	else
		printf(ERROR);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	double num = 0.0;
	char *s;
	DynArr *stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack
		
		if(strcmp(s, "+") == 0)
			add(stack);
		

		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absoluteVal(stack);
		else if(strcmp(s, "sqrt") == 0)
			sqrRoot(stack);
		else if(strcmp(s, "exp") == 0)
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			natLog(stack);
		else if(strcmp(s, "log") == 0)
			Log(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (isNumber(s, &num)) //If is is number, push on stack
				pushDynArr(stack, num);

			//If the user enters "e", pass in approx value of e
			else if (strcmp(s, "e") == 0)
				pushDynArr(stack, 2.718281828459045);

			//If the user enters "pi", pass in approx value of pi
			else if (strcmp(s, "pi") == 0) 
				pushDynArr(stack, 3.14159265359);

			

			else
				printf("Error: A non numeric string was entered.\n");
			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */

	//There should be only one element on the stack at the end:
	if (stack->size == 1) {
		//The answer to the calculation is the only remaining number on the stack
		result = topDynArr(stack);
		printf("\nResult: %f\n", result);
	}
		
	else {
		printf("Error: more operands than operators, or illegal input\n");
		printf("Terminating program\n");
		exit(EXIT_FAILURE);
	}

	
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}