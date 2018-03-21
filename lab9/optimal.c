// First in first out page replacement algorithm
#include<stdio.h>
int check(int a[], int n,int x);
void print(int a[], int n);
int main()
{
  int las,pas,s;
  printf("Enter the size logical address space: ");
  scanf("%d",&las);
  printf("Enter the size of the page/frame: ");
  scanf("%d",&s);
  printf("Enter the size physical address space: ");
  scanf("%d",&pas);
  int n = las/s;
  int page_table[n];
  int c=0;
  printf("Enter the stream of queries: " );
  for(i=0;i<n;i++)
    scanf("%d",page_table[i]);
  
return 0;
}
void print(int a[], int n)
{
  printf("\nPrinting: ");
  int i;
  for(i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
  printf("\n");
}
int check(int a[], int n,int x)
{
  int i;
  for(i=0;i<n-1;i++)
    {
      if(a[i]==x)
        return 1;
    }
  return 0;
}
