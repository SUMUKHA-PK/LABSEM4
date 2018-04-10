//FIFO page replacement
#include<stdio.h>
void print(int page[], int n);
int getslot(int page[], int n,int sl);
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
			printf("The page table after this request: ");
			int x = getslot(page,n,sl);
			page[x]=requests[i];
			print(page,n);
			sl=x;
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

int getslot(int page[], int n,int sl)
{
	return (sl+1)%n;
}


/*

----------------------------------------------------------------TEST CASES----------------------------------------------

Enter the size of the page table: 4
Enter the number of page requests: 10
Enter the requests: 8 4 10 5 3 6 1 7 2 4 
The page table after this request: | 8 |  |  |  |
The page table after this request: | 8 | 4 |  |  |
The page table after this request: | 8 | 4 | 10 |  |
The page table after this request: | 8 | 4 | 10 | 5 |
The page table after this request: | 3 | 4 | 10 | 5 |
The page table after this request: | 3 | 6 | 10 | 5 |
The page table after this request: | 3 | 6 | 1 | 5 |
The page table after this request: | 3 | 6 | 1 | 7 |
The page table after this request: | 2 | 6 | 1 | 7 |
The page table after this request: | 2 | 4 | 1 | 7 |


*/