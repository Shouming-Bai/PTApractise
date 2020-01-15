// 24-≈≈–Ú
// bubble sort
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N;
	scanf("%d", &N);
	
	int *A = (int*) malloc( sizeof(int) * N );
	int i, j;
	for( i=0; i<N; i++ ){
		scanf("%d", &(A[i]) );
	}
	
	int isSwap;
	int tmp;
	for( i=N; i; i-- ){
		isSwap = 0;
		for( j=0; j<N-1; j++ ){
			if( A[j] > A[j+1] ){
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
				isSwap = 1;
			}
		}
		if( isSwap == 0 ){
			break;
		}
	}
	
	printf("%d", A[0] );
	for( i=1; i<N; i++ ){
		printf(" %d", A[i] );
	}
	
	return 0;
}
