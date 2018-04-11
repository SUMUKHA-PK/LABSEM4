#include <stdio.h>
#include <stdlib.h>

struct files
{
	int name;
	int size;
	int start;
	int end;
	int present;
};

struct block
{
	int free;
	int next;
};

struct files FILES[100];

struct block FREE_BLOCKS[100];

int LAST=-1, no_free=0;

void add( int no_files, int no_blocks, int block_size)
{
	int count=0, blocks_required=0,initial=0,final=0;

	for (int i = 0; i < no_files; ++i)
	{
		if(FILES[i].present == 0)
		{
			if(FILES[i].size % block_size == 0)
			{
				blocks_required = FILES[i].size / block_size;
			}
			else
			{
				blocks_required = FILES[i].size / block_size + 1;
			}
			if(no_free >= blocks_required)
			{
				int k=-1;
				FILES[i].present = 1;
				for (int h = 0; h < no_blocks; ++h)
				{
					if(FREE_BLOCKS[h].free == 0)
					{
					    if(blocks_required==0){
					    	FILES[i].end = k;
					    	//printf("%d-----\n", k);
					    	break;
					    }
					    FREE_BLOCKS[h].free = 1;
					    if(k==-1)
					    {
					    	FILES[i].start = h;
					    }
					    else
					    {
					    	FREE_BLOCKS[k].next = h;
					    }
					    k=h;
					    //printf("%d-----\n", k);
						blocks_required--;
						no_free--;
					}
				}
				if(blocks_required==0){
					    	FILES[i].end = k;
					    	//printf("%d-----\n", k);

					    }

			}

		}
	}
}
void delete(int file, int no_files, int no_blocks, int block_size)
{
	int blocks_required;
	if(FILES[file].size % block_size == 0)
		blocks_required = FILES[file].size / block_size;
	else
		blocks_required = FILES[file].size / block_size + 1;
	if(FILES[file].present == 1)
	{
		FILES[file].present = -1;
		int i;

		for ( i = FILES[file].start; i != FILES[file].end; )
		{
			FREE_BLOCKS[i].free = 0;
			no_free++;
			i = FREE_BLOCKS[i].next;
		}
		no_free++;
		FREE_BLOCKS[i].free = 0;
	}
}
int main(int argc, char const *argv[])
{
	printf("Enter the total capacity of disk\n");
	int total_capacity;
	scanf("%d",&total_capacity);
	printf("Enter the size opf each block\n");
	int block_size;
	scanf("%d",&block_size);
	int no_blocks = total_capacity/block_size;
	for (int i = 0; i < no_blocks; ++i)
		FREE_BLOCKS[i].free = 0;
	no_free=no_blocks;
	printf("--%d--\n",no_free );
	printf("Enter the choice\n1 Add 2.Remove 3.Stop\n");
	int ch;
	scanf("%d",&ch);

	int no_files,j=0,count=0,no_remove,remove;

	while(ch!=3)
	{
		switch(ch)
		{
			case 1: printf("Enter the number of files\n");
					scanf("%d",&no_files);

					printf("Enter the size of the files\n");

					for (int i = 0; i < no_files; ++i)
					{
						scanf(" %d",&FILES[j].size);
						FILES[j].present = 0;
						j++;
					}

					add(j,no_blocks, block_size);

					for (int i = 0; i < j; ++i)
					{
						int blocks_required;
						if(FILES[i].size % block_size == 0)
						{
							blocks_required = FILES[i].size / block_size;
						}
						else
						{
							blocks_required = FILES[i].size / block_size + 1;
						}
						int h=0;
						if(FILES[i].present == 1){
							int k;
							printf("The file  %d of size %d cannot be allocated",i,FILES[i].size );
							for ( k = FILES[i].start; k != FILES[i].end;)
							{
								printf(" %d", k);
								k = FREE_BLOCKS[k].next;
							}
							printf(" %d", k);
							printf("\n");
						}
						if(FILES[i].present == 0)
							printf("The file  %d of size %d cannot be allocated",i,FILES[i].size );
					}
					break;
			case 2: printf("Enter the no files to remove\n");
					scanf("%d",&no_remove);

					printf("Enter files to delete\n");

					for (int i = 0; i < no_remove; ++i)
					{
						scanf("%d",&remove);
						delete(remove,j,no_blocks, block_size);
					}

					add(j,no_blocks, block_size);

					for (int i = 0; i < j; ++i)
					{
						int blocks_required;
						if(FILES[i].size % block_size == 0)
						{
							blocks_required = FILES[i].size / block_size;
						}
						else
						{
							blocks_required = FILES[i].size / block_size + 1;
						}

						if(FILES[i].present == 1){
							int k;
							printf("The file  %d of size %d cannot be allocated",i,FILES[i].size );
							for ( k = FILES[i].start; k != FILES[i].end;)
							{
								printf(" %d", k);
								k = FREE_BLOCKS[k].next;
							}
							printf(" %d", k);
							printf("\n");
						}
						if(FILES[i].present == 0)
							printf("The file %d of size %d cannot be allocated\n",i,FILES[i].size );
					}

			        break;

		}
		printf("Enter the choice\n1 Add 2.Remove 3.Stop\n");
		scanf("%d",&ch);
	}
	return 0;
}
