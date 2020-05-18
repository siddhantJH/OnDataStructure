#include <stdio.h>
#include <stdlib.h>
void FracKnapsack(double value[],double weight[]);
void main()
{
int i;
double value[]={60,100,120};
double weight[]={10,20,30};
FracKnapsack(value,weight);
}
void FracKnapsack(double value[],double weight[])
{
    double currentweight=0;
    double resultvalue=0;
    double VbyW[3];
    int i,round,j;
    for(i=0;i<3;i++)
    VbyW[i]=value[i]/weight[i];
    for(round=1;round<=2;round++){
        for(j=0;j<2;j++)
        {
            if(value[j]/weight[j]<value[j+1]/weight[j+1])
            {
    swap(&weight[j],&weight[j+1]);
    swap(&value[j],&value[j+1]);
            }
        }

}
        printArray(value);
        printf("\n");
        printArray(weight);
        printf("\n");
for(i=0;i<3;i++)
{
   if(currentweight+weight[i]<=50)
   {
    currentweight=currentweight+weight[i];
    resultvalue=resultvalue+value[i];
   }else
   {
    double remain=50-currentweight;
    resultvalue+=(remain/weight[i])*value[i];

   }
}
printf("%lf ",resultvalue);
}
void printArray(double VbyW[])
{
    int i;
    for(i=0;i<3;i++)
        printf("%lf ",VbyW[i]);
}
void swap(double *a,double *b)
{
    double temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
