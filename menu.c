
void menu()
{
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
                    cadastrarAluno();
                break;

                case 2:
                    cadastrarProfessor();
                break;

                case 3:
                    cadastrarMateria();
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
                cancelarAluno();
            break;

            case 2:
                cancelarProfessor();
            break;

            case 3:
                cancelarMateria();
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
                vincularAluno();
            break;

            case 2:
                vincularProfessor();
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
                desvincularAluno();
            break;

            case 2:
                desvincularProfessor();
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