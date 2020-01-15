#include <stdio.h>
#include <stdlib.h>

void Heap_sort( long* data, int N );

int main()
{
	int N;
	scanf("%d", &N);
	long* data = (long*) malloc( sizeof(long) *N );
	int i;
	for( i=0; i<N; i++ )
		scanf("%ld", &data[i] );
	
	Heap_sort( data, N );
	
	printf("%ld", data[0] );
	for( i=1; i<N; i++ )
		printf(" %ld", data[i] );
	
	return 0;
}

void swap( long* a, long* b );
void Asjust_to_max_heap( long* heap, int size );
void Adjust_at( int site, long* heap, int size );

void Heap_sort( long* data, int N ){
	Asjust_to_max_heap( data, N );
	int i;
	for( i=N-1; i>0; i-- ){
		swap( &data[i], &data[0] );
		Adjust_at( 0, data, i );
	}
}

void Asjust_to_max_heap( long* heap, int size ){
	int site;
	for( site=(size-2)/2; site>=0; site-- )
		Adjust_at( site, heap, size );
}

void Adjust_at( int site, long* heap, int size ){
	int sl = site*2 +1;
	int sr = sl + 1;
	while( sl<size && heap[site] < heap[sl] || sr<size && heap[site]<heap[sr] ){
		if( sr<size ){
			if( heap[sr] > heap[sl] ){
				swap( &heap[sr], &heap[site] );
				site = sr;
			}else{
				swap( &heap[sl], &heap[site] );
				site = sl;
			}
		}else{
			swap( &heap[sl], &heap[site] );
			site = sl;
		}
		sl = site*2 +1;
		sr = sl + 1;
	}
}

void swap( long* a, long* b ){
	long tmp = *a;
	*a = *b;
	*b = tmp;
}


