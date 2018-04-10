//SCAN ALGORITHM
#include<stdio.h>
void sort (int a[],int n);
int main()
{
  int n;
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  int x,i;
  char p;
  printf("Enter the starting track of the seek pin: ");
  scanf("%d",&x);
  printf("Enter the direction of motion of seek pin: ");
  getchar();scanf("%c",&p);
  int queue[n],s=0;
  printf("Enter the end of the tracks(cylinder size): ");
  int size;
  scanf("%d",&size);
  printf("Enter the track position of all the requests: ");
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
      if(queue[n-1]!=size){printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[n-1],size,abs(size-queue[n-1]));s+=abs(size-queue[n-1]);}
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,size,queue[z-1],abs(size-queue[z-1]));
      s+=abs(queue[z-1]-size);
      for(i=z-1;i>0;i--)
      {
        printf("The %d-th movement is from track %d to %d with total seek of: %d\n",j+1,queue[i],queue[i-1],abs(queue[i]-queue[i-1]));
        j++;s+=abs(queue[i]-queue[i-1]);
      }
      if(queue[0]!=0){printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[0],0,queue[0]);s+=queue[0];}
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
      if(queue[0]!=0){printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[0],0,queue[0]);s+=queue[0];}
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,0,queue[z+1],abs(queue[z+1]));
      s+=abs(queue[z+1]);
      for(i=z+2;i<n;i++)
      {
        printf("The %d-th movement is from track %d to %d with total seek of: %d\n",j+1,queue[i-1],queue[i],abs(queue[i]-queue[i-1]));
        j++;s+=abs(queue[i]-queue[i-1]);
      }
      if(queue[n-1]!=size){printf("The %d-th movement is from track %d to %d with total seek of: %d\n",j+1,queue[n-1],size,abs(size-queue[n-1]));s+=abs(queue[n-1]-size);}
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
//-------------------------------------------------------------------TEST CASES----------------------------------------------------------------

/*1*/

//----Enter the number of requests:
//8
//----Enter the starting track of the seek pin:
//53
//----Enter the direction of motion of seek pin:
//+
//----Enter the end of the tracks(cylinder size):
//199
//----Enter the track position of all the requests:
//98 14 37 122 64 124 67 183
//----The 1-th movement is from track 53 to 64, with total seek of: 11
//----The 2-th movement is from track 64 to 67 with total seek of: 3
//----The 3-th movement is from track 67 to 98 with total seek of: 31
//----The 4-th movement is from track 98 to 122 with total seek of: 24
//----The 5-th movement is from track 122 to 124 with total seek of: 2
//----The 6-th movement is from track 124 to 183 with total seek of: 59
//----The 7-th movement is from track 183 to 199 with total seek of: 16
//----The 8-th movement is from track 199 to 37 with total seek of: 162
//----The 9-th movement is from track 37 to 14 with total seek of: 23
//----The 10-th movement is from track 14 to 0 with total seek of: 14

//----Final seek amount: 345

/*2*/

//----Enter the number of requests:
// 8
//----Enter the starting track of the seek pin:
//53
//----Enter the direction of motion of seek pin:
//-
//----Enter the end of the tracks(cylinder size):
//199
//----Enter the track position of all the requests:
// 98 14 37 122 64 124 67 183
//----The 1-th movement is from track 53 to 37, with total seek of: 16 
//----The 2-th movement is from track 37 to 14 with total seek of: 23
//----The 3-th movement is from track 14 to 0 with total seek of: 14
//----The 4-th movement is from track 0 to 67 with total seek of: 67
//----The 5-th movement is from track 67 to 98 with total seek of: 31
//----The 6-th movement is from track 98 to 122 with total seek of: 24
//----The 7-th movement is from track 122 to 124 with total seek of: 2
//----The 8-th movement is from track 124 to 183 with total seek of: 59
//----The 9-th movement is from track 183 to 199 with total seek of: 16

//----Final seek amount: 252
