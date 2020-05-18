#include <stdio.h>
#include <stdlib.h>


void main()
{
int i;
int jp[7]={35,45,25,20,15,12,5};
int jd[7]={3,5,4,2,3,1,2};
int constraint=max(jd,7);
int slot[constraint];
for(i=0;i<constraint;i++)//filling every slot with empty sign as zero
    slot[i]=0;              //Algorithm(a,n){
for(i=0;i<7;i++)          //for(i=1 to n)do
{
    int x=jp[i];            //x=select[a];
    if(jd[i]<=constraint)      //if(feasible[x])then
        {                          //{
            if(slot[jd[i]-1]==0){    // solution=solution+x;
             slot[jd[i]-1]=x;    //}
            }else{              //}
    int j;
 for(j=constraint-1;j>=0;j--)
 {
    if(slot[j]!=0)
    continue;
    else
    break;
 }
 slot[j]=x;
}
}
if(slot[0]!=0)
    break;
}
printArray(slot,constraint);
}
void printArray(int a[],int constraint)
{
    int i;
        int maxProfit=0;
    for(i=0;i<constraint;i++){
        printf("%d ",a[i]);
        maxProfit+=a[i];
}
printf("\nMaximum profit you can have for %d hours is %d",constraint,maxProfit);
}
int max(int a[],int n)
{
    int i;
    int max=0;
    for(i=0;i<n;i++){
    if(a[i]>max)
        max=a[i];
    }
    return max;
}
