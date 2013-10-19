/* CS261- Assignment 1 - Q.5*/
/* Name: Kamal Chaya, Cam Tu Vo
 * Date: 10.9.2013
 * Development Environment: Microsoft Visual Studio 2012 Ultimate Ed.
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	 int i = 0;
	 while (word[i] != '\0') {
		 /*
		 We capitalize every letter on an even
		 numbered index, and make a letter lowercase
		 if it is on an odd numbered index.
		 */
		 if (i % 2 == 0) {
			 if (!isupper(word[i]))
				 word[i] = toUpperCase(word[i]);
		 }

		 else if (!(i % 2 == 0)) {
			 if (!islower(word[i]))
				 word[i] = toLowerCase(word[i]);
		 }

		 i++;
	 }
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[100];

	printf("Enter a word: \n");
	scanf("%s", word);
    
    /*Call studly*/
	studly(word);
    
    /*Print the new word*/
	printf("Word with studly caps: \n");
	printf("%s", word);
    
    return 0;
}
