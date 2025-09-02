#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "lista.h"

int main() {
    Lista minhaLista;
    inicializarLista(&minhaLista, 10);

    // Teste de inserção e impressão
    Aluno a1 = {101, "Alice", 8.5};
    Aluno a2 = {102, "Bruno", 7.0};
    Aluno a3 = {103, "Carla", 9.2};

    inserirAluno(&minhaLista, a1);
    inserirAluno(&minhaLista, a2);
    inserirAluno(&minhaLista, a3);

    printf("\n--- Lista Inicial ---\n");
    imprimirLista(&minhaLista);

    // Teste Exercício 1 - Alterar Nota
    printf("\n--- Teste Alterar Nota ---\n");
    printf("Nota de Alice antes: %.2f\n", minhaLista.alunos[0].nota);
    alterarNota(&minhaLista.alunos[0], 9.0);
    printf("Nota de Alice depois: %.2f\n", minhaLista.alunos[0].nota);

    // Teste Exercício 2 - Remover Último
    printf("\n--- Teste Remover Último ---\n");
    printf("Tamanho da lista antes de remover: %d\n", minhaLista.tamanho);
    removerUltimo(&minhaLista);
    printf("Tamanho da lista depois de remover: %d\n", minhaLista.tamanho);
    printf("Lista após remoção:\n");
    imprimirLista(&minhaLista);

    // Teste Exercício 3 - Buscar Aluno por RM
    printf("\n--- Teste Buscar Aluno por RM ---\n");
    int rm_existente = 102;
    int rm_inexistente = 999;
    int pos_existente = buscarAlunoPorRM(minhaLista, rm_existente);
    int pos_inexistente = buscarAlunoPorRM(minhaLista, rm_inexistente);

    if (pos_existente != -1) {
        printf("Aluno com RM %d encontrado na posição %d (Nome: %s)\n", rm_existente, pos_existente, minhaLista.alunos[pos_existente].nome);
    } else {
        printf("Aluno com RM %d não encontrado.\n", rm_existente);
    }

    if (pos_inexistente != -1) {
        printf("Aluno com RM %d encontrado na posição %d (Nome: %s)\n", rm_inexistente, pos_inexistente, minhaLista.alunos[pos_inexistente].nome);
    } else {
        printf("Aluno com RM %d não encontrado.\n", rm_inexistente);
    }

    // Teste Exercício 4 - Calcular Média
    printf("\n--- Teste Calcular Média ---\n");
    float media = calcularMedia(minhaLista);
    printf("Média das notas na lista: %.2f\n", media);

    // Liberar memória alocada
    free(minhaLista.alunos);

    return 0;
}
