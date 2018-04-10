#include<stdio.h>
#include<unistd.h>
int main()
{
  int a= alarm(5);
  printf("%d",a);
  return 0;
}
