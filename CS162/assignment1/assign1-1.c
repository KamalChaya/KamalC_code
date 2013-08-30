/****************************************************
** Program Filename: assign1-1.c

** Author: Kamal Chaya

** Date: DUE 4.14.2013

** Description: Finds solutions to cryptarithmetic  
puzzles where letters correspond to numbers.

** Input: None; the program already knows the puzzle.

** Output: Solutions to the puzzle (which letter
corresponds to which number).
******************************************************/

#include <stdio.h>

int main() {
  int T, O, G, D;
  /*
    We need to have a nested for loop to iterate through the
    values 0-9 for the letters T, O, G, and D).
   */
	
	for (T = 0; T <= 9; T++) {
	  for (O = 0; O <= 9; O++) {
	    for (G = 0; G <= 9; G++) {
	      for (D = 0; D <= 9; D++) {
		/*
		  T, O, G, D cannot have the same value as per the rules for this 
		  assignment. Thus we check for this condition here; If they do,
		  we simply continue with the iterations without displaying the
		  solutions.
		 */
		if ((D == G) || (D == O) || (D == T) || (G == O) || (G == T) || (O == T)) 	   
		  continue;	       

		else if ((400*T + 40*O + 4*O) == (1000*G + 100*O + 10*O + D)) {
		  printf("\nT = %d", T);
		  printf("\nO = %d", O);
		  printf("\nG = %d", G);
		  printf("\nD = %d", D);
		  break;
		}

	      }
	    }
	  }
	}
	
	return 0;
}


