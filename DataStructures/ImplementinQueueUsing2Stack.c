#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
void main()
{
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    printf("%d\n",Delete());
    printf("%d\n",Delete());
    printf("%d\n",Delete());
    printf("%d\n",Delete());
    printf("%d\n",Delete());
}



void pushS1(int item)
{
struct node *p=(struct node*)malloc(sizeof(struct node));
if(p==NULL){
return;
}
p->i=item;
p->next=NULL;
p->next=head1;
head1=p;
}



void pushS2(int item)
{
struct node *p=(struct node*)malloc(sizeof(struct node));
if(p==NULL){
return;
}
p->i=item;
p->next=NULL;
p->next=head2;
head2=p;
}


int popS1()
{
int item;
struct node *temp;
if(head1==NULL){
printf("UnderFlow");
return -1;
}
else{
item=head1->i;
temp=head1;
head1=head1->next;
free(temp);
return item;
}
}



int popS2()
{
int item;
struct node *temp;
if(head2==NULL){
printf("UnderFlow");
return -1;
}
else{
item=head2->i;
temp=head2;
head2=head2->next;
free(temp);
return item;
}
}


/***insert**/
void Insert(int item)
{
pushS1(item);
}


int StackisEmptyS1()
{
if(head1==NULL)
return 1;
else
return 0;
}


int StackisEmptyS2()
{
if(head2==NULL)
    return 1;
else
    return 0;
}


/***Delete**/
void Delete()
{
int x;
if(StackisEmptyS2())
{
    if(StackisEmptyS1())
    {
        printf("Queue is Empty");
        return -1;
    }
else
    {
while(!StackisEmptyS1())
{
    x=popS1();
    pushS2(x);
}
}
}
x=popS2();
return x;
}
