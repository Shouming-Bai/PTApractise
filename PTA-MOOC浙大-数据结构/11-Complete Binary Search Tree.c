#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct output{
	int start;
	int difference;
	int amount;
};

void Sort( int* inorder, int N ){
	int i, j;
	int HasSwap=1;
	int tmp;
	while( HasSwap ){
		HasSwap = 0;
		for( i=0,j=1 ; j<N; i++,j++){
			if( inorder[i] > inorder[j] ){
				tmp = inorder[i];
				inorder[i] = inorder[j];
				inorder[j] = tmp;
				HasSwap = 1;
			}
		}
	}
//	for( i=0; i<N; i++){
//		printf("%d ", inorder[i]);
//	}	
}

int main()
{
	int N;
	scanf("%d", &N);
	int layers, ret, redundant, last_layer_amount, amount;
	layers = (int)( log(N)/log(2) ) + 1;
	last_layer_amount = pow( 2.0, layers-1 );
	amount = last_layer_amount*2 -1;
	ret = N - last_layer_amount + 1;;
	redundant = last_layer_amount - ret;
	
	int* inorder = (int*) malloc( sizeof(int) * amount );
	int i, j;
	for( i=0; i<N; i++)
		scanf("%d", &inorder[i] );
	Sort( inorder, N );
	int StopSite = (ret-1)*2;
	for( i=N-1, j=amount-2; i>StopSite; i--, j-=2)
		inorder[j] = inorder[i];
	
	struct output OutControl[layers];
	OutControl[layers-1].start = 0;
	OutControl[layers-1].difference = 2;
	OutControl[layers-1].amount = last_layer_amount;
	int increment = 1;
	for( i=layers-2; i>=0; i--){
		OutControl[i].start = OutControl[i+1].start + increment;
		OutControl[i].difference = OutControl[i+1].difference * 2;
		OutControl[i].amount = OutControl[i+1].amount / 2;
		increment *= 2;
	}
	OutControl[layers-1].amount = ret;
	printf("%d", inorder[ OutControl[0].start ] );
	int difference;
	for( i=1; i<layers; i++){
		difference = 0;
		for( j=0; j<OutControl[i].amount; j++){
			printf(" %d", inorder[ OutControl[i].start + difference ] );
			difference += OutControl[i].difference ;
		}
	}
	
	return 0;
}
