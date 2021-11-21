#include <arvoreAVL.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

void init_arvore_AVL(Node_AVL **r)
{
	*r = NULL;
}

static int load_factor(Node_AVL *r)
{
	if(r == NULL) return 0;
	return altura_AVL(r->direita) - altura_AVL(r->esquerda);
}

static Node_AVL *RE(Node_AVL *y)
{
	Node_AVL *x = y->direita;
	y->direita = x->esquerda;
	x->esquerda = y;
	return x;
}

static Node_AVL *RD(Node_AVL *y)
{
	Node_AVL *x = y->esquerda;
	y->esquerda = x->direita;
	x->direita = y;
	return x;
}

static Node_AVL *RED(Node_AVL *y)
{
	y->esquerda = RE(y->esquerda);
	return RD(y);
}

static Node_AVL *RDE(Node_AVL *y)
{
	y->direita = RD(y->direita);
	return RE(y);
}

Aluno *pesquisar_AVL(Node_AVL *r, int matricula)
{
	if(r == NULL) {
		return NULL;
	} else if(r->valor->matricula == matricula) {
		return r->valor;
	} else if(r->valor->matricula < matricula) {
		return pesquisar_AVL(r->direita, matricula);
	} else {
		return pesquisar_AVL(r->esquerda, matricula);
	}
}

Node_AVL *inserir_AVL(Node_AVL *r, Aluno *a)
{
	if(a == NULL) {
		perror("Aluno nulo.");
		return r;
	}
	if(r == NULL) {
		r = (Node_AVL *) malloc(sizeof(Node_AVL));
        r->esquerda = r->direita = NULL;
        r->valor = a;
        return r;
	}
	if(a->matricula < r->valor->matricula) {
		r->esquerda = inserir_AVL(r->esquerda, a);
	} else {
		r->direita = inserir_AVL(r->direita, a);
	}

	if(load_factor(r) == 2) {
		if(load_factor(r->direita) > 0)
			return RE(r);
		else
			return RDE(r);
	}
	if(load_factor(r) == -2) {
		if(load_factor(r->esquerda) < 0)
			return RD(r);
		else
			return RED(r);
	}

	return r;
}

int altura_AVL(Node_AVL *r)
{
	if(r == NULL)
    	return 0;
    int hd = altura_AVL(r->direita);
    int he = altura_AVL(r->esquerda);
    return MAX(he, hd) + 1;
}

int num_elementos_AVL(Node_AVL *r)
{
	if(r == NULL)
		return 0;
	return 1 + num_elementos_AVL(r->esquerda) + num_elementos_AVL(r->direita);
}

void print_em_ordem_AVL(Node_AVL *r)
{
	if(r != NULL) {
		print_em_ordem_AVL(r->esquerda);
		PRINT_ALUNO(r->valor);
		print_em_ordem_AVL(r->direita);
	}
}
