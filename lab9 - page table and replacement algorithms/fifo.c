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
  int n = las/s;n++;
  int page_table[n];
  for(int i=0;i<n;i++)
    page_table[i]=-1;
  int c=0;
  while(1)
  {
    int f=0;
    c++;
    printf("If you want to continue hit 1, else 0: \n");
    int x; scanf("%d",&x);if(x==0) break;
    int la,pa;
    printf("Enter the logical address: ");
    scanf("%d",&la);
    c=c%n;
    if(!check(page_table,c,la)){f=1;page_table[c-1]=la;}
    if(f==0)c--;
    printf("Page Table: \n");
    print(page_table,n-1);
  }
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
