/**********************************************************
** Program Filename: RiemannSumCalculator.cpp
** Author: Kamal Chaya
** Date: 2.7.2013
** Description: 
	-Calculates approximated indefinite integrals of 
	 a function via the riemann sum method for 5 predefined 
	 functions (the user can choose for which function they
	 would like to calculate the riemann sum). Riemann sums 
	 are calculated by taking the sum of the areas of shapes 
	 under the curve of a function. The result is a rough
	 approximation of the area under the curve of the function. 
	-The riemann sum in this program is always calculated
	 with the LEFT endpoint. 
** Input:
	-The user inputs their choice of which predefined function
	 they want to use.
	-The user inputs whether they want to use rectangles, 
	 trapezoids, or both
	-The user inputs the initial and final x values, and also
	 the number of shapes (n) to be used.
	-The user inputs whether or not they would like to reuse 
	 the program or quit.
** Output:
    -The program outputs the calculated value of the riemann
	 sum.
	-Ask the user which function they want to use
	-Ask the user which calculation method they want to use
	-Prompt the user for the number of rectangles or trapezoids
	-Prompt the user for the initial and final x values (bounds
	of integration). 
**********************************************************/
//Calling a function within another function is ACCEPTABLE

//Includes
#include <iostream>
#include <cmath>
#include <cstdlib>

//Import appropriate items from the std namespace
using std::cout;
using std::cin;
using std::pow;
using std::exit;

//Declarations of functions
double f1 (double x);
double f2 (double x);
double f3 (double x);
double f4 (double x);
double f5 (double x);

/*
-The area calculating functions below use pointers so that the functions
f1 through f5 can be passed to them as arguments. This way, these
functions can calculate the area for any one of the 5 functions. 
-"float (*f)(float)" signifies that *f is a pointer to a function which
has a return type of float, which takes a single argument of type float. 
-For both of the area calculating functions, xi is the initial x value (a),
xf is the final x value (b), n is the number of shapes (Rectangles or
trapezoids), and 
*/

