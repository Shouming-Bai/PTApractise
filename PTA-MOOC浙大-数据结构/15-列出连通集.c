#include <stdio.h>


int graph[10][10];
int flag[10];
int queue[10];
int header, tail;

void DFS( int v, int n ){
	printf(" %d", v);
	flag[v] = 1;
	int i;
	for( i=0; i<n; i++){
		if( graph[v][i] && flag[i]==0 )
			DFS( i, n );
	}
}

void DFS_in_Components( int n ){
	int i;
	for( i=0; i<n; i++ )
		flag[i] = 0;
	for( i=0; i<n; i++ ){
		if( flag[i] == 0 ){
			printf("{");
			DFS( i, n );
			printf(" }\n");
		}
	}
}



void BFS( int start, int n ){
	header = tail = -1;
	queue[++tail] = start;
	flag[start] = 1;
	int i;
	while( header < tail ){
		start = queue[++header];
		printf(" %d", start);
		for( i=0; i<n; i++ ){
			if( graph[start][i] && flag[i]==0 ){
				queue[++tail] = i;
				flag[i] = 1;
			}
		}
	}
}

void BFS_in_Components( int n ){
	int i;
	for( i=0; i<n; i++ )
		flag[i] = queue[10] = 0;
	for( i=0; i<n; i++ ){
		if( flag[i] == 0 ){
			printf("{");
			BFS( i, n );
			printf(" }\n");
		}
	}
}

int main()
{
	int N, E;
	scanf("%d%d", &N, &E);
	int i, j;
	for( i=0; i<N; i++ ){
		for( j=0; j<N; j++ )
			graph[i][j] = 0;
	}
	
	int v1, v2;
	while( E-- ){
		scanf("%d%d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	DFS_in_Components( N );
	BFS_in_Components( N );
	
	return 0;
}
