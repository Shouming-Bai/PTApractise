#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RADIUS 7.5

typedef struct __coordinate{
	int x, y;
} Coordinate;

typedef struct __graph{
	int Nv;
	int **edge;
	Coordinate *site;
} Graph;

Graph* CreateGraph( int Nv );
void InitGraph( Graph *g, int D );
int Escape( Graph *g );
double absolute( double a );
int DFS( Graph *g, int src, int dest );
void Destroy( Graph *g );

int main()
{
	int N, D;
	scanf("%d %d", &N, &D );
	Graph* graph = CreateGraph( N + 2 );
	
	InitGraph( graph, D );
	
	int success = Escape( graph );
	if( success ){
		printf("Yes");
	}else{
		printf("No");
	}
	
	Destroy( graph );
	return 0;
}

Graph* CreateGraph( Nv ){
	Graph *g = (Graph*) malloc( sizeof(Graph) );
	g->Nv = Nv;
	//initiate edge:
	g->edge = (int**) malloc( sizeof(int*) * Nv );
	int i, j;
	for( i=0; i<Nv; i++ ){
		g->edge[i] = (int*) malloc( sizeof(int) * Nv );
	}
	for( i=0; i<Nv; i++ ){
		for( j=0; j<Nv; j++ ){
			g->edge[i][j] = 0;
		}
	}
	//initiate site;
	g->site = (Coordinate*) malloc( sizeof(Coordinate) * Nv );
	
	return g;
}

void InitGraph( Graph *g, int D ){
	//difine edge[1][] as source, edge[0][] as destination;
	int x, y;
	int i, j;
	int dist;
	for( i=2; i<g->Nv; i++ ){
		scanf("%d %d", &x, &y );
		g->site[i].x = x;
		g->site[i].y = y;
		// let's see if it's connected to the origin:
		if( sqrt( x*x + y*y ) - RADIUS <= D ){
			g->edge[1][i] = 1;
			g->edge[i][1] = 1;
		}
		// let's see if it's connected to the bank:
		if( absolute( x - 50) <=D 
			|| absolute( x + 50) <=D
			|| absolute( y - 50) <=D
			|| absolute( y + 50) <=D ){
			g->edge[0][i] = 1;
			g->edge[i][0] = 1;
		}
		// let's see if it's connected to orther vertex:
		for( j=2; j<i; j++ ){
			dist = sqrt( pow(g->site[j].x - x, 2) + pow(g->site[j].y - y, 2) );
			if( dist <= D ){
				g->edge[j][i] = 1;
				g->edge[i][j] = 1;
			}
		}
	}
}

int visited[102];

int Escape( Graph *g ){
	int i;
	for( i=0; i<g->Nv; i++ ){
		visited[i] = 0;
	}
	for( i=2; i<g->Nv; i++ ){
		if( DFS( g, 1, 0) )
			return 1;
	}
	return 0;
}

int DFS( Graph *g, int src, int dest ){
	int i;
	if( g->edge[src][dest] == 1 )
		return 1;
	for( i=0; i<g->Nv; i++ ){
		if( g->edge[src][i] == 1 && visited[i]==0 ){
			visited[i] = 1;
			if( DFS( g, i, dest ) )
				return 1;
		}
	}
	return 0;
}

void Destroy( Graph *g ){
	int i;
	for( i=0; i<g->Nv; i++ ){
		free( g->edge[i] );
	}
	free( g->edge );
	free( g->site );
	free( g );
}

double absolute( double a ){
	if( a < 0 )
		a = -a;
	return a;
}
