// LRU page replacement

#include<stdio.h>
void print(int page[], int n);
int getslot(int page[], int count[], int n, int x);
int main()
{
  int n;
  printf("Enter the size of the page table: ");
  scanf("%d",&n);
  int page[n];
  for(int k=0;k<n;k++)
    page[k]=0;
  int req;
  printf("Enter the number of page requests: ");
  scanf("%d",&req);
  int requests[req];
  int i;
  int count[n];
  for(i=0;i<n;i++)
    count[i]=0;
  printf("Enter the requests: ");
  for(i=0;i<req;i++)
    scanf("%d",&requests[i]);
  int test=req;
  i=0;
  while(test--)
    {
      int x = getslot(page,count,n,requests[i]);
      if(x!=-1)
      {
        printf("The page table after this request: ");
        count[x]=1;
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

int getslot(int page[], int count[], int n, int x)
{
  int i,m=1e9,j;
  for(i=0;i<n;i++)
    {
      if(x==page[i])
        {
          count[i]++;
          return -1;
        }
    }
  for(i=0;i<n;i++)
    {
      if(count[i]<m)
        {
          m=count[i];
          j=i;
        }
    }
    return j;
}

/*
----------------------------------------------------------------TEST CASES------------------------------------------------------------------

Enter the size of the page table: 5
Enter the number of page requests: 12
Enter the requests: 3 1 8 7 1 10 9 3 2 1 8 3
The page table after this request: | 3 |  |  |  |  |
The page table after this request: | 3 | 1 |  |  |  |
The page table after this request: | 3 | 1 | 8 |  |  |
The page table after this request: | 3 | 1 | 8 | 7 |  |
The query already exists!
The page table after this request: | 3 | 1 | 8 | 7 | 10 |
The page table after this request: | 9 | 1 | 8 | 7 | 10 |
The page table after this request: | 3 | 1 | 8 | 7 | 10 |
The page table after this request: | 2 | 1 | 8 | 7 | 10 |
The query already exists!
The query already exists!
The page table after this request: | 3 | 1 | 8 | 7 | 10 |


*/
