#include <stdio.h>

typedef struct __node{
	char data;
	int L;
	int R;
} Node;

Node tree1[10], tree2[10];
int que1[10]={0}, que2[10]={0};
int top1=-1, top2=-1;
int head1=-1, head2=-1;
int tail1=-1, tail2=-1;
int amount1=0, amount2=0;
int root1=-1, root2=-1;

void GetTree( Node* tree, int n, int* seekRoot){
	char blank1, data, blank2, l, blank3, r;
	int i;
	int number;
	for( i=0; i<n; i++ ){
		scanf("%c%c%c%c%c%c", &blank1, &data, &blank2, &l, &blank3, &r);
		tree[i].data = data;
		if( l>='0' && l<='9' ){
			number = l - '0';
			tree[i].L = number;
			seekRoot[number] = 1;
		}else{
			tree[i].L = -1;
		}
		if( r>='0' && r<='9' ){
			number = r - '0';
			tree[i].R = number;
			seekRoot[number] = 1;
		}else{
			tree[i].R = -1;
		}
	}
}

int FindRoot( int n,  int* seekRoot){
	int i;
	for( i=0; i<n; i++){
		if( seekRoot[i] == 0 )
			return i;
	}
}

int main()
{
	scanf("%d", &amount1);
	GetTree( tree1, amount1 ,que1);
	
	scanf("%d", &amount2);
	GetTree( tree2, amount2, que2);
	if( amount1==0 && amount2==0){
		printf("Yes");
		return 0;
	}
	root1 = FindRoot( amount1, que1);
	root2 = FindRoot( amount2, que2);
	if( amount1 != amount2 || tree1[root1].data != tree2[root2].data ){
		printf("No");
		return 0;
	}
	que1[++head1] = root1;
	que2[++head2] = root2;
	int carrier;
	Node* tailNode1, *tailNode2;
	int i=0;
	while( tail1 != head1 ){
		tailNode1 = &tree1[que1[tail1+1]];
		tailNode2 = &tree2[que2[tail2+1]];
		if( tree1[ tailNode1->L ].data != tree2[ tailNode2->L ].data ){
			carrier = tailNode2->L;
			tailNode2->L = tailNode2->R ;
			tailNode2->R  = carrier;
		}
		if( tree1[ tailNode1->L ].data != tree2[ tailNode2->L ].data ||
			tree1[ tailNode1->R ].data != tree2[ tailNode2->R ].data){
			printf("No");
			return 0;	
		}
		if( tailNode1->L != -1)
			que1[++head1] = tailNode1->L ;
		if( tailNode1->R != -1)
			que1[++head1] = tailNode1->R ;
		if( tailNode2->L != -1)
			que2[++head2] = tailNode2->L ;
		if( tailNode2->R != -1)
			que2[++head2] = tailNode2->R ;
		tail1++;
		tail2++;
		
	}
	printf("Yes");
	
	return 0;
}

