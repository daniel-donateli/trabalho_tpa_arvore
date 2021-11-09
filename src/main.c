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

	a = pesquisar(raiz, 3);
	if(a != NULL) PRINT_ALUNO(a);
	else{
		printf("NULO\n");	
	}
	//print_em_ordem(raiz);
	return 0;
}
