#include <stdio.h>
#define MAX			100
#define INFINITE	1000

struct __last{
	int dist;
	int from;
} path[MAX+1][MAX+1];

int g[MAX][MAX];
int down[MAX];
//int exist = 1;

void GetEdge( int m );
int Calculate_Shortest_Path( int n );
void Print_Proper_Start( int n );

int main()
{
	int n, m;
	scanf("%d%d", &n, &m );
	int i, j;
	for( i=1; i<=MAX; i++ ){
		for( j=1; j<=MAX; j++ )
			g[i][j] = INFINITE;
	}
	
	GetEdge( m );
	int exist = Calculate_Shortest_Path( n );
	if( exist==0 ){
		printf("0");
		return 0;
	}
	
	Print_Proper_Start( n );
	
	return 0;
}

void GetEdge( int m ){
	int v1, v2, dist;
	while( m-- ){
		scanf("%d%d%d", &v1, &v2, &dist );
		g[v1][v2] = g[v2][v1] = dist;
	}
}

int SeekCrossing( int start, int n );

int Calculate_Shortest_Path( int n ){
	int i, j, k;
	for( i=1; i<=n; i++ ){
		for( j=0; j<=n; j++ ){
			path[i][j].dist = INFINITE;
			path[i][j].from = -1;
		}
	}
	int is_not_connected = 0;
	int crossing;
	int crossDist;
	int newdist;
	//calculate shortest path from every the vertex i;
	for( i=1; i<=n; i++){
//		printf("\n# Calculate_Shortest_Path() start= %d", i);
		//clear down[] sign;
		for( j=1; j<=n; j++ )
			down[j] = 0;
		//prepapration for start off from i;
		path[i][i].dist = 0;
		crossing = i;
		
		for( j=1; j<=n; j++ ){
			//look for new crossing, if it's not exist then exit;
			crossing = SeekCrossing( i, n );
			crossDist = path[i][crossing].dist;
//			printf("\n# crossing = %d", crossing);
			if( crossing == 0 )
				return 0;
			//traverse crossing'all adjacent vertex, and update path;
			for( k=1; k<=n; k++ ){
				if( g[crossing][k] < INFINITE ){
					newdist = crossDist + g[crossing][k];
					if( newdist < path[i][k].dist ){
						path[i][k].dist = newdist;
						path[i][k].from = crossing;
						
					}
				}
			}
		}
	}
	return 1;
}

int SeekCrossing( int start, int n ){
	int crossDist = INFINITE;
	int crossing = 0;
	int k;
	for( k=1; k<=n; k++ ){
		if( down[k]==0 && path[start][k].dist < crossDist ){
			crossing = k;
			crossDist = path[start][k].dist;
		}
	}
	down[crossing] = 1;
	return crossing;
}


void Print_Proper_Start( int n ){
	int maxdist = 0;
	int proper;
	int shortest_maxdist=INFINITE;
	int i, j;
//	for( i=1; i<=n; i++ ){
//		printf("\n\n\t");
//		for( j=1; j<=n; j++ ){
//			printf("%d\t", j);
//		}
//		printf("\ndist\t");
//		for( j=1; j<=n; j++ ){
//			printf("%d\t", path[i][j].dist );
//		}
//		printf("\nfrom\t");
//		for( j=1; j<=n; j++ ){
//			printf("%d\t", path[i][j].from );
//		}
//	}
	for( i=1; i<=n; i++ ){
		maxdist = 0;
		for( j=1; j<=n; j++ ){
			if( path[i][j].dist > maxdist ){
				maxdist = path[i][j].dist;
			}
		}
		if( maxdist < shortest_maxdist ){
			proper = i;
			shortest_maxdist = maxdist;
		}
	}
	printf("%d %d", proper, shortest_maxdist);
}
