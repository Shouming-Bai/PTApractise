//给定一棵二叉树的先序遍历序列和中序遍历序列，要求计算该二叉树的高度。
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int getHeight( char *pre, int preL, int preR, char *in, int inL, int inR, int deep ){
	if( preL == preR ){
		return ++deep;
	}else if( preR < preL){
		return deep;
	}
	int i;
//	printf("\ndeep = %d\n", deep );
//	for( i=preL; i<=preR; i++ ){
//		printf("%c", pre[i]);
//	}
//	printf("\n", deep );
//	for( i=inL; i<=inR; i++ ){
//		printf("%c", in[i]);
//	}
	i = inL;
	while(1){
		if( in[i] == pre[preL] ){
			break;
		}else{
			i ++;
		}
	}
	int leftLength = i - inL;
	int leftDeep = getHeight( pre, preL+1, preL+leftLength, in, inL, i-1, deep+1 );
	int rightDeep = getHeight( pre, preL+leftLength+1, preR, in, i+1, inR, deep+1 );
	return leftDeep > rightDeep ? leftDeep : rightDeep;
}

int main()
{
	int N;
	scanf("%d", &N );
	char *pre = (char*) malloc( sizeof(char) *N );
	char *in = ( char*) malloc( sizeof(char) *N );
	getchar();
	int i;
	for( i=0; i<N; i++ ){
		pre[i] = getchar();
	}
	getchar();
	for( i=0; i<N; i++ ){
		in[i] = getchar();
	}
//	for( i=0; i<N; i++ ){
//		printf("%c", in[i] );
//	}
	
	int height = getHeight( pre, 0, N-1, in, 0, N-1, 0 );
	printf("%d", height );
	
	return 0;
}

