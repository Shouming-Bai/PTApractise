#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
	int coef;
	int exp;
	struct __node* next;
} *Node;

typedef struct __poly{
	Node head;
	Node tail;
} Poly;

Node MakeNode( int c, int e){
	Node newNode = (Node) malloc( sizeof(struct __node) );
	newNode->coef = c;
	newNode->exp = e;
	newNode->next = NULL;
	return newNode;
}

Poly MakePoly(){
	Poly newPoly;
	newPoly.head = NULL;
	return newPoly;
}

void PrintPoly( Poly poly ){
	if( poly.head == 0 ){
		printf("0 0");
		return;
	}
	Node p=poly.head;
	printf("%d %d", p->coef, p->exp );
	for( p=p->next; p!=NULL; p=p->next )
		printf(" %d %d", p->coef, p->exp );
}

void AddElement( int c, int e, Poly* poly ){
	Node newNode = MakeNode( c, e);
	if( poly->head == NULL ){
		poly->head = newNode;
	}else{
		poly->tail->next = newNode;
	}
	poly->tail = newNode;
}

Poly GetPoly( int n ){
	Poly newPoly = MakePoly();
	int c, e;
	while( n ){
		scanf("%d %d", &c, &e);
		AddElement( c, e, &newPoly );
		n--;
	}
	return newPoly;
}

void Merge( Node term, Poly* poly){
	
	if( poly->head ==NULL ){
		poly->head = poly->tail = term;
		return;
	}
	Node p, prep;
	for( p=poly->head ; p!=NULL; p=p->next ){
		if( p->exp == term->exp ){
			p->coef += term->coef ;
			free(term);
			if( p->coef ==0){
				prep->next = p->next;
				if( p==poly->tail )
					poly->tail = prep;
				free( p );
			}
			return;
		}else if( p->exp > term->exp && p->next != NULL ){
			if( p->next->exp < term->exp ){
				term->next = p->next;
				p->next = term;
				return;
			}		
		}else{
			p->next = term;
			poly->tail = term;
			return;
		}
		prep = p;
	}
}

Poly Multiply( Poly poly1, Poly poly2){
	Poly product = MakePoly();
	Node p1 ,p2;
	for( p1=poly1.head; p1!=NULL; p1=p1->next ){
		for( p2=poly2.head; p2!=NULL; p2=p2->next ){
			Node term = MakeNode( p1->coef * p2->coef , p1->exp + p2->exp );
			Merge( term, &product );
		}
	}
	return product;
}

Poly Plus( Poly poly1, Poly poly2){
	Poly sum = MakePoly();
	Node p1 = poly1.head;
	Node p2 = poly2.head;
	while( p1!=NULL && p2!=NULL ){
		int e1 = p1->exp;
		int e2 = p2->exp;
		if( e1 == e2 ){
			int c = p1->coef + p2->coef ;
			if( c != 0 )
				AddElement( c , e1 , &sum);
			p1 = p1->next;
			p2 = p2->next;
		}else if(e1 > e2 ){
			AddElement( p1->coef, e1 , &sum);
			p1 = p1->next;
		}else{
			AddElement( p2->coef, e2 , &sum);
			p2 = p2->next;
		}
	}
	while( p1!=NULL ){
		AddElement( p1->coef, p1->exp, &sum);
		p1 = p1->next ;
	}
	while( p2!=NULL ){
		AddElement( p2->coef, p2->exp, &sum);
		p2 = p2->next ;
	}
	
	return sum;
}



void Free( Poly poly ){
	if( poly.head ==NULL )
		return;
	
	Node p;
	while( poly.head != NULL ){
		p=poly.head;
		poly.head = p->next ;
		free(p);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Poly poly1 = GetPoly(n);
	scanf("%d", &n);
	Poly poly2 = GetPoly(n);
	
	Poly product = Multiply( poly1, poly2);
	Poly sum = Plus( poly1, poly2);
	PrintPoly( product );
	printf("\n");
	PrintPoly( sum );
	
	Free( poly1 );
	Free( poly2 );
	Free( product );
	Free( sum );
	
	return 0;
}
