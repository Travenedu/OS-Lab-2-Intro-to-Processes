#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){//
  pid_t pid;
  pid_t pid2;
  int loop_iterations;
  int sleepTimer;
  int i;
  int status;
  srand(time(NULL));

  //sets random number of iterations for loop between 1 and 30
  loop_iterations = ((rand() % 30)+1);//30
  //printf("Number of iterations: %d\n", loop_iterations);
  
  //sets random amount of time for child process to sleep
  sleepTimer = (rand() % 10)+1;

  //Creates first child process from parent
  pid = fork();

  //Creates a second child process from parent
  if (pid != 0){
    pid2 = fork();
  }

  if (pid != 0 && pid2 != 0){

  //Signals parent process to wait for children to finish
  waitpid(pid, &status, 0);
  printf("Child Pid: %d has completed\n", pid);

  //Signals parent process to wait for children to finish
  waitpid(pid2, &status, 0);
  printf("Child Pid: %d has completed\n", pid2);

  }else{
    //Child process loops through random amount of iterations
    for (i = 0; i <= loop_iterations; i++) {
      printf("Child Pid: %d is going to sleep!\n", getpid());
      
      //Goes to sleep for random amount of time between 1 and 10
      sleep(sleepTimer);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(),getppid());
    }
    exit(0);
  }
  return 0;
}
