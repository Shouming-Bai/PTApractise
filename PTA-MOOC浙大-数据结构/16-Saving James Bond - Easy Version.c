#include <stdio.h>
#include <math.h>

typedef struct __vertex{
	int x;
	int y;
	int flag;
} vertex;
vertex v[100];
int N, D;

int near_to_bank( int index ){
	if( v[index].x - (-50) <= D || 50 - v[index].x <= D ||
		v[index].y - (-50) <= D	|| 50 - v[index].y <= D	  ){
		return 1;
	}
	return 0;
}

double distance_between( int i, int j ){
	double x = v[i].x - v[j].x;
	double y = v[j].y - v[j].y;
	return sqrt( x*x + y*y );
}

int jump_to( int index, int n ){
//	printf("( %d, %d )\n", v[index].x, v[index].y );
	v[index].flag = 1;
	if( near_to_bank( index ) )
		return 1;
	int i;
	for( i=0; i<n; i++ ){
		if( v[i].flag )
			continue;
		if( distance_between( index, i ) <= (double)D ){
			if( jump_to( i, n) )
				return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d", &N, &D);
	
	int i, x, y;
	for( i=0; i<N; i++ ){
		scanf("%d%d", &x, &y);
		v[i].x = x;
		v[i].y = y;
		v[i].flag = 0;
	}
	for( i=0; i<N; i++){
		if( v[i].flag )
			continue;
		x = v[i].x;
		y = v[i].y;
		if( sqrt((double)(x*x + y*y))  <= 7.5+D ){
			if( jump_to( i, N ) == 1 ){
				printf("Yes");
				break;
			}
		}
	}
	if( i==N )
		printf("No");
		
	return 0;
}
