#include <aluno.h>
#include <arvore.h>
#include <arvoreAVL.h>
#include <file_reader.h>
#include <menu.h>

int main(int argc, char *argv[])
{
	/*
	Node *raiz;
	Aluno *a = NULL;
	init_arvore(&raiz);

	a = new_aluno(1, "Teste 1", 100);
	raiz = inserir(raiz, a);
	
	a = new_aluno(2, "Teste 2", 100);
	raiz = inserir(raiz, a);
	
	a = new_aluno(3, "Teste 3", 100);
	raiz = inserir(raiz, a);
	

	print_em_ordem(raiz);
	printf("Altura: %d\n", altura(raiz));
	printf("Quantidade de elementos: %d\n", num_elementos(raiz));
	*/

	
	Node_AVL *raiz_AVL;
	Aluno *a = NULL;
	init_arvore_AVL(&raiz_AVL);

	a = new_aluno(3, "Teste 3", 100);
	raiz_AVL = inserir_AVL(raiz_AVL, a);

	a = new_aluno(2, "Teste 2", 100);
	raiz_AVL = inserir_AVL(raiz_AVL, a);

	a = new_aluno(1, "Teste 1", 100);
	raiz_AVL = inserir_AVL(raiz_AVL, a);

	a = pesquisar_AVL(raiz_AVL, 3);

	PRINT_ALUNO(a);

	print_em_ordem_AVL(raiz_AVL);
	printf("Altura: %d\n", altura_AVL(raiz_AVL));
	printf("Quantidade de elementos: %d\n", num_elementos_AVL(raiz_AVL));
	

	return 0;
}
