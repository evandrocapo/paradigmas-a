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

TAlunos *lst_cria_alunos(void); // cria lista NULL
TProfessores *lst_cria_professores(void); // cria lista NULL
TDisciplinas *lst_cria_disciplinas(void); // cria lista NULL

TAlunos *lst_insere_alunos(TAlunos *l, char nome[50]); // insere aluno na lista TAlunos e retorna.
TProfessores *lst_insere_professores(TProfessores *l, char nome[50]); // insere professor na lista TProfessores e retorna.
TDisciplinas *lst_insere_disciplinas(TDisciplinas *l, char nome[50]); // insere disciplina na lista TDisciplinas e retorna.

TAlunos *lst_insere_alunos_na_disciplina_aux(TAlunos *l, char nome[50], int ra); // insere aluno na lista TAlunos e retorna na TAlunos da disciplina.
TProfessores *lst_insere_professores_na_disciplina_aux(TProfessores *l, char nome[50], int cod); // insere professor na lista TProfessores e retorna na TProfessores da disciplina.

void lst_imprime_alunos(TAlunos *l); // imprime todos os alunos.
void lst_imprime_professores(TProfessores *l); // imprime todos os professores.
void lst_imprime_disciplinas(TDisciplinas *l); // imprime todas as disciplinas.

void lst_remover_alunos(TAlunos *l, int info); // remove um aluno com o ra informado.
void lst_remover_professores(TProfessores *l, int info); // remove um professor do cod informado
void lst_remover_disciplinas(TDisciplinas *l, int info); // remove uma disciplina do cod informado..

TAlunos* lst_procura_alunos(TAlunos *l, int ra); // procura aluno e retorna o endereço da memoria do aluno.
TProfessores* lst_procura_professores(TProfessores *l, int cod); // procura professor e retorna o endereço da memoria do professor.
TDisciplinas* lst_procura_disciplinas(TDisciplinas *l, int cod); // procura disciplina e retorna o endereço da memoria do disciplina.

void lst_insere_alunos_na_disciplina(TAlunos *l, int ra[50], int quant_aluno, TDisciplinas *f, int cod_disc[50], int quant_disc); // insere alunos pelo ra nas disciplinas.
void lst_insere_professores_na_disciplina(TProfessores *l, int cod[50], int quant_professor, TDisciplinas *f, int cod_disc[50], int quant_disc); // insere professores pelo cod na disciplinas.

void lst_imprime_alunos_na_disciplina(TDisciplinas *l, int cod_dis); // imprime alunos de uma disciplina
void lst_imprime_professores_na_disciplina(TDisciplinas *l, int cod_dis); // imprime professores de uma disciplina

void lst_remover_alunos_disciplinas(TDisciplinas *l, int ra[50], int quantidade); // remove alunos de uma disciplina
void lst_remover_professores_disciplinas(TDisciplinas *l, int cod[50], int quantidade); // remove professores de uma disciplina

void menu(TAlunos *alunos, TProfessores *professores, TDisciplinas *disciplinas);

void cadastrarAluno(TAlunos *alunos);
void cadastrarProfessor(TProfessores *professores);
void cadastrarMateria(TDisciplinas *disciplinas);

void cancelarAluno(TAlunos *alunos);
void cancelarProfessor(TProfessores *professores);
void cancelarMateria(TDisciplinas *disciplinas);

void vincularAluno(TAlunos *alunos, TDisciplinas *disciplinas);
void vincularProfessor(TProfessores *professores, TDisciplinas *disciplinas);

void desvincularAluno(TAlunos *alunos, TDisciplinas *disciplinas);
void desvincularProfessor(TProfessores *professores, TDisciplinas *disciplinas);

int main()
{
    // char nome[50];
    // int ra_a[50];
    // int cod_a[50];
    // ra_a[0] = 20200001;
    // ra_a[1] = 20200002;
    // cod_a[0] = 20202000;
    TAlunos *alunos = lst_cria_alunos();
    TProfessores *professores = lst_cria_professores();
    TDisciplinas *disciplinas = lst_cria_disciplinas();

    menu(alunos, professores, disciplinas);

    // strcpy(nome, "Evandro");
    // alunos = lst_insere_alunos(alunos, nome);
    // strcpy(nome, "Agostinho");
    // alunos = lst_insere_alunos(alunos, nome);
    // strcpy(nome, "Felipe");
    // alunos = lst_insere_alunos(alunos, nome);
    // strcpy(nome, "Fernando");
    // alunos = lst_insere_alunos(alunos, nome);
    // strcpy(nome, "Shima");
    // professores = lst_insere_professores(professores, nome);
    // strcpy(nome, "Miro");
    // professores = lst_insere_professores(professores, nome);
    // strcpy(nome, "Calculo A");
    // disciplinas = lst_insere_disciplinas(disciplinas, nome);
    // strcpy(nome, "Paradigmas A");
    // disciplinas = lst_insere_disciplinas(disciplinas, nome);

    // lst_insere_alunos_na_disciplina(alunos,ra_a, 2, disciplinas, cod_a, 1);

    // lst_remover_alunos(alunos, 20200000);
    // lst_imprime_alunos(alunos);
    // lst_imprime_professores(professores);
    // lst_imprime_disciplinas(disciplinas);
    // lst_imprime_alunos_na_disciplina(disciplinas, cod_a[0]);

    return 0;
}

