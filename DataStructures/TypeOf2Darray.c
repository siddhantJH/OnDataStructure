#include <stdio.h>



//using single pointer and no malloc call
void main()
{
int n,*p,r,c,i,j;
printf("Enter no of rows and columns:\n");
scanf("%d %d",&r,&c);
p=(int *)malloc(sizeof(int)*r*c);
for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    scanf("%d",(p+i*c+j));
for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    printf("%d ",*(p+i*c+j));
}


//using array of pointers and 1 malloc call
#include <stdio.h>
void main()
{
    int r,c,i,j;
    printf("Enter the rows and column:\n");
    scanf("%d %d",&r,&c);
    int *row[r];
    for(i=0;i<r;i++)
     row[i]=malloc(sizeof(int)*c);
     printf("Enter the values\n");
     for(i=0;i<r;i++)
        for(j=0;j<c;j++)
           scanf("%d",&row[i][j]);
           for(i=0;i<r;i++)
        for(j=0;j<c;j++)
           printf("%d ",row[i][j]);
}

//using double pointer and 2 malloc call
#include <stdio.h>
void main()
{
int **arr,r,c,i,j;
printf("Enter no of rows and column:\n");
scanf("%d %d",&r,&c);

arr=malloc(sizeof(int *)*r);

for(i=0;i<r;i++)
    arr[i]=malloc(sizeof(int)*c);

 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   scanf("%d",(*(arr+i)+j));
  for(i=0;i<r;i++)
   for(j=0;j<c;j++)
    printf("%d ",*(*(arr+i)+j));
}
