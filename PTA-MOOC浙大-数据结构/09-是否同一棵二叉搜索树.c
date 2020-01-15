#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
	int data;
	struct __node* left;
	struct __node* right;
} *Node;

Node MakeNode( int n ){
	Node newNode = (Node) malloc( sizeof(struct __node) );
	newNode->data = n;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void Insert( int data, Node tree){
	if( data < tree->data ){
		if( tree->left ){
			Insert( data, tree->left );
		}else{
			tree->left = MakeNode( data );
		}
	}else{
		if( tree->right ){
			Insert( data, tree->right );
		}else{
			tree->right = MakeNode( data );
		}
	}
}

Node GetTree( int n ){
	int data;
	scanf("%d", &data);
	n--;
	Node tree = MakeNode( data );
	while( n-- ){
		scanf("%d", &data);
		Insert( data, tree );
	}
	return tree;
}

int Compare( Node t1, Node t2){
	if( t1==NULL && t2==NULL ){
		return 1;
	}else if( t1->data != t2->data ){
		return 0;
	}else{
		if( Compare( t1->left, t2->left) ){
			return Compare( t1->right, t2->right);
		}else
			return 0;
	}
}

void Free( Node tree ){
	if( !tree )
		return;
	Free( tree->left );
	Free( tree->right);
	free( tree );
}

int main()
{
	int N, L;
	scanf("%d", &N);
	int is_same;
	int is_first = 1;
	while( N ){
		scanf("%d", &L);
		Node tree = GetTree( N );
		while( L-- ){
			Node another = GetTree( N );
			is_same = Compare( tree, another );
			if( is_first ){
				is_first = 0;
				if( is_same )
					printf("Yes");
				else
					printf("No");
			}else{
				if( is_same )
					printf("\nYes");
				else
					printf("\nNo");
			}
			Free( another );
		}
		Free( tree );
		scanf("%d", &N);
	}
	return 0;
}
