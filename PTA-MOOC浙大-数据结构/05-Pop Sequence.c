#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define WRONG 	0

int PushPop( int* stack, int* amount, int max, int* top, int n){
	int i;
	for( i=*top+1; i<n; i++){
		if( stack[i]==2 ){
			stack[i] = 1;
			*top = i;
			if( ++ *amount >= max )
				return WRONG;
		}
	}
	if( stack[n]==2 ){
		stack[n] = 0;
		return SUCCESS;
	}else{
		return WRONG;
	}
}

void Pop( int* stack, int* amount, int max, int* top ){
	stack[*top] = 0;
	--*amount;
	int i = *top -1;
	for( ; i>0; i--){
		if( stack[i] == 1 ){
			*top = i;
			return;
		}
	}
	*top = 0;
}

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	int stack[N+1];
	int judge[K];
	int i, j, n;
	
	int line;
	int success;
	for( line=0; line<K; line++ ){
		for( i=0; i<=N; i++)
			stack[i] = 2;
		success = 1;
		int amount=0, top=0;
		for( i=0; i<N; i++){
			scanf("%d", &n);
			if( success==0 )
				continue;
			if( n>top ){
				success = PushPop( stack, &amount, M, &top, n);
				if( success == 0 )
					continue;
			}else if( n==top ){
				Pop( stack, &amount, M, &top );
			}else{
				success = 0;
			}
		}
		if( success ){
			judge[line] = 1;
		}
	}
	if( judge[0] == 1 ){
		printf("YES");
	}else{
		printf("NO");
	}
	for( line=1; line<K; line++){
		if( judge[line] == 1 ){
			printf("\nYES");
		}else{
			printf("\nNO");
		}
	}
	return 0;
}
