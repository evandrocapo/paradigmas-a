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
    struct aluno* prox;
} typedef TAlunos;

struct professor
{
    char nome[50];
    int cod;
    struct professor* prox;
} typedef TProfessores;

struct disciplina
{
    char nome[50];
    int cod;
    TAlunos* alunos;
    TProfessores* professor;
    struct disciplina* prox;
} typedef TDisciplinas;

TAlunos* lst_cria_alunos(void);           // cria lista NULL
TProfessores* lst_cria_professores(void); // cria lista NULL
TDisciplinas* lst_cria_disciplinas(void); // cria lista NULL

TAlunos* lst_insere_alunos(TAlunos* l, char nome[50]);                // insere aluno na lista TAlunos e retorna.
TProfessores* lst_insere_professores(TProfessores* l, char nome[50]); // insere professor na lista TProfessores e retorna.
TDisciplinas* lst_insere_disciplinas(TDisciplinas* l, char nome[50]); // insere disciplina na lista TDisciplinas e retorna.

TAlunos* lst_insere_alunos_na_disciplina_aux(TAlunos* l, char nome[50], int ra);                 // insere aluno na lista TAlunos e retorna na TAlunos da disciplina.
TProfessores* lst_insere_professores_na_disciplina_aux(TProfessores* l, char nome[50], int cod); // insere professor na lista TProfessores e retorna na TProfessores da disciplina.

void lst_imprime_alunos(TAlunos* l);           // imprime todos os alunos.
void lst_imprime_professores(TProfessores* l); // imprime todos os professores.
void lst_imprime_disciplinas(TDisciplinas* l); // imprime todas as disciplinas.

TAlunos* lst_remover_alunos(TAlunos* l, int info);           // remove um aluno com o ra informado.
TProfessores* lst_remover_professores(TProfessores* l, int info); // remove um professor do cod informado
TDisciplinas* lst_remover_disciplinas(TDisciplinas* l, int info); // remove uma disciplina do cod informado..

TAlunos* lst_procura_alunos(TAlunos* l, int ra);                 // procura aluno e retorna o endereço da memoria do aluno.
TProfessores* lst_procura_professores(TProfessores* l, int cod); // procura professor e retorna o endereço da memoria do professor.
TDisciplinas* lst_procura_disciplinas(TDisciplinas* l, int cod); // procura disciplina e retorna o endereço da memoria do disciplina.

void lst_insere_alunos_na_disciplina(TAlunos* l, int ra[50], int quant_aluno, TDisciplinas* f, int cod_disc[50], int quant_disc);                // insere alunos pelo ra nas disciplinas.
void lst_insere_professores_na_disciplina(TProfessores* l, int cod[50], int quant_professor, TDisciplinas* f, int cod_disc[50], int quant_disc); // insere professores pelo cod na disciplinas.

void lst_imprime_alunos_na_disciplina(TDisciplinas* l, int cod_dis);      // imprime alunos de uma disciplina
void lst_imprime_professores_na_disciplina(TDisciplinas* l, int cod_dis); // imprime professores de uma disciplina

void lst_remover_alunos_disciplinas(TDisciplinas* l, int ra, int quantidade);       // remove alunos pelo ra nas disciplinas
void lst_remover_professores_disciplinas(TDisciplinas* l, int cod, int quantidade); // remove professores pelo cod nas disciplinas

int menu(TAlunos* alunos, TProfessores* professores, TDisciplinas* disciplinas);

TAlunos* cadastrarAluno(TAlunos* alunos);
TProfessores* cadastrarProfessor(TProfessores* professores);
TDisciplinas* cadastrarMateria(TDisciplinas* disciplinas);

TAlunos* cancelarAluno(TAlunos* alunos);
TProfessores* cancelarProfessor(TProfessores* professores);
TDisciplinas* cancelarMateria(TDisciplinas* disciplinas);

void vincularAluno(TAlunos* alunos, TDisciplinas* disciplinas);
void vincularProfessor(TProfessores* professores, TDisciplinas* disciplinas);

void desvincularAluno(TAlunos* alunos, TDisciplinas* disciplinas);
void desvincularProfessor(TProfessores* professores, TDisciplinas* disciplinas);

