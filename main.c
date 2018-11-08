#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  while(1){
    printf("Hi I'm: %d", getpid());
    sleep(1);
  }
}
