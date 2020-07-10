#include <stdio.h>
#include <stdlib.h>

struct node   // self referencing node type
{
int i;
struct node *next;
};
struct node *head=NULL;
struct node* createNode()  //creating a node and storing a value to it
{
    int n;
    struct node *p;
    printf("Enter data\n");
    scanf("%d",&n);
    p=(struct node *)malloc(sizeof(struct node));
    p->i=n;
    p->next=NULL;
    return p;
}
void InsertNodeAtEnd()    //inserting a node at a particular position
{
    struct node *t,*p;
    p=createNode();
    if(head!=NULL)
    {
    t=head;
    while(t->next!=NULL)
    {
     t=t->next;
    }
    t->next=p;
    }
    else
    {
     head=p;
    }
}
void InsertNodeAtMiddle()
{
int n;
struct node *p,*t;
printf("Enter a value after which you want to enter\n");
scanf("%d",&n);
p=createNode();
if(head==NULL)
{
head=p;
}
else
{
t=head;
while(t->i!=n)
{
    t=t->next;
}
p->next=t->next;
t->next=p;
}
}
void InsertAtBegin() //don,t use unnecessary pointers;
{
    struct node *p;
    p=createNode();
    if(head==NULL)
    {
        head=p;
    }else{
      p->next=head;
      head=p;
    }
}
void DeleteFromBegin()
{
    struct node *p;
    if(head==NULL)
       {
        printf("The List is empty");
       }
       else
       {
       p=head;
       head=head->next;
       free(p);
       }
}
void DeleteFromEnd()
{
struct node *t,*p;
if(head==NULL)
{
printf("List is Empty");
}
else
{
t=head;
while(t->next->next!=NULL)
{
t=t->next;
}
free(t->next);
t->next=NULL;
}
}
void DeletFromMiddle()
{
int n;
struct node *t,*t1;
if(head==NULL)
{
    printf("List is empty\n");
}else{
    printf("Enter a node you want to delete");
    scanf("%d",&n);
    t=head;
    while(t->next->i!=n)
    {
     t=t->next;
    }
    t1=t->next;
    t->next=t->next->next;
    free(t1);
}
}
void Traverse()
{
    struct node *t;
    if(head==NULL){
    printf("The list is empty");
    }else{
    t=head;
    while(t!=NULL)
    {
    printf("%d ",t->i);
    t=t->next;
    }
    }
}
void TraverseInReverse(struct node *re)
{
if(re)
{
TraverseInReverse(re->next);
printf("%d ",re->i);
}
}
void TraverseInForward(struct node *re)
{
    if(re)
    {
     printf("%d ",re->i);
     TraverseInForward(re->next);
    }
}
void ReverseLinkedListUsingIteration(struct node *curr)
{
    struct node *prev=NULL,*next=NULL;
    if(head==NULL){
        printf("The list is Empty");
    }else{
        while(curr!=NULL)
        {
             next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
        }
        head=prev;
    }
}
void main()
{
char ch;
InsertNodeAtEnd();
InsertNodeAtEnd();
InsertNodeAtEnd();
InsertNodeAtEnd();
Traverse();
printf("\nThe connected nodes in Reverse Order\n");
ReverseLinkedListUsingIteration(head);
Traverse();
}
