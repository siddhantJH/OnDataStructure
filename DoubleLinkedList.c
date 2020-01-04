#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
struct node* createNode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
}
void InsertNodeAtFirst()
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter an info\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)
    {
        start=temp;

    }else{
         start->prev=temp;
         temp->next=start;
         start=temp;
    }
}
void InsertNodeAtLast()
{
    struct node *temp,*t,*r;
    temp=createNode();
    printf("Enter an info\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
temp->prev=NULL;
    if(start==NULL)
    {
      start=temp;
      temp->next=NULL;
      temp->prev=NULL;
    }else{
        t=start;
        while(t->next!=NULL){
            t=t->next;
    }
    t->next=temp;
    temp->prev=t;
    temp->next=NULL;
}
}
void InsertNodeAtAnyPos(int pos)
{
    int c=1;
struct node *temp,*r,*t;
temp=createNode();
printf("Enter an info\n ");
scanf("%d",&temp->info);
temp->next=NULL;
temp->prev=NULL;
if(start==NULL)
{
    start=temp;
}else{
t=start;
while(t->next!=NULL)
{
    c++;
    if(c==pos)
        break;
    else
    t=t->next;
}
r=t->next;
t->next=temp;
temp->prev=t;
temp->next=r;
}
}
void traverse()
{
struct node *t;
if(start==NULL)
{
    printf("List is Empty");
}else{
t=start;
while(t->next!=NULL){
    printf("%d ",t->info);
    t=t->next;
}
}
}
int menu()
{
    int ch;
    printf("1: for InsertionAtFirst\n");
    printf("2: for InsertionAtLast\n");
    printf("3: for Traverse\n");
    printf("4: for InsertionAtAnyPosition");
  //  printf("5: DeleteFromEnd\n");*/

    printf("\nEnter Your choice");
    scanf("%d",&ch);
    return ch;
}
void main()
{
int p;
    while(1)
    {
        system("CLS");
        switch(menu()){
case 1:
    InsertNodeAtFirst();
    break;
case 2:
   InsertNodeAtLast();
   break;
case 3:
   traverse();
   break;
case 4:
    printf("Enter a position\n");
    scanf("%d",&p);
    InsertNodeAtAnyPos(p);
    break;
default:
    printf("Enter correct choice");
    break;
}
getch();
}
}
