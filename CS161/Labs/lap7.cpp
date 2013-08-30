//lab7 Kamal Chaya
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

int main()
{
	
	
	double *d;
	double d1 = 7.8, d2 = 10.0, d3 = 0.009;
	
	d = &d1;
	cout << "\nAddr d1: " << d;
	cout << "\nVal d1: " << *d;
	
	d = &d2;
	cout << "\nAddr d2: " << d;
	cout << "\nVal d2: " << *d;
	
	d = &d3;
	cout << "\nAddr d3: " << d;
	cout << "\nVal d3: " << *d;	
	
	double **dp;
	dp = &d;
	d = &d1;
	cout << "\nAddr d1: " << dp;
	cout << "\nVal d1: " << *dp;
	
	d = &d2;
	cout << "\nAddr d2: " << dp;
	cout << "\nVal d2" << *dp;
	
	d = &d3;
	cout << "\nAddr d3: " << dp;
	cout << "\nVal d3" << *dp;
	
	


	
	return 0;
}