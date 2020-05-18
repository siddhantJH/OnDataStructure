#include <stdio.h>
#include <stdlib.h>


void main()
{
int i,j;
int jp[5]={20,15,10,5,1};//we must arrange it in decreasing number of profit
int jd[5]={2,2,1,3,3};
int constraint=max(jd,5);
int slot[constraint];
for(i=0;i<constraint;i++)
slot[i]=0;
for(j=0;j<5;j++){
    int x=jp[j];
    if(slot[jd[j]-1]==0)
    {
    slot[jd[j]-1]=x;
    }else{
    for(i=jd[j]-1;i>=0;i--)
    {
        if(slot[i]!=0)
            continue;
        else{
            slot[i]=x;//we must apply break to it or else in the next iteration it will be true and x will get stored again
            break;
    }
    }
    }
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

