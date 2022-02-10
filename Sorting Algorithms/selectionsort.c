#include<stdio.h>
#include<malloc.h>
void selectionsort(int*);
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
	
	selectionsort(A);
	for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
void selectionsort(int *A)
{
	int i,j,smallest,pos;
	for(i=0;i<N-1;i++)
	{
		smallest=A[i];
		pos=i;
		for(j=i;j<N;j++)
		{
			if(A[j]<smallest)
			{
				smallest=A[j];
				pos=j;
			}
		}
		exchange(A,i,pos);
	}
}
void exchange(int *A,int a,int b)
{
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}