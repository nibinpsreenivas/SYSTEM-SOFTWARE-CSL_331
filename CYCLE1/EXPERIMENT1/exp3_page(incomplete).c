#include<stdio.h>
int main()
{
      int f[20],i,j,k,l,m,p,process[20],ff,rest,psize,frames,yes,re,yyes;
      printf("\nEnter the main memory size");
      scanf("%d",&m);
      printf("\nEnter the page size:");
      scanf("%d",&psize);
      frames=m/psize;
      for(i=0;i<frames;i++)
      {
        f[i]=-1;
      }
      printf("\nThe physical memory is divided into %d number of frames",frames);
      printf("\nEnter number of process");
      scanf("%d",&p);
      printf("\nEnter number of pages required for each process");
          for(i=0;i<p;i++)
	   {
	      printf("\nprocess[%d]",i);
              scanf("%d",&process[i]);
	   }
      
  
 while(1)
 {
     for(i=0;i<frames;)
     {
       for(j=0;j<p;j++)
       {
          for(k=0,l=1;k<process[j];k++)
           {
             x:
             printf("\nENTER THE FRAME NUMBER WHERE PAGE[%d] of process[%d] must be placed(<%d):",l,k,frames);
             scanf("%d",&ff);
             if(ff<10)
             {
             if(f[ff]==-1)
              {
                f[ff]=j;
                i=i+1;
                if(i>=frames)
                {
                  rest=process[j]-k+1;
                  printf("\nmemory FULL %d of process[%d] cannot be allocated ",rest,j);
                  printf("\n Do you wish to remove any process from the frames? yes = 1 no=2");
                  scanf("%d",&yes);
                if(yes == 1)
                {
                
                  while(1)
                  {
                   printf("enter the frame number to be removed");
                   scanf("%d",&re);
                   f[re]=-1;
                   i=i-1;
                   printf("do you want to remove one more frame yes =1 no = 0");
                   scanf("%d",&yyes);
                   if(yyes==1)
                   {
                      goto x;
                   }
                   else
                   break;
                   }
              }
              else 
               break;
            }
            }
            else
              {
                printf("frame %d is already allocated",ff);
               }
               }
               else
               printf("ERROR %d is out of bound of frame",ff);
                
           }
           
       
       }
          
     }
   
  
  }
return 0;
}
