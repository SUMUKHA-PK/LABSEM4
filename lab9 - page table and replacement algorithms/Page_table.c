#include<stdio.h>
int check(int a[], int n);
void sorting(int a[],int n);
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
  for(int i=0;i<n;i++)
    page_table[i]=-1;
  printf("Enter the page table entries, if doesnt exist, -1: ");
  for(int i=0;i<n;i++)
    {
      scanf("%d",&page_table[i]);
      while(page_table[i]>pas/s)
      {
        printf("Invalid page table entry, re-enter: ");
        scanf("%d",&page_table[i]);
      }
      while(check(page_table,i+1))
      {
        printf("Frame already exists, re-enter data: ");
        page_table[i]=-1;
        scanf("%d",&page_table[i]);
        while(page_table[i]>n)
        {
          printf("Invalid page table entry, re-enter: ");
          scanf("%d",&page_table[i]);print(page_table,i);
        }
      }
    }
  int q;
  printf("Enter the number of input queries: ");
  scanf("%d",&q);
  while(q--)
  {
    int la,pa;
    printf("Enter the logical address: ");
    scanf("%d",&la);

    int pgno = la/s;
    int offset = la%s;

    int fno = page_table[pgno];
    if(fno==-1)
      {
        printf("Frame doesn't exist in this location! \n");
      }
    else
    {
      pa = fno*s+offset;
      printf("The physical address is %d \n",pa);
      printf("Page Table: \n");
      print(page_table,n);
    }
  }
return 0;
}
int check(int a[], int n)
{
  int i;
  for(i=0;i<n-1;i++)
    {
      if(a[i]==a[n-1]&&a[i]>=0)
        return 1;
    }
  return 0;
}
void sorting(int a[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
        {
          if(a[i]>a[j])
            {
              int t;
              t=a[i];
              a[i]=a[j];
              a[j]=t;
            }
        }
    }
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
/*---------------------------------------------------------------------------TEST CASES-----------------------------------------------------------------------------
Enter the size logical address space: 1000
Enter the size of the page/frame: 100
Enter the size physical address space: 500
Enter the page table entries, if doesnt exist, -1: -1
1
-1
4
2
-1
-1
3
3
Frame already exists, re-enter data: 3
Frame already exists, re-enter data: -1
-1
Enter the number of input queries: 5
Enter the logical address: 120
The physical address is 120
Page Table:

Printing:  -1  1  -1  4  2  -1  -1  3  -1  -1
Enter the logical address: 220
Frame doesn't exist in this location!
Enter the logical address: 900
Frame doesn't exist in this location!
Enter the logical address: 1020
The physical address is 419612320
Page Table:

Printing:  -1  1  -1  4  2  -1  -1  3  -1  -1
Enter the logical address: 320
The physical address is 420
Page Table:

Printing:  -1  1  -1  4  2  -1  -1  3  -1  -1


*/
