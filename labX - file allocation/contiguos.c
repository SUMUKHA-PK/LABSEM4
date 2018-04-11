#include <stdio.h>
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
				blocks_required = FILES[i].size / block_size;
			else
				blocks_required = FILES[i].size / block_size + 1;
			if(LAST!=no_blocks-1)
			{
				if(LAST + blocks_required < no_blocks)
				{
					FILES[i].start = LAST + 1;
					FILES[i].end = LAST + blocks_required;
					LAST = FILES[i].end;
					FILES[i].present = 1;
					for (int j = FILES[i].start; j <= FILES[i].end; ++j)
					{
						FREE_BLOCKS[j].free = 1;
					}
					no_free -= FILES[i].end - FILES[i].start + 1;
				}
			}
			else
			{
				for (int i = 0; i < no_blocks; ++i)
				{
					initial = i;
					while(FREE_BLOCKS[i].free == 0 && FREE_BLOCKS[i+1].free == 0)
					{
						final = i+1;
					}
					if(final - initial + 1 <= blocks_required)
					{
						FILES[i].start = initial;
						FILES[i].end = initial + blocks_required-1;
						FILES[i].present = 1;

						for (int j = FILES[i].start; j <= FILES[i].end; ++j)
						{
							FREE_BLOCKS[j].free = 1;
						}

						no_free -= FILES[i].end - FILES[i].start + 1;
						break;
					}
				}
			}
		}
	}
}
void delete(int file, int no_files, int no_blocks, int block_size)
{
	if(FILES[file].present == 1)
	{
		FILES[file].present = -1;

		for (int i = FILES[file].start; i <= FILES[file].end; ++i)
		{
			FREE_BLOCKS[i].free = 0;
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
	{
		FREE_BLOCKS[i].free = 0;
	}

	no_free=no_blocks;

	printf("Enter the choice\n1 Add 2.Remove 3. Stop\n");
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
						if(FILES[i].present == 1)
							printf("File %d -- Block(s) %d to %d\n",i, FILES[i].start,FILES[i].end );
						if(FILES[i].present == 0)
							printf("File %d -- Cannot be allocated\n",i);
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

					for (int i = 0; i < j; ++i)
					{
						if(FILES[i].present == 1)
							printf("File %d -- Block(s) %d to %d\n",i, FILES[i].start,FILES[i].end );
						if(FILES[i].present == 0)
							printf("File %d Cannot be allocated\n",i);
					}

			        break;

		}
		printf("Enter the choice\n1.Add 2.Remove 3.Stop\n");
		scanf("%d",&ch);
	}
	return 0;
}
