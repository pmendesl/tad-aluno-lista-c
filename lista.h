#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct {
    Aluno *alunos;
    int tamanho;
    int capacidade;
} Lista;

void inicializarLista(Lista *lista, int capacidade);
void inserirAluno(Lista *lista, Aluno aluno);
void removerAluno(Lista *lista, int matricula);
void imprimirLista(Lista *lista);
int buscarAlunoPorRM(Lista l, int rm);
float calcularMedia(Lista l);

#endif
