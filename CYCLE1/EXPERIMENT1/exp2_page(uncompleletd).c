#include<stdio.h>
#include<stdlib.h>

int main()
{
       int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
       int p[10], fno[10][20];



       printf("\nEnter the memory size -- ");
       scanf("%d",&ms);

       printf("\nEnter the page size -- ");
       scanf("%d",&ps);

       nop = ms/ps;
       printf("\nThe no. of pages available in memory are -- %d ",nop);

       printf("\nEnter number of processes -- ");
       scanf("%d",&np);
       rempages = nop;
    for(i=1;i<=np;i++)
    {

          printf("\nEnter no. of pages required for p[%d]-- ",i);
          scanf("%d",&p[i]);

          if(p[i] >rempages)
          {
              printf("\nMemory is Full");
              break;
          }
          rempages = rempages - p[i];

          printf("\nEnter frame for p[%d] --- ",i);
              for(j=0;j<p[i];j++)
                 scanf("%d",&fno[i][j]);
    }

      
}
