#include<stdio.h>
#include<stdlib.h>
void merge(int*,int,int,int,int);
void mergesort(int*,int,int);
int main()
{

	int i,*A,N;
	scanf("%d",&N);
	A= (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&(A[i]));
	}
	mergesort(A,0,N-1);
	for(i=0;i<N;i++)
	{
		printf("%d ",A[i]);
	}
return 0;
}
void mergesort(int *A,int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(A,beg,mid-1);
		mergesort(A,mid,end);
		merge(A,beg,mid-1,mid,end);
	}
}
void merge(int *A,int p,int q,int r,int s)
{
	int *B,*C,b,c,i,j,k;
	b=p-q+1;
	c=r-s+1;
	B=(int*)malloc(b*sizeof(int));
	C=(int*)malloc(c*sizeof(int));
	for(k=p,i=0;k<=q;k++,i++)
	{
		B[i]=A[k];
	}
	for(k=r,j=0;k<=s;k++,j++)
	{
		C[i]=A[k];
	}
	i=0;j=0;k=p;
	while((i<b)&&(j<c))
	{
		if(B[i]<C[j])
		{A[k]=B[i];i++;}
		else
		{A[k]=C[j];j++;}
		k++;
	}
	while(j<c)
		{A[k]=C[j];j++;
		k++;}
		
	while(i<b)
		{A[k]=B[i];i++;
		k++;}
}