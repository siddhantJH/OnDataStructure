#include <stdio.h>
#include <stdlib.h>
/*void createNode();
void InsertAtEnd();
void InsertAtFront();
void InsertAtAnyPoint(int pos);*/
struct node
{
    int info;
    struct node *link;
};
struct node *start=NULL;
struct node* createNode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
}
void InsertAtEnd()
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter an Information\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL){
    start=temp;
    }else{
    t=start;
    while(t->link!=NULL)
        t=t->link;
        t->link=temp;
    }
}
void InsertAtFront()
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter an Information\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }else{
    temp->link=start;
    start=temp;
    }
}
void InsertAtAnyPoint(int pos)
{
    int c=1;
       struct node *temp,*t,*r;
    temp=createNode();
    printf("Enter an Information\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL){
    start=temp;
    }else{
    t=start;
    while(t->link!=NULL){
            c++;
    if(c==pos)
        break;
    else
        t=t->link;
    }
    r=t->link;
        t->link=temp;
        temp->link=r;
    }
}
void deleteNodefromStart()
{
    struct node *temp,*r;
    if(start=NULL)
    {
        printf("List is empty");
    }else{
        r=start;
        start=start->link;
        free(r);
    }
}
void deleteNodefromEnd()
{
    struct node *temp,*r,*t;
    if(start==NULL)
    {
        printf("List is empty");
    }else{
    r=start;
    while(r->link!=NULL){
            temp=r;
        r=r->link;
    }
    t=temp->link;
    temp->link=NULL;
    free(t);
    }
}
void traverse()
{
    struct node *temp,*t;
    if(start==NULL)
    {
        printf("List is Empty");
    }
    t=start;
    while(t->link!=NULL)
    {
        printf("%d ",t->info);
        t=t->link;
    }
}
int menu()
{
    int ch;
    printf("1: for InsertionAtEnd\n");
    printf("2: for InsertionAtFront\n");
    printf("3: for InsertionAtAnyPoint\n");
    printf("4: for ShowInformation\n");
    printf("5: DeleteFromEnd\n");

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
    InsertAtEnd();
    break;
case 2:
    InsertAtFront();
    break;
case 3:
    printf("Enter position\n");
    scanf("%d",&p);
    InsertAtAnyPoint(p);
    break;
case 4:
    traverse();
    break;
case 5:
    deleteNodefromEnd();
    break;

default:
    printf("Enter correct choice");
    break;
}
getch();
}
}
