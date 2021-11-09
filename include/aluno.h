#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno {
	int matricula;
	char nome[50];
	int nota;
} Aluno;

#define PRINT_ALUNO(aluno) do {\
			printf("{\n"); \
			printf("\tMatrícula: %d;\n", aluno->matricula); \
			printf("\tNome: %s;\n", aluno->nome); \
			printf("\tNota: %d;\n", aluno->nota); \
			printf("}\n");\
		} while(0)

static inline Aluno *new_aluno(int matricula, char nome[50], int nota)
{
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	a->matricula = matricula;
	strcpy_s(a->nome, 50, nome);
	a->nota = nota;
	return a;
}
