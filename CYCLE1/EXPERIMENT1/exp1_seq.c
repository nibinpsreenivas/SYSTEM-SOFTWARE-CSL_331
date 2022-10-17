#include<stdio.h>
#include<stdlib.h>


int main()
{
  int i,j,n,st,c,k,index,count=0,f[50],ind[50],len;
     for(i=0;i<25;i++)
     {
        f[i]=0;
     }
  while(1)
  {printf("Files Allocated are : \n");
  x: count=0;
  printf("Enter starting block and length of files: ");
scanf("%d%d", &st,&len);
for(k=st;k<(st+len);k++)
if(f[k]==0)
count++;
if(len==count)
{
for(j=st;j<(st+len);j++)
if(f[j]==0)
{
f[j]=1;
printf("%d\t%d\n",j,f[j]);
}
if(j!=(st+len-1))
printf("The file is allocated to disk\n");
}
else
printf("The file is not allocated \n");
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
if(c==0)
{
 break;
 }
 }
}
