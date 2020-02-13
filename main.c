#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno typedef TAlunos;
struct professor typedef TProfessores;
struct disciplina typedef TDisciplinas;

int RA = 20200000;
int COD_PROF = 20200000;
int COD_DISC = 20200000;

void cadastrarAluno();
void cadastrarProfessores();
void cadastrarDisciplina();
TAlunos *lst_cria_alunos(void);
TProfessores *lst_cria_professores(void);
TDisciplinas *lst_cria_disciplinas(void);

struct aluno{
    char nome[50];
    int ra;
    struct aluno *prox;
} typedef TAlunos;

struct professor{
    char nome[50];
    int cod;
    struct professor *prox;
} typedef TProfessores;

struct disciplina{
    char nome[50];
    int cod;
    TAlunos alunos;
    TProfessores professor;
    struct disciplina *prox;
} typedef TDisciplinas;

int main(){
    TAlunos *alunos = lst_cria_alunos();
    TProfessores *professores = lst_cria_professores();
    TDisciplinas *disciplinas = lst_cria_disciplinas();

    cadastrarAluno(alunos);

    return 0;
}

/* funcao imprime */
void lst_imprime_alunos(TAlunos *alunos){
    TAlunos *p ;
    for(p = l; p!=NULL; p = p->prox){
        printf("nome = %d\n", p->nome);
        printf("ra = %d\n", p->ra);
    }
}

void lst_imprime_professores(TProfessores professores){
    TProfessores *p ;
    for(p = l; p!=NULL; p = p->prox){
        printf("nome = %d\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_disciplinas( disciplinas){
    TDisciplinas *p ;
    for(p = l; p!=NULL; p = p->prox){
        printf("nome = %d\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}


/* funcao de criacao: RETORNA uma lista vazia */
TAlunos *lst_cria_alunos(){
    return NULL;
}

TProfessores *lst_cria_professores(){
    return NULL;
}

TDisciplinas *lst_cria_disciplinas(){
    return NULL;
}

/* insercao no inicio: RETORNA a lista atualizada */
TAlunos *lst_insere_alunos(TAlunos *l, int i, char nome[50]) {
TAlunos *novo = (TAlunos *)malloc(sizeof(TAlunos));

strcpy(novo->nome,nome);
novo->ra = RA;
novo->prox = l;
RA = RA + 1;

return novo;
}

TProfessores *lst_insere_professores(TProfessores *l, int i, char nome[50]) {
TProfessores *novo = (TProfessores *)malloc(sizeof(TProfessores));

strcpy(novo->nome,nome);
novo->cod = COD_DISC;
novo->prox = l;
COD_DISC = COD_DISC + 1;

return novo;
}

TDisciplinas *lst_insere_professores(TDisciplinas *l, int i, char nome[50]) {
TDisciplinas *novo = (TDisciplinas *)malloc(sizeof(TDisciplinas));

strcpy(novo->nome,nome);
novo->cod = COD_PROF;
novo->prox = l;
COD_PROF = COD_PROF + 1;

return novo;
}