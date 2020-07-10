#include <stdio.h>
#include <stdlib.h>

//Structure of List type
struct node
{
    int VertexNo;
    struct node *next;
};

//Structure of Graph type
struct Graph
{
    int V;
    int E;
    struct node **arr;
};

struct Graph *G;

//creating a new link for a vertex
struct node* CreateNode(int item)
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
p->VertexNo=item;
p->next=NULL;
return p;
}

struct node** CreateVertexArray(struct Graph *G)
{
int i;
struct node **p;
p=malloc(sizeof(struct node*)*G->V+1);
for(i=0;i<G->V;i++)
    p[i]=NULL;
return p;
};

void main()
{
    int i,start,end;
     G=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter no of Vertex and Edges:\n");
    scanf("%d %d",&G->V,&G->E);
    G->arr=CreateVertexArray(G);
    for(i=0;i<G->E;i++)
    {
        scanf("%d %d",&start,&end);
        struct node *t;
        if(G->arr[start]==NULL)
        {
            G->arr[start]=CreateNode(start);
        }
        t=G->arr[start];
      while(t->next!=NULL)
      {
          t=t->next;
      }
      t->next=CreateNode(end);
    }
    printStartAndEnd(G);
}

void printStartAndEnd(struct Graph *G)
{
    int i,j;
    for(i=0;i<G->V+1;i++)
    {
        struct node *t;
        t=G->arr[i];
        while(t!=NULL)
        {
          printf("%d",t->VertexNo);
          printf("-->");
          t=t->next;
        }
        if(G->arr[i]!=NULL)
            printf("NULL");
        printf("\n");
    }
}
