#include <stdio.h>
#define null -1

typedef struct __node{
	int left;
	int right;
} TreeNode;

int amount;
TreeNode tree[10];
int que[10]={0};
int head=-1;
int tail=-1;
int leaf[10];
int nleaves = 0;

void GetTree( int n ){
	char b1, l, b2, r;
	int i;
	for( i=0; i<n; i++ ){
		scanf("%c%c%c%c", &b1, &l, &b2, &r );
		if( l>='0' && l<='9' ){
			tree[i].left = l-'0';
			que[l-'0'] = 1;
		}else{
			tree[i].left = null;
		}
		if( r>='0' && r<='9' ){
			tree[i].right = r-'0';
			que[r-'0'] = 1;
		}else{
			tree[i].right = null;
		}
//		printf("tree[%d]: %2d  %2d\n", i, tree[i].left ,tree[i].right );
	}
	for( i=0; i<n; i++ ){
		if( que[i] == 0 ){
			que[++head] = i;
			break;
		}
	}
}

void FindLeaves(){
	TreeNode theNode;
	int hasSon;
	while( tail != head ){
		theNode = tree[ que[tail+1] ];
		hasSon = 0;
		if( theNode.left != null ){
			que[++head] = theNode.left ;
			hasSon = 1;
		}
		if( theNode.right != null ){
			que[++head] = theNode.right ;
			hasSon = 1;
		}
		if( hasSon==0 ){
			leaf[nleaves++] = que[tail+1];
		}
		tail++;
//		printf("\n# tail=%d   head=%d", tail, head);
	}
}

int main()
{
	scanf("%d", &amount);
	GetTree( amount );
	FindLeaves();
	printf("%d", leaf[0]);
	int i;
	for( i=1; i<nleaves; i++ )
		printf(" %d", leaf[i]);
	
	return 0;
}