int main(int argc, const char* argv[])
{
    // char nome[50];
    // int ra_a[50];
    // int cod_a[50];
    // ra_a[0] = 20200001;
    // ra_a[1] = 20200002;
    // cod_a[0] = 20202000;
    TAlunos* alunos = lst_cria_alunos();
    TProfessores* professores = lst_cria_professores();
    TDisciplinas* disciplinas = lst_cria_disciplinas();

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

int menu(TAlunos* alunos, TProfessores* professores, TDisciplinas* disciplinas)
{
    int escolha, opcao, opcao2;
    int lst_op;

    do
    {
        printf(" Escolha o que deseja fazer: \n");
        printf("0 - Listar cadastros\n");
        printf("1 - Cadastro\n");
        printf("2 - Cancelamento\n");
        printf("3 - Vincular\n");
        printf("4 - Desvincular\n");
        printf("5 - Sair\n");

        fflush(stdin);
        scanf("%d", &escolha);

        if (escolha == 5) {
            printf("Finalizando\n");
        }
        else if (escolha == 0) {
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Materia\n");
            printf("4 - Voltar\n");

            fflush(stdin);
            scanf("%d", &opcao);

            if (opcao == 1) {
                lst_imprime_alunos(alunos);
            }
            else if (opcao == 2) {
                lst_imprime_professores(professores);
            }
            else if (opcao == 3) {
                printf("1 - Disciplina\n");
                printf("2 - Alunos na disciplina\n");
                printf("3 - Professores na disciplina\n");
                printf("4 - Voltar\n");

                fflush(stdin);
                scanf("%d", &opcao2);

                if (opcao2 == 1) lst_imprime_disciplinas(disciplinas);
                else if (opcao2 == 2) {
                    printf("Digite o codigo da disciplina\n");
                    fflush(stdin);
                    scanf("%d", &lst_op);

                    lst_imprime_alunos_na_disciplina(disciplinas, lst_op);
                }
                else if (opcao2 == 3) {
                    printf("Digite o codigo da disciplina\n");
                    fflush(stdin);
                    scanf("%d", &lst_op);

                    lst_imprime_professores_na_disciplina(disciplinas, lst_op);
                }
                else {}
            }
            else {}
        }
        else if (escolha == 1) {
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Materia\n");
            printf("4 - Voltar\n");

            fflush(stdin);
            scanf("%d", &opcao);

            if (opcao == 1) {
                alunos = cadastrarAluno(alunos);
            }
            else if (opcao == 2) {
                professores = cadastrarProfessor(professores);
            }
            else if (opcao == 3) {
                disciplinas = cadastrarMateria(disciplinas);
            }
            else {}
        }
        else if (escolha == 2) {
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Materia\n");
            printf("4 - Voltar\n");

            fflush(stdin);
            scanf("%d", &opcao);

            if (opcao == 1) {
                alunos = cancelarAluno(alunos);
            }
            else if (opcao == 2) {
                professores = cancelarProfessor(professores);
            }
            else if (opcao == 3) {
                disciplinas = cancelarMateria(disciplinas);
            }
            else {}
        }
        else if (escolha == 3) {
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Voltar\n");

            fflush(stdin);
            scanf("%d", &opcao);

            if (opcao == 1) {
                vincularAluno(alunos, disciplinas);
            }
            else if (opcao == 2) {
                vincularProfessor(professores, disciplinas);
            }
            else {}
        }
        else if (escolha == 4) {
            printf("1 - Aluno\n");
            printf("2 - Professor\n");
            printf("3 - Voltar\n");

            fflush(stdin);
            scanf("%d", &opcao);

            if (opcao == 1) {
                desvincularAluno(alunos, disciplinas);
            }
            else if (opcao == 2) {
                desvincularProfessor(professores, disciplinas);
            }
            else {}
        }
        else {
            printf("Comando não encontrado");
        }
    } while (escolha != 5);

    return 0;
}

/* funcao imprime */
void lst_imprime_alunos(TAlunos* l)
{
    TAlunos* p;
    if (l == NULL)
    {
        printf("Nenhum aluno cadastrado.");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("ra = %d\n", p->ra);
    }
}

void lst_imprime_professores(TProfessores* l)
{
    TProfessores* p;
    if (l == NULL)
    {
        printf("Nenhum professor cadastrado.");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_disciplinas(TDisciplinas* l)
{
    TDisciplinas* p;
    if (l == NULL)
    {
        printf("Nenhuma disciplina cadastrada.");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        printf("nome = %s\n", p->nome);
        printf("cod = %d\n", p->cod);
    }
}

void lst_imprime_alunos_na_disciplina(TDisciplinas* l, int cod_dis)
{
    TDisciplinas* p;
    TAlunos* f;
    for (p = l; p != NULL && p->cod != cod_dis; p = p->prox)
    {
    }
    if (p != NULL)
    {
        if (p->cod == cod_dis)
        {
            f = p->alunos;
            if (f == NULL) {
                printf("Nenhuma aluno encontrado\n");
            }
            else{
            printf("Disciplina: %s\n", p->nome);
            lst_imprime_alunos(f);
            }
        }
    }
    else
    {
        printf("Disciplina não encontrada");
    }
}

void lst_imprime_professores_na_disciplina(TDisciplinas* l, int cod_dis)
{
    TDisciplinas* p;
    TProfessores* f;
    for (p = l; p != NULL && p->cod != cod_dis; p = p->prox)
    {
    }
    if (p != NULL)
    {
        if (p->cod == cod_dis)
        {
            f = p->professor;
            if (f == NULL) {
                printf("Nenhuma professor encontrado\n");
            }
            else{
            printf("Disciplina: %s\n", p->nome);
            lst_imprime_professores(f);
            }
        }
    }
    else
    {
        printf("Disciplina não encontrada");
    }
}

/* funcao de criacao: RETORNA uma lista vazia */
TAlunos* lst_cria_alunos()
{
    return NULL;
}

TProfessores* lst_cria_professores()
{
    return NULL;
}

TDisciplinas* lst_cria_disciplinas()
{
    return NULL;
}

/* insercao no inicio: RETORNA a lista atualizada */
TAlunos* lst_insere_alunos(TAlunos* l, char nome[50])
{
    TAlunos* novo = (TAlunos*)malloc(sizeof(TAlunos));

    strcpy(novo->nome, nome);
    novo->ra = RA;
    novo->prox = l;
    RA = RA + 1;

    return novo;
}

TAlunos* lst_insere_alunos_na_disciplina_aux(TAlunos* l, char nome[50], int ra)
{
    TAlunos* novo = (TAlunos*)malloc(sizeof(TAlunos));

    strcpy(novo->nome, nome);
    novo->ra = ra;
    novo->prox = l;

    return novo;
}

TProfessores* lst_insere_professores(TProfessores* l, char nome[50])
{
    TProfessores* novo = (TProfessores*)malloc(sizeof(TProfessores));

    strcpy(novo->nome, nome);
    novo->cod = COD_PROF;
    novo->prox = l;
    COD_PROF = COD_PROF + 1;

    return novo;
}

TProfessores* lst_insere_professores_na_disciplina_aux(TProfessores* l, char nome[50], int cod)
{
    TProfessores* novo = (TProfessores*)malloc(sizeof(TProfessores));

    strcpy(novo->nome, nome);
    novo->cod = cod;
    novo->prox = l;

    return novo;
}

TDisciplinas* lst_insere_disciplinas(TDisciplinas* l, char nome[50])
{
    TDisciplinas* novo = (TDisciplinas*)malloc(sizeof(TDisciplinas));
    TAlunos* alunos = NULL;
    TProfessores* professor = NULL;

    strcpy(novo->nome, nome);
    novo->cod = COD_DISC;
    novo->prox = l;
    novo->alunos = NULL;
    novo->professor = NULL;
    COD_DISC = COD_DISC + 1;

    return novo;
}

/* remoção: remove no da lista com a info informada */
TAlunos* lst_remover_alunos(TAlunos* l, int info)
{
    TAlunos* a = NULL;
    TAlunos* p = l;

    printf("entrei 1");
    while (p != NULL && p->ra != info)
    {
        printf("loop");
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
    printf("terminei");
    return a;
}

TProfessores* lst_remover_professores(TProfessores* l, int info)
{
    TProfessores* a = NULL;
    TProfessores* p = l;

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
    return a;
}

TDisciplinas* lst_remover_disciplinas(TDisciplinas* l, int info)
{
    TDisciplinas* a = NULL;
    TDisciplinas* p = l;

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
    return a;
}

/* adição na disciplinas: adiciona alunos e professores dentro da disciplinas informadas*/

void lst_insere_alunos_na_disciplina(TAlunos* l, int ra[50], int quant_aluno, TDisciplinas* f, int cod_disc[50], int quant_disc)
{
    TAlunos* aluno = lst_cria_alunos();
    TDisciplinas* disciplina = lst_cria_disciplinas();
    char nome_aluno[50];
    int ra_aluno;

    int i, j;

    for (i = 0; i < quant_aluno; i++)
    {
        aluno = lst_procura_alunos(l, ra[i]);
        if (aluno != NULL)
        {
            for (j = 0; j < quant_disc; j++)
            {
                disciplina = lst_procura_disciplinas(f, cod_disc[j]);
                if (disciplina != NULL)
                {
                    strcpy(nome_aluno, aluno->nome);
                    ra_aluno = aluno->ra;
                    disciplina->alunos = lst_insere_alunos_na_disciplina_aux(disciplina->alunos, nome_aluno, ra_aluno);
                }
                else
                {
                    printf("Disciplina com cod %d não encontrado", cod_disc[i]);
                }
            }
        }
        else
        {
            printf("Aluno com RA %d não encontrado.", ra[i]);
        }
    }
}

void lst_insere_professores_na_disciplina(TProfessores* l, int cod[50], int quant_professor, TDisciplinas* f, int cod_disc[50], int quant_disc)
{
    TProfessores* professor = lst_cria_professores();
    TDisciplinas* disciplina = lst_cria_disciplinas();
    char nome_professor[50];
    int ra_professor;

    int i, j;

    for (i = 0; i < quant_professor; i++)
    {
        professor = lst_procura_professores(l, cod[i]);
        if (professor != NULL)
        {
            for (j = 0; j < quant_disc; j++)
            {
                disciplina = lst_procura_disciplinas(f, cod_disc[j]);
                if (disciplina != NULL)
                {
                    strcpy(nome_professor, professor->nome);
                    ra_professor = professor->cod;
                    disciplina->professor = lst_insere_professores_na_disciplina_aux(disciplina->professor, nome_professor, ra_professor);
                }
                else
                {
                    printf("Disciplina com cod %d não encontrado", cod_disc[i]);
                }
            }
        }
        else
        {
            printf("Professor com RA %d não encontrado.", cod[i]);
        }
    }
}

/* remoção na disciplina: remove no da lista dentro da disciplona com as infos informada */

void lst_remover_alunos_disciplinas(TDisciplinas* l, int ra, int quantidade)
{
    TAlunos* p = l->alunos;

    lst_remover_alunos(p, ra);

    printf("Alunos removidos com sucesso !");
}

void lst_remover_professores_disciplinas(TDisciplinas* l, int cod, int quantidade)
{
    TProfessores* p = l->professor;

    lst_remover_professores(p, cod);

    printf("Professores removidos com sucesso !");
}

/* procurar na lista: procura na lista com a informação informada */

TAlunos* lst_procura_alunos(TAlunos* l, int ra)
{
    TAlunos* p;
    if (l == NULL)
    {
        printf("Nenhum aluno encontrado.");
        return NULL;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->ra == ra)
        {
            return p;
        }
    }

    return NULL;
}

TProfessores* lst_procura_professores(TProfessores* l, int cod)
{
    TProfessores* p;
    if (l == NULL)
    {
        printf("Nenhum professor encontrado.");
        return NULL;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->cod == cod)
        {
            return p;
        }
    }

    return NULL;
}

TDisciplinas* lst_procura_disciplinas(TDisciplinas* l, int cod)
{
    TDisciplinas* p;
    if (l == NULL)
    {
        printf("Nenhuma disciplina encontrada.");
        return NULL;
        ;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->cod == cod)
        {
            return p;
        }
    }

    return NULL;
}

TAlunos* cadastrarAluno(TAlunos* alunos)
{
    char nome[50];
    printf("Digite o nome do Aluno: ");
    fflush(stdin);
    scanf("%s", nome);
    return lst_insere_alunos(alunos, nome);
}
TProfessores* cadastrarProfessor(TProfessores* professores)
{
    char nome[50];
    printf("Digite o nome do Professor: ");
    fflush(stdin);
    scanf("%s", nome);
    return lst_insere_professores(professores, nome);
}
TDisciplinas* cadastrarMateria(TDisciplinas* disciplinas)
{
    char nome[50];
    printf("Digite o nome da Disciplina: ");
    fflush(stdin);
    scanf("%s", nome);
    return lst_insere_disciplinas(disciplinas, nome);
}

TAlunos* cancelarAluno(TAlunos* alunos)
{
    int ra;
    printf("Digite o numero de RA\n");
    fflush(stdin);
    scanf("%d", &ra);
    alunos = lst_remover_alunos(alunos, ra);
    return alunos;
}

TProfessores* cancelarProfessor(TProfessores* professores)
{
    int cod;
    printf("Digite o numero de COD\n");
    fflush(stdin);
    scanf("%d", &cod);
    professores = lst_remover_professores(professores, cod);
    return professores;
}
TDisciplinas* cancelarMateria(TDisciplinas* disciplinas)
{
    int cod;
    printf("Digite o numero de COD\n");
    fflush(stdin);
    scanf("%d", &cod);
    disciplinas = lst_remover_disciplinas(disciplinas, cod);
    return disciplinas;
}

void vincularAluno(TAlunos* alunos, TDisciplinas* disciplinas) {
    int ra[50], cod[50], quant_a, quant_d, i;

    printf("Digite a quantidade de alunos\n");
    fflush(stdin);
    scanf("%d", &quant_a);

    for (i = 0; i < quant_a; i++) {
        printf("Digite o ra do aluno %d\n", i);
        fflush(stdin);
        scanf("%d", &ra[i]);
    }

    printf("Digite a quantidade de disciplinas");
    fflush(stdin);
    scanf("%d", &quant_d);

    for (i = 0; i < quant_d; i++) {
        printf("Digite o cod da disciplina %d\n", i);
        fflush(stdin);
        scanf("%d", &cod[i]);
    }

    lst_insere_alunos_na_disciplina(alunos, ra, quant_a, disciplinas, cod, quant_d);
}
void vincularProfessor(TProfessores* professores, TDisciplinas* disciplinas) {
    int cod_p[50], cod[50], quant_p, quant_d, i;

    printf("Digite a quantidade de professores\n");
    fflush(stdin);
    scanf("%d", &quant_p);

    for (i = 0; i < quant_p; i++) {
        printf("Digite o ra do professor %d\n", i);
        fflush(stdin);
        scanf("%d", &cod_p[i]);
    }

    printf("Digite a quantidade de disciplinas");
    fflush(stdin);
    scanf("%d", &quant_d);

    for (i = 0; i < quant_d; i++) {
        printf("Digite o cod da disciplina %d\n", i);
        fflush(stdin);
        scanf("%d", &cod[i]);
    }

    lst_insere_professores_na_disciplina(professores, cod_p, quant_p, disciplinas, cod, quant_d);
}

void desvincularAluno(TAlunos* alunos, TDisciplinas* disciplinas) {
    int ra[50], cod[50], quant_a, quant_d, i, j;
    TAlunos* pr_aluno = lst_cria_alunos();
    TDisciplinas* pr_disc = lst_cria_disciplinas();

    printf("Digite a quantidade de alunos\n");
    fflush(stdin);
    scanf("%d", &quant_a);

    for (i = 0; i < quant_a; i++) {
        printf("Digite o ra do aluno %d\n", i);
        fflush(stdin);
        scanf("%d", &ra[i]);
    }

    printf("Digite a quantidade de disciplinas");
    fflush(stdin);
    scanf("%d", &quant_d);

    for (i = 0; i < quant_d; i++) {
        printf("Digite o cod da disciplina %d\n", i);
        fflush(stdin);
        scanf("%d", &cod[i]);
    }

    for (i = 0; i < quant_a; i++) {
        pr_aluno = lst_procura_alunos(alunos, ra[i]);
        if (pr_aluno != NULL)
        {
            for (j = 0; j < quant_d; j++)
            {
                pr_disc = lst_procura_disciplinas(disciplinas, cod[j]);
                if (pr_disc != NULL)
                {
                    lst_remover_alunos_disciplinas(pr_disc, pr_aluno->ra, 1);
                }
                else
                {
                    printf("Disciplina com cod %d não encontrado", cod[j]);
                }
            }
        }
        else
        {
            printf("Aluno com RA %d não encontrado.", ra[i]);
        }
    }

}
void desvincularProfessor(TProfessores* professores, TDisciplinas* disciplinas) {
    int cod_p[50], cod[50], quant_p, quant_d, i, j;
    TProfessores* pr_prof = lst_cria_professores();
    TDisciplinas* pr_disc = lst_cria_disciplinas();

    printf("Digite a quantidade de professores\n");
    fflush(stdin);
    scanf("%d", &quant_p);

    for (i = 0; i < quant_p; i++) {
        printf("Digite o ra do professor %d\n", i);
        fflush(stdin);
        scanf("%d", &cod_p[i]);
    }

    printf("Digite a quantidade de disciplinas");
    fflush(stdin);
    scanf("%d", &quant_d);

    for (i = 0; i < quant_d; i++) {
        printf("Digite o cod da disciplina %d\n", i);
        fflush(stdin);
        scanf("%d", &cod[i]);
    }

    for (i = 0; i < quant_p; i++) {
        pr_prof = lst_procura_professores(professores, cod_p[i]);
        if (pr_prof != NULL)
        {
            for (j = 0; j < quant_d; j++)
            {
                pr_disc = lst_procura_disciplinas(disciplinas, cod[j]);
                if (pr_disc != NULL)
                {
                    lst_remover_professores_disciplinas(pr_disc, pr_prof->cod, 1);
                }
                else
                {
                    printf("Disciplina com cod %d não encontrado", cod[j]);
                }
            }
        }
        else
        {
            printf("Aluno com RA %d não encontrado.", cod_p[i]);
        }
    }
}