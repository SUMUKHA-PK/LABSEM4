#include<stdio.h>

struct partitioner
  {
    int q[10000],size;
  }partition[10000];

  int check(struct partitioner partition[],int n,int x);
  int find(int a[],int n, int s);
  void doit(int a[],int x,int i);


int main()
{
  printf("Enter the number of partitions: ");
  int part,i,j,n;
  scanf("%d",&part);
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  for(i=0;i<part;i++)
    {
      printf("Enter the size of the partition %d: ",i);
      int x; scanf("%d",&x);
      partition[i].size=x;
      printf("Enter the size of the processes for %d partition: ",i);
      for(j=0;j<n;j++)
        {scanf("%d",&x);partition[i].q[j]=x;}
    }
  /*for(i=0;i<part;i++)
    {
      printf("The size of the partition: %d \t",partition[i].size);
      printf("The size of the processes per partition: ");
      for(j=0;j<n;j++)
        printf(" %d ",partition[i].q[j]);
      printf("\n");
    }*/int f=0;
  while(check(partition,n,part)&&f==0)
    {
      for(i=0;i<part;i++)
        {
          int k=find(partition[i].q,n,partition[i].size);
          if(k==-1)
            {printf("Not possible!\n");f=1;break;}
          else
            {
              doit(partition[i].q,k,i);
            }
        }
    }
  return 0;
}
int check(struct partitioner partition[],int n,int x)
{
  int i,j,c=0,d=0;
  for(i=0;i<x;i++)
    {c=0;
      for(j=0;j<n;j++)
        {
          if(partition[i].q[j]==1000)
            c++;
        }
      if(c==n)
        d++;
    }
  if(d==x)
    return 0;
  return 1;
}
int find(int a[],int n, int s)
{
  int m=0,i,j;
  for(i=0;i<n;i++)
    {
      if(a[i]>m&&a[i]<=s)
        {m=a[i];j=i;}
    }
  if(m==0)
    return -1;
  return j;
}
void doit(int a[],int x,int i)
{
  printf("Process %d assigned to partition %d\n",x,i);
  a[x]=1000;
}
