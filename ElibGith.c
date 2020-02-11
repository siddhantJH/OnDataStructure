
#include <stdio.h>

#include <stdlib.h>





struct ListNode

{

    int VertexNo;

    struct ListNode *next;

};

struct Graph

{

    int V;

    int E;

    struct ListNode *Adj;

};

struct Graph * AdjListOfGraph()
{
    int i,x,y;
    struct Graph* G;
    struct ListNode *temp,*t,*l;
    G=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter the no of Vertex and Edges");
    scanf("%d %d",&G->V,&G->E);
    G->Adj=(struct ListNode*)malloc(sizeof(struct ListNode)*G->V);
    for(i=0;i<G->V;i++)
    {
        G->Adj[i].VertexNo=i;
        G->Adj[i].next=G->Adj+i;
    }
    for(i=0;i<G->E;i++)
    {
        printf("Enter the source and destination");
        scanf("%d %d",&x,&y);
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->VertexNo=y;
        temp->next=G->Adj+x;
        t=G->Adj+x;
        while(t->next!=G->Adj+x)
        {
            t=t->next;
        }
        t->next=temp;
    }
    for(i=0;i<G->V;i++)
    {
    t=G->Adj+i;
    printf("%d -->",t->VertexNo);
    while(t->next!=G->Adj+i)
    {
        t=t->next;
        printf("%d ",t->VertexNo);
    }
    printf("\n");
}
}
/*void printList(struct Graph *G)
{
    int i;
    struct ListNode *t;
    for(i=0;i<G->V;i++)
    {
        t=G->Adj+i;
        printf("%d",i);
        while(t->next!=G->Adj+i)
        {
            printf("%d ",t->VertexNo);
            t=t->next;
        }
    }
}*/
int menu()
{
    int ch;
    printf("1: for add edges to graph \n");
    printf("2: for printGraph\n");
    printf("\nEnter Your choice");
    scanf("%d",&ch);
    return ch;
}
void main()
{
    struct Graph *g;
int p;
    while(1)

    {
        system("CLS");
        switch(menu()){
case 1:
    g=AdjListOfGraph();
    break;
default:
    printf("Enter correct choice");
    break;
}
getch();
}
}



