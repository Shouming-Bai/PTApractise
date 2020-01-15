// 24-≈≈–Ú
// heap sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void PrintArray( int *A, int N );

void HeapSort( int *A, int N );

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i, j;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	HeapSort( A, N );
	
	PrintArray( A, N);
	
	return 0;
}

void PercDown( int *heap, int site, int N ){
	int tmp = heap[site];
	int son = site *2 +1;
	for( ; son<N; site=son, son=son*2+1 ){
		if( son+1<N && heap[son+1] > heap[son] ){
			son++;
		}
		if( heap[son] > tmp ){
			heap[site] = heap[son];
		}else{
			break;
		}
	}
	heap[site] = tmp;
	//PrintArray( heap, N );
}

void HeapSort( int *A, int N ){
	int i, max;
	for( i=(N-1)/2; i>=0; i-- ){
		PercDown( A, i, N );
	}
	
	for( i=N-1; i>0; i-- ){
		max = A[0];
		A[0] = A[i];
		A[i] = max;
		PercDown( A, 0, i );
	}
}

void PrintArray( int *A, int N ){
	int i;
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
}
