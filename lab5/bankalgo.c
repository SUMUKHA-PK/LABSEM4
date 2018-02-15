#include<stdio.h>
int checker(int *need,int work[],int n,int m,int finish[]);
int check(int finish[],int n );
int dothis(int *need,int work[],int n,int m,int c,int finish[],int *allocation);
int main()
{
  int n,m;
  printf("Enter the number of processes and number of resource types: ");
  scanf("%d %d",&n,&m);
  int available[m],work[m],finish[n],max[n][m],allocation[n][m],need[n][m],sequence[n];
  int i,j;
  printf("Enter the --available-- array: ");
  for(i=0;i<m;i++)
    scanf("%d",&available[i]);
  for(i=0;i<m;i++)
    work[i]=available[i];
  for(i=0;i<n;i++)
    finish[i]=0;
  printf("Enter the --allocation-- array: ");
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
        scanf("%d",&allocation[i][j]);
    }
  printf("Enter the --max-- array: ");
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
        scanf("%d",&max[i][j]);
    }
  for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
        need[i][j]=max[i][j]-allocation[i][j];
    }
  int o=0;
  int p,q;
  while(1)
  {
    p=checker((int *)need,work,n,m,finish);
    q=check(finish,n);
    if(!p||!q)
      break;
    for(i=0;i<n;i++)
      {
        if(dothis((int *)need,work,n,m,i,finish,(int *)allocation))
          {
          //  printf("I DID IT\n");
            finish[i]=1;
            sequence[o]=i+1;
            o++;
          }
      }
  }
if(q==0)
    {
      printf("The sequence of execution is --- ");
      for(i=0;i<n;i++)
        printf("P(%d) ",sequence[i]);
      printf("\n");
    }
else if(p==0)
    printf("Not safe to execute!\n");
  return 0;
}

int check(int finish[],int n )
{
  int i,c=0;
  for(i=0;i<n;i++)
    {
      if(finish[i]==1)
        c++;
    }
  if(c==n)
    return 0;
  else
    return 1;
}
int checker(int *need,int work[],int n,int m,int finish[])
{
  int i,j,k=0;
  for(i=0;i<n;i++)
    {k=0;
      for(j=0;j<m;j++)
        {
          if(work[j]<=*((need+i*m)+j)&&finish[i]==0)
            k++;
        }
      if(k>0)
        return 1;
    }
  if(k==0)
    return 0;
}
int dothis(int *need,int work[],int n,int m,int c,int finish[],int *allocation)
{
  int j,k=0;
  for(j=0;j<m;j++)
    {
  //    printf("J=%d c=%d n=%d\n\n",j,c,n);
  //    printf("need:%d work:%d j: %d \n",*((need+c*m)+j),work[j],j);
      if(*((need+c*m)+j)<=work[j]&&finish[c]==0)
      {
        k++;
    //    printf("need:%d work:%d j: %d \n",*((need+c*m)+j),work[j],j);
      }

    }//printf("k:%d \n",k);
  if(k==m)
    {
      for(j=0;j<m;j++)
        work[j]+=*((allocation+c*m)+j);
      return 1;
    }
  else
    return 0;
}
