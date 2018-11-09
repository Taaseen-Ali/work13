#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>


static void sighandler(int signo){
  if(signo == SIGINT){
    int file = open("errlog.txt", O_WRONLY | O_CREAT , 0666);
    if(file<0){
      printf("Error opening file: %s\n", strerror(errno));
      exit(0);
    }
    lseek(file, 0, SEEK_END);
    write(file, "Exit due to SIGINT\n", 19);
    close(file);
    exit(0);
  }

  if(signo == SIGUSR1){
    printf("Parent process: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  kill(getpid(), SIGUSR1);
  while(1){
    
    printf("Hi I'm %d\n", getpid());
    sleep(1);
  }
}
