#pragma once

#include <stdio.h>

#include <aluno.h>

typedef struct node {
	Aluno *valor;
	struct node *esquerda;
	struct node *direita;
} Node;

void init_arvore(Node **r);

Node *inserir(Node *r, Aluno *a);

Aluno *pesquisar(Node *r, int matricula);

Node *remover(Node *r, int matricula);

int altura(Node *r);

int num_elementos(Node *r);

void print_em_ordem(Node *r);
