#include <stdlib.h>
#include <stdio.h>

#include <menu.h>

static inline void print_menu()
{
	fflush(stdout);
	printf("-------------------------------------------------------------------------------\n");
	printf("                                 Menu Principal                                \n");
	printf("-------------------------------------------------------------------------------\n");
	printf("| 1 - Exibir estatísticas                                                     |\n");
	printf("| 2 - Efetuar busca por matrícula                                             |\n");
	printf("| 3 - Excluir por matrícula                                                   |\n");
	printf("| 4 - Incluir aluno                                                            |\n");
	printf("| 0 - Sair                                                                     |\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("Opção: ");
}


int menu(Node *arv_bin, Node_AVL *arv_avl)
{
	int quit = 0;
	int op, matricula, nota;
	char nome[50];
	Aluno *a;
				
	while(!quit) {
		print_menu();
		fflush(stdout);
		scanf("%d", &op);
		getc(stdin);
		printf("\n");
		switch(op)
		{
			case 1:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                  Estatísticas                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Altura árvore binária: %d\n", altura(arv_bin));
				printf("Quantidade de elementos árvore binária: %d\n", num_elementos(arv_bin));
				printf("Altura árvore AVL: %d\n", altura_AVL(arv_avl));
				printf("Quantidade de elementos árvore AVL: %d\n", num_elementos_AVL(arv_avl));
				break;
			case 2:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                     Buscar                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Matrícula: ");
				fflush(stdout);
				scanf("%d", &matricula);
				getc(stdin);
				a = NULL;
				a = pesquisar(arv_bin, matricula);
				if(a == pesquisar_AVL(arv_avl, matricula)) {
					if(a != NULL)
						PRINT_ALUNO(a);
					else printf("Aluno não encontrado\n");
				}
				break;
			case 3:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                     Excluir                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Matrícula: ");
				fflush(stdout);
				scanf("%d", &matricula);
				getc(stdin);
				a = NULL;
				a = pesquisar(arv_bin, matricula);
				arv_bin = remover(arv_bin, matricula);
				if(a == NULL) 
					printf("Aluno não encontrado\n");
				else {
					printf("Excluindo aluno: ");
					PRINT_ALUNO(a);
					free(a);
				}
				break;
			case 4:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                     Inserir                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Matrícula: ");
				fflush(stdout);
				scanf("%d", &matricula);
				getc(stdin); // Remover '\n' do stdout

				printf("\nNome: ");
				fflush(stdout);
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = 0; //Remover '\n' da string

				printf("\nNota: ");
				fflush(stdout);
				scanf("%d", &nota);
				getc(stdin); // Remover '\n' do stdout
				printf("\n");

				// Inserir
				a = new_aluno(matricula, nome, nota);
				arv_bin = inserir(arv_bin, a);
				arv_avl = inserir_AVL(arv_avl, a);
				break;
			case 0:
				printf("Salvando arquivos...\n");
				FILE *fp = fopen("arvore_binaria.txt", "w");
				write_file(fp, arv_bin);
				fclose(fp);
				fp = fopen("arvore_avl.txt", "w");
				write_file_AVL(fp, arv_avl);
				fclose(fp);
				printf("Arquivos salvos.");
				quit = 1;
				break;
			default:
				printf("Opção inválida\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}
