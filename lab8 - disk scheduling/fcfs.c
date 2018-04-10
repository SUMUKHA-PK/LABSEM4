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
  /* 

  -------------------------------------------------------------------TEST CASES----------------------------------------------------

  Enter the number of requests: 8
Enter the start of the pin: 53
Enter the track position of the requests: 98 14 37 122 64 124 67 183
The movement of the seek pin:
Process 0 on track 98 -- 45 
Process 1 on track 14 -- 84 
Process 2 on track 37 -- 23 
Process 3 on track 122 -- 85 
Process 4 on track 64 -- 58 
Process 5 on track 124 -- 60 
Process 6 on track 67 -- 57 
Process 7 on track 183 -- 116 

 Final seek amount: 528
