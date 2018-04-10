// LRU page replacement

#include<stdio.h>
void print(int page[], int n);
int getslot(int page[], int n,int sl);
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
  printf("Enter the requests: ");
  for(i=0;i<req;i++)
    scanf("%d",&requests[i]);
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

int getslot(int page[], int n,int sl)
{
  return (sl+1)%n;
}
