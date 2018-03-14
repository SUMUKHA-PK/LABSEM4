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
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,size,queue[z],abs(size-queue[z]));
      s+=abs(queue[z]-size);
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
      printf("The %d-th movement is from track %d to %d with total seek of: %d\n",++j,queue[i],queue[z],abs(queue[z]-queue[i]));
      s+=abs(queue[z]-queue[i]);
      for(i=z+1;i<n;i++)
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
//30
//----Enter the direction of motion of seek pin:
//+
//----Enter the end of the tracks(cylinder size):
//180
//----Enter the track position of all the requests:
//56 13 2 10 89 40 33 100
//----The 1-th movement is from track 30 to 33, with total seek of: 3
//----The 2-th movement is from track 33 to 40 with total seek of: 7
//----The 3-th movement is from track 40 to 56 with total seek of: 16
//----The 4-th movement is from track 56 to 89 with total seek of: 33
//----The 5-th movement is from track 89 to 100 with total seek of: 11
//----The 6-th movement is from track 100 to 180 with total seek of: 80
//----The 7-th movement is from track 180 to 33 with total seek of: 147
//----The 8-th movement is from track 13 to 10 with total seek of: 3
//----The 9-th movement is from track 10 to 2 with total seek of: 8
//----The 10-th movement is from track 2 to 0 with total seek of: 2

//----Final seek amount: 310

/*2*/

//----Enter the number of requests:
//8
//----Enter the starting track of the seek pin:
//30
//----Enter the direction of motion of seek pin:
//-
//----Enter the end of the tracks(cylinder size):
//180
//----Enter the track position of all the requests:
//56 12 2 10 89 40 33 100
//----The 1-th movement is from track 30 to 12, with total seek of: 18
//----The 2-th movement is from track 12 to 10 with total seek of: 2
//----The 3-th movement is from track 10 to 2 with total seek of: 8
//----The 4-th movement is from track 2 to 0 with total seek of: 2
//----The 5-th movement is from track 2 to 33 with total seek of: 31
//----The 6-th movement is from track 33 to 40 with total seek of: 7
//----The 7-th movement is from track 40 to 56 with total seek of: 16
//----The 8-th movement is from track 56 to 89 with total seek of: 33
//----The 9-th movement is from track 89 to 100 with total seek of: 11
//----The 10-th movement is from track 100 to 180 with total seek of: 80

//----Final seek amount: 208
