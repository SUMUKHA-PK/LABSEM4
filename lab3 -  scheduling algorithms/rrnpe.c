#include<stdio.h>
void addition(int bu[],int wt[],int i,int x,int n);
int check(int bu[],int n);
int main()
{
  int n,t,i,x;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  printf("Enter the time quantum: ");
  scanf("%d",&t);
  int bu[n],wt[n],tat[n];
  printf("Enter the burst times of the processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&bu[i]);
  int bur[n];
  for(i=0;i<n;i++)
    bur[i]=bu[i];
  printf("Implementing ROUND-ROBIN scheduling(non-preemptive) algorithm..\n");
  while(check(bu,n))
    {
      for(i=0;i<n;i++)
        {
          if(bu[i]>=t)
            {
              bu[i]-=t;
              x=t;
            }
          else
            {
              x=bu[i];
              bu[i]=0;
            }
          addition(bu,wt,i,x,n);
        }
      for(i=0;i<n;i++)
        printf("%d ",bu[i]);
      printf("\n");
    }
  for(i=0;i<n;i++)
    {
      tat[i]=bur[i]+wt[i];
    }
  printf("bu wt tat\n");
  for(i=0;i<n;i++)
    {
      printf("%d  %d  %d\n",bur[i],wt[i],tat[i]);
    }
}
int check(int bu[],int n)
{
  int i,c=0;
  for(i=0;i<n;i++)
    {
      if(bu[i]==0)
        c++;
    }
  if(c==n)
    return 0;
  else
    return 1;
}
void addition(int bu[],int wt[],int i,int x,int n)
{
  int j;
  for(j=0;j<n;j++)
    {
      if((bu[j]!=0)&&(j!=i))
        {
          wt[j]+=x;
        }
    }
}
