#include<stdio.h>

int main()
{
  int i,pn,pt[1000]={0},fn;
  printf("\n Enter no of requests : ");
  scanf("%d",&pn);
  printf("Enter the requests for pages  : ");
  for(i=0;i<pn;i++)
    scanf("%d",&pt[i]);
  printf("\n Enter the no of frames in the page table: ");
  scanf("%d",&fn);
  int fr[fn],ch[fn];
  for(i=0;i<fn;i++)
  {fr[i]=-1; ch[i]=0; }

  int j,flag,ctr=0,hit=0,miss=0;
  for(i=0;i<pn;i++)
  {
    printf("request:  %d \t\n",pt[i]);

    flag=0;
    for(j=0;j<fn;j++)
    {
      if(fr[j]==pt[i])
      { ch[j]=1;
        flag=1;
        break;
      }
    }

    if(flag==0)
    { miss++;

      if(ch[ctr]==0)
      fr[ctr]=pt[i];
      else
      {   for(;ch[ctr]==1;ctr=(ctr+1)%fn)
          ch[ctr]=0;

          fr[ctr]=pt[i];

      }
      ctr=(ctr+1)%fn;
      for(j=0;j<fn;j++)
        printf("| %d ",fr[j]);

    }
    else
    hit++;

    printf("| \n");
  }
  printf("\n Page fault : %d",miss);
  return -1;
}
