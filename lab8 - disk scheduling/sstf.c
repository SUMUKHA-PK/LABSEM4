#include<stdio.h>
int getshortest(int a[], int b[], int count[], int n);
int main()
{
  int n;
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  int x,i;
  printf("Enter the starting track of the seek pin: ");
  scanf("%d",&x);
  int queue[n],s=0;
  printf("Enter the track position of all the requests: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&queue[i]);
  }
  int b[n],count[n];
  for(i=0;i<n;i++)
  	b[i]=0;
  int j=0;
  int flag=0;
  int test=n;
  int sum = 0;
  while(test--)
  	{
  		if(flag==0)
  			{
  				for(i=0;i<n;i++)
					count[i]=abs(queue[i]-x);
				int z = getshortest(queue,b,count,n);
				printf("The %d-th movement was from %d to %d and the pin moved %d \n",++j,x,queue[z],abs(queue[z]-x));
				sum+=abs(queue[z]-x);
				x=z;
				flag=1;			
  			}
  		else
  			{
  				for(i=0;i<n;i++)
					count[i]=abs(queue[i]-queue[x]);	
  				int z = getshortest(queue,b,count,n);
  				printf("Location: %d",z);
  				printf("The %d-th movement was from %d to %d and the pin moved %d \n",++j,queue[x],queue[z],abs(queue[z]-queue[x]));
  				sum+=abs(queue[z]-queue[x]);
  				x=z;
  			}
  	}
  printf("The total distance moved : %d \n",sum);
  return 0;
}

int getshortest(int a[], int b[], int count[], int n)
{
	int i,j;
	int min = 1e9;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
			{
				if(min>count[i]&& count[i]>0)
				{
					min=count[i];
					j=i;
				}
			}
	}
	b[j]=1;
	return j;
}

/*

----------------------------------------------------TEST CASES-------------------------------------------------------------

Enter the number of requests: 8
Enter the starting track of the seek pin: 53
Enter the track position of all the requests: 98 14 37 122 64 124 67 183
The 1-th movement was from 53 to 64 and the pin moved 11 
Location: 6The 2-th movement was from 64 to 67 and the pin moved 3 
Location: 2The 3-th movement was from 67 to 37 and the pin moved 30 
Location: 1The 4-th movement was from 37 to 14 and the pin moved 23 
Location: 0The 5-th movement was from 14 to 98 and the pin moved 84 
Location: 3The 6-th movement was from 98 to 122 and the pin moved 24 
Location: 5The 7-th movement was from 122 to 124 and the pin moved 2 
Location: 7The 8-th movement was from 124 to 183 and the pin moved 59 
The total distance moved : 236 

*/