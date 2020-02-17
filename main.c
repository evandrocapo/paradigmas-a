#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno typedef TAlunos;
struct professor typedef TProfessores;
struct disciplina typedef TDisciplinas;

int RA = 20200000;
int COD_PROF = 20201000;
int COD_DISC = 20202000;

struct aluno {
    char nome[50];
    int ra;
    struct aluno* prox;
} typedef TAlunos;

struct professor {
    char nome[50];
    int cod;
    struct professor* prox;
} typedef TProfessores;

struct disciplina {
    char nome[50];
    int cod;
    TAlunos alunos;
    TProfessores professor;
    struct disciplina* prox;
} typedef TDisciplinas;

TAlunos* lst_insere_alunos(TAlunos* l, char nome[50]);
TProfessores* lst_insere_professores(TProfessores* l, char nome[50]);
TDisciplinas* lst_insere_disciplinas(TDisciplinas* l, char nome[50]);
TAlunos* lst_cria_alunos(void);
TProfessores* lst_cria_professores(void);
TDisciplinas* lst_cria_disciplinas(void);
void lst_imprime_alunos(TAlunos* l);
void lst_imprime_professores(TProfessores* l);
void lst_imprime_disciplinas(TDisciplinas* l);
void lst_remover_alunos(TAlunos* l, int info);
void lst_remover_professores(TProfessores* l, int info);
void lst_remover_disciplinas(TDisciplinas* l, int info);


int main() {
    char nome[50];
    TAlunos* alunos = lst_cria_alunos();
    TProfessores* professores = lst_cria_professores();
    TDisciplinas* disciplinas = lst_cria_disciplinas();

    strcpy(nome, "Evandro");
    alunos = lst_insere_alunos(alunos, nome);
    strcpy(nome, "Agostinho");
    alunos = lst_insere_alunos(alunos, nome);
    strcpy(nome, "Shima");
    professores = lst_insere_professores(professores, nome);
    strcpy(nome, "Miro");
    professores = lst_insere_professores(professores, nome);
    strcpy(nome, "Calculo A");
    disciplinas = lst_insere_disciplinas(disciplinas, nome);
    strcpy(nome, "Paradigmas A");
    disciplinas = lst_insere_disciplinas(disciplinas, nome);
    lst_remover_alunos(alunos, 20200000);
    lst_imprime_alunos(alunos);
    lst_imprime_professores(professores);
    lst_imprime_disciplinas(disciplinas);

    return 0;
}

/* funcao imprime */
void lst_imprime_alunos(TAlunos* l) {
    TAlunos* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("nome = %s\n", p->nome);
        printf("ra = %d\n", p->ra);
    }
}

void lst_imprime_professores(TProfessores* l) {
    TProfessores* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_disciplinas(TDisciplinas* l) {
    TDisciplinas* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}


/* funcao de criacao: RETORNA uma lista vazia */
TAlunos* lst_cria_alunos() {
    return NULL;
}

TProfessores* lst_cria_professores() {
    return NULL;
}

TDisciplinas* lst_cria_disciplinas() {
    return NULL;
}

/* insercao no inicio: RETORNA a lista atualizada */
TAlunos* lst_insere_alunos(TAlunos* l, char nome[50]) {
    TAlunos* novo = (TAlunos*)malloc(sizeof(TAlunos));

    strcpy(novo->nome, nome);
    novo->ra = RA;
    novo->prox = l;
    RA = RA + 1;

    return novo;
}

TProfessores* lst_insere_professores(TProfessores* l, char nome[50]) {
    TProfessores* novo = (TProfessores*)malloc(sizeof(TProfessores));

    strcpy(novo->nome, nome);
    novo->cod = COD_DISC;
    novo->prox = l;
    COD_DISC = COD_DISC + 1;

    return novo;
}

TDisciplinas* lst_insere_disciplinas(TDisciplinas* l, char nome[50]) {
    TDisciplinas* novo = (TDisciplinas*)malloc(sizeof(TDisciplinas));

    strcpy(novo->nome, nome);
    novo->cod = COD_PROF;
    novo->prox = l;
    COD_PROF = COD_PROF + 1;

    return novo;
}

/* remoção: remove no da lista com a info informada */
void lst_remover_alunos(TAlunos* l, int info){
    TAlunos *a;
    TAlunos *p = l;

    while(p != NULL && p->ra != info){
        a = p;
        p = p->prox;
    }
    if(p != NULL){
        if(p->ra == info){
            if(a == NULL){
                l = p->prox;
            }
            else{
                a->prox = p->prox;
            }
            free(p);
        }
    }
}

void lst_remover_professores(TProfessores* l, int info){
    TProfessores *a;
    TProfessores *p = l;

    while(p != NULL && p->cod != info){
        a = p;
        p = p->prox;
    }
    if(p != NULL){
        if(p->cod == info){
            if(a == NULL){
                l = p->prox;
            }
            else{
                a->prox = p->prox;
            }
            free(p);
        }
    }
}

void lst_remover_disciplinas(TDisciplinas* l, int info){
    TDisciplinas *a;
    TDisciplinas *p = l;

    while(p != NULL && p->cod != info){
        a = p;
        p = p->prox;
    }
    if(p != NULL){
        if(p->cod == info){
            if(a == NULL){
                l = p->prox;
            }
            else{
                a->prox = p->prox;
            }
            free(p);
        }
    }
}