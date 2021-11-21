#pragma once

#include <stdio.h>

#include <arvore.h>
#include <arvoreAVL.h>

// A função fecha a stream quando termina de ser executada
void read_file(FILE *fp, Node **r, Node_AVL **r_AVL);

// A stream continua aberta depois que termina de escrever no arquivo
void write_file(FILE *fp, Node *r);

void write_file_AVL(FILE *fp, Node_AVL *r);
