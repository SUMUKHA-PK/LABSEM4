#include<stdio.h>
#include<math.h>
int main()
{
  printf("Enter the number of requests: ");
  int n,i;
  scanf("%d",&n);
  int queue[n],seek[n];
  printf("Enter the start of the pin: ");
  int start; scanf("%d",&start);
  printf("Enter the track position of the requests: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&queue[i]);
    seek[i]=0;
  }
  seek[0]=abs(start-queue[0]);
  for(i=1;i<n;i++)
  {
    seek[i]+=abs(queue[i]-queue[i-1]);
  }
  printf("The movement of the seek pin:\n");
  for(i=0;i<n;i++)
  {
    printf("Process %d on track %d -- %d \n",i,queue[i],seek[i]);
  }
  int s=0;
  for(i=0;i<n;i++)
    s+=seek[i];
  printf("\n Final seek amount: %d\n",s);
  return 0;
}
