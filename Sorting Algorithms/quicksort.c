#include<stdio.h>
#include<stdlib.h>
void quicksort(int*,int,int);
int partition(int*,int,int);
void exchange(int*,int,int);
int main()
{

	int i,*A,N;
	scanf("%d",&N);
	A= (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&(A[i]));
	}
	quicksort(A,0,N-1);
	for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
return 0;
}
void quicksort(int *A,int p,int r)
{
	int q;
	if(p<r)
	{q=partition(A,p,r);
	quicksort(A,p,q-1);
	quicksort(A,q+1,r);
	}
}
int partition(int *A,int p,int r)
{
	int i,j,pivot;
	pivot=A[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(A[j]<pivot)
		{
			i++;
			exchange(A,i,j);
		}
	}
		exchange(A,i+1,r);
		return(i+1);	
}
void exchange(int *A,int a,int b){
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}