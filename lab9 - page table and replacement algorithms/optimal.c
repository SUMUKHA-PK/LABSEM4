// Optimal Page replacement  algorithm

#include<stdio.h>
void print(int page[], int n);
int getslot(int page[],int requests[],int b[],int req, int n, int x,int p);
int main()
{
  int n;
  printf("Enter the size of the page table: ");
  scanf("%d",&n);
  int page[n];
  for(int k=0;k<n;k++)
    page[k]=0;
  int req;
  int b[n];
  for(int h=0;h<n;h++)
    b[h]=0;
  printf("Enter the number of page requests: ");
  scanf("%d",&req);
  int requests[req];
  int i;
  printf("Enter the requests: ");
  for(i=0;i<req;i++)
    scanf("%d",&requests[i]);
  int test=req;
  i=0;
  while(test--)
    {
      int x = getslot(page,requests,b,req,n,requests[i],i);
      if(x!=-1)
      {
        printf("The page table after this request: ");
        page[x]=requests[i];
        i++;
        print(page,n);
      }
      else
        {printf("The query already exists!\n");i++;}
    }
  return 0;
}
void print(int page[], int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(page[i]!=0)printf("| %d ",page[i]);
      else printf("|  ");
    }
  printf("|\n");
}

int getslot(int page[],int requests[],int b[],int req, int n, int x,int p)
{
  int i,m=1e9,j;
  int count[n];
  for(i=0;i<n;i++)
    {
      int c=0;
      for(int l=p;l<req;l++)    // Count the number of times the request has been asked
        {
          if(requests[l]==page[i])
            c++;
        }
      count[i]=c;
    }
  for(i=0;i<n;i++)
    {
      if(x==page[i])           // Return if it already is present
        {
          return -1;
        }
    }
  for(i=0;i<n;i++)
    {
      if(b[i]==0)
        {
          b[i]=1;
          return i;
        }
      else
        {
          if(count[i]<m)        // Find min
            {
              m=count[i];
              j=i;
            }
        }
    }
    return j;
}

/*
----------------------------------------------------------------------TEST CASES---------------------------------------------------------------

Enter the size of the page table: 5
Enter the number of page requests: 14
Enter the requests: 1 3 7 6 2 1 9 7 1 4 4 1 7 1 3 2 4 1
The page table after this request: | 1 |  |  |  |  |
The page table after this request: | 1 | 3 |  |  |  |
The page table after this request: | 1 | 3 | 7 |  |  |
The page table after this request: | 1 | 3 | 7 | 6 |  |
The page table after this request: | 1 | 3 | 7 | 6 | 2 |
The query already exists!
The page table after this request: | 1 | 9 | 7 | 6 | 2 |
The query already exists!
The query already exists!
The page table after this request: | 1 | 4 | 7 | 6 | 2 |
The query already exists!
The query already exists!
The query already exists!
The query already exists!

*/