//Calculate area with rectangles
double calcAreaRect (double xi, double xf, int n, double (*f)(double) ); 
//Calculate area with trapezoids
double calcAreaTrap (double xi, double xf, int n, double (*f)(double) );
int main()
{
	bool userWantsRedo = true;

	while (userWantsRedo == true)
	{
		//Declare variables
		int chosenFunction = 0;

		/*
		a is the initial x value
		b is the final x value
		nR is the number of rectangles
		nT is the number of trapezoids
		*/
		double a, b = 0; 
		int nR, nT = 0;

		//This stores the user's choice of calculation method.
		int calcMethod = 0; 
		
		//Ask the user what function they want to use.
		cout << "-------------------------------------------------------\n";
		cout << "Which predefined function would you like to \n";
		cout << "calculate the approximated area (Riemann sum) for?\n";

		//Display the available functions to the user.
		cout << "\nEnter '1' to choose: f(x) = 5x^4 + 3x^3 - 10x + 2 \n";
		cout << "Enter '2' to choose: f(x) = x^2 - 10 \n";
		cout << "Enter '3' to choose: f(x) = 40x + 5 \n";
		cout << "Enter '4' to choose: f(x) = x^3 \n";
		cout << "Enter '5' to choose: f(x) = 20x^2 + 10x - 2 \n";
		cout << "Enter anything else to quit.\n";

		cin >> chosenFunction;

		/*
		If chosenFunction is anything except 1, 2, 3, 4, or 5, that means  
		the user wants to quit right away. Thus, invoke the exit function to
		end the program. 
		*/
		if ((chosenFunction < 1) || (chosenFunction > 5))
			exit(0); //Return error code = 0; program terminated successfully.	

		/*
		This infinite while loop is here so that if the user
		enters something OTHER than 1, 2, or 3 when prompted for which 
		calculation method they would like to use, the program will
		recognize this as an error and give them the opportunity to 
		re-input a number. 
		*/
		while(1)
		{
			/*
			Ask the user which method they would like to use for 
			calculating the area (with rectangles, trapezoids, or both). 
			*/
			cout << "\nWould you like to calculate the area using rectangles,";
			cout << "\ntrapezoids, or both? (1, 2, 3): ";
			cin >> calcMethod;
			/*
			-the cin.fail() function will return TRUE if the user does not
			input a value of the correct type. This error checking mechanism
			allows us to account for the situation in which a user may, by 
			mistake, enter something other than an integer. 
			-If calcMethod is not 1, 2, or 3, OR if the user does not enter an
			integer, then do not break out of the
			infinite loop; allow the user another chance to enter a number.
			*/
			if ((calcMethod < 1) || (calcMethod > 3) || (cin.fail()))
			{
				/*
				cin.clear() and cin.ignore() correct the stream, and skip the
				left over data from the stream (respectively); this will make 
				it so that the program does not repeat indefinitely when the
				user inputs a value which is not of the correct type. 
				*/
				cin.clear();
				cin.ignore();
				cout << "\nInvalid input; you did not enter a 1, 2, or 3.";
				cout << "\nPlease re-enter either a 1, 2, or 3.";
			}
			else
				break; //Valid input entered, so break out of the while loop.
		}


		cout << "\nEnter the starting point (initial x value): ";
		cin >> a;

		cout << "\nEnter the ending point (final x value): ";
		cin >> b;

		if (calcMethod == 1)
		{
			cout << "\nEnter the number of rectangles: ";
			cin >> nR;
		}

		else if (calcMethod == 2)
		{
			cout << "\nEnter the number of trapezoids: ";
			cin >> nT;
		}

		else if (calcMethod == 3)
		{
			cout << "\nEnter the number of rectangles: ";
			cin >> nR;
			cout << "\nEnter the number of trapezoids: ";
			cin >> nT;
		}

		/*
		This switch statement has a case for each of the predefined functions,
		so that calculations can be done for each of them.
		*/
		switch (chosenFunction)
		{
			case 1:
				if (calcMethod == 1)
				{
					//Calculate area with rectangles only
					cout << "\nFor the function f(x): 5x^4 + 3x^3 - 10x + 2,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f1);	
				}
				
				else if (calcMethod == 2)
				{
					//Calculate area with trapezoids only
					cout << "\nFor the function f(x): 5x^4 + 3x^3 - 10x + 2,";
					cout << "\nthe approximate area (calculated with trapezoids)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f1);
				}
				
				else
				{
					//Calculate area with rectangles and trapezoids
					cout << "\nFor the function f(x): 5x^4 + 3x^3 - 10x + 2,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f1);	
					cout << "\nThe approximate area calculated";
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f1);
				}
				break;

			case 2:
				if (calcMethod == 1)
				{
					//Calculate area with rectangles only
					cout << "\nFor the function f(x): x^2 - 10,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f2);	
				}

				else if (calcMethod == 2)
				{
					//Calculate area with trapezoids only
					cout << "\nFor the function f(x): x^2 - 10,";
					cout << "\nthe approximate area (calculated with trapezoids)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f2);
				}
				
				else
				{
					//Calculate area with rectangles and trapezoids
					cout << "\nFor the function f(x): x^2 - 10,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f2);	
					cout << "\nThe approximate area calculated";
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f2);
				}	
				break;

			case 3:
				if (calcMethod == 1)
				{
					//Calculate area with rectangles only
					cout << "\nFor the function f(x): 40x + 5,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f3);
				}

				else if (calcMethod == 2)
				{
					//Calculate area with trapezoids only
					cout << "\nFor the function f(x): 40x + 5,";
					cout << "\nthe approximate area (calculated with trapezoids)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f3);
				}
				
				else
				{
					//Calculate area with rectangles and trapezoids
					cout << "\nFor the function f(x): 40x + 5,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f3);	
					cout << "\nThe approximate area calculated";
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f3);
				}
				break;

			case 4:
				if (calcMethod == 1)
				{
					//Calculate area with rectangles only
					cout << "\nFor the function f(x): x^3,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f4);
				}

				else if (calcMethod == 2)
				{
					//Calculate area with trapezoids only
					cout << "\nFor the function f(x): x^3,";
					cout << "\nthe approximate area (calculated with trapezoids)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f4);
				}
				
				else
				{
					//Calculate area with rectangles and trapezoids
					cout << "\nFor the function f(x): x^3,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f4);	
					cout << "\nThe approximate area calculated";
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f4);
				}
				break;

			case 5:
				if (calcMethod == 1)
				{
					//Calculate area with rectangles only
					cout << "\nFor the function f(x): 20x^2 + 10x - 2,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f5);
				}

				else if (calcMethod == 2)
				{
					//Calculate area with trapezoids only
					cout << "\nFor the function f(x): 20x^2 + 10x - 2,";
					cout << "\nthe approximate area (calculated with trapezoids)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f5);
				}
				
				else
				{
					//Calculate area with rectangles and trapezoids
					cout << "\nFor the function f(x): 20x^2 + 10x - 2,";
					cout << "\nthe approximate area (calculated with rectangles)";
					cout << "\nover the interval x = " << a << " to x = " << b;
					cout << "\nwith " << nR << " rectangles is: ";
					cout << calcAreaRect(a, b, nR, f5);	
					cout << "\nThe approximate area calculated";
					cout << "\nwith " << nT << " trapezoids is: ";
					cout << calcAreaTrap(a, b, nT, f5);
				}
				break;
		}

		while (1)
		{
			/*
			Ask the user if they want to reuse the program
			or not
			*/
			char yesOrNo;
			cout << "\nDo you want to reuse the program?";
			cout << "\nEnter 'y' or 'Y' for yes, and 'n' or 'N' for no";
			cin >> yesOrNo;
			if ((yesOrNo == 'y') || (yesOrNo == 'Y'))
			{
				userWantsRedo = true;
				break;
			}

			else if ((yesOrNo == 'n') || (yesOrNo == 'N'))
			{
				userWantsRedo = false;
				break;
			}

			else
			{
				cout << "\nInvalid input: please enter a 'y', 'Y'";
				cout << "\n'n', or 'N'.";
			}
		}
	}
	return 0;
}

