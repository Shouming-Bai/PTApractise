#include <stdio.h>
#include <stdlib.h>
#define DISTANCE	6

typedef struct __adjnode *AdjNode;
struct __adjnode{
	int v;
	AdjNode next;
};

typedef struct __graph *Graph;
struct __graph{
	int nv;
	int ne;
	int* flag;
	AdjNode* firstAdj;
};

int queue[10000];
int enter;
int out;

Graph CreateGraph( int N );
void Link( Graph g, int v1, int v2 );
int CountFriends( Graph g, int v );
void ClearFlag( Graph g, int v );
void FreeGraph( Graph g );

int main()
{
	int N, M;
	int v1, v2;
	scanf("%d%d", &N, &M);
	Graph g1 = CreateGraph( N );
	while( M-- ){
		scanf("%d%d", &v1, &v2 );
		Link( g1, v1-1, v2-1 );
	}
	int i, Nf;
	for( i=0; i<N; i++ ){
		Nf = 1 + CountFriends( g1, i );
		printf("%d: %.2f%%\n", i+1, (double)Nf / N * 100 );
	}
	
	FreeGraph( g1 );
	
	return 0;
}



Graph CreateGraph( int N ){
	Graph newGraph = (Graph) malloc( sizeof(struct __graph) );
	newGraph->ne = N;
	newGraph->nv = 0;
	newGraph->flag = (int*) malloc( sizeof(int)*N );
	newGraph->firstAdj = (AdjNode*) malloc( sizeof(AdjNode)*N );
	int i;
	for( i=0; i<N; i++ ){
		newGraph->flag [i] = 0;
		newGraph->firstAdj[i] = NULL;
	}
	return newGraph;
}
void Link( Graph g, int v1, int v2 ){
	AdjNode newNode1 = (AdjNode) malloc( sizeof(struct __adjnode) );
	newNode1->v = v2;
	newNode1->next = g->firstAdj[v1];
	g->firstAdj[v1] = newNode1;
	
	AdjNode newNode2 = (AdjNode) malloc( sizeof(struct __adjnode) );
	newNode2->v = v1;
	newNode2->next = g->firstAdj[v2];
	g->firstAdj[v2] = newNode2;
}

int CountFriends( Graph g, int v ){
	enter = 0;
	out = -1;
	queue[enter] = v;
	g->flag[v] = 1;
//	int friends =0;
	int visiting;
	int qlayer = 0;
	int layer = 0;
	AdjNode p;
	while( out <= qlayer ){
		visiting = queue[++out];
		for( p=g->firstAdj[visiting]; p; p=p->next ){
			if( g->flag[p->v] )
				continue;
			g->flag[p->v] = 1;
//			friends++;
			if( layer<DISTANCE )
				queue[++enter] = p->v;
		}
		if( queue[qlayer] == visiting && layer<DISTANCE ){
			qlayer = enter;
			layer++;
		}
	}
	
	ClearFlag( g, v );
	return qlayer;
}

void ClearFlag( Graph g, int v ){
	enter = 0;
	out = -1;
	queue[enter] = v;
	g->flag[v] = 0;
	AdjNode p;
	int qlayer = 0;
	int layer = 0;
	int visiting;
	while( out <= qlayer ){
		visiting = queue[++out];
		for( p=g->firstAdj[visiting]; p; p=p->next ){
			if( g->flag[p->v] == 0 )
				continue;
			g->flag[p->v] = 0;
			if( layer<DISTANCE )
				queue[++enter] = p->v;
		}
		if( visiting == queue[qlayer] && layer<DISTANCE ){
			qlayer = enter;
			layer++;
		}
	}
}

void FreeGraph( Graph g ){
	AdjNode head, p;
	int i;
	for( i=0; i<g->nv; i++ ){
		for( head=g->firstAdj[i]; head;  ){
			p=head->next;
			head=p->next;
			free(p);
		}
	}
	free(g->firstAdj);
	free(g->flag);
}
