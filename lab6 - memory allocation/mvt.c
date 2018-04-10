#include<stdio.h>
int main()
{
  int part,i,j,n,size;
  printf("Enter the size of the memory: ");
  scanf("%d",&size);
  int q[size];
  for(i=0;i<size;i++)
    q[i]=-1;
  int t=0;i=0;
  while(1)
    {
      printf("1.Input process 2.Exit and show configuration\n");
      int x;
      scanf("%d",&x);
      if(x==1)
        {
          printf("Enter the size of the %d process: ",i);
          int qp;scanf("%d",&qp);
          if(t+qp<=size)
            {
              for(int ab=t;ab<t+qp;ab++)
                q[ab]=i;
              i++;t+=qp;
            }
          else
            {
              printf("Memory is full! Do you want to remove a process already in memory?\n");
              int zz;printf("1.Yes 2.No\n");scanf("%d",&zz);
              if(zz==1)
                {
                  printf("Enter the process ID and its memory size to remove it: ");
                  int id,mem;
                  scanf("%d%d",&id,&mem);
                  for(j=0;j<size;j++)
                    {
                      if(q[j]==id)
                        {
                          t=j;
                          for(int qw=j;qw<j+mem;qw++)
                            q[qw]=-1;
                          break;
                        }
                    }
                }
            }
        }
      if(x==2)
        {
          printf("The folowing is the memory configuration: ");
          for(int ab=0;ab<size;ab++)
            printf("%d ",q[ab]);
          printf("\n");
        }
    }
  return 0;
}
