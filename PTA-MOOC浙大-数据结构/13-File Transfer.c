#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int* computer= (int*) malloc( sizeof(int)*(N+1) );
	int i, j;
	for( i=1; i<=N; i++){
		computer[i] = i;
	}
	char operation;
	getchar();
	
	int tmp;
	int c1, c2;
	while( (operation=getchar()) != 'S' ){
		scanf("%d %d", &c1, &c2);
		getchar();
		if( operation=='C'){
			if( computer[c1]==computer[c2] )
				printf("yes\n");
			else
				printf("no\n");
		}else{
			tmp = computer[c2];
			computer[c2] = computer[c1];
			for( i=1; i<=N; i++ ){
				if( computer[i]==tmp )
					computer[i] = computer[c1];
			}
		}
	}
//	for( i=1; i<=N; i++){
//		printf("%d ", computer[i]);
//	}
	int amount=0;
	for( i=1; i<=N; i++ ){
		if( computer[i] ){
			amount++;
			for( j=i+1; j<=N; j++)
				if( computer[j]==computer[i] )
					computer[j] = 0;
		}
	}
	if( amount==1 ){
		printf("The network is connected.");
	}else{
		printf("There are %d components.", amount);
	}
	return 0;
}
