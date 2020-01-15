#include <stdio.h>
#include <stdlib.h>
#define INFINITE	100000

typedef struct __term Term;
struct __term {
	int coef;
	int exp;
	Term* next;
};

typedef struct __polynomial Polynomial;
struct __polynomial {
	Term* first;
	Term* last;
	int numberOfTerms;
};

Polynomial* getPolynomial( int n );
Polynomial* multiply( Polynomial* poly1, Polynomial* poly2 );
Polynomial* plus( Polynomial* poly1, Polynomial* poly2 );
void printPolynomial( Polynomial* poly );
void deletePolynomial( Polynomial* poly );

int main( void )
{
	int n;
	// input 2 polynomials;
	scanf("%d", &n );
	Polynomial *poly1 = getPolynomial( n );
	scanf("%d", &n );
	Polynomial *poly2 = getPolynomial( n );
	// get product and sum of the 2 polynomails;
	Polynomial *product = multiply( poly1, poly2 );
	Polynomial *sum = plus( poly1, poly2 );
	// pirnt the product and sum;
	printPolynomial( product );
	printf("\n");
	printPolynomial( sum );
	
	deletePolynomial( poly1 );
	deletePolynomial( poly2 );
	deletePolynomial( product );
	deletePolynomial( sum );
	return 0;
}

Term* getTerm( void ) {
	Term *newTerm = (Term*) malloc( sizeof(Term) );
	scanf("%d %d", &(newTerm->coef), &(newTerm->exp) );
	newTerm->next = NULL;
	return newTerm;
}

Polynomial* getPolynomial( int n ){
	Polynomial* newPoly = (Polynomial*) malloc( sizeof(Polynomial) );
	newPoly->first = newPoly->last = NULL;
	newPoly->numberOfTerms = n;
	if ( n==0 )
		return newPoly;
	newPoly->first = newPoly->last = getTerm();
	int i;
	for (i=1; i<n; i++){
		newPoly->last->next = getTerm();
		newPoly->last = newPoly->last->next ;
	}
	return newPoly;
}

Term* makeTerm( int coef, int exp ){
	Term* newTerm = (Term*) malloc( sizeof(Term) );
	newTerm->coef = coef;
	newTerm->exp = exp;
	newTerm->next = NULL;
	return newTerm;
}

void calibration( Polynomial *poly ){
	if( poly->first ==NULL ){
		poly->last = NULL;
		poly->numberOfTerms  = 0;
		return;
	}
	Term *p = poly->first ;
	int length=0;
	for( ; p->next; p=p->next ){
		length ++;
	}
	length++;
	poly->last = p;
	poly->numberOfTerms = length;
}

Polynomial* multiply( Polynomial* poly1, Polynomial* poly2 ){
	Polynomial* product = malloc( sizeof(Polynomial) );
	// if polynomial product == 0, return:
	if( poly1->numberOfTerms ==0 || poly2->numberOfTerms ==0 ){
		product->first = product->last = NULL;
		product->numberOfTerms = 0;
		return product;
	}
	// if polynomial product != 0, calculate it:
	product->first = product->last = makeTerm( 0, INFINITE );//product has a head node;
	Term *p1, *p2, *p, *newTerm;
	int newCoef, newExp;
	for( p1=poly1->first; p1; p1=p1->next ){
		p = product->first ;
		for( p2=poly2->first; p2; p2=p2->next ){
			newCoef = p1->coef * p2->coef;
			newExp = p1->exp + p2->exp;
			while( p->next != NULL && p->next->exp > newExp )
				p = p->next ;
			if ( p->next ==NULL || newExp > p->next->exp ){
				newTerm = makeTerm( newCoef, newExp );
				newTerm->next = p->next ;
				p->next = newTerm;
				p = newTerm ;
			} else {
				p->next->coef += newCoef;
			}
		}
	}
	// delete zero value term:
	p1 = product->first;
	while ( p1->next ){
		if( p1->next->coef == 0 ){
			p2 = p1->next;
			p1->next = p2->next ;
			free( p2 );
		}else
			p1 = p1->next;
	}
	// delete the header of product:
	p = product->first ;
	product->first = p->next;
	free( p );
	// get the length, and find the last term:
	calibration( product );
	return product;
}

Polynomial* plus( Polynomial* poly1, Polynomial* poly2 ){
	Polynomial *sum = (Polynomial*) malloc( sizeof(Polynomial) );
	sum->first = makeTerm( 0, INFINITE );
	Term *p1 = poly1->first;
	Term *p2 = poly2->first;
	Term *p = sum->first ;
	while ( p1 && p2 ) {
		if ( p1->exp > p2->exp ) {
			p->next = makeTerm( p1->coef, p1->exp );
			p1 = p1->next;
		} else if (p2->exp > p1->exp ){
			p->next = makeTerm( p2->coef, p2->exp );
			p2 = p2->next;
		} else {
			if ( p1->coef + p2->coef == 0 ){
				p1 = p1->next;
				p2 = p2->next;
				continue;
			}
			p->next = makeTerm( p1->coef + p2->coef , p1->exp );
			p1 = p1->next;
			p2 = p2->next;
		}
		p = p->next ;
	}
	while( p1 && p1->coef !=0 ){
		p->next = makeTerm( p1->coef, p1->exp );
		p = p->next ;
		p1 = p1->next ;
	}
	while( p2 && p2->coef !=0 ){
		p->next = makeTerm( p2->coef, p2->exp );
		p = p->next ;
		p2 = p2->next ;
	}
	// delete the header of sum:
	p = sum->first ;
	sum->first = p->next ;
	free( p );
	// get last term and the length:
	calibration( sum );
	
	return sum;
}

void printPolynomial( Polynomial* poly ){
	if( poly->first == NULL ){
		printf("0 0");
		return;
	}
	Term *p = poly->first;
	printf("%d %d", p->coef, p->exp );
	for( p=p->next; p; p=p->next )
		printf(" %d %d", p->coef, p->exp );
}

void deletePolynomial( Polynomial *poly ){
	Term *p1 = poly->first;
	Term *p2;
	while( p1 ){
		p2 = p1;
		p1 = p2->next ;
		free( p2 );
	}
	free( poly );
}
