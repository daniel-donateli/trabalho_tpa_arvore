#include <locale.h>

#include <aluno.h>
#include <arvore.h>
#include <arvoreAVL.h>
#include <file_reader.h>
#include <menu.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	Node *arv_bin;
	Node_AVL *arv_avl;
	init_arvore(&arv_bin);
	init_arvore_AVL(&arv_avl);

	FILE *fp = fopen("dados.txt", "r");
	read_file(fp, &arv_bin, &arv_avl);

	/*
	printf("Árvore Binária:\n");
	print_em_ordem(arv_bin);
	printf("Altura: %d\n", altura(arv_bin));
	printf("Quantidade de elementos: %d\n", num_elementos(arv_bin));

	printf("Árvore AVL:\n");
	print_em_ordem_AVL(arv_avl);
	printf("Altura AVL: %d\n", altura_AVL(arv_avl));
	printf("Quantidade de elementos AVL: %d\n", num_elementos_AVL(arv_avl));
	*/

	return menu(arv_bin, arv_avl);
}
