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
	float * u;
	int time = 0;
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

	lenChange = wireLen/sections;


	u = (float *) malloc(wireLen*(timeInt+1)*(sizeof(float)));
	
	

	//Init the first 30 temps
	for (k = 0; k <= 29; k++) {
		if (k != 29)
			u[k] = 0;
		else
			u[k] = 100;
	}

	//Calculate all the other temps, put them in the array
	for (i = 30; i <= (wireLen*(timeInt+1)); i++) {
		if (i % 10 == 9)
			nineCnt++;

		if (i % 30 == 0)
			u[i] = 0;

		else if (nineCnt == 3) {
			u[i] = 100;
			nineCnt = 0;
		}
		//k=thermCond, p=dens, c=specificheat
		else {
			u[i] = (thermCond*timeChange)/(density*heatCap*pow(lenChange, 2)) * (u[i-29] - 2*u[i-30] + u[i-31]) + u[i-30];
		}

	}
	
	

	for (j = 0; j <= (wireLen*(timeInt+1)); j++) {
		if (time > timeInt)
			break;

		if (j % 30 == 0) {
			printf("\nTime: %d", time);
			time++;
		}

		if (j % 10 == 0)
			printf("\n");

		printf("%.2f ", u[j]);
	}
	
	
	free(u); //Free up the memory
	return 0;
}
