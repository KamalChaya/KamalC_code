/***************************************************************
**Program Filename: Problem6.10.cpp
**Author: Kamal Chaya
**Date: DUE 3.15.2013	
**Description:
	-A program which creates a class called temperature, and has 
	 multiple member functions which convert a user inputted 
	 temperature to kelvin, farenheight, and celcius. The class 
	 will also have member functions which will ask the user to
	 input a temperature in Kelvin, Celcius, or Farenheight, 
	 and will store this temperature in a variable. The user
	 will be able to choose which temperature they would like
	 to enter.
**Input:
	-What kind of temperature they want to input
	-The temperature they want to input (using the temperature
	 units they specified)
**Output:
	-The user inputted temperature in all three different 
	 temperature units (celcius, kelvin, farenheight). 
 ***************************************************************/

#include <iostream>
using std::cout;
using std::cin;

class Temperature {
public:
	 /******************************************************
	 ** Function: setTempKelvin();
	 ** Description: If the user wants to enter a kelvin
	    temperature, this function is called to read the
		input and store it in the Ktemp variable.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/
	void setTempKelvin() {
		cout << "\nEnter your Temperature :> ";
		cin >> inputTemp;
		Ktemp = inputTemp;
	}

    /******************************************************
	 ** Function: setTempCelcius();
	 ** Description: If the user wants to enter a Celcius
	    temperature, this function is called to read the
		input into the inputTemp variable. It then 
		converts the input into kelvin, storing the resulting
		temperature in the Ktemp variable.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/
	void setTempCelcius() {
		cout << "\nEnter your Temperature :> ";
		cin >> inputTemp;
		Ktemp = inputTemp + 273.15;
	}

	/******************************************************
	 ** Function: setTempFarenheight();
	 ** Description: If the user wants to enter a Farenheight
	    temperature, this function is called to read the
		input into the inputTemp variable.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/
	void setTempFarenheight() {
		cout << "\nEnter your Temperature :> ";
		cin >> inputTemp;
		Ktemp = (inputTemp - 32)*(5.0/9) + 273.15;
	}

    /******************************************************
	 ** Function: returnFtemp();
	 ** Description: returns the temperature in farenheight
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: Temperature has been inputted
	 ** Post-Conditions: 
	 *******************************************************/
	double returnFTemp() {
		Ftemp = (Ktemp - 273.15)*(9/5.0) + 32;
		return Ftemp;
	}

    /******************************************************
	 ** Function: returnCtemp();
	 ** Description: returns the temperature in celcius
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: Temperature has been inputted
	 ** Post-Conditions: 
	 *******************************************************/
	double returnCtemp() {
		Ctemp = Ktemp - 273.15;
		return Ctemp;
	}

    /******************************************************
	 ** Function: returnKtemp();
	 ** Description: returns the temperature in kelvin
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: Temperature has been inputted
	 ** Post-Conditions: 
	 *******************************************************/
	double returnKtemp() {
		return Ktemp;
	}
		
private:
	double inputTemp, Ktemp, Ctemp, Ftemp;
};


int main() {

	Temperature input;
	char yOrN;
	bool redo;

	//Do while loop to allow the user to reuse the program.
	do {
		while (1) {
			int choice = 0;
			cout << "\nWhich kind of temperature do you want to enter?";
			cout << "\n(Kelvin(1), Farenheight(2), or Celcius(3))? ";
			cin >> choice;

			if (choice == 1) {
				input.setTempKelvin();
				break;
			}
		
			else if (choice == 2) {
				input.setTempFarenheight();
				break;
			}

			else if (choice == 3) {
				input.setTempCelcius();
				break;
			}

			else
				cout << "\nInvalid integer entered-please reinput";
		}
	
		cout << "Temperature:\n";
		cout << input.returnCtemp() << " degrees Celcius\n";
		cout << input.returnFTemp() << " degrees Farenheight\n";
		cout << input.returnKtemp() << " degrees Kelvin\n";

		while (1) {
			cout << "\nDo you want to re-use the program? (y/n)";
			cin >> yOrN;

			if ((yOrN == 'y') || (yOrN == 'Y')) {
				redo = true;
				break;
			}

			else if ((yOrN == 'n') || (yOrN == 'N')) {
				redo = false;
				break;
			}

			else
				cout << "\nInvalid character entered; please re-input.";
		}

	} while (redo == true);


	return 0;
}
