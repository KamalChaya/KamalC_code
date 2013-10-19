/* CS261- Assignment 1 - Q.1*/
/* Name: 
	-Kamal Chaya
	-Cam Tu Vo
 * Development Environment: Microsft Visual Studio Ultimate 2012
 * Date:
	10.08.2013
 * Solution description:
	generates random unique id's (checks id's against previously
	generated id's to ensure uniqueness). Also generates random
	scores, prints the ID's and scores, and calculates and prints
	the average, minimum, and maximum score.
 */
 
/*
Questions:
more optimal way to generate unique random id's?
deallocating memory is just using the free function right?
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
Dynamically allocates memory for 10 students, and returns
a pointer to this memory.

Preconditions: None
Postconditions: That the pointer points to the memory for 
the 10 students.
*/
struct student* allocate(){
     /*Allocate memory for ten students*/
	 struct student * students = (struct student *) malloc(10*sizeof(struct student));

     /*return the pointer*/
	 return students;
}

/*
Generate unique, random ID numbers (1-10) and random scores (0-100) for each
of the 10 students.

Preconditions: Must have a student object or a pointer to a student object
to pass into the function.
Postconditions: Must have unique random ids and random scores for each student.
*/
void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
	
	int temp = 0, i = 0, j = 0, no_duplicates = 0;

	//Seed random number generator with time because time is always changing:
	srand(time(NULL));

	//Initialize ID's and scores to 0 first:
	for (i = 0; i <= 9; i++) {
		students[i].id = 0;
		students[i].score = 0;
	}

	//generate 10 ID's
	for (i = 0; i <= 9; i++) {
		students[i].id = rand() % 10 + 1;
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
}

/*
Prints the ID's and scores of all 10 students.

Preconditions: Have a student object or a pointer to a student object.
The array of the student object must be completely filled with numbers
for the id's and scores of students.
Postconditions: None
 */
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

	int i = 0;
	printf("ID score\n");
	for (i = 0; i <= 9; i++) 
		printf("%d %d\n", students[i].id, students[i].score);
}

/*
Finds the minimum, maximum, and average scores, and prints them
on the screen.

Preconditions: Have a student object or a pointer to a student object.
The array of the student object must be completely filled with numbers
for the id's and scores of students.
Postconditions: None
 */
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = 0, max = 0, i = 0, temp = 0, temp2 = 0, sum = 0;
	float avg = 0;

	/*
	  Search the scores for the maximum and minimum, and then
	  sum up the scores
	 */
	max = students[0].score;
	min = students[0].score;
	sum = students[0].score;

	for (i = 0; i <= 8; i++) {
		temp = students[i + 1].score;
		temp2 = students[i + 1].score;

		if (temp > max)
			max = temp;

		if (temp2 < min)
			min = temp2;

		sum += students[i + 1].score;
	}

	avg = sum/10.0;

	//print min, max, and average.
	printf("minimum score: %d\n", min);
	printf("maximum score: %d\n", max);
	printf("average score: %.2f\n", avg);
		
}

/*
Frees up the memory on the heap that was
previously allocated in the allocate() function.

Preconditions: That there exist a object of type
student or a pointer to one.
Postconditions: The memory that was once allocated
to the student object is now deallocated.
*/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
	int i = 0;
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();

    /*call generate*/
	generate(stud);

    /*call output*/
	output(stud);
    
    /*call summary*/
	summary(stud);
    
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
