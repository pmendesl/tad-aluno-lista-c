#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"

void inicializarLista(Lista *lista, int capacidade) {
    lista->alunos = (Aluno*) malloc(capacidade * sizeof(Aluno));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void inserirAluno(Lista *lista, Aluno aluno) {
    if (lista->tamanho < lista->capacidade) {
        lista->alunos[lista->tamanho] = aluno;
        lista->tamanho++;
    } else {
        printf("Lista cheia! Nao foi possivel inserir o aluno.\n");
    }
}

void removerAluno(Lista *lista, int matricula) {
    int i, j;
    int encontrado = 0;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->alunos[i].rm == matricula) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        for (j = i; j < lista->tamanho - 1; j++) {
            lista->alunos[j] = lista->alunos[j+1];
        }
        lista->tamanho--;
        printf("Aluno com RM %d removido com sucesso.\n", matricula);
    } else {
        printf("Aluno com RM %d nao encontrado na lista.\n", matricula);
    }
}

void imprimirLista(Lista *lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho; i++) {
        printf("RM: %d, Nome: %s, Nota: %.2f\n", lista->alunos[i].rm, lista->alunos[i].nome, lista->alunos[i].nota);
    }
}

void removerUltimo(Lista *l) {
    if (l->tamanho > 0) {
        l->tamanho--;
        printf("Ultimo aluno removido da lista.\n");
    } else {
        printf("Lista vazia, nao ha alunos para remover.\n");
    }
}

int buscarAlunoPorRM(Lista l, int rm) {
    for (int i = 0; i < l.tamanho; i++) {
        if (l.alunos[i].rm == rm) return i;
    }
    return -1;
}

float calcularMedia(Lista l) {
    float soma = 0;
    for (int i = 0; i < l.tamanho; i++) {
        soma += l.alunos[i].nota;
    }
    return (l.tamanho > 0) ? soma / l.tamanho : 0;
}
