#include<stdio.h>
#include<malloc.h>
void bubblesort(int*);
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
	
	bubblesort(A);
	for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
void bubblesort(int *A)
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				exchange(A,j,j+1);
			}
		}
	}
}
void exchange(int *A,int a,int b)
{
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}