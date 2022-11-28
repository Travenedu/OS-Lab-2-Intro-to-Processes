#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

//Figure out where this should go
int main(int argc, char* argv[]){
  
  int loop_iterations;
  int i;

  //Creates first child process from parent
  int pid = fork();

  //Creates a second child process from parent
  if (pid != 0){
    fork();
  }

  //Child process loops through random amount of iterations
  if (pid == 0){
    srand(time(NULL));

    //sets random number of iterations for loop between 1 and 30
    loop_iterations = (rand() % 30)+1);

    for (i = 1; i <= loop_iterations; i++) {
      printf("Child Pid: %d is going to sleep!\n", getpid());
      
      //Goes to sleep for random amount of time between 1 and 10
      sleep((rand() % 10)+1);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(),getppid());

    }
    exit(0);
  }
  //Signals parent process to wait for children to finish
  int res = wait(NULL);

  //if wait sends an error then there in no executing child process
  if (res == -1){
    //no child process
    printf("There is no child process to wait for\n");
  } else{
    //There is a child process still executing
    printf("Child Pid: %d has completed\n", res);
  }

  return 0;
}
