#include <stdio.h>
#include <stdlib.h>

void Merge_sort_recursive( long* data, int size );

int main()
{
	int N;
	scanf("%d", &N);
	long* data = (long*) malloc( sizeof(long) *N );
	int i;
	for( i=0; i<N; i++ )
		scanf("%ld", &data[i] );

	Merge_sort_recursive( data, N );
	
	printf("%ld", data[0] );
	for( i=1; i<N; i++ )
		printf(" %ld", data[i] );
		
	free( data );
	return 0;
}

void swap( long* a, long* b );
void M_recursive( int light, int right, long* data, long* tmp );

void Merge_sort_recursive( long* data, int size ){
	long* tmp = (long*) malloc( sizeof(long) *size );
	M_recursive( 0, size-1, data, tmp );
}

void Merge( int lhead, int rhead, int rightEnd, long* data, long* tmp );

void M_recursive( int light, int right, long* data, long* tmp ){
	if( light >= right )
		return;
	int center = (light + right) /2;
	M_recursive( light, center, data, tmp );
	M_recursive( center+1, right, data, tmp );
	Merge( light, center+1, right, data, tmp );
}

void Merge( int lhead, int rhead, int rightEnd, long* data, long* tmp ){
	int start = lhead;
	int p = lhead;
	int lightEnd = rhead - 1;
	while( lhead<=lightEnd && rhead<=rightEnd ){
		if( data[lhead] < data[rhead] ){
			tmp[p++] = data[lhead++];
		}else
			tmp[p++] = data[rhead++];
	}
	while( lhead<=lightEnd )
		tmp[p++] = data[lhead++];
	while( rhead<=rightEnd )
		tmp[p++] = data[rhead++];

	for( ; start<=rightEnd; start++ )
		data[start] = tmp[start];
}

void swap( long* a, long* b ){
	long tmp = *a;
	*a = *b;
	*b = tmp;
}


