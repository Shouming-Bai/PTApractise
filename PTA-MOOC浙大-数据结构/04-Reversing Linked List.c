#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
	int address;
	int data;
	int next;
} Node;

void GetList( Node* list, int N){
	int i;
	int address, data, next;
	for( i=0; i<N; i++ ){
		scanf("%d %d %d", &address, &data, &next);
		list[i].address = address;
		list[i].data = data;
		list[i].next = next;
	}
}

void PrintAddress( int n ){
	if( n ==-1 ){
		printf("-1");
		return;
	}
	int i, base=10000;
	for( i=0; i<5; i++){
		printf("%d", n/base%10);
		base /= 10;
	}
}

void PrintList( Node* list ,int N){
	PrintAddress(list[0].address );
	printf(" %d ", list[0].data );
	PrintAddress(list[0].next);
	int i;
	for( i=1; i<N; i++){
		printf("\n");
		PrintAddress(list[i].address );
		printf(" %d ", list[i].data );
		PrintAddress(list[i].next);
	}
}

int Sort( int ad, Node* list, int N){
//	int ad2=-1;
	int i, j;
	Node carrier;
	for( i=0; i<N; i++ ){
		for( j=i; j<N; j++){
			if( list[j].address == ad ){
				carrier = list[i];
				list[i] = list[j];
				list[j] = carrier;
				ad = list[i].next;
				if( ad==-1 )
					return i+1;
				break;
			}
		}
	}
	return N;
}

void Resort( Node* list, int N, int K){
	int pieces = N / K;
	int halfK = K / 2;
	int site, i;
	Node carrier;
	for( site=0; site<pieces; site++ ){
		for( i=0; i<halfK; i++ ){
			int point1 = i + site*K;
			int point2 = K-1-i + site*K;
			carrier = list[point1];
			list[point1] = list[point2];
			list[point2] = carrier;
		}
	}
	int N1 = N-1;
	for( i=0; i<N1; i++){
		list[i].next = list[i+1].address;
	}
	list[N1].next = -1;
}

int main(){
	int ad, N, K;
	scanf("%d %d %d", &ad, &N, &K);
	Node list[N];
	GetList( list, N);
	N = Sort( ad, list, N);
	Resort( list, N, K);
	PrintList( list , N);
	
	return 0;
}
