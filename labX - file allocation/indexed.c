#include <stdio.h>
#include <stdlib.h>
struct files
{
	int name;
	int size;
	int start;
	int end;
	int present;
	int index_block;
};
struct block
{
	int free;
	int *index;
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
			if(no_free >= blocks_required + 1)
			{
				int l = 0;
				FILES[i].present = 1;
				for ( l = 0; l < no_blocks; ++l)
				{
					if(FREE_BLOCKS[l].free == 0)
					{
						FREE_BLOCKS[l].free = 1;
						no_free--;
						FREE_BLOCKS[l].index = (int*)malloc(blocks_required*sizeof(int));
						FILES[i].index_block = l;
						break;
					}
				}
				int k=0;
				for (int h = 0; h < no_blocks; ++h)
				{
					if(FREE_BLOCKS[h].free == 0)
					{
						if(blocks_required==0)
							break;
						FREE_BLOCKS[h].free = 1;
						FREE_BLOCKS[l].index[k++] = h;
						blocks_required--;
						no_free--;
					}
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

		FREE_BLOCKS[FILES[file].index_block].free = 0;

		for (int i = 0; i < blocks_required; ++i)
		{
			FREE_BLOCKS[FREE_BLOCKS[FILES[file].index_block].index[i]].free = 0;
			no_free++;
		}
	}
}
int main(int argc, char const *argv[])
{
	printf("Enter the total capacity of disk\n");
	int total_capacity;
	scanf("%d",&total_capacity);
	printf("Enter the size of each block\n");
	int block_size;
	scanf("%d",&block_size);
	int no_blocks = total_capacity/block_size;
	for (int i = 0; i < no_blocks; ++i)
		FREE_BLOCKS[i].free = 0;
	no_free=no_blocks;
	printf("Enter your choice 1. Add  2.Remove 3.Stop\n");
	int ch;
	scanf("%d",&ch);
	int no_files,j=0,count=0,no_remove,remove;
	while(ch!=3)
	{
		switch(ch)
		{
			case 1: printf("Enter the number of files\n");
					scanf("%d",&no_files);
					printf("Enter the file size\n");
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
							blocks_required = FILES[i].size / block_size;
						else
							blocks_required = FILES[i].size / block_size + 1;
						if(FILES[i].present == 1){
							printf("The File %d of size %d is in",i,FILES[i].size );
							for (int k = 0; k < blocks_required; ++k)
							{
								printf(" %d", FREE_BLOCKS[FILES[i].index_block].index[k]);
							}
							printf(" and added to index_block %d\n", FILES[i].index_block);
						}
						if(FILES[i].present == 0)
							printf("File %d --- %d Cannot be allocated\n",i,FILES[i].size );
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
							blocks_required = FILES[i].size / block_size;
						else
							blocks_required = FILES[i].size / block_size + 1;
						if(FILES[i].present == 1){
							printf("The File %d of size %d is in ",i,FILES[i].size );
							for (int k = 0; k < blocks_required; ++k)
							{
								printf(" %d", FREE_BLOCKS[FILES[i].index_block].index[k]);
							}
							printf(" and added to index_block %d\n", FILES[i].index_block);
						}
						if(FILES[i].present == 0)
							printf("File %d --- %d Cannot be allocated\n",i,FILES[i].size );
					}

			        break;
		}
		printf("Enter the choice\n1.Add 2.Remove 3.Stop\n");
		scanf("%d",&ch);
	}
	return 0;
}
