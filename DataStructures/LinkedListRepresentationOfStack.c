#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *next;
};
struct node *head=NULL;
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
}
void push(int item)
{
struct node *p=(struct node*)malloc(sizeof(struct node));
if(p==NULL){
return;
}
p->i=item;
p->next=NULL;
p->next=head;
head=p;
}
int pop()
{
int item;
struct node *temp;
if(head==NULL){
printf("UnderFlow");
return -1;
}
else{
item=head->i;
temp=head;
head=head->next;
free(temp);
return item;
}
}
