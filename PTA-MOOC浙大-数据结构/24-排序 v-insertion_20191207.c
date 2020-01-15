// 24-еепР
// insertion sort
#include <stdio.h>
#include <stdlib.h>

void InsertionSort( int *A, int N ){
	int i, j;
	int tmp;
	for( i=1; i<N; i++ ){
		tmp = A[i];
		for( j=i; j>0 && tmp < A[j-1]; j-- ){
			A[j] = A[j-1];
		}
		A[j] = tmp;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i, j;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	InsertionSort( A, N );
	
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
	
	return 0;
}
