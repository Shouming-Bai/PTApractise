#include <stdio.h>
#include <stdlib.h>

int main()
{
	int maxSum, maxHead, maxTail;
	int sum, head, tail;
	int n, *num;
	scanf("%d", &n);
	num = (int*) malloc( sizeof(int) * n );
	int i;
	for (i=0; i<n; i++)
		scanf("%d", &num[i] );
	
	maxSum = -1;
	sum = 0;
	head = tail = 0;
	maxHead = 0;
	maxTail = n-1;
	
	for ( i=0; i<n; i++ ){
		sum += num[i];
		if ( sum < 0 ) {
			sum = 0;
			head = i + 1;
		} else {
			tail = i;
			if ( sum > maxSum ){
				maxSum = sum;
				maxHead = head;
				maxTail = tail;
			}
		}
	}
	if( maxSum < 0 )
		maxSum = 0;
	printf("%d %d %d", maxSum, num[maxHead], num[maxTail] );
	
	return 0;
}
