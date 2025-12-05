# Sistema Acadêmico em C

Projeto desenvolvido como trabalho semestral da disciplina de **Algoritmos**, utilizando a linguagem C e manipulação de arquivos binários.

O sistema permite:

- Cadastrar alunos (matrícula, nome e nota)
- Listar todos os alunos cadastrados
- Buscar aluno pela matrícula
- Remover aluno pela matrícula

## Tecnologias utilizadas

- Linguagem C
- Manipulação de arquivos binários (`FILE`, `fopen`, `fread`, `fwrite`, etc.)
- Organização em múltiplos arquivos (`.c` e `.h`)

## Estrutura do projeto

```text
main.c      # Função principal, menu do sistema
aluno.c     # Implementação das operações sobre alunos
aluno.h     # Declaração da struct Aluno e das funções
