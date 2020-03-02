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

struct aluno
{
    char nome[50];
    int ra;
    struct aluno *prox;
} typedef TAlunos;

struct professor
{
    char nome[50];
    int cod;
    struct professor *prox;
} typedef TProfessores;

struct disciplina
{
    char nome[50];
    int cod;
    TAlunos *alunos;
    TProfessores *professor;
    struct disciplina *prox;
} typedef TDisciplinas;

TAlunos *lst_cria_alunos(void);
TProfessores *lst_cria_professores(void);
TDisciplinas *lst_cria_disciplinas(void);

TAlunos *lst_insere_alunos(TAlunos *l, char nome[50]);
TProfessores *lst_insere_professores(TProfessores *l, char nome[50]);
TDisciplinas *lst_insere_disciplinas(TDisciplinas *l, char nome[50]);

TAlunos *lst_insere_alunos_na_disciplina_aux(TAlunos *l, char nome[50], int ra);
TProfessores *lst_insere_professores_na_disciplina_aux(TProfessores *l, char nome[50], int cod);
TDisciplinas *lst_insere_disciplinas_na_disciplina_aux(TDisciplinas *l, char nome[50], int cod);

void lst_imprime_alunos(TAlunos *l);
void lst_imprime_professores(TProfessores *l);
void lst_imprime_disciplinas(TDisciplinas *l);

void lst_remover_alunos(TAlunos *l, int info);
void lst_remover_professores(TProfessores *l, int info);
void lst_remover_disciplinas(TDisciplinas *l, int info);

TAlunos* lst_procura_alunos(TAlunos *l, int ra);
TProfessores* lst_procura_professores(TProfessores *l, int cod);
TDisciplinas* lst_procura_disciplinas(TDisciplinas *l, int cod);


void lst_insere_alunos_na_disciplina(TAlunos *l, int ra[50], int quant_aluno, TDisciplinas *f, int cod_disc[50], int quant_disc);
void lst_insere_professores_na_disciplina(TProfessores *l, int cod[50], int quant_professor, TDisciplinas *f, int cod_disc[50], int quant_disc);

void lst_imprime_alunos_na_disciplina(TDisciplinas *l, int cod_dis);
void lst_imprime_professores_na_disciplina(TDisciplinas *l, int cod_dis);
void lst_remover_alunos_disciplinas(TDisciplinas *l, int ra[50], int quantidade);
void lst_remover_professores_disciplinas(TDisciplinas *l, int cod[50], int quantidade);

int main()
{
    char nome[50];
    TAlunos *alunos = lst_cria_alunos();
    TProfessores *professores = lst_cria_professores();
    TDisciplinas *disciplinas = lst_cria_disciplinas();

    strcpy(nome, "Evandro");
    alunos = lst_insere_alunos(alunos, nome);
    strcpy(nome, "Agostinho");
    alunos = lst_insere_alunos(alunos, nome);
    strcpy(nome, "Felipe");
    alunos = lst_insere_alunos(alunos, nome);
    strcpy(nome, "Fernando");
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
    lst_imprime_alunos_na_disciplina(disciplinas, 20202000);

    return 0;
}

/* funcao imprime */
void lst_imprime_alunos(TAlunos *l){
    TAlunos *p;
    if (l == NULL)
    {
        printf("Nenhum aluno cadastrado na materia.");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("ra = %d\n", p->ra);
    }
}

