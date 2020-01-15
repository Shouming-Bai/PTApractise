#include <stdio.h>

int main()
{
	int sum, max;
	int n, *num;
	scanf("%d", &n);
	num = (int*) malloc( sizeof(int) * n );
	int i;
	for( i=0; i<n; i++ )
		scanf("%d", &num[i] );
	
	sum = max = 0;
	for( i=0; i<n; i++ ){
		sum += num[i];
		if (sum < 0) {
			sum = 0;
		} else if (sum > max) {
			max = sum;
		}
	}
	
	printf("%d", max);
	
	return 0;
}
