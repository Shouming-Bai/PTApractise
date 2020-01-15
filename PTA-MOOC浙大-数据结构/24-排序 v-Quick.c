#include <stdio.h>
#include <stdlib.h>

void Quick_sort( long* data, int size );

int main()
{
	int n;
	scanf("%d", &n);
	long* data = (long*) malloc( sizeof(long) *n );
	
	int i;
	for( i=0; i<n; i++ )
		scanf("%ld", &data[i] );
	
	Quick_sort( data, n );
	
	printf("%ld", data[0]);
	for( i=1; i<n; i++ )
		printf(" %ld", data[i] );
	
	free(data);
	return 0;
}

void Qsort( long* data, int left, int right );

void Quick_sort( long* data, int size ){
	Qsort( data, 0, size-1 );
}

void swap( long* a, long* b );

void Qsort( long* data, int left, int right ){
	if( left>= right )
		return;
	int criteria = (left+right) / 2;
	swap( &data[left], &data[criteria] );
	criteria = left;
	int i;
	for( i=left+1; i<=right; i++ ){
		if( data[i] < data[criteria] )
			swap( &data[i], &data[++left] );
	}
	swap( &data[criteria], &data[left] );
	Qsort( data, criteria, left-1 );
	Qsort( data, left+1, right );
}

void swap( long* a, long* b ){
	long tmp = *a;
	*a = *b;
	*b = tmp;
}
