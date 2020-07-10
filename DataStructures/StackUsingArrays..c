#include <stdio.h>


int top=-1;
int stack[10];
void main()
{
int  n;
int stack[10];
push(10);
push(9);
push(8);
push(7);
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
printf("%d ",pop());
}
void push(int item)
{
    if(top==9){
        printf("Overflow");
    }
    else
    {
     stack[++top]=item;
    }
}
int pop()
{
int item;
if(top==-1)
{
printf("UnderFlow");
return -1;
}
else
{
    return stack[top--];
}
}