void lst_imprime_professores(TProfessores *l){
    TProfessores *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_disciplinas(TDisciplinas *l){
    TDisciplinas *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_alunos_na_disciplina(TDisciplinas *l, int cod_dis){
    TDisciplinas *p;
    TAlunos *f;
    for (p = l; p != NULL && p->cod != cod_dis; p = p->prox)
    {
    }
    if (p != NULL)
    {
        if (p->cod == cod_dis)
        {
            f = p->alunos;
            printf("Disciplina: %s\n", p->nome);
            lst_imprime_alunos(f);
        }
    }
    else
    {
        printf("Disciplina não encontrada");
    }
}

void lst_imprime_professores_na_disciplina(TDisciplinas *l, int cod_dis){
    TDisciplinas *p;
    TProfessores *f;
    for (p = l; p != NULL && p->cod != cod_dis; p = p->prox)
    {
    }
    if (p != NULL)
    {
        if (p->cod == cod_dis)
        {
            f = p->professor;
            printf("Disciplina: %s\n", p->nome);
            lst_imprime_professores(f);
        }
    }
    else
    {
        printf("Disciplina não encontrada");
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
TAlunos *lst_insere_alunos(TAlunos *l, char nome[50]){
    TAlunos *novo = (TAlunos *)malloc(sizeof(TAlunos));

    strcpy(novo->nome, nome);
    novo->ra = RA;
    novo->prox = l;
    RA = RA + 1;

    return novo;
}

TAlunos *lst_insere_alunos_na_disciplina_aux(TAlunos *l, char nome[50], int ra){
    TAlunos *novo = (TAlunos *)malloc(sizeof(TAlunos));

    strcpy(novo->nome, nome);
    novo->ra = ra;
    novo->prox = l;

    return novo;
}

TProfessores *lst_insere_professores(TProfessores *l, char nome[50]){
    TProfessores *novo = (TProfessores *)malloc(sizeof(TProfessores));

    strcpy(novo->nome, nome);
    novo->cod = COD_PROF;
    novo->prox = l;
    COD_PROF = COD_PROF + 1;

    return novo;
}

TProfessores *lst_insere_professores_na_disciplina_aux(TProfessores *l, char nome[50], int cod){
    TProfessores *novo = (TProfessores *)malloc(sizeof(TProfessores));

    strcpy(novo->nome, nome);
    novo->cod = cod;
    novo->prox = l;

    return novo;
}

TDisciplinas *lst_insere_disciplinas(TDisciplinas *l, char nome[50]){
    TDisciplinas *novo = (TDisciplinas *)malloc(sizeof(TDisciplinas));
    TAlunos *alunos;
    TProfessores *professor;

    strcpy(novo->nome, nome);
    novo->cod = COD_DISC;
    novo->prox = l;
    // *alunos = novo->alunos;
    // alunos = lst_cria_alunos();
    // *professor = novo->professor;
    // professor = lst_cria_professores();
    COD_DISC = COD_DISC + 1;

    return novo;
}

TDisciplinas *lst_insere_disciplinas_na_disciplina_aux(TDisciplinas *l, char nome[50], int cod){
    TDisciplinas *novo = (TDisciplinas *)malloc(sizeof(TDisciplinas));
    TAlunos *alunos;
    TProfessores *professor;

    strcpy(novo->nome, nome);
    novo->cod = cod;
    novo->prox = l;

    return novo;
}

/* remoção: remove no da lista com a info informada */
void lst_remover_alunos(TAlunos *l, int info){
    TAlunos *a;
    TAlunos *p = l;

    while (p != NULL && p->ra != info)
    {
        a = p;
        p = p->prox;
    }
    if (p != NULL)
    {
        if (p->ra == info)
        {
            if (a == NULL)
            {
                l = p->prox;
            }
            else
            {
                a->prox = p->prox;
            }
            free(p);
        }
    }
}

void lst_remover_professores(TProfessores *l, int info){
    TProfessores *a;
    TProfessores *p = l;

    while (p != NULL && p->cod != info)
    {
        a = p;
        p = p->prox;
    }
    if (p != NULL)
    {
        if (p->cod == info)
        {
            if (a == NULL)
            {
                l = p->prox;
            }
            else
            {
                a->prox = p->prox;
            }
            free(p);
        }
    }
}

void lst_remover_disciplinas(TDisciplinas *l, int info){
    TDisciplinas *a;
    TDisciplinas *p = l;

    while (p != NULL && p->cod != info)
    {
        a = p;
        p = p->prox;
    }
    if (p != NULL)
    {
        if (p->cod == info)
        {
            if (a == NULL)
            {
                l = p->prox;
            }
            else
            {
                a->prox = p->prox;
            }
            free(p);
        }
    }
}

/* adição na disciplinas: adiciona alunos e professores dentro da disciplinas informadas*/

void lst_insere_alunos_na_disciplina(TAlunos *l, int ra[50], int quant_aluno, TDisciplinas *f, int cod_disc[50], int quant_disc){
    TAlunos *aluno = lst_cria_alunos();
    TDisciplinas *disciplina = lst_cria_disciplinas();
    char nome_aluno[50];
    int ra_aluno;

    int i, j;

    for(i = 0; i < quant_aluno; i++){
        aluno = lst_procura_alunos(l, ra[i]);
        if(aluno != NULL){
            for(j = 0; j < quant_disc; j++){
                disciplina = lst_procura_disciplinas(f, cod_disc[j]);
                if(disciplina != NULL){
                    strcpy(nome_aluno,aluno->nome);
                    ra_aluno = aluno->ra;
                    disciplina->alunos = lst_insere_alunos_na_disciplina_aux(disciplina->alunos, nome_aluno, ra_aluno);
                }
                else{
                    printf("Disciplina com cod %d não encontrado", cod_disc[i]);
                }
            }
        }else{
            printf("Aluno com RA %d não encontrado.", ra[i]);
        }
    }
}

void lst_insere_professores_na_disciplina(TProfessores *l, int cod[50], int quant_professor, TDisciplinas *f, int cod_disc[50], int quant_disc){
    
}

/* remoção na disciplina: remove no da lista dentro da disciplona com as infos informada */

void lst_remover_alunos_disciplinas(TDisciplinas *l, int ra[50], int quantidade){
    TAlunos *p = l->alunos;
    int i;

    for (i = 0; i < quantidade; i++)
    {
        lst_remover_alunos(p, ra[i]);
    }

    printf("Alunos removidos com sucesso !");
}

void lst_remover_professores_disciplinas(TDisciplinas *l, int cod[50], int quantidade){
    TProfessores *p = l->professor;
    int i;

    for (i = 0; i < quantidade; i++)
    {
        lst_remover_professores(p, cod[i]);
    }

    printf("Professores removidos com sucesso !");
}

/* procurar na lista: procura na lista com a informação informada */

TAlunos* lst_procura_alunos(TAlunos *l, int ra){
    TAlunos *p;
    if (l == NULL)
    {
        printf("Nenhum aluno encontrado.");
        return NULL;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if(p->ra == ra){
            return p;
        }
    }

    return NULL;
}

TProfessores* lst_procura_professores(TProfessores *l, int cod){
    TProfessores *p;
    if (l == NULL)
    {
        printf("Nenhum professor encontrado.");
        return NULL;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if(p->cod == cod){
            return p;
        }
    }

    return NULL;
}

TDisciplinas* lst_procura_disciplinas(TDisciplinas *l, int cod){
    TDisciplinas *p;
    if (l == NULL)
    {
        printf("Nenhuma disciplina encontrada.");
        return NULL;;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if(p->cod == cod){
            return p;
        }
    }

    return NULL;
}