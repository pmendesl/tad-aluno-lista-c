#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int rm;
    char nome[50];
    float nota;
} Aluno;

void alterarNota(Aluno *a, float novaNota);

#endif
