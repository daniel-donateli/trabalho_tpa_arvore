#include <arvore.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

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
		return pesquisar(r->direita, matricula);
	} else {
		return pesquisar(r->esquerda, matricula);
	}
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
    return r;
}

Node *remover(Node *r, int matricula)
{
	if (r == NULL)
        return NULL;
    else if (matricula < r->valor->matricula)
        r->esquerda = remover(r->esquerda, matricula);
    else if (matricula > r->valor->matricula)
        r->direita = remover(r->direita, matricula);
    else {
    	// Sem filhos
    	if (r->esquerda == NULL && r->direita == NULL) {
            free(r);
            r = NULL;
        }
        // Filho a direita
        else if (r->esquerda == NULL) {
            Node *d = r->direita;
            free(r);
            r = d;
        }
        // Filho a esquerda
        else if (r->direita == NULL) {
             Node *e = r->esquerda;
             free(r);
             r = e;
        }
        // 2 Filhos
        else {
            Node* e = r->esquerda;
            // Encontrar o maior elemento da subárvore esquerda
            while (e->direita != NULL) {
                e = e->direita;
            }
            // Trocar o maior elemento da esquerda com a raiz
            Aluno *aux = r->valor;
            r->valor = e->valor;
            e->valor = aux;
            //Agora chamo o método para remover a folha.
            r->esquerda = remover(r->esquerda, matricula);
         }
    }
    return r;
}

int altura(Node *r)
{
	if(r == NULL)
    	return 0;
    int hd = altura(r->direita);
    int he = altura(r->esquerda);
    return MAX(he, hd) + 1;
}

void print_em_ordem(Node *r)
{
	if(r != NULL) {
		print_em_ordem(r->esquerda);
		PRINT_ALUNO(r->valor);
		print_em_ordem(r->direita);
	}
}
