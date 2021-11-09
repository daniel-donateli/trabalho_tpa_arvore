#include <arvore.h>

void init_arvore(Node **r)
{
	*r = NULL;
}

Aluno *pesquisar(Node *r, int matricula)
{
	if(r == NULL) {
		return NULL;
	} else if(r->valor->matricula == matricula) {
		return r->valor;
	} else if(r->valor->matricula < matricula) {
		return pesquisar(r->esquerda, matricula);
	} else {
		return pesquisar(r->direita, matricula);
	}
	/*
	if (r ==NULL)
        return 0;
    else if(r->info == info)
        return 1;
    else if (info < r->info)
        return pesquisar(r->esq, info);
    else
        return pesquisar(r->dir, info);
	*/
}

Node *inserir(Node *r, Aluno *a)
{
	if(a == NULL) {
		perror("Aluno nulo.");
		return r;
	}
	if(r == NULL) {
		r = (Node *) malloc(sizeof(Node));
        r->esquerda = r->direita = NULL;
        r->valor = a;
	} else {
		if(a->matricula < r->valor->matricula) {
			r->esquerda = inserir(r->esquerda, a);
		} else {
			r->direita = inserir(r->direita, a);
		}
	}

/*
	else
        {
        //Se a raiz não for nula e a informação for menor que a armazenada na raiz
        //vamos inserir na sub-arvore esquerda
        if (info < (*r)->info)
        {
            //Note que passamos o endereço do ponteiro para a subarvore esquerda pois
            //o método espera receber ponteiro para ponteiro
            inserir(&((*r)->esq), info);
        }
        //Se a raiz não for nula e a informação for maior que a armazenada na raiz
        //vamos inserir na sub-arvore direira
        else
        {
            inserir(&((*r)->dir), info);
        }
    }\
    */

    return r;
}

void print_em_ordem(Node *r)
{
	if(r != NULL) {
		print_em_ordem(r->esquerda);
		PRINT_ALUNO(r->valor);
		print_em_ordem(r->direita);
	}
	/*
	if(r != NULL){
        exibirEmOrdem(r->esq);
        printf("\n%d", r->info);
        exibirEmOrdem(r->dir);
    }
    */
}
