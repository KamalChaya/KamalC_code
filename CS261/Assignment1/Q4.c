/* CS261- Assignment 1 - Q.4*/
/* Name: Kamal Chaya, Cam Tu Vo
 * Date: 10.10.2013
 * Development Environment: Microsoft Visual Studio 2012 Ultimate Edition.
 * Solution description: 
	-Dynamically allocate an array of n students, and then sort 
	their scores in ascending order using an optimized bubble sorting 
	algorithm, ensuring that each student retains their original score
	(Meaning the ID and score must always share the same index value).

 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

/*
This function sorts the students scores with an optimized bubble sort
algorithm, and it also ensures that the ID's stay with their corresponding
scores so that each student retains their original score.

Preconditions: Need an array of type students (a pointer to a student struct) to
pass into the function. We also need an integer containing the number of students
to pass into the function.
PostConditions: 
-The students scores will be sorted in ascending order in the array
-Each score and its corresponding original ID will be located at the same
index in the array (Meaning each student retains their original score). 
*/
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
	//The temp variables are for swapping purposes.
	int i = 0, j = 0, temp = 0, temp2 = 0, swaps = 0;

	for (j = 0; j <= n*n; j++) {
		swaps = 0;
		for (i = 0; i <= n - 2; i++) {
			if (students[i].score > students[i+1].score) {
				//To indicate that swaps have occured:
				swaps++;

				/*Swap the score AND the corresponding ID, this way each student
				is always matched up with their original score.
				*/
				temp = students[i].score;
				temp2 = students[i].id;

				students[i].score = students[i+1].score;
				students[i].id = students[i+1].id;
				students[i+1].score = temp;
				students[i+1].id = temp2;
			}
		}
		if (swaps == 0)
			break;
	}

}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 11, i = 0, j = 0, no_duplicates = 0;
    
    /*Allocate memory for n students using malloc.*/
	struct student * students = (struct student *) malloc(n*sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
	srand(time(NULL));

	//Initialize ID's and scores to 0 first:
	for (i = 0; i <= n - 1; i++) {
		students[i].id = 0;
		students[i].score = 0;
	}

	//generate ID's
	for (i = 0; i <= n - 1; i++) {
		students[i].id = rand() % n + 1;
		students[i].score = rand() % 100;

		for (j = 0; j <= i; j++) {
			if (no_duplicates == 1) {
				j = 0;
				no_duplicates = 0;
			}

			/*
				This while loop ensures that if an id
				generated is the same as any previously
				generated id, a random id will be continuously
				generated until it is different from the 
				previous id.
			*/
			while ((students[i].id == students[j].id) && (i != j)) {
				students[i].id = rand() % 10 + 1;
				
				/*
				 When a new random id is generated for
				 students[i].id, it may be different from
				 students[j].id, but because it is new, it 
				 may still be the same as id's BEFORE
				 students[j].id. Thus, after generating a 
				 new id for students[i].id, after we verify 
				 that it is different from students[j].id,
				 we set a variable (no_duplicates) to 1 to
				 indicate we have checked this condition, and
				 then we go break out of the while loop and
				 go through the entire students array up to
				 i to ensure that the NEW students[i].id
				 is not same as any of the id's BEFORE
				 students[j].id.

				 EX:
				 Suppose the first three elements of the
				 students[i].id array are:
					5, 4, and 4.
				 When i = 2 and j = 1, the program will 
				 detect the duplicate of 4 and 4. it will
				 enter the while loop "while (students[i].id == students[j].id)"
				 and change the 4 at students[2].id.

				 However, what may happen is that the newly
				 generated id at students[2] may end up being 5.
				 This is no longer a duplicate with the 4 at 
				 students[1].id, but it IS a duplicate with the
				 id at students[0].id. 

				 Thus, after we make the newly generated id, we 
				 first check to make sure that the students[j].id
				 is not the same as the students[i].id (in this case,
				 make sure the 5 at students[2] is not equal to 
				 the 4 at students[1], which it is not. Now, we
				 set the value of a variable no_duplicates to 1; 
				 this indicates that we have checked this condition.
				 After this, break out of the
				 while loop. At the beggining of the for loop, we can
				 now set j=0 because of "if (no_duplicates == 1)"

				 Now since j=0, the comparisons between students[j].id
				 and students[i].id will start at the beggining again;
				 so the 5 at students[0].id will now be compared to
				 the 5 at students[3].id. The program will detect this
				 duplicate, and the 5 at students[3].id will be 
				 changed.
				 */

				if (students[i].id != students[j].id) {
					no_duplicates = 1;
					break;
				}
			}

			if ((j == i) && (no_duplicates == 1)) {
				no_duplicates = 0;
				break;
			}
		}		
	}

    /*Print the contents of the array of n students.*/
	printf("ID score\n");
	for (i = 0; i <= n - 1; i++) 
		printf("%d %d\n", students[i].id, students[i].score);

    /*Pass this array along with n to the sort() function*/
	sort(students, n);
    
    /*Print the contents of the array of n students.*/
	printf("After sorting scores: \n");
	printf("ID score\n");
	for (i = 0; i <= n - 1; i++) 
		printf("%d %d\n", students[i].id, students[i].score);

    
    return 0;
}
