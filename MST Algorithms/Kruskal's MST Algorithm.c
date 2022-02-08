#include<stdio.h>
#include<stdlib.h>
typedef struct VERTEX{
	int id;
	struct VERTEX *next;
	struct VERTEX *head;
}Vertex;
typedef struct EDGE{
	float weight;
	Vertex *u,*v;
} Edge;
float adj[][4]={{0,13,11,1},{13,0,2,2},{11,2,0,4},{1,2,4,0}};
int no_edges=0,n=4;
Edge* getEdgeList();
void sortEdges(Edge*);
Vertex* findSet(Vertex*);
void unionSet(Vertex*,Vertex*);
Vertex* makeSet(int);

int main()
{
	int i=0,c=0;
	Edge *edges,*MST;
	MST=(Edge*)malloc((n-1)*sizeof(Edge));
	printf("%d",2);
	edges=getEdgeList();
	sortEdges(edges);
	for(i=0;i<no_edges;i++)
	{
	if((findSet(edges[i].u)->id)!=(findSet(edges[i].v)->id))
	{
		MST[c]=edges[i];
		c++;
		unionSet(edges[i].u,edges[i].v);
	}
	}
	for(i=0;i<c;i++)
	{
		printf("%f (%d,%d)\n",MST[i].weight,MST[i].u->id,MST[i].v->id);
	}
}
Edge* getEdgeList()
{
	int i,j,k;
	Vertex **vertices;
	Edge *edges;
	vertices=(Vertex**)malloc(n*sizeof(Vertex*));
	
	for(i=0;i<n;i++)
	{
		vertices[i]=makeSet(i);
		for(j=i;j<n;j++)
		{
			if(adj[i][j]>0)
			{
			no_edges++;
			}
		}
	}
	
	k=0;
	edges=(Edge*)malloc(no_edges*sizeof(Edge));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adj[i][j]>0)
			{
			edges[k].weight=adj[i][j];
			edges[k].u=vertices[i];
			edges[k].v=vertices[j];
			k++;
			}
		}
	}
	return edges;
}
void sortEdges(Edge* edges)
{
	int i,j;
	Edge temp;
	for(i=0;i<no_edges;i++)
	{
		for(j=0;j<no_edges-1;j++)
		{
			if(edges[j].weight>edges[j+1].weight)
			{
				temp=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=temp;
			}
		}

	}
}
Vertex* makeSet(int i)
{
	Vertex *v=(Vertex*)malloc(n*sizeof(Vertex));
	if(v!=NULL)
		{v->next=NULL;
		v->id=i;
		v->head=v;
		return v;}
	else
		printf("Error");
		exit;
}
Vertex* findSet(Vertex *v)
{
	return v->head;
}
void unionSet(Vertex *u,Vertex *v)
{
	Vertex *ptr=NULL;

	ptr=u;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=v->head;

	ptr=ptr->next;

	while(ptr!=NULL)
	{
		ptr->head=u->head;
		ptr=ptr->next;
		
	}
