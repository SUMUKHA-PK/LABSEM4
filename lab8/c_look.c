//C-LOOK ALGORITHM
#include<stdio.h>
void sort (int a[],int n);
int main()
{
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int x,i;
  char p;
  printf("Enter the starting track of the seek pin: ");
  scanf("%d",&x);
  printf("Enter the direction of motion of seek pin: ");
  getchar();
  scanf("%c",&p);
  int queue[n],s=0;
  printf("Enter the track position of all the processes: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&queue[i]);
  }
  sort(queue,n);
  if(p=='+')
    {
      int z;
      for(i=0;i<n;i++)
        {
          if(queue[i]>=x)
            {
              z=i;break;
            }
        }
      int j=0;
      if(x!=queue[z])
        {
          printf("The %d-th movement is from track %d to %d, with total seek of: %d \n",++j,x,queue[z],abs(queue[z]-x));
          s+=abs(queue[z]-x);
        }
      for(i=z+1;i<n;i++)
        {
          printf("The %d-th movement is from track %d to %d with total seek of: %d \n",j+1,queue[i-1],queue[i],abs(queue[i]-queue[i-1]));
          j++;s+=abs(queue[i]-queue[i-1]);
        }
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[n-1],queue[z],abs(queue[z]-queue[n-1]));
      s+=abs(queue[z]-queue[n-1]);
      for(i=z-1;i>0;i--)
      {
        printf("The %d-th movement is from track %d to %d with total seek of: %d\n",j+1,queue[i],queue[i-1],abs(queue[i]-queue[i-1]));
        j++;s+=abs(queue[i]-queue[i-1]);
      }
      printf("\nFinal seek amount: %d\n",s);
    }
  else
  {
    int z;
    for(i=0;i<n;i++)
      {
        if(queue[i]>=x)
          {
            z=i;break;
          }
      }
    int j=0;
    if(x!=queue[z])
      {
        printf("The %d-th movement is from track %d to %d, with total seek of: %d \n",++j,x,queue[z-1],abs(queue[z-1]-x));
        s+=abs(queue[z-1]-x);
      }
    for(i=z-1;i>0;i--)
      {
        printf("The %d-th movement is from track %d to %d with total seek of: %d \n",j+1,queue[i],queue[i-1],abs(queue[i]-queue[i-1]));
        j++;s+=abs(queue[i]-queue[i-1]);
      }
    printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[i],queue[z],abs(queue[z]-queue[i]));
    s+=abs(queue[z]-queue[i]);
    for(i=z+1;i<n;i++)
    {
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",j+1,queue[i-1],queue[i],abs(queue[i]-queue[i-1]));
      j++;s+=abs(queue[i]-queue[i-1]);
    }
    printf("\nFinal seek amount: %d\n",s);
  }
  return 0;
}
void sort (int a[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
      {
        if(a[i]>a[j])
          {
            int t =a[i];
            a[i]=a[j];
            a[j]=t;
          }
      }
  }
}
//--------------------------------------------------------------------------------TEST CASES---------------------------------------------------------------------------------------

/*1*/

//----Enter the number of processes:
// 7
//----Enter the starting track of the seek pin:
//12
//----Enter the direction of motion of seek pin:
//+
//----Enter the track position of all the processes:
// 5 100 3 8 14 28 78
//----The 1-th movement is from track 12 to 14, with total seek of: 2
//----The 2-th movement is from track 14 to 28 with total seek of: 14
//----The 3-th movement is from track 28 to 78 with total seek of: 50
//----The 4-th movement is from track 78 to 100 with total seek of: 22
//----The 5-th movement is from track 100 to 14 with total seek of: 86
//----The 6-th movement is from track 8 to 5 with total seek of: 3
//----The 7-th movement is from track 5 to 3 with total seek of: 2

//----Final seek amount: 179

/*2*/

//----Enter the number of processes:
//7
//----Enter the starting track of the seek pin:
//12
//----Enter the direction of motion of seek pin:
//-
//----Enter the track position of all the processes:
//5 100 3 8 14 28 78
//----The 1-th movement is from track 12 to 8, with total seek of: 4
//----The 2-th movement is from track 8 to 5 with total seek of: 3
//----The 3-th movement is from track 5 to 3 with total seek of: 2
//----The 4-th movement is from track 3 to 14 with total seek of: 11
//----The 5-th movement is from track 14 to 28 with total seek of: 14
//----The 6-th movement is from track 28 to 78 with total seek of: 50
//----The 7-th movement is from track 78 to 100 with total seek of: 22

//----Final seek amount: 106
