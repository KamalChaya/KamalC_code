/*
Kamal Chaya
chayak@onid.orst.edu
CS311-400
Homework #4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  int fd, k = 0;
  int fSize = 0;
  unsigned int i = 0, j = 0, currI = 0;
  
  struct stat * archiveStat = malloc(sizeof(struct stat));
  char * buf, fileSize[10], fileName[15];

  /*Integer variables which will tell us which flags are triggered:
    All are initialized to 0, a value of 1 means that corresponding flag was 
    supplied as a command line argument*/
  
  int tEnabled = 0;
  int vEnabled = 0;

  /*Go through the argv array and search for all the possible flags*/
  for (i = 1; i < argc; i++) {

    if (strcmp(argv[i], "-t") == 0) 
      tEnabled = 1;

    if (strcmp(argv[i], "-v") == 0)
      vEnabled = 1;
  }


  fd = open(argv[argc-1], O_RDWR);

  if (fd == -1) {
    printf("\nCould not open archive file, exiting...");
    exit(EXIT_FAILURE);
  }

  if (fstat(fd, archiveStat) == -1) {
    printf("\nCould not retrieve stat structure, fstat() call failed, exiting...");
    exit(EXIT_FAILURE);
  } 

  buf = malloc(sizeof(char)*archiveStat->st_size);

  if (read(fd, buf, archiveStat->st_size) == -1) {
    printf("\nCould not read archive file, exiting...");
    exit(EXIT_FAILURE);
  }

 
     for (i = 8; i < archiveStat->st_size; i++) {
       if (tEnabled == 1) {

	 //find the backslash which terminates the filename
	 if (buf[i] == '/') {
	   j = i - 1;

	   //get to the beggining of the filename
	   while (isalnum((int) buf[j]) || ispunct((int) buf[j])) 
	     j--;

	   ++j;
	   k = 0;
	   //print from the beggining of the filename
	   while (buf[j] != '/') {
	     fileName[k] = buf[j];
	     j++;
	     k++;
	   }
	   printf("%s\n", fileName);
	 }
       }
     }

  return 0;
} 
