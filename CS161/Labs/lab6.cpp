/*
Kamal Chaya
Lab 6
*/

#include <sys/time.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


long recursiveFact (int x);
long iterativeFact (int x);
long long recursiveComb (int n, int r);
long long iterativeComb (int n, int r);


//1st arg=n, 2nd arg=r

int main(int argc, char *argv[]) 
{	
	typedef struct timeval time;
	time stop, start;
	
	int n, r;
	n = atoi(argv[1]);
	r = atoi(argv[2]);
	
	cout << "\nWith n = " << n << " and r = " << r << "...\n";
	/*
	cout << "\n" << iterativeFact(5);
	cout << "\n" << recursiveFact(5);
	*/
		
	/*
	cout << "\n" << iterativeComb(n, r);
	cout << "\n" << recursiveComb(n, r);
	*/
	
	
	
	//Time recursive.
	gettimeofday(&start, NULL);
	cout << "\nRecursive comb: " << recursiveComb (n, r);
	
	
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "\nSeconds (Recursive): " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "\nMicro (Recursive): " << stop.tv_usec-start.tv_usec << endl;
	
	//Time iterative.
	gettimeofday(&start, NULL);
	cout << "\nIterative comb: " << iterativeComb (n, r);
	
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "\nSeconds (Iterative): " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "\nMicro (Iterative): " << stop.tv_usec-start.tv_usec << endl;
	
	
	
	return 0;
	
}


long recursiveFact (int x)
{
	if (x == 0)
		return 1;
	
	else
		return x * recursiveFact(x - 1);
	
}

long iterativeFact (int x)
{
	long fact;
	
	if (x == 0)
		fact = 1;
	
	else
	{
		fact = 1;
		for (int i = 1; i <= x; i++)
		{
			fact *= i;
		}
	}
	
	return fact;
}

long long recursiveComb (int n, int r)
{
	long long rC = recursiveFact(n)/((recursiveFact(r)*recursiveFact(n-r)));
	
	return rC;
}

long long iterativeComb (int n, int r)
{
	long long iC = iterativeFact(n)/(iterativeFact(r)*(iterativeFact(n-r)));
	return iC;
}
	



