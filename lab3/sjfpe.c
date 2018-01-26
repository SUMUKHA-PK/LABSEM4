#include<stdio.h>
void sorting(int a[],int b[],int c[],int n);
int main()
{
  int n,i;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int ar[n],bu[n],wt[n],tat[n];
  printf("Enter the priority of the processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&pr[i]);
  printf("Enter the arrival times of processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
  printf("Enter the burst times of the processes: ");
  for(i=0;i<n;i++)
    scanf("%d",&bu[i]);
  printf("Implementing SHORTEST JOB FIRST scheduling algorithm...\n");
  sorting(bu,ar,n);
  wt[0]=0;
  for(i=1;i<n;i++)
    {
      wt[i]=wt[i-1]+bu[i-1]+ar[i-1]-ar[i];
    }
  for(i=0;i<n;i++)
    {
      tat[i]=bu[i]+wt[i];
    }
  printf("pr ar bu wt tat\n");
  for(i=0;i<n;i++)
    {
      printf("%d %d %d  %d  %d\n",pr[i],ar[i],bu[i],wt[i],tat[i]);
    }
  return 0;
}
void sorting(int a[],int b[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
      {
        for(j=0;j<n-i-1;j++)
          {
            if(a[j]>a[j+1])
              {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                temp=b[j+1];
                b[j+1]=b[j];
                b[j]=temp;
              }
          }
      }
}
