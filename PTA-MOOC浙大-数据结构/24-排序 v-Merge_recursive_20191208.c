// 24-≈≈–Ú
// merge sort by recurrence
#include <stdio.h>
#include <stdlib.h>

void PrintArray( int *A, int N );

void MergeSort( int *A, int N );

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i, j;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	MergeSort( A, N );
	
	PrintArray( A, N);
	
	return 0;
}
///////////////////////////////////////////////////////////////////

void merge( int *A,int *B, int l_head, int r_head, int r_end ){
	int p1 = l_head;
	int p2 = r_head;
	int p = l_head;
	while( p1<r_head && p2<r_end ){
		if( A[p1] < A[p2] ){
			B[p++] = A[p1++];
		}else{
			B[p++] = A[p2++];
		}
	}
	while( p1 < r_head ){
		B[p++] = A[p1++];
	}
	while( p2 < r_end ){
		B[p++] = A[p2++];
	}
	for( p=l_head; p<r_end; p++ ){
		A[p] = B[p];
	}
}

void m_sort( int *A, int *B, int left, int right ){
	int mid;
	if( left < right ){
		mid = (left + right) / 2;
		m_sort( A, B, left, mid );
		m_sort( A, B, mid+1, right );
		merge( A, B, left, mid+1, right+1 );
	}
}

void MergeSort( int *A, int N ){
	int *B = (int*) malloc( sizeof(int) *N );
	if( B == NULL ){
		printf("\nError: insufficiente space.");
		return;
	}
	m_sort( A, B, 0, N-1 );
	free( B );
}

///////////////////////////////////////////////////////////////////
void PrintArray( int *A, int N ){
	int i;
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
}
