#ifndef ALUNO_H
#define ALUNO_H


struct Aluno
{
    int matricula;
    char nome[50];
    float nota;
};


void cadastrarAluno();
void listarAluno();
void buscarAluno();
void removerAluno();

#endif