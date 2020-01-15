#include <stdio.h>
#include <stdlib.h>
#define INFINITE	0xffff
#define BORDER		6

int main()
{
	int N, M;
	scanf("%d %d", &N, &M );
	N++;
	
	int **edge = (int**) malloc( sizeof( int*) * N );
	int i, j, k;
	for( i=0; i<N; i++ ){
		edge[i] = (int*) malloc( sizeof(int) * N );
	}
	for( i=0; i<N; i++ ){
		for( j=0; j<N; j++ ){
			edge[i][j] = INFINITE;
			edge[j][i] = INFINITE;
		}
	}
	for( i=0; i<N; i++ ){
		edge[i][i] = 0;
	}
	
	int v1, v2;
	for( i=0; i<M; i++ ){
		scanf("%d %d", &v1, &v2 );
		edge[v1][v2] = 1;
		edge[v2][v1] = 1;
	}
	
	for( k=1; k<N; k++ ){
		for( i=1; i<N; i++ ){
			for( j=1; j<N; j++ ){
				if( edge[i][j] > edge[i][k] + edge[k][j]){
					edge[i][j] = edge[j][i] = edge[i][k] + edge[k][j];
				}
			}
		}
	}
	
	int n;
	for( i =1; i<N; i++ ){
		n=0;
		for( j=1; j<N; j++ ){
			if( edge[i][j] <= BORDER ){
				n++;
			}
		}
		printf("%d: %.2f%%\n", i, n*100.0/(N-1) );
	}
	return 0;
}
