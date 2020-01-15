#include <stdio.h>
#include <stdlib.h>

void Shell_sort( long* data, int N );

int main()
{
	int N;
	scanf("%d", &N);
	long* data = (long*) malloc( sizeof(long) *N );
	int i;
	for( i=0; i<N; i++ )
		scanf("%ld", &data[i] );
	
	Shell_sort( data, N );
	
	printf("%ld", data[0] );
	for( i=1; i<N; i++ )
		printf(" %ld", data[i] );
	
	return 0;
}

int convergent( int d );

void Shell_sort( long* data, int N ){
	int d, i, j, tmp;
	for( d=(N/2)-1; d>0; d=convergent( d ) ){
		for( i=d; i<N; i++ ){
			tmp = data[i];
			for( j=i-d; j>=0 && data[j]>tmp; j-=d ){
				data[j+d] = data[j];
			}
			data[j+d] = tmp;
		}
	}
}

int convergent( int d ){
	d = d/2 - 1;
	if( d == 0 )
		return 1;
	return d;
}
