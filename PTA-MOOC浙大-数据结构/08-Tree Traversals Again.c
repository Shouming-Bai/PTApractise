#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
	int data;
	struct __node* left;
	struct __node* right;
} *Node;

struct __stack{
	Node node;
	int haspop;
} stack[30];

int top = -1;
char operation[5];

Node MakeNode( int n ){
	Node newNode = (Node) malloc( sizeof(struct __node) );
	newNode->data = n;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void Push( int n, int turn_right ){
	Node newNode = MakeNode( n );
	if( turn_right ){
		stack[top].node->right = newNode;
//		printf("# put %d at %d\'s right\n", n, stack[top].node->data );
	}else{
		stack[top].node->left = newNode;
//		printf("# put %d at %d\'s left\n", n, stack[top].node->data );
	}
	stack[++top].node = newNode;
	stack[top].haspop = 0;
//	printf("#top = %d\n", top);
}

void Pop(){
	while( stack[top].haspop ){
		top--;
	}
	stack[top].haspop = 1;
}

void PostTraversal( Node root, int n ){
	if( root->left )
		PostTraversal( root->left, 0 );
	 if( root->right )
		PostTraversal( root->right, 0 );
	
	if( n ){
		printf("%d", root->data );
	}else
		printf("%d ", root->data );

}

int main()
{
	Node root = MakeNode( 0 );
	int n;
	int data;
	int Last_Is_Pop = 0;
	
	scanf("%d", &n);
	n *= 2;
	if( n==0 ){
		return 0;
	}else{
		scanf("%s", operation);
		scanf("%d", &data);
		root->data = data;
		stack[++top].node = root;
		stack[top].haspop = 0;
//		printf("# top = %d\n", top);
		n--;
	}
	
	while( n-- ){
		scanf("%s", operation);
		if( operation[1] == 'u' ){
			scanf("%d", &data);
			Push( data, Last_Is_Pop );
			Last_Is_Pop = 0;
		}else{
			Pop();
//			printf("# top = %d\n", top);
			Last_Is_Pop = 1;
		}
	}
	
	PostTraversal( root, 1 );
	return 0;
}

