#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"


int main(){

    int opcao, matricula;

    do {

        printf("\n--- SISTEMA ACADEMICO ---\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Buscar Aluno\n");
        printf("4. Remover Aluno\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAluno();
                break;
            case 3:
                printf("Informe Matricula: ");
                scanf("%d", &matricula);
                buscarAluno(matricula);
                break;
            case 4:
                printf("Informe Matricula: ");
                scanf("%d", &matricula);
                removerAluno(matricula);
                break;
            case 0:
                printf("Saindo");
                break;
            default:
                printf("Opcao invalida");
        }

    }while(opcao != 0);

    return 0;
}
