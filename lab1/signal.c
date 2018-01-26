#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void sig(int signum)
{
    printf("Recieved signal %d\n",signum);
    int k = kill(getpid(),signum); //returns a zero on success
    printf("%d\n",k);
    if(k==0)
      printf("SUCCESSS\n");
    exit(signum);
}
int main()
{
  signal(SIGINT,sig);
  while(1)
    {
      printf("PRINTING\n");
      sleep(1);
    }
  return EXIT_SUCCESS;
}
