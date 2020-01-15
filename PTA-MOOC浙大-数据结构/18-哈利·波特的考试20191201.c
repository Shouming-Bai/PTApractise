#include <stdio.h>
#include <stdlib.h>
#define INFINITE	0xffff

int main()
{
	int M, N;
	scanf("%d %d", &N, &M );
	N++;
	
	int k, i, j;
	int dist[101][101];
	for( i=0; i<N; i++ ){
		for( j=0; j<N; j++ ){
			dist[i][j] = INFINITE;
		}
	}
	for( i=0; i<N; i++ ){
		dist[i][i] = 0;
	}
	
	int v1, v2, e;
	for( i=0; i<M; i++ ){
		scanf("%d %d %d", &v1, &v2, &e );
		dist[v1][v2] = dist[v2][v1] = e;
	}
	
	for( k=1; k<N; k++ ){
		for( i=1; i<N; i++ ){
			for( j=1; j<N; j++ ){
				if( dist[i][j] > dist[i][k] + dist[k][j] ){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	int opt =0, max=INFINITE;
	int crt, crtMax;
	for( crt=1; crt<N; crt++ ){
		crtMax = 0;
		//printf("crt=%2d: ", crt );//debug
		for( i=1; i<N; i++ ){
			//printf(" %3d", dist[crt][i] );//debug
			if( crtMax < dist[crt][i] ){
				crtMax = dist[crt][i];
			}
		}
		//printf("\n");//debug
		if( crtMax < INFINITE && crtMax < max ){
			opt = crt;
			max = crtMax;
		}
	}
	if( opt != 0 ){
		printf("%d %d", opt, max );
	}else{
		printf("0");
	}
	
	return 0;
}
