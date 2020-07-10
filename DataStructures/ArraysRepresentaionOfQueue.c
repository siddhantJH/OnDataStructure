#include <stdio.h>

int Queue[5];
int front=0;
int rear=0;
int n=5;
void main()
{
Enqueue(10);
Enqueue(20);
printf("%d\n",Dequeue());
printf("%d\n",Dequeue());
printf("%d\n",Dequeue());
}
void Enqueue(int item)
{
rear=(rear+1)%n;
if(rear==front)
{
 printf("Queue if Full");
 if(rear==0)
 {
    rear=n-1;
 }else
 {
    rear=rear-1;
 }
}
else
    Queue[rear]=item;
    return;
}
int Dequeue()
{
int item;
if(rear==front)
{
printf("Queue is Empty");
return -1;
}
else
{
    front=(front+1)%n;
    item=Queue[front];
    return item;
}
}
