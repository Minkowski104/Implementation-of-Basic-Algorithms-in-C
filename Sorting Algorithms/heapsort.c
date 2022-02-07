#include<stdio.h>
#include<malloc.h>
int LEFT(int x){
	return (2*x)+1;
}
int RIGHT(int x){
	return (2*x)+2;
}
void maxHeapify(int*,int,int);
void buildHeap(int*,int);
void heapsort(int*);
void exchange(int*,int,int);
int N;
int main()
{
	int i,*A;
	scanf("%d",&N);
	A= (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&(A[i]));
	}
/*	
	buildHeap(A,N);
	printf("\n");
for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
*/	
	
	heapsort(A);
	for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
void heapsort(int *A)
{
	int heap_size;
	buildHeap(A,N);
	for(heap_size=N;heap_size>=1;  )
	{
		exchange(A,0,heap_size-1);
		heap_size--;
		maxHeapify(A,0,heap_size);
	}
}
void buildHeap(int *A,int heap_size)
{
	int j;
	for(j=(heap_size/2);j>=0;j--)
	{
		maxHeapify(A,j,N);
	}
}
void maxHeapify(int *A,int i,int heap_size)
{
	int largest,l,r;
	l=LEFT(i);
	r=RIGHT(i);
	largest =i;
	if((r<heap_size)&&(A[r]>A[largest]))
	{
		largest = r;
	}
	if((l<heap_size)&&(A[l]>A[largest]))
	{
		largest=l;
	}
	exchange(A,i,largest);
	if(largest!=i)
	{maxHeapify(A,largest,heap_size);}
}
void exchange(int *A,int a,int b)
{
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}