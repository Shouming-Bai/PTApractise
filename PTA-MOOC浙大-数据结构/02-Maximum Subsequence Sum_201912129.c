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
	
	int maxSum = -1;
	int maxFirst=0, maxLast=0;
	int first=0, last=0;
	int sum = 0;
	for( i=0; i<K; i++ ){
		sum += a[i];
		if( sum < 0 ){
			sum = 0;
			first = i+1;
		}else if( sum > maxSum ){
			maxSum = sum;
			maxFirst = first;
			maxLast = i;
		}
	}
	
	if( maxSum < 0 ){
		printf("0 %d %d", a[0], a[K-1] );
	}else{
		printf("%d %d %d", maxSum, a[maxFirst], a[maxLast] );
	}
	
	return 0;
}
