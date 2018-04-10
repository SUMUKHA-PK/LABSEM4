#include<stdio.h>
struct file{
  int ID,size;
};
struct queue
{
  int p;
  int q;
};
struct block
{
  int allocated;
  int file;
};
struct file File[1000];
void print(struct block Block[],int n);
int check(struct block Block[], int n,int p);
int main()
{
  int size_disk, size_block,i;
  printf("Enter the size of the disk: ");
  scanf("%d",&size_disk);
  printf("Enter the size of each physical block: ");
  scanf("%d",&size_block);
  int n_blocks = size_disk/size_block;

  struct block Block[n_blocks];
  for(int l=0;l<n_blocks;l++)
  {
    Block[l].allocated=-1;
     Block[l].file=-1;
  }

  struct queue Q[100];
  int c =0,co=0,cou=0;
  while(1)
  {
    printf("What do you want to do? 1. ADD 2. REMOVE 3.EXIT 4.SEARCH\n");
    int x;
    scanf("%d",&x);
    if(x==3)
      break;
    if(x==1)
      {
        int flag=0;
        printf("Enter the ID of the file: ");
        scanf("%d",&File[c].ID);
        printf("Enter the size of the file: ");
        scanf("%d",&File[c].size);
        c++;
        int p = File[c-1].size/size_block;if(p==0)p=1;//printf("%d",p);
        int q = File[c-1].size - p*size_block;//printf("%d",q);
        if(check(Block,n_blocks,p+1))       // Adding larger files to queue
          {
            printf("File moved to queue, remove other files to include this!\n");
            Q[cou].p=p;
            Q[cou].q=q;
            cou++;
          }
        else               // Only if file fits, it can proceed
          {
            int h;
            for(h=co;h<co+p;h++)  //Full blocks
              {
                Block[h].file=File[c-1].ID;
                Block[h].allocated=1;
              }
            co+=p;
            if(q>0)                   //Half blocks if exist
              {
                co++;
                Block[co].allocated=1;
                Block[h].file = File[c-1].ID;
              }
          }
        print(Block,n_blocks);
      }
    if(x==2)
      {
        printf("Enter the ID of the file to be removed: ");
        int ID;
        scanf("%d",&ID);
        for(i=0;i<n_blocks;i++)
          {
            if(Block[i].file==ID)
              {Block[i].file=-1;co--;}
          }
        printf("It has been removed\n");
        printf("Following is the memory space: ");
        print(Block,n_blocks);
      }
  }
}
void print(struct block Block[],int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ",Block[i].file);
  printf("\n");
}
int check(struct block Block[], int n,int p)
{
  int i,c=1,m=0;
  for(i=0;i<n-1;i++)
    {
      if(Block[i].file==-1&&Block[i+1].file==-1)
        {
          c++;
          if(c>m)
            c=m;
        }
      else if(Block[i].file==-1&&Block[i].file!=-1)
        c=0;
    }
  if(m>p)
    return 1;
  else
    return 0;
}
