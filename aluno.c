#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

const char *ARQUIVO_DB = "alunos.bin";


void cadastrarAluno(){
    system("cls");
    struct Aluno a;
    FILE *file = fopen(ARQUIVO_DB, "ab");

    if (file == NULL){
        printf("Erro ao abrir arquivo.");
        return;
    }

    printf("Digite a matricula: ");
    scanf("%d", &a.matricula);
    getchar();
    printf("Digite nome: ");
    fgets(a.nome, 50, stdin);
    getchar();
    a.nome[strcspn(a.nome, "\n")] = 0;
    printf("Digite a nota: ");
    scanf("%f", &a.nota);

    fwrite(&a, sizeof(struct Aluno), 1, file);
    fclose(file);
    printf("Aluno cadastrado");
}


void listarAluno(){
    system("cls");
    struct Aluno a;
    FILE *file = fopen(ARQUIVO_DB, "rb");

    if (file == NULL){
        printf("Nenhum cadastro encontrado ou erro ao abrir o arquivo");
        return;
    }

    printf("---Lista de Alunos---\n");
    while(fread(&a, sizeof(struct Aluno), 1, file)) {
        printf("Matricula: %d | Nome: %s | Nota: %.2f\n", a.matricula, a.nome, a.nota);
    }
    fclose(file);
}

void buscarAluno(int id){
    system("cls");
    struct Aluno a;
    FILE *file = fopen(ARQUIVO_DB, "rb");
    int enco =0;

    if (file == NULL){
        printf("Falha ao ler arquivo");
        return;
    }

    while(fread(&a, sizeof(struct Aluno), 1, file)){
        if (a.matricula == id){
            printf("\n--- Aluno encontrado ---\n");
            printf("Nome: %s\nNota: %.2f\n", a.nome, a.nota);
            enco = 1;
            break;
        }
    }
    if (!enco){
        printf("Matricula %d nao encontrado.\n", id);
    }
    fclose(file);
}


void removerAluno(int id) {
    system("cls");
    struct Aluno a;
    FILE *file = fopen(ARQUIVO_DB, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    int encontrou = 0;

    if (file == NULL || temp == NULL) {
        printf("Erro\n");
        return;
    }


    while (fread(&a, sizeof(struct Aluno), 1, file)) {
        if (a.matricula == id) {
            encontrou = 1;
        } else {
            fwrite(&a, sizeof(struct Aluno), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove(ARQUIVO_DB);
    rename("temp.bin", ARQUIVO_DB);

    if (encontrou) 
        printf("Aluno removido com sucesso.\n");
    else 
        printf("Aluno nao encontrado.\n");
}

