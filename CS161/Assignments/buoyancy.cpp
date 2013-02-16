/**********************************************************
**Program Filename: buoyancy.cpp
**Author: Kamal Chaya
**Date: 1.25.2013 (What date are we supposed to put?)
**Description:
	-Takes user inputted values for radius and weight of
	 a sphere, and calculates its buoyant force to 
	 determine if it will float or sink in water. 
	-Prints an apppropriate message based on if it floats
	 or sinks.
	-Asks the user if they want to reuse the program or 
	 exit, and takes action accordingly. 
**Input: 
	-user inputted float value for weight of sphere(in lbs)
	-user inputted float value for radius of sphere(in feet)
**Output:
	-A message prompting the user to enter a value for 
	 the weight.
	-A message prompting the user to enter a value for 
	 the radius.
	-A message stating whether the sphere will float
	 or sink in water.
	-A message asking the user whether they want to reuse 
	 the program or exit.
**********************************************************/

//Include pertinent libraries
#include <iostream>
#include <cmath>

//Bring in the necessary items from the standard namespace
using std::cout;
using std::cin;
using std::pow;

int main()
{
	
	
	/*
		The pi constant is not defined in most C++ math libraries
		(cmath does not define it), so it must be defined by the 
		programmer like below. 6 multiplied by the arcsin of 0.5
		is 6*pi/6, resulting in pi. Note that the arcsin function
		comes from the cmath library. 
	 */
	const double PI = 6.0 * asin(0.5);
	
	//The specific weight of water (62.4 lb/ft^3), needed to calculate buoyant force
	const float SPECIFIC_WEIGHT_H2O = 62.4;
	
	//This variable is used to determine if the user wants to reuse the program or exit.
	bool userWantsRedo = true; 
	
	do
	{
		//Initialize variables for user input
		float r = 0; 						//for radius of sphere
		float weight = 0;  				//for weight of sphere
		
		//Welcome message
		cout << "\n-------------------------------------------------------------";
		cout << "\nThis program will determine if a sphere floats or sinks based\n";
		cout << "on a radius and weight that you provide.\n";
		
		/*
		Prompt the user for input for the radius and height
		and read the values into the appropriate variables.
		 */
		cout << "\nPlease enter the radius of the sphere (in feet) as an integer:\n";
		cin >> r;
		cout << "\nPlease enter the weight of the sphere (in pounds) as an integer:\n";
		cin >> weight;
		
		/*
		Declare a variable for the volume of sphere, and initialize it by
		calculating its value with the formula V = (4/3)pi*r^3
		 */
		float volume = (4/3) * PI * pow(r, 3);
		
		/*
		Declare a variable for the buoyant force, and initialize it by
		calculating its value with the formula F = yV, where y is the
		specific weight of water (62.4 lb/ft^3). 
		 */
		float buoyantForce = SPECIFIC_WEIGHT_H2O * volume;
		
		if (buoyantForce >= weight) 
			/*
			Say the sphere floats if the buoyant force 
			is equal to or exceeds the weight entered by the user.
			 */
			cout << "\nThis sphere will float.\n";
		else
			/*
			Say the sphere sinks if the buoyant force
			is less than the weight entered by the user (this is the only other
			possible case that can occur besides buoyantForce >= weight).
			 */
			cout << "\nThis sphere will sink.\n";
			
		//An indefinite while loop.
		while(1) 
		{
			//Use this variable to record whether or not the user wants to reuse the program
			char yesOrNo;
		
			//Ask the user if they want to reuse the program.
			cout << "\nDo you want to try using the program again for a different";
			cout << "\nsphere? Type 'y' for yes, or 'n' for no (lowercase only):\n";
			cin >> yesOrNo;
			
			if (yesOrNo == 'y')
			{
				/*
				if the user enters a 'y', set the value of userWantsRedo to true
				so that the program can re-enter the 1st dowhile loop. This allows
				the user to use the program again.
				*/
				userWantsRedo = true;
				break;
			}
			
			else if (yesOrNo == 'n')
			{
				/*
				If the user enters a 'n', set the value of userWantsRedo to false
				so that the program cannot re-enter the 1st dowhile loop. After exiting
				the first while loop, the program will end, just as the user desired.
				*/
				userWantsRedo = false;
				break;
			}
				
			else
				/*
				Notice that in the else case, the program does not break out of the 
				infinite while loop. This ensures that the program will go through 
				the while loop again, allowing the user to re-enter a 'y' or 'n'.
				This way, even if the user enters something other than a 'y' or 'n',
				the proram will recognize it as an error, and allow the user another 
				chance to enter valid input.
				*/
				cout << "\nInvalid input; you did not enter a 'y' or 'n'.";
				cout << "\nPlease enter a 'y' or 'n'.";
		}	
	
	}	while(userWantsRedo == true);	
	
	cout << "\nExiting program...\n";
	
	return 0;
}