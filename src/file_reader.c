#include <stdio.h>
#include <stdlib.h>

#include <file_reader.h>

void read_file(FILE *fp, Node **r, Node_AVL **r_AVL)
{
	if(fp == NULL) perror("Não foi possível abrir o arquivo.");
	int i;
	char *token;
	char linha[256];
	int qtd = atoi(fgets(linha, 256, fp));
	char nome[50];
	int matricula;
	int nota;
	printf("Lendo arquivo...\n");
	fflush(stdout);
	for(i=0; i<qtd; i++) {
		printf("%d/%d\n", i, qtd);
		fflush(stdout);
		fgets(linha, 256, fp);
		token = strtok(linha, ";");
		matricula = atoi(token);
		token = strtok(NULL, ";");
		strcpy(nome, token);
		token = strtok(NULL, ";");
		nota = atoi(token);
		Aluno *a = new_aluno(matricula, nome, nota);
		*r = inserir(*r, a);
		*r_AVL = inserir_AVL(*r_AVL, a);
	}
	printf("\nLeitura finalizada.\n");
	fclose(fp);
}

void write_file(FILE *fp, Node *r)
{
	if(r != NULL) {
		write_file(fp, r->esquerda);
		fprintf(fp, "%d;%s;%d\n", r->valor->matricula, r->valor->nome, r->valor->nota);
		write_file(fp, r->direita);
	}
}

void write_file_AVL(FILE *fp, Node_AVL *r)
{
	if(r != NULL) {
		write_file_AVL(fp, r->esquerda);
		fprintf(fp, "%d;%s;%d\n", r->valor->matricula, r->valor->nome, r->valor->nota);
		write_file_AVL(fp, r->direita);
	}
}
