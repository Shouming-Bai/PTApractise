#include <stdio.h>

int mid[30];
int post[30];

void Root( int midLeft, int midRight, int postLeft, int postRight ){
	if( postLeft > postRight)
		return;
	
	int root = post[postRight];
	printf(" %d", root );
	int rootSiteInMid;
	for( rootSiteInMid=midLeft; rootSiteInMid<=midRight; rootSiteInMid++){
		if( mid[rootSiteInMid]==root )
			break;
	}
	int N_left_half = rootSiteInMid-midLeft;
	int N_right_half = midRight - midLeft + 1 - N_left_half -1;
	Root( midLeft, rootSiteInMid-1, postLeft, postLeft+N_left_half-1 );
	Root( rootSiteInMid+1, midRight,  postLeft+N_left_half, postRight-1);
}

void getRoot( int N ){
	Root( 0, N-1, 0, N-1 );
}

int main()
{
	int N;
	scanf("%d", &N);
	int i;
	for( i=0; i<N; i++ )
		scanf("%d", &post[i] );
	for( i=0; i<N; i++ )
		scanf("%d", &mid[i] );
	
	printf("Preorder:");
	getRoot( N );
}
