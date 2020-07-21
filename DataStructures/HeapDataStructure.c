#include<stdio.h>
#include<stdlib.h>
#include <math.h>

/*Implementation Of Heap Data structure and various operation that we can
on it as Follows: */

//Heap: is a global Pointer which hold an Array of integer.
//Heapify       |   void Max_Heapify(int i,int *Heap);
//Build_heap    |   void Build_Heap()
//InsertKey     |   void Insert_Key(int i,int key)
//Extract_max   |   int Extract_max()
//HeapSort      |   int HeapSort(int n)

//to use a particular function use the function name and specified argument as specified above.
//Follow this Sequence of Operation.
//1)Run.
//2)Enter the elements of heap.
//3)BuildHeap.
//4)Heapsort.
//5)Extract Max.
//6)Insert

/** In order to use a Heapsort and Extract Max the structure must be a max heap*/
/***********HEAP DS USING ARRAY********************/


int Heap_size;
int *Heap,n;
void main()
{
int i;
printf("Enter the size of heap");
scanf("%d",&n);
Heap_size=n;
Heap=(int *)malloc(sizeof(int)*n);
printf("Enter the Elements of tree\n");
for(i=0;i<n;i++)
{
scanf("%d",&Heap[i]);
}
 printf("Elemets after building the heap\n");
 Build_Heap();
 for(i=0;i<n;i++)
 printf("%d ",Heap[i]);
 printf("\nElements after HeapSorting the Array\n");
 HeapSort();
 for(i=0;i<n;i++)
 printf("%d ",Heap[i]);
 printf("\n");
  printf("To use the Other function call with specified function argument:\n");
}

int Parent(int i)
{
if(i>0)
return abs(floor(i-1)/2);
}

int Left(int i)
{
return 2*i+1;
}

int Right(int i)
{
return 2*i+2;
}

/*To swap a root with leaf used by heapsort and Max_Heapify function*/
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}

/*Max heap_fie function for heapfying  the node*/
Max_Heapify(int i,int *Heap)
{
int largest=0;
int l=Left(i);
int r=Right(i);

if(l<=Heap_size-1 && Heap[i]<Heap[l])
    largest=l;
    else
    largest=i;
if(r<=Heap_size-1 && Heap[largest]<Heap[r])
    largest=r;
if(largest!=i){
    swap(&Heap[i],&Heap[largest]);
Max_Heapify(largest,Heap);
}
}

/*for use of insert a new key into a heap
pass index and key as an argument*/
void Insert_Key(int i,int key)
{
Heap_size++;
Heap[i]=key;
while(i>0 && Heap[i/2]<Heap[i]){
swap(&Heap[i],&Heap[i/2]);
i/=2;
}
}

/*For Extracting an element from heap by using swapping
it with rightmost leaf and the applying heap_fie on it*/
int Extract_max()
{
int max=Heap[0];
swap(&Heap[0],&Heap[--Heap_size]);
Max_Heapify(0,Heap);
return max;
}


/*for Performing Heap Sort in a Max heap structure
by Swapping Largest first Element with smallest leaf*/
int HeapSort(int n)
{
     int i;
     for(i=6;i>=1;i--){
     swap(&Heap[0],&Heap[i]);
     Heap_size=Heap_size-1;
     Max_Heapify(0,Heap);
}
}

/*For Converting a Binary Tree into a Max Heap Using
Max_Heap function call from Largest NonLeafNode to Root*/
void Build_Heap()
{
int i;
int n=floor(Heap_size/2)-1;
for(i=n;i>=0;i--)
    Max_Heapify(i,Heap);
}
