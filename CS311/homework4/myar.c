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
#include <time.h>

int main(int argc, char *argv[]) {
  int fd, tempFd, k = 0;
  unsigned int fSize = 0;
  int fSizeDigits = 0, fSizeTemp = 0;
  unsigned int i = 0, j = 0, currI = 0;

  int spaceCntr = 0;
  time_t fileTime;
  struct tm * brokenTime;
  int month;
  
  struct stat * archiveStat = malloc(sizeof(struct stat));
  struct stat * tempFileStat = malloc(sizeof(struct stat));
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
       if (tEnabled == 1 || vEnabled == 1) {

	 //find the backslash which terminates the filename
	 if (buf[i] == '/') {
	   j = i - 1;

	   //get to the beggining of the filename
	   while (isalnum((int) buf[j]) || ispunct((int) buf[j])) 
	     j--;

	   ++j;
	   k = 0;
	   //put the filename in the fileName char * array.
	   while (buf[j] != '/') {
	     fileName[k] = buf[j];
	     j++;
	     k++;
	   }

	   //If verbose was not enabled just print the filenames only
	   if (vEnabled == 0)
	     printf("%s\n", fileName);

	   //otherwise print out all the necessary info for verbose
	   else {
	     //open the file so we can use fstat on it to get the info we need
	     tempFd = open(fileName, O_RDONLY);

	     if (tempFd < 0) {
	       printf("Error: Could not open file, exiting...");
	       exit(EXIT_FAILURE);
	     }

	     if (fstat(tempFd, tempFileStat) == -1) {
	       printf("Error: fstat() call failed, exiting...");
	       exit(EXIT_FAILURE);
	     }
	     
	     //get the permissions from the stat struct and print
	     printf((tempFileStat->st_mode & S_IRUSR) ? "r" : "-");
	     printf((tempFileStat->st_mode & S_IWUSR) ? "w" : "-");
	     printf((tempFileStat->st_mode & S_IXUSR) ? "x" : "-");
	     printf((tempFileStat->st_mode & S_IRGRP) ? "r" : "-");
	     printf((tempFileStat->st_mode & S_IWGRP) ? "w" : "-");
	     printf((tempFileStat->st_mode & S_IXGRP) ? "x" : "-");
	     printf((tempFileStat->st_mode & S_IROTH) ? "r" : "-");
	     printf((tempFileStat->st_mode & S_IWOTH) ? "w" : "-");
	     printf((tempFileStat->st_mode & S_IXOTH) ? "x" : "-");

	     /*
	       print the user id and group id in the following format:
	       userid/groupid
	      */
	     printf(" %u/%u", tempFileStat->st_uid, tempFileStat->st_gid);
	     
	     //get the filesize
	     fSize = tempFileStat->st_size;

	     /*figure out how many digits are in the size so we can print
	       the appropriate number of spaces before printing the filesize
	       to ensure correct format
	      */

	     fSizeTemp = fSize;
	     while (fSizeTemp != 0) {
	       fSizeTemp /= 10;
	       fSizeDigits++;
	     }


	     for (spaceCntr = 0; spaceCntr < 7 - fSizeDigits; spaceCntr++) 
	       printf(" ");

	     //print filesize
	     printf("%d", fSize);
	     fSizeDigits=0;
	     
	     printf(" ");
	     
	     fileTime = tempFileStat->st_atime;
	     brokenTime = localtime(&fileTime);

	     //print month
	     month = brokenTime->tm_mday;

	     switch(month) {
	     case 0:
	       printf("Jan");
	       break;
	     case 1:
	       printf("Feb");
	       break;
	     case 2:
	       printf("Mar");
	       break;
	     case 3:
	       printf("Apr");
	       break;
	     case 4:
	       printf("May");
	       break;
	     case 5:
	       printf("Jun");
	       break;
	     case 6: 
	       printf("Jul");
	       break;
	     case 7:
	       printf("Aug");
	       break;
	     case 8:
	       printf("Sep");
	       break;
	     case 9:
	       printf("Oct");
	       break;
	     case 10:
	       printf("Nov");
	       break;
	     case 11:
	       printf("Dec");
	       break;
	     }

	     //print the day
	     printf("  %d", brokenTime->tm_mday);

	     //print hours & minutes
	     printf(" %d:%d", brokenTime->tm_hour, brokenTime->tm_min);

	     //print year and filename
	     printf(" %d %s", brokenTime->tm_year+1900, fileName);

	     printf("\n");
	     

	   }
	 }
       }
     }

  return 0;
} 
