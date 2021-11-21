#pragma once

#include <aluno.h>

typedef struct node_AVL {
	Aluno *valor;
	struct node_AVL *esquerda;
	struct node_AVL *direita;
} Node_AVL;

void init_arvore_AVL(Node_AVL **r);

Aluno *pesquisar_AVL(Node_AVL *r, int matricula);

Node_AVL *inserir_AVL(Node_AVL *r, Aluno *a);

int altura_AVL(Node_AVL *r);

int num_elementos_AVL(Node_AVL *r);

void print_em_ordem_AVL(Node_AVL *r);
