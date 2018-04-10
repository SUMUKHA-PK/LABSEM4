// Least recently used page replacement algorithm
#include<stdio.h>
int check(int* a, int n,int x);
void print(int* a, int n);
int find(int *a,int n);
void doit(int *a , int c, int n);
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
  int page_table[n][2];
  for(int i=0;i<n;i++)
    {page_table[i][1]=-1;page_table[i][0]=0;}
  int c=0;
  while(1)
  {
    int f=0;
    printf("If you want to continue hit 1, else 0: \n");
    int x; scanf("%d",&x);if(x==0) break;
    int la,pa,co=0;
    printf("Enter the logical address: ");
    scanf("%d",&la);
    if(!check((int*)page_table,n,la))  //TODO : Reset operation on timer , do the filling only when full
    {
      co++;
      f=1;
      if(full(page_table,n))
      {
        c=find((int*)page_table,n);
        page_table[c][1]=la;
      }
      else
        {
          page_table[co-1][1]=la;
        }
      doit((int*)page_table,c,n);
    }
    if(f==0)c--;
    printf("Page Table: \n");
    print((int*)page_table,n-1);
  }
return 0;
}
void print(int* a, int n)
{
  printf("\nPrinting: ");
  int i;
  for(i=0;i<n;i++)
    {
      printf(" %d %d \n",*(a+i*n),*(a+i*n+1));
    }
  printf("\n");
}
int check(int* a, int n,int x)
{
  int i;
  for(i=0;i<n-1;i++)
    {
      if(*(a+i*n)==x)
        return 1;
    }
  return 0;
}
int find(int *a,int n)
{
  int i,m=0,j;
  for(i=0;i<n;i++)
    {
      if(*(a+i*n)!=-1)
        {
          if(m<*(a+i*n))
            m=*(a+i*n);
            j=i;
        }
    }
  return j;
}
void doit(int *a , int c, int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(*(a+i*n)!=-1)
        {
          if(i!=c)
            {
              (*(a+i*n+1))++;
            }
        }
    }
}
