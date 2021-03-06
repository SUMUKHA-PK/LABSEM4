#include<stdio.h>
struct partitions
{
  int capacity,valid;
}parts[10000];
int findmax(struct partitions parts[], int n,int pro);
int main()
{
  int n,number,i;
  printf("Enter the size of the queue: ");
  scanf("%d",&n);
  printf("Enter the number of partitions: ");
  scanf("%d",&number);
  printf("Enter the size of the partitions :");
  for(i=0;i<number;i++)
    scanf("%d",&parts[i].capacity);
  for(i=0;i<number;i++)
    parts[i].valid=1;
  for(i=0;i<n;i++)
    {
      printf("Enter the size of the process: ");
      int pro; scanf("%d",&pro);
      int x = findmax(parts,number,pro);
      if(x!=-1)
        {
          parts[x].valid=0;
          printf("Process %d assigned to partition %d \n", i, x);
        }
      else
        {
          printf("Process %d cannot be assigned to any partition\n",i);
          printf("Do you want to de-allocate any partition? 1.Yes 2.No\n");
          int p;
          scanf("%d",&p);
          if(p==1)
            {
              printf("Allowed partitions are: ");int co=0;
              for(int h=0;h<number;h++)
                {
                  if(parts[h].valid==0&&parts[h].capacity>=pro)
                    {co++;
                      printf("%d ",h);
                    }
                }int f=0;
              if(co==0) {printf("There are no allowed partitions!\n");f=1;}
              if(f==0)
                {
                  printf("\n Enter the partition you want to de-allocate: ");
                  int h;
                  scanf("%d",&h);
                  parts[h].valid=0;
                  printf("Process %d assigned to partition %d \n", i, h);
                }
            }
        }
    }
  return 0;
}
int findmax(struct partitions parts[], int n,int pro)
{
  int i,m=1000000,x=-1;
  for(i=0;i<n;i++)
    {
      if(parts[i].valid==1)
        {
          if(m>=parts[i].capacity&& parts[i].capacity>=pro)
          {  m=parts[i].capacity;
            x=i;}

        }
    }
  return x;
}
//----------------------------------------------------------------TEST-CASES-----------------------------------------------------------------------
//----Enter the size of the queue:
//7
//----Enter the number of partitions:
//7
//----Enter the size of the partitions :
//1000 400 50 100 500 600 250
//----Enter the size of the process:
// 45
//----Process 0 assigned to partition 2
//----Enter the size of the process:
//980
//----Process 1 assigned to partition 0
//----Enter the size of the process:
//1000
//----Process 2 cannot be assigned to any partition
//----Do you want to de-allocate any partition? 1.Yes 2.No
//1
//----Allowed partitions are: 0
//----Enter the partition you want to de-allocate:
//0
//----Process 2 assigned to partition 0
//----Enter the size of the process:
//200
//----Process 3 assigned to partition 6
//----Enter the size of the process:
// 98
//----Process 4 assigned to partition 3
//----Enter the size of the process:
//600
//----Process 5 assigned to partition 5
//----Enter the size of the process:
//500
//----Process 6 assigned to partition 4
