/*
Kamal Chaya
chayak@onid.orst.edu
CS311-400
Homework 4
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sigIntHandler() {
  printf("SIGINT has been caught, terminating the program\n");
  exit(EXIT_SUCCESS);
}

void sigUsr1Handler() {
  printf("SIGUSR1 has been caught\n");
}

void sigUsr2Handler() {
  printf("SIGUSR2 has been caught\n");
}

int main() {
  if (signal(SIGUSR1, sigUsr1Handler) == SIG_ERR) 
    printf("can't catch SIGUSR1\n");
  
  if (signal(SIGUSR2, sigUsr2Handler) == SIG_ERR)
    printf("can't catch SIGUSR2\n");

  if (signal(SIGINT, sigIntHandler) == SIG_ERR)
    printf("can't catch SIGINT\n");

  kill(getpid(), SIGUSR1);
  kill(getpid(), SIGUSR2);
  kill(getpid(), SIGINT);

  return 0;
}
