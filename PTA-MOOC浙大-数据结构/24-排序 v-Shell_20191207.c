// 24-≈≈–Ú
// Shell sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void PrintArray( int *A, int N );

void ShellSort( int *A, int N );

int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i, j;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	ShellSort( A, N );
	
	PrintArray( A, N);
	
	return 0;
}

void ShellSort( int *A, int N ){
	int itv, tmp;		// invterval;
	int p, i;
	int e = log(N/2) / log( 2);
	for( ; e>0; e-- ){
		itv = pow( 2, e )- 1;
		for( p=itv; p<N; p++ ){
			tmp = A[p];
			for( i=p; i>=itv && A[i-itv]>tmp; i-=itv ){
				A[i] = A[i-itv];
			}
			A[i] = tmp;
		}
	}
}

void PrintArray( int *A, int N ){
	int i;
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
}
