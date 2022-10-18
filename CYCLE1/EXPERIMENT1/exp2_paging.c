#include<stdio.h>
int main()
{
      int page[35],i,n,f,psize,off,pno,d;
      printf("\nEnter the number of  pages in memory");
      scanf("%d",&n);
      printf("\nEnter the page size:");
      scanf("%d",&psize);
      printf("\nEnter number of frames");
      scanf("%d",&f);
      for(i=0;i<n;i++)
	  {
         page[i]=-1;
	  }
      printf("\nEnter the page table\n");
      printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
      printf("\npageno\tframeno\n-------\t-------");
  for(i=0;i<n;i++)
  {
     printf("\n\n%d\t\t",i);
     scanf("%d",&page[i]); 
  }
 while(1)
 {
       printf("\n\nEnter the logical address(i.e,page no & offset):");
       scanf("%d%d",&pno,&off);
         if(page[pno]==-1)
           printf("\n\nThe required page is not present in any of frames");
         else
           printf("\n\nPhysical address(i.e,frame no & offset):%d,%d",page[pno],off);
        printf("\nDo you want to continue 1-yes and 0 -no?:");
        scanf("%d",&d);
   if(d==0)
     break;
  }
return 0;
}