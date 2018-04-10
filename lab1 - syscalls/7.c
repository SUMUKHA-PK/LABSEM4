#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
  int f=open("31.txt",O_WRONLY|O_APPEND|O_RDWR|O_EXCL);
  int a=getuid();
  printf("%d-> this is the real user id\n",a);
  a=geteuid();
  printf("This is the effective user id %d\n",a);
  a=getgid();
  printf("This is the real group id %d\n",a);
  int b=getegid();
  printf("This is the effective group id %d\n",b);
  printf("The pid  of the process is %d\n",getpid());
  printf("The epid for the process is %d\n",getppid());
  return 0;
}
