// 24-����
// quick sort
#include <stdio.h>
#include <stdlib.h>

void PrintArray( int *A, int N );

void QuickSort( int *A, int N );

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	QuickSort( A, N );
	
	PrintArray( A, N);
	
	return 0;
}
///////////////////////////////////////////////////////////////////

void Swap( int *a, int *b ){
	int tmp = *a;
	*a = *b;
	*b =tmp;
}

int Median3( int *A, int left, int right ){
	right--;
	int mid = (left + right) /2;
	if( A[left] > A[mid] ){
		Swap( &A[left], &A[mid] );
	}
	if( A[left] > A[right] ){
		Swap( &A[left], &A[right] );
	}
	if( A[mid] > A[right] ){
		Swap( &A[mid], &A[right] );
	}
	Swap( &A[mid], &A[right-1] );
	
	return A[right-1];
}

void Qsort( int *A, int left, int right ){
	if( left+1 == right ){
		return;
	}else if( left+3 >= right ){
		Median3( A, left, right );
		return;
	}
	
	int pivot = Median3( A, left, right );
	int pL = left;
	int pR = right-2;
	while( 1 ){
		while( A[++pL] < pivot );
		while( A[--pR] > pivot );
		if( pL < pR ){
			Swap( &A[pL], &A[pR] );
		}else{
			break;
		}
	}
	Swap( &A[pL], &A[right-2] );
	Qsort( A, left, pL );
	Qsort( A, pL+1, right );
}

void QuickSort( int *A, int N ){
	Qsort( A, 0, N );
}

///////////////////////////////////////////////////////////////////
void PrintArray( int *A, int N ){
	int i;
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
}
