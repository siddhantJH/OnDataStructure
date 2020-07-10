#include <stdio.h>
#include <stdlib.h>


struct Graph
{
    int V;
    int E;
    int **arr;
};
struct Graph *G;
void main()
{
int i,start,end,j;
G=(struct Graph*)malloc(sizeof(struct Graph));
if(G){
    printf("Space available\n");
}else{
    printf("Space not available\n");
    return;
}
//Entering values of vertex and edge
printf("Enter the no of Vertex and Edges:\n");
scanf("%d %d",&G->V,&G->E);

//initializing with array of pointers
G->arr=(int **)malloc(sizeof(int*)*G->V);

//initializing each pointer with array of integer
for(i=0;i<G->V;i++)
    G->arr[i]=(int*)malloc(sizeof(int)*G->V);

//Initializing array to zero
for(i=0;i<G->V;i++){
for(j=0;j<G->V;j++){
G->arr[i][j]=0;
}
}




//Enter the value of start and end
printf("Enter the Edges start and end:\n");
for(i=0;i<G->E;i++)
{
scanf("%d %d",&start,&end);
G->arr[start][end]=1;
G->arr[end][start]=1;
}

//print the value of in matrix form
for(i=0;i<G->V;i++){
for(j=0;j<G->V;j++){
    printf("%d ",G->arr[i][j]);
}
printf("\n");
}
printf("\n");
printf("BFS pattern is:\n");
BFS();
}






//perform BFS in the above graph
int Visited[5]={0,0,0,0,0};
int u;
void BFS()
{
//change source from here.
printf("Enter the source:\n");
scanf("%d",&u);
Visited[u]=1;
printf("%d ",u);
int i;
while(1)
{
for(i=0;i<G->V;i++)
{
    if(G->arr[u][i]==1){
    if(Visited[i]==0)
    {
     Enqueue(i);
     Visited[i]=1;
     printf("%d ",i);
    }
}
}
if(isQueueEmpty())
{
    return;
}else{
    u=Dequeue();
}
}
}







//for queue Functionality
int Queue[4],front,rear;
void Enqueue(int item)
{
rear=(rear+1)%G->V;
if(rear==front)
{
    printf("Queue is Full");
    if(rear==0)
        rear=G->V-1;
    else
        rear=rear-1;
return;
}else{
Queue[rear]=item;
return;
}
}

int Dequeue()
{
    if(front==rear)
    {
        printf("Queue is empty");
        return -1;
    }else{
    int item;
    front=(front+1)%G->V;
    item=Queue[front];
    return item;
    }
}

isQueueEmpty()
{
if(front!=rear)
    return 0;
else
    return 1;
}
