#include<stdio.h>
#include<unistd.h>
int main()
{
  int a= alarm(5);
  printf("%d\n",a);
  return 0;
}
