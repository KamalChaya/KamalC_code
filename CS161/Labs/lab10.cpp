#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>


using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;

#define GAS_PRICE 1.50

class GasPump {
public:
	void displayPrice() {
		cout << "\nWelcome to the shell gas pump in Oregon.";
		cout << "\nGas Cost: $1.50/gal";
	}

	void startGasCollect() {
		amtDispensed = 0;
		cout << "\nPress 1 to start pumping gas.";
		cout << "\nPress ENTER to stop.";
		
		int StartGasPump;
		cin >> StartGasPump;

		if (StartGasPump == 1) {
			while (1) {

				
				//clock_t begin = clock();
				Sleep(500);
				//clock_t end = clock();
				timeElapsed += 0.5;

				if (fmod(timeElapsed, 5) == 0) {
					amtDispensed += 0.5;
					cout << "\nGas dispensed: " << amtDispensed << " gallons.";
					cout << "\nAmount Charged: " << amtDispensed * GAS_PRICE << "$.";
				}
			}
		}
	}

private:
	double amtDispensed; //Gallons
	double amtCharged;
	double timeElapsed;

	

};

int main() {

	GasPump shell;
	shell.displayPrice();
	shell.startGasCollect();
	return 0;
}