#include <stdio.h>
#include <stdlib.h>

int main()
{
	int K;
	scanf("%d", &K );
	
	int *a = (int*) malloc( sizeof(int) *K );
	int i;
	for( i=0; i<K; i++ ){
		scanf("%d", &(a[i]) );
	}
	
	int maxSum = 0;
	int sum = 0;
	for( i=0; i<K; i++ ){
		sum += a[i];
		if( sum < 0 ){
			sum = 0;
		}else if( sum > maxSum ){
			maxSum = sum;
		}
	}
	
	printf("%d", maxSum );
	
	return 0;
}
