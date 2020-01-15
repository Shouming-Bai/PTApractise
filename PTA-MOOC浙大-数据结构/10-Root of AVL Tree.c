#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
//typedef  ;
typedef struct __node{
	DataType data;
	struct __node* left;
	struct __node* right;
	int height;
} *Node;

Node makeNode( int data );
void Free( Node tree );
Node Insert( int data, Node tree);
Node L_Rotation( Node A );
Node R_Rotation( Node A );
Node LR_Rotation( Node A );
Node RL_Rotation( Node A );
int GetHight( Node L, Node R );
int GetBalanceFactor( Node L, Node R );

int main()
{
	int N;
	DataType data;
	scanf("%d", &N);
	
	Node tree=NULL;
	while( N-- ){
		scanf("%d", &data);
		tree = Insert( data, tree );
	}
	printf("%d", tree->data );
	Free( tree );
	
	return 0;
}

Node MakeNode( int data ){
	Node newNode = (Node) malloc( sizeof(struct __node) );
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	newNode->height = 0;
	return newNode;
}

void Free( Node tree ){
	if( tree ){
		Free( tree->left );
		Free( tree->right );
		free( tree );
	}
}


int GetHeight( Node L, Node R ){
	int l = -1;
	int r = -1;
	if( L )
		l = L->height ;
	if( R )
		r = R->height ;
	return (l>r ? l : r) + 1;
}

int DifferenceOf( Node L, Node R ){
	int l = -1;
	int r = -1;
	if( L )
		l = L->height ;
	if( R )
		r = R->height ;
	return l-r;
}

Node Insert( int data, Node tree){
	if( !tree ){
		tree = MakeNode( data );
	}else if( data < tree->data ){
		tree->left = Insert( data, tree->left );
		if( DifferenceOf(tree->left, tree->right ) == 2 ){
			if( data < tree->left->data )
				tree = L_Rotation( tree );
			else
				tree = LR_Rotation( tree );
		}
	}else if( data > tree->data ){
		tree->right = Insert( data, tree->right );
		if( DifferenceOf( tree->left, tree->right) == -2 ){
			if( data > tree->right->data )
				tree = R_Rotation( tree );
			else
				tree = RL_Rotation( tree );
		}
	}
	tree->height = GetHeight( tree->left, tree->right );
	return tree;
}

Node L_Rotation( Node A ){
	Node B = A->left ;
	A->left = B->right ;
	B->right = A;
	A->height = GetHeight( A->left, A->right );
	return B;
}

Node R_Rotation( Node A ){
	Node B = A->right;
	A->right = B->left ;
	B->left = A;
	A->height = GetHeight( A->left, A->right );
	return B;
}

Node LR_Rotation( Node A ){
	A->left = R_Rotation( A->left );
	A = L_Rotation( A );
	return A;
}

Node RL_Rotation( Node A ){
	A->right = L_Rotation( A->right );
	A = R_Rotation( A );
	return A;
}
