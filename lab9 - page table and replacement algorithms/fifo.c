//FIFO page replacement

#include<stdio.h>
void print(int page[], int n);
int getslot(int page[], int n,int sl,int x);
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
	int sl=-1;
	for(i=0;i<req;i++)
		{
			int x = getslot(page,n,sl,requests[i]);
			if(x!=-1)
			{
				printf("The page table after this request: ");
				page[x]=requests[i];
				print(page,n);
				sl=x;
			}
			else
				{
					printf("Query already exists!\n");
				}
		}
	return 0;
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

int getslot(int page[], int n,int sl,int x)
{
	int i;
	for(i=0;i<n;i++)
		{
			if(x==page[i])
				return -1;
		}
	return (sl+1)%n;
}


/*

----------------------------------------------------------------TEST CASES----------------------------------------------

Enter the size of the page table: 4
Enter the number of page requests: 10
Enter the requests: 1 2 3 1 2 4 2 8 9 4
The page table after this request: | 1 |  |  |  |
The page table after this request: | 1 | 2 |  |  |
The page table after this request: | 1 | 2 | 3 |  |
Query already exists!
Query already exists!
The page table after this request: | 1 | 2 | 3 | 4 |
Query already exists!
The page table after this request: | 8 | 2 | 3 | 4 |
The page table after this request: | 8 | 9 | 3 | 4 |
Query already exists!

*/
