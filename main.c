#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[50];
    int ra;
} TAluno;

typedef struct professor{
    char nome[50];
    int cod;
} TProfessor;

typedef struct disciplina
{
    char nome[50];
    int cod;
    TAluno alunos;
    TProfessor professor;
} TDisciplina;

typedef struct listaAluno{
    TAluno aluno;

    TAluno *prox;
} noAluno;

typedef struct listaProfessor{
    TProfessor professor;

    TProfessor *prox;
} noProfessor;

typedef struct listaDisciplina{
    TDisciplina disciplina;

    TDisciplina *prox;
} noDisciplina;

void cadastrarAluno();
void cadastrarDisciplina();
void cadastrarProfessores();

int main(){
    noAluno alunos;
    noProfessor professores;
    noDisciplina disciplinas;

    cadastrarAluno(alunos);

    return 0;
}

void cadastrarAluno(noAluno *alunos){

}

void cadastrarProfessores(noProfessor professores){

}

void cadastrarDisciplina(noDisciplina disciplinas){

}