#include<stdio.h>
int findmin(int bu[],int ar[],int t,int n,int y);
int main()
{
  int n,i;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int bu[n],wt[n],tat[n],ar[n];
  printf("Enter the burst times of the processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&bu[i]);
  printf("Enter the arrival times of the processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
  printf("Implementing SHORTEST JOB FIRST (non-preemptive) scheduling algorithm...\n");
  int t=0;
  int x=0;
  int bur[n],arr[n];
  for(i=0;i<n;i++)
    {
      int z=bu[x];
      printf("walirfhb%d\n",z);
      x=findmin(bu,ar,t,n,z);
      bur[i]=bu[x];
      arr[i]=ar[x];
      if(arr[i]==0)
          wt[i]=0;
      else
        {
          wt[i]=wt[i-1]+bur[i]-arr[i];
        }
      t+=bur[i];
      printf("!%d!",t);
    }
  for(i=0;i<n;i++)
    tat[i]=bur[i]+wt[i];
  printf("arr bur  wt tat\n");
  for(i=0;i<n;i++)
    {
      printf("%d   %d   %d    %d\n",arr[i],bur[i],wt[i],tat[i]);
    }
  return 0;
}int g=0;
int findmin(int bu[],int ar[],int t,int n,int y)
{
//  printf("\nPRINTIT %d \n",y);
  int i,min=1000000;
  int index;
  for(i=0;i<n;i++)
    {
      if(ar[i]<=t)
        {
          if(g!=0)
          {
          if((bu[i]<min)&&(bu[i]>y))
            {
              printf("!y=%d min=%d bu[i]=%d!\n",y,min,bu[i]);
              min=bu[i];
              index=i;
              //bu[i]=100000;
            }
          }
          else
            {
              if(bu[i]<min)
                {
                  printf("!y=%d min=%d bu[i]=%d!\n",y,min,bu[i]);
                  min=bu[i];
                  index=i;
                  //bu[i]=100000;
                  g=1;
                }
            }
        }
    }
return index;
}
