/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
      l=G->Adj+0;
         while(l->next!=G->Adj+0)
         {
             printf("%d",l->VertexNo);
             l=l->next;
         }
    }
void printList(struct Graph *G)
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
}
int main()
{
    struct Graph *g;
    g=AdjListOfGraph();
    printList(g);
}











