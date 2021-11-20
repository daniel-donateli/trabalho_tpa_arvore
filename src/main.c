#include <aluno.h>
#include <arvore.h>
#include <file_reader.h>
#include <menu.h>

int main(int argc, char *argv[])
{
	Node *raiz;
	Aluno *a = NULL;
	init_arvore(&raiz);

	a = new_aluno(1, "Teste 1", 100);
	raiz = inserir(raiz, a);
	
	a = new_aluno(2, "Teste 2", 100);
	raiz = inserir(raiz, a);
	
	a = new_aluno(3, "Teste 3", 100);
	raiz = inserir(raiz, a);
	
	//print_em_ordem(raiz);

	//raiz = remover(raiz, 1);

	print_em_ordem(raiz);
	printf("Altura: %d\n", altura(raiz));
	return 0;
}