void menu(TAlunos *alunos, TProfessores *professores, TDisciplinas *disciplinas){
    int escolha, opcao;
    do{
        printf(" Escolha o que deseja fazer: \n");
        printf("1 - Cadastro\n");
        printf("2 - Cancelamento\n");
        printf("3 - Vincular\n");
        printf("4 - Desvincular");
        printf("5 - Sair\n");

        scanf("%d", &escolha);

        system("cls");

        switch (escolha){

        case 1:
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Materia\n");
            printf("4 - Voltar\n");

            scanf("%d\n", &opcao);

            switch (opcao){
                case 1:
                    cadastrarAluno(alunos);
                break;

                case 2:
                    cadastrarProfessor(professores);
                break;

                case 3:
                    cadastrarMateria(disciplinas);
                break;

                case 4:
                break;
            }
        break;

        case 2:
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Materia\n");
            printf("4 - Voltar\n");

            scanf("%d\n", &opcao);

            switch (opcao){

            case 1:
                cancelarAluno(alunos);
            break;

            case 2:
                cancelarProfessor(professores);
            break;

            case 3:
                cancelarMateria(disciplinas);
            break;

            case 4:
            break;
            }
        break;

        case 3:
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Voltar\n");

            scanf("%d\n", &opcao);

            switch (opcao){

            case 1:
                vincularAluno(alunos, disciplinas);
            break;

            case 2:
                vincularProfessor(professores, disciplinas);
            break;

            case 3:
            break;
            }
        break;

        case 4:
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Voltar\n");

            scanf("%d\n", &opcao);

            switch (opcao){

            case 1:
                desvincularAluno(alunos, disciplinas);
            break;

            case 2:
                desvincularProfessor(professores, disciplinas);
            break;

            case 3:
            break;
            }
        break;

        case 5:
            printf("Finalizando");
            break;
        }
    } while (escolha != 5);
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
    TProfessores *professor = lst_cria_professores();
    TDisciplinas *disciplina = lst_cria_disciplinas();
    char nome_professor[50];
    int ra_professor;

    int i, j;

    for(i = 0; i < quant_professor; i++){
        professor = lst_procura_professores(l, cod[i]);
        if(professor != NULL){
            for(j = 0; j < quant_disc; j++){
                disciplina = lst_procura_disciplinas(f, cod_disc[j]);
                if(disciplina != NULL){
                    strcpy(nome_professor,professor->nome);
                    ra_professor = professor->cod;
                    disciplina->professor = lst_insere_professores_na_disciplina_aux(disciplina->professor, nome_professor, ra_professor);
                }
                else{
                    printf("Disciplina com cod %d não encontrado", cod_disc[i]);
                }
            }
        }else{
            printf("Professor com RA %d não encontrado.", cod[i]);
        }
    }
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

void cadastrarAluno(TAlunos *alunos){
    char nome[50];
    scanf("%s",nome);
    alunos = lst_insere_alunos(alunos, nome);
}
void cadastrarProfessor(TProfessores *professores){
    char nome[50];
    scanf("%s",nome);
    professores = lst_insere_professores(professores, nome);
}
void cadastrarMateria(TDisciplinas *disciplinas){
    char nome[50];
    scanf("%s",nome);
    disciplinas = lst_insere_disciplinas(disciplinas, nome);
}

void cancelarAluno(TAlunos *alunos){
    int ra;
    printf("Digite o numero de RA\n");
    scanf("%d\n", &ra);
    lst_remover_alunos(alunos, ra);
}

void cancelarProfessor(TProfessores *professores){
    int cod;
    printf("Digite o numero de COD\n");
    scanf("%d\n", &cod);
    lst_remover_professores(professores, cod);
}
void cancelarMateria(TDisciplinas *disciplinas){
    int cod;
    printf("Digite o numero de COD\n");
    scanf("%d\n", &cod);
    lst_remover_disciplinas(disciplinas, cod);
}

void vincularAluno(TAlunos *alunos, TDisciplinas *disciplinas){}
void vincularProfessor(TProfessores *professores, TDisciplinas *disciplinas){}

void desvincularAluno(TAlunos *alunos, TDisciplinas *disciplinas){}
void desvincularProfessor(TProfessores *professores, TDisciplinas *disciplinas){}