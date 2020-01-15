#include <stdio.h>
#include <stdlib.h>
#define MINVALUE -100001

typedef struct __heap *Heap;
struct __heap{
	int* data;
	int size;
	int MaxSize;
};

Heap CreateHeap( int N ){
	Heap newHeap = (Heap) malloc( sizeof(struct __heap) );
	newHeap->data = (int*) malloc( sizeof(int) * (N+1) );
	newHeap->data[0] = MINVALUE;
	newHeap->MaxSize = N;
	newHeap->size = 0;
	return newHeap;
}

void Insert( int data, Heap h ){
//	printf("inserting %d\n", data);
	if( h->size == h->MaxSize ){
//		printf("The heap is full, inserting failed !\n");
		return;
	}
	int son = ++h->size;
	int dad = son/2;
	while( data < h->data[dad] ){
		h->data[son] = h->data[dad];
		son = dad;
		dad = son/2;
	}
	h->data[son] = data;
//	printf("%d has be inserted.\n", data);
}


int main()
{
	int N, M, data;
	scanf("%d%d", &N, &M);
	Heap h = CreateHeap( N );
	while( N-- ){
		scanf("%d", &data);
		Insert( data, h );
	}
	
	int i;
	while( M-- ){
		scanf("%d", &i);
		printf("%d", h->data[i] );
		for( i/=2; i>0; i/=2){
			printf(" %d", h->data[i] );
		}
		if( M != 0 )
			printf("\n");
	}
	
	return 0;
}
