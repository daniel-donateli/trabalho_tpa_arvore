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

/*
int menu(HashFechada *h1, HashFechada *h2)
{
	int quit = 0;
	int op, matricula, nota;
	char nome[50];
	Aluno *a;
				
	while(!quit) {
		print_menu();
		fflush(stdout);
		scanf("%d", &op);
		printf("\n");
		switch(op)
		{
			case 1:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                  Estatísticas                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("\nHash 1: \n");
				print_stats(h1);
				printf("\nHash 2: \n");
				print_stats(h2);
				break;
			case 2:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                     Buscar                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Matrícula: ");
				scanf("%d", &matricula);
				a = search_hashFechada_matricula(h1, matricula);
				if(a == remove_hashFechada(h2, matricula)) {
					if(a != NULL) PRINT_ALUNO(a);
				}
				else {
					printf("Aluno não encontrado\n");
				}
				break;
			case 3:
				printf("-------------------------------------------------------------------------------\n");
				printf("                                     Excluir                             \n");
				printf("-------------------------------------------------------------------------------\n");
				printf("Matrícula: ");
				scanf("%d", &matricula);
				a = remove_hashFechada(h1, matricula);
				if(a == remove_hashFechada(h2, matricula)) {
					if(a == NULL) printf("Aluno não encontrado\n");
					else {
						printf("Excluindo aluno: ");
						PRINT_ALUNO(a);
						free(a);
					}
				}
				else {
					printf("Erro ao excluir\n");
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
				insert_hashFechada(h1, a);
				insert_hashFechada(h2, a);
				break;
			case 0:
				printf("Salvando arquivos...\n");
				FILE *fp = fopen("hash_fechada1000.txt", "w");
				write_file(fp, h1);
				fclose(fp);
				fp = fopen("hash_fechada997.txt", "w");
				write_file(fp, h2);
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
*/