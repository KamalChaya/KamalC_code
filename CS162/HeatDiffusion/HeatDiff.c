/*
	Filename: HeatDiff.c
	Author: Kamal Chaya
	Date: DUE 5.8.2013
	Description: 
		-Reads data concerning physical properties of metal
	from a .dat file and calculates the heat diffusion at specific 
	time and length intervals, and writes the results in binary to 
	a different .dat file.
	Input: 
		-.dat file containing metal data
	Output: 
		-The program will output to the screen the heat diffusion at
		specific time and length intervals
		-The program will write the heat diffusion data to a different
		.dat file in binary format.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	float thermCond = 0, heatCap = 0, density = 0;
	float initTemp = 0, tempLbnd = 0, tempUbnd = 0; //Lbnd=lowerbound, Ubnd=upperbound.
	float wireLen = 0, sections = 0, timeInt = 0, timeChange = 0;
	float curPos = 0;

	FILE * fp; 
	const char * filename = "heat_input.dat"; 

	fp = fopen(filename, "r"); //Open file (readonly).

	fscanf(fp, "%f", &thermCond); //Read in data from heat_input.dat
	fscanf(fp, "%f", &density); 
	fscanf(fp, "%f", &heatCap); 
	fscanf(fp, "%f", &initTemp); 
	fscanf(fp, "%f", &tempLbnd);
	fscanf(fp, "%f", &tempUbnd);
	fscanf(fp, "%f", &wireLen);
	fscanf(fp, "%f", &sections);
	fscanf(fp, "%f", &timeInt);
	fscanf(fp, "%f", &timeChange);

	/*
	 (k*deltaT/cp) * ((u t x+1) - 2(u t x) + (u t x-1))/deltaX^2 + (u t x) = u t + deltaT x
	 */


	return 0;
}