//Definitions of the predefined functions
double f1 (double x)
{
	return (5*pow(x, 4) + 3*pow(x, 3) - 10*x + 2);
}

double f2 (double x)
{
	return (pow(x, 2) - 10);
}

double f3 (double x)
{
	return (40*x + 5);
}

double f4 (double x)
{
	return pow(x, 3);
}

double f5 (double x)
{
	return (20*pow(x, 2) + 10*x - 2);
}

/*
This function uses iteration to sum up the functions values from xi to xf - width.
It then 
*/
double calcAreaRect (double xi, double xf, int n, double (*f)(double) )
{
	double sumOfHeight = 0;
	double funcVal;
	double width = ((xf - xi)/n);
	double lastEndPt = xf - width;
	if (xi <= xf)
	{
		double i;
		for (i = xi; i <= lastEndPt; i += width)
		{
			funcVal = (*f)(i);
			sumOfHeight += funcVal;
		}
		//Check if function was evaluated at last pt; if not, evaluate it here:
		if (i < lastEndPt + width)
		{
			funcVal = (*f)(i);
			sumOfHeight += funcVal;
		}
	}

	else
	{//if xi > xf, then the for loop must iterate while i >= the endpt.
		double i;
		for (i = xi; i >= lastEndPt; i += width)
		{
			funcVal = (*f)(i);
			sumOfHeight += funcVal;
		}
		//Check if function was evaluated at last pt; if not, evaluate it here:
		if (i > lastEndPt + width)
		{
			funcVal = (*f)(i);
			sumOfHeight += funcVal;
		}
	}
	return width*sumOfHeight;
}

double calcAreaTrap (double xi, double xf, int n, double (*f)(double) )
{
 	double sumOfHeight = 0;
	double funcVals;
	double deltaX = ((xf - xi)/n);
	if (xi <= xf)
	{
		double i;
		for (i = xi; i <= xf; i += deltaX)
		{
			/*
			When using the trapezoid method, the value of the function
			must be multiplied by 2 if it is NOT evaluated at the initial
			or final x value. That is the purpose of this if-else statement.
			*/
			if ((i > xi) && (i < xf))
			{
				funcVals = 2*((*f)(i));
				sumOfHeight += funcVals;
			}

			else
			{
				funcVals = (*f)(i);
				sumOfHeight += funcVals;
			}
		}
		/*
		-Test if the function has been evaluated at the last pt or not; if it has not,
		evaluate it here and add it on to the exiting sum. 

		-A frequent error that was occuring was that the function was not being evaluated
		at the final x value (the final bound of integration inputted by the user). This
		is because floating point numbers are used extensively in this program, which do
		not have very good precision (they can be rounded when we dont want them to be, 
		etc). The value of deltaX (the increment) was being rounded so that it was 
		SLIGHTLY bigger than what it was supposed to be (because it was a floating point
		type). Because of this, the value of "i" (the counter variable in the foor loop) 
		was increased so that it was SLIGHTLY bigger than what it should have been. 
		The end result of this was that BEFORE the last iteration of the foor loop, the 
		counter variable was actually BIGGER than xf by a very small amount. Because of
		this, the final iteration of the for loop was not performed, and thus the 
		user chosen function was not evaluated at the final endpoint, making the area
		significantly smaller than it was supposed to be. 

		-if i was less than xf + deltaX at the time it left the for loop, then that 
		means the for loop must have exited prematurely. The for loop should ONLY
		exit when i is incremented so that it is bigger than xf BY THE AMOUNT deltaX.
		Thus, here, we evaluate the user chosen function at the last value of i
		even if this iteration is skipped in the for loop. We then add it on to the 
		sum. The correct area will always be calculated because of this. 

		-This has also been added to the calcAreaRect function. 
		*/
		if (i < xf + deltaX)
		{
			funcVals = (*f)(i);
			sumOfHeight += funcVals;
		}
	}

	else
	{
		double i;
		//if xi > xf, then the for loop must iterate while i >= final x value.
		for (i = xi; i >= xf; i += deltaX)
		{
			if ((i < xi) && (i > xf))
			{
				funcVals = 2*((*f)(i));
				sumOfHeight += funcVals;
			}

			else
			{
				funcVals = (*f)(i);
				sumOfHeight += funcVals;
			}
		}
		//Check if function was evaluated at last pt; if not, evaluate it here:
		if (i > xf + deltaX)
		{
			funcVals = (*f)(i);
			sumOfHeight += funcVals;
		}
	}

	return deltaX * 0.5 * sumOfHeight;
}