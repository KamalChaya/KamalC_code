/*
	infile: HeatDiff.c
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
#include <math.h>

int main() {
	float thermCond = 0, heatCap = 0, density = 0;
	float initTemp = 0, tempLbnd = 0, tempUbnd = 0; //Lbnd=lowerbound, Ubnd=upperbound.
	float wireLen = 0, sections = 0, timeInt = 0, timeChange = 0;
	float lenChange = 0;

	int k;
	int j;
	int i;
	int nineCnt = 0;
	float ** u;
	int time = 0;
	float constants;
	FILE * fp; 
	FILE * fpw;
	const char * infile = "heat_input.dat"; 
	const char * binfile = "heat_bin.dat";

	fp = fopen(infile, "r"); //Open file (readonly).
	fpw = fopen(binfile, "wb"); //open bin file to write

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

	lenChange = wireLen/sections;
	
	constants = ((thermCond*timeChange)/(heatCap*density*pow(lenChange, 2)));

	u = (float **) malloc (sizeof(float *) * sections);

	//X=columns, Y=rows
	for (i = 0; i <= (sections - 1); i++) 
		u[i] = (float *) malloc(sizeof(float) * timeInt);
	
	//Init temps
	for (i = 0; i <= sections - 1; i++) {
		if (i == sections - 1)
			u[i][0] = 100;
		else
			u[i][0] = 0;
	}

	/*
		k = thermalCond, p=density, c=specific heat
		(k*deltaT / cp*deltaX^2)(ut x+1 -2ut x + ut x-1) + ut x = ut + deltaT x
	*/

	//Calc temps
	for (i = 1; i <= timeInt - 1; i++) {
		for (j = 0; j <= sections - 1; j++) {

			if (j == sections - 1)
				u[j][i] = 100;

			else if (j == 0)
				u[j][i] = 0;
			
			else
				 u[j][i] = constants *(u[j+1][i-1] - 2*u[j][i-1] + u[j-1][i-1]) + u[j][i-1];
		}
	}

	//print temps
	for (i = 0; i <= timeInt - 1; i++) {
		printf("\nTime: %d", i+1);
		for (j = 0; j <= sections - 1; j++) {
			if (j % 10 == 0)
				printf("\n");

			printf("%.2f ", u[j][i]);
		}
	}

	//write binary to file
	fwrite(u, sizeof(float), sections*timeInt,	fpw);
	
	//free mem
	for (i = 0; i <= sections - 1; i++) {
		free(u[i]);
	}

	free(u);
	return 0;
}
