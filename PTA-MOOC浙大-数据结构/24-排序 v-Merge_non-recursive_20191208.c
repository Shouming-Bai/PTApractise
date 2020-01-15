// 24-≈≈–Ú
// merge sort by non-recurrence
#include <stdio.h>
#include <stdlib.h>

void PrintArray( int *A, int N );

void MergeSort( int *A, int N );

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	MergeSort( A, N );
	
	PrintArray( A, N);
	
	return 0;
}
///////////////////////////////////////////////////////////////////
void merge( int *A, int *B, int l_head, int r_head, int r_end ){
	int p1 = l_head;
	int p2 = r_head;
	int p = p1;
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
	while( p2< r_end ){
		B[p++] = A[p2++];
	}
}

void merge_pass( int *A, int *B, int N, int length ){
	int p1 = 0;
	int p2 = length;
	for( ; p2+length <= N; p1=p2+length,p2=p1+length ){
		merge( A, B, p1, p2, p2+length );
	}
	if( p2 < N ){
		merge( A, B, p1, p2, N );
	}else{
		while( p1 < N ){
			B[p1] = A[p1];
			p1 ++;
		}
	}
}

void MergeSort( int *A, int N ){
	int *B = (int*) malloc( sizeof(int) * N );
	if( B == NULL ){
		printf("\nError! Insufficient space.");
		return;
	}
	
	int length = 1;
	while( length < N ){
		merge_pass( A, B, N, length );
		length *= 2;
		merge_pass( B, A, N, length );
		length *= 2;
	}
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
