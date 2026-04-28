#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXdiscente 15
#define MAXcurso 6
#define MAXturma 30

typedef struct{

    char nome[100], cpf[15];
    int idade;

}Discente;

typedef struct{

    char nomeCurso[100];
    int horas, numVagas, numPart, codigo;

}Curso;

typedef struct{

    int numTurma, ano;
    Discente aluno;
    Curso curso;
    float nota, horasPart;

}Turma;

Discente discentes[MAXdiscente];
Curso cursos[MAXcurso];
Turma turmas[MAXturma];

int quantDisc = 0;
int quantCurs = 0;
int quantTurm = 0;

void pausar(){
   printf("\tPressione ENTER...");
   getchar();
}

void menuPrincipal();
void menuDiscente();
void menuCurso();
void menuTurma();
void menuRelatorios();

void cadDiscente();
void ediDiscente();
void excDiscente();
void pesDiscente();

void cadCurso();
void ediCurso();
void excCurso();
void pesCurso();

void cadTurma();
void ediTurma();
void excTurma();
void pesTurma();

void A();
void B();
void C();
void D();
void E();
void F();
void G();

int validarTurma();

int salvarDiscentes();
void carregarDiscentes();
int salvarCursos();
void carregarCursos();
int salvarTurmas();
void carregarTurmas();

//==== MAIN ====

int main(){

    carregarDiscentes();
    carregarCursos();
    carregarTurmas();

    menuPrincipal();

    return 0;
}

// ===== MENUS =====

void menuPrincipal(){

   int op = 0;

   do{
       system("cls");

       printf("\t+------------------+\n");
       printf("\t|  MENU PRINCIPAL  |\n");
       printf("\t+------------------+\n\n");

       printf("\t+------------------+\n");
       printf("\t| 1 - Discentes    |\n");
       printf("\t| 2 - Cursos       |\n");
       printf("\t| 3 - Turmas       |\n");
       printf("\t| 4 - Relatorios   |\n");
       printf("\t| 5 - Sair         |\n");
       printf("\t+------------------+\n");

       printf("\n\t> informe a opcao: ");
       scanf("%d", &op);
       printf("\n");

    switch(op){

    case 1:
        menuDiscente();
        break;

    case 2:
        menuCurso();
        break;

    case 3:
        menuTurma();
        break;

    case 4:
        menuRelatorios();
        break;

    case 5:
        printf("\tEncerrando programa...\n");
        break;

    default:
        printf("\n\t[AVISO] Opcao invalida! [AVISO]\n");
        getchar();
        pausar();
        break;

    }

   }while(op != 5);

}

void menuDiscente(){
int opD = 0;

    do{
        system("cls");

        printf("\t+-----------------+\n");
        printf("\t|  MENU DISCENTE  |\n");
        printf("\t+-----------------+\n\n");

        printf("\t+-----------------+\n");
        printf("\t| 1 - Cadastrar   |\n");
        printf("\t| 2 - Editar      |\n");
        printf("\t| 3 - Excluir     |\n");
        printf("\t| 4 - Pesquisar   |\n");
        printf("\t| 5 - Voltar      |\n");
        printf("\t+-----------------+\n");

        printf("\n\t> informe a opcao: ");
        scanf("%d", &opD);
        printf("\n");

    switch (opD){

    case 1:
        cadDiscente();
        break;

    case 2:
        ediDiscente();
        break;

    case 3:
        excDiscente();
        break;

    case 4:
        pesDiscente();
        break;

    case 5:

        break;

    default:
        printf("\n\t[AVISO] Opcao invalida [AVISO]\n");
        getchar();
        pausar();
        break;
    }


  }while(opD != 5);


}

void menuCurso(){

     int opC = 0;

    do{
        system("cls");

        printf("\t+-----------------+\n");
        printf("\t|    MENU CURSO   |\n");
        printf("\t+-----------------+\n\n");

        printf("\t+-----------------+\n");
        printf("\t| 1 - Cadastrar   |\n");
        printf("\t| 2 - Editar      |\n");
        printf("\t| 3 - Excluir     |\n");
        printf("\t| 4 - Pesquisar   |\n");
        printf("\t| 5 - Voltar      |\n");
        printf("\t+-----------------+\n");

        printf("\n\t> informe a opcao: ");
        scanf("%d", &opC);

       printf("\n");

    switch (opC){

    case 1:
        cadCurso();
        break;

    case 2:
        ediCurso();
        break;

    case 3:
        excCurso();
        break;

    case 4:
        pesCurso();
        break;

    case 5:

        break;

    default:
        printf("\n\t[AVISO] Opcaoo invalida [AVISO]\n");
        getchar();
        pausar();
        break;
    }


  }while(opC != 5);


}

void menuTurma(){

    if(validarTurma() == 0){
        pausar();
        getchar();
        return;
    }

    int opT = 0;

    do{

        system("cls");

        printf("\t+-----------------+\n");
        printf("\t|    MENU TURMA   |\n");
        printf("\t+-----------------+\n\n");

        printf("\t+-----------------+\n");
        printf("\t| 1 - Cadastrar   |\n");
        printf("\t| 2 - Editar      |\n");
        printf("\t| 3 - Excluir     |\n");
        printf("\t| 4 - Pesquisar   |\n");
        printf("\t| 5 - Voltar      |\n");
        printf("\t+-----------------+\n");

        printf("\n\t> informe a opcao: ");
        scanf("%d", &opT);
        printf("\n");

    switch (opT){
        case 1:

        cadTurma();
        break;

    case 2:
        ediTurma();
        break;

    case 3:
        excTurma();
        break;

    case 4:
        pesTurma();
        break;

    case 5:

        break;

    default:
        printf("\n\t[AVISO] Opcao invalida [AVISO]\n");
        getchar();
        pausar();
        break;
    }

  }while(opT != 5);

}

void menuRelatorios(){

    if(validarTurma() == 0){
        return;
    }

    int opR = 0;

    do{
        system("cls");

        printf("\t+---------------------------------------------------------------------------------------------------------+\n");
        printf("\t|                                          MENU RELATORIOS                                                |\n");
        printf("\t+---------------------------------------------------------------------------------------------------------+\n\n");

        printf("\t+---------------------------------------------------------------------------------------------------------+\n");
        printf("\t| 1 - Listagem do cpf, nome e idade dos discentes.                                                        |\n");
        printf("\t| 2 - Listagem dos codigos, nomes, horas e numero de vagas dos cursos.                                    |\n");
        printf("\t| 3 - Listagem de todos os discentes a partir de uma palavra do nome.                                     |\n");
        printf("\t| 4 - Listagem do numero da turma, cpf, nome e nota do discente.                                          |\n");
        printf("\t| 5 - Listagem dos numeros das turmas, cpf, nome e nota do discente, bem como o codigo e nome do curso.   |\n");
        printf("\t| 6 - Listagem do cpf, nome e nota do discente conforme o numero da turma.                                |\n");
        printf("\t| 7 - Listagem de todas as turmas, bem como a media das notas dos discentes.                              |\n");
        printf("\t| 8 - Voltar                                                                                              |\n");
        printf("\t+---------------------------------------------------------------------------------------------------------+\n");

        printf("\n\t> informe a opcao: ");
        scanf("%d", &opR);
        printf("\n");

    switch (opR){

    case 1:
        A();
        break;

    case 2:
        B();
        break;

    case 3:
        C();
        break;

    case 4:
        D();
        break;

    case 5:
        E();
        break;

    case 6:
        F();
        break;

    case 7:
        G();
        break;

    case 8:
        return;

    default:
        printf("\n\t[AVISO] Opcao invalida [AVISO]\n");
        getchar();
        pausar();
        break;
    }


  }while(opR != 9);


}

//==== VALIDAÇÃO DA TURMA ====

int validarTurma(){

    if(quantCurs == 0){
        printf("\n\t[ERRO] Nao existem cursos cadastrados. Cadastre um curso antes de criar uma turma. [ERRO]\n");
        return 0;
    }

    if (quantDisc == 0) {
        printf("\n\t[Erro] Nao ha discentes cadastrados. Cadastre um discente antes de criar uma turma. [Erro]\n");
        return 0;
    }

    return 1;
}

//===== FUNÇÕEES DISCENTES =====

void cadDiscente(){

    getchar();

    if (quantDisc >= MAXdiscente) {
        printf("\n\t[ERRO] Limite de cadastros atingido! [ERRO]\n");
        pausar();
        return;
    }

    system("cls");
    int achou = 0;

    printf("\n");
    printf("\t+-------------------+\n");
    printf("\t| CADASTRO DISCENTE |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o CPF: ");
    fgets(discentes[quantDisc].cpf, 15, stdin);
    discentes[quantDisc].cpf[strcspn(discentes[quantDisc].cpf, "\n")] = '\0';

    int soNumeros = 1;
    for(int i=0; i<strlen(discentes[quantDisc].cpf); i++){
        if(isdigit(discentes[quantDisc].cpf[i]) == 0){
            soNumeros = 0;
            break;
        }
    }

    if (soNumeros == 0) {
        printf("\n\t[ERRO] O CPF deve conter apenas numeros [ERRO]\n");
        pausar();
        return;
    }

    for(int i=0; i<quantDisc; i++){
        if(strcmp(discentes[quantDisc].cpf, discentes[i].cpf) == 0){
            achou = 1;

            printf("\n\t[AVISO] CPF %s ja cadastrado no sistema [AVISO]\n", discentes[quantDisc].cpf);
            pausar();
            return;
        }
    }


    printf("\n\t> Digite o nome: ");
    fgets(discentes[quantDisc].nome, 100, stdin);
    discentes[quantDisc].nome[strcspn(discentes[quantDisc].nome, "\n")] = '\0';

    printf("\n\t> Digite a idade: ");
    scanf("%d", &discentes[quantDisc].idade);
    getchar();

    quantDisc++;
    salvarDiscentes();
    pausar();
}

void ediDiscente(){

    getchar();

    char cpfBusca[15];
    int achou = 0;
    int opD;

    system("cls");

    printf("\n");
    printf("\t+---------------------+\n");
    printf("\t|   EDITAR DISCENTE   |\n");
    printf("\t+---------------------+\n");

    printf("\n\t> Digite o CPF do discente: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    for(int i=0; i<quantDisc; i++){
        if(strcmp(discentes[i].cpf, cpfBusca) == 0){
            achou = 1;

            do{
                system("cls");

                printf("\n");
                printf("\t+-----------------------+\n");
                printf("\t|  DISCENTE ENCONTRADO  |\n");
                printf("\t+-----------------------+\n");
                printf("\n\t>Nome: %s\n", discentes[i].nome);
                printf("\t>idade: %d\n", discentes[i].idade);
                printf("\t>CPF: %s\n", discentes[i].cpf);

                printf("\n");
                printf("\t+----------------------------------------+\n");
                printf("\t|   Deseja editar os dados do discente   |\n");
                printf("\t+----------------------------------------+\n");
                printf("\t1 - SIM\n");
                printf("\t2 - NAO\n");
                printf("\t> informe a opcao: ");
                scanf("%d", &opD);
                getchar();

                printf("\n");

                switch(opD){
                case 1:

                    printf("\n");
                    printf("\t+---------------+\n");
                    printf("\t|  DADOS NOVOS  |\n");
                    printf("\t+---------------+\n");

                    printf("\n\t> Digite o novo nome: ");
                    fgets(discentes[i].nome, 100, stdin);
                    discentes[i].nome[strcspn(discentes[i].nome, "\n")] = '\0';

                    printf("\n\t> Digite a nova idade: ");
                    scanf("%d", &discentes[i].idade);
                    getchar();

                    printf("\n\t!!! Dados atualizados  !!!\n");
                    salvarDiscentes();
                    pausar();
                    return;

                case 2:
                    printf("\n\t[AVISO] Edicao cancelada. [AVISO]\n");
                    pausar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    pausar();
                    break;

                }

            }while(1);

        }

    }

    if(achou == 0){
        printf("\n\t[AVISO] CPF do discente nao encontrado [AVISO]\n");
        pausar();

    }

}

void excDiscente(){

    char cpfBusca[15];
    int achou = 0;

    getchar();
    system("cls");

    printf("\n");
    printf("\t+-----------------------+\n");
    printf("\t|   EXCLUIR DISCENTE    |\n");
    printf("\t+-----------------------+\n");
    printf("\n\t> Digite o CPF do discente que deseja excluir: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    int opE;

    for(int i=0; i < quantDisc; i++){
         if(strcmp(discentes[i].cpf, cpfBusca) == 0){
            achou = 1;

            do{
                system("cls");

                printf("\n");
                printf("\t+------------------------+\n");
                printf("\t|   DISCENTE ENCONTRADO  |\n");
                printf("\t+------------------------+\n");
                printf("\n\t>Nome: %s\n", discentes[i].nome);
                printf("\t>idade: %d\n", discentes[i].idade);
                printf("\t>CPF: %s\n", discentes[i].cpf);

                printf("\n");

                printf("\t+--------------------------------------+\n");
                printf("\t| Deseja excluir os dados do discente? |\n");
                printf("\t+--------------------------------------+\n");
                printf("\t1 - SIM\n");
                printf("\t2 - NAO\n");
                printf("\t> informe a opcao: ");
                scanf("%d", &opE);
                getchar();

                printf("\n");

                switch(opE){

                case 1:

                    discentes[i] = discentes[quantDisc - 1];
                    quantDisc--;
                    salvarDiscentes();

                    printf("\n\t[AVISO] Discente excluido com sucesso! [AVISO]\n");
                    pausar();
                    return;

                case 2:
                    printf("\n\t[AVISO] Exclusao cancelada. [AVISO]\n");
                    pausar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    pausar();
                    break;

                }

            }while(1);



        }

   }

   if(achou == 0) {
        printf("\n\n\t[AVIOS] Discente com CPF %s nao encontrado! [AVISO]\n", cpfBusca);
       pausar();
    }

}

void pesDiscente(){

    getchar();

    char cpfBusca[15];
    int achou = 0;

    system("cls");

    printf("\n\t+------------------------+\n");
    printf("\t|   PROUCURAR DISCENTE   |\n");
    printf("\t+------------------------+\n");

    printf("\n\t> Digite o CPF do discente: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    for(int i=0; i<quantDisc; i++){
        if(strcmp(discentes[i].cpf, cpfBusca) == 0){
            achou = 1;

            printf("\n\t+-----------------------+\n");
            printf("\t|  DISCENTE ENCONTRADO  |\n");
            printf("\t+-----------------------+\n");
            printf("\n\t>Nome: %s\n", discentes[i].nome);
            printf("\t>idade: %d\n", discentes[i].idade);
            printf("\t>CPF: %s\n", discentes[i].cpf);

            pausar();
        }
    }
    if(achou == 0){
        printf("\n\t[AVIOS] CPF do discente nao encontrado [AVISO]\n");
        pausar();
    }

}

//===== ARQUIVOS DISCENTE =====

int salvarDiscentes(){

    FILE *d = fopen("discentes.txt", "w");

    if(d == NULL){

        printf("\t[ERRO] Arquivo nao encontrado. [ERRO]n");
        return 1;
    }

    for(int i=0; i<quantDisc; i++){

        fprintf(d, "%s;%s;%d\n", discentes[i].cpf, discentes[i].nome, discentes[i].idade);

    }

    fclose(d);

    printf("\n\t[AVISO] Dados salvos com sucesso em discentes.txt! [AVISO]\n");

    return 0;
}

void carregarDiscentes(){

    FILE *d = fopen("discentes.txt", "r");

    if(d == NULL){
        quantDisc = 0;
        return;
    }

        while(fscanf(d,"%14[^;];%99[^;];%d\n", discentes[quantDisc].cpf, discentes[quantDisc].nome,
                     &discentes[quantDisc].idade) != EOF){

                        quantDisc++;

                        if(quantDisc >= MAXdiscente){
                            break;
                        }

           }

        fclose(d);

}

//==== FUNÇÕES CURSOS ====

void cadCurso(){

    getchar();

    if (quantCurs >= MAXcurso){
        printf("\n\t[ERRO] Limite de cadastros atingido! [ERRO]\n");
        pausar();
        return;
    }

    system("cls");

    printf("\n");
    printf("\t+--------------------+\n");
    printf("\t|   CADASTRO CURSO   |\n");
    printf("\t+--------------------+\n");

    printf("\t> Digite o nome: ");
    fgets(cursos[quantCurs].nomeCurso, 100, stdin);
    cursos[quantCurs].nomeCurso[strcspn(cursos[quantCurs].nomeCurso, "\n")] = '\0';

    if(quantCurs != 0){
        for(int i=0; i<quantCurs; i++){
            if(strcmp(cursos[quantCurs].nomeCurso, cursos[i].nomeCurso) == 0){
                printf("\n\t[AVISO] Curso %s ja cadastrado [AVISO]\n", cursos[quantCurs].nomeCurso);
                pausar();

                return;
            }
        }

    }

    printf("\n\t> Digite o codigo do curso: ");
    scanf("%d", &cursos[quantCurs].codigo);
    getchar();

    if(quantCurs != 0){
        for(int j=0; j<quantCurs; j++){
            if(cursos[quantCurs].codigo == cursos[j].codigo){
            printf("\n\t[AVISO] Curso com codigo %d ja cadastrado [AVISO]\n", cursos[quantCurs].codigo);
            pausar();

            return;
            }
        }
    }

    printf("\n\t> Digite quantas horas tem: ");
    scanf("%d", &cursos[quantCurs].horas);
    getchar();

    printf("\n\t> Digite a quantidade de vagas: ");
    scanf("%d", &cursos[quantCurs].numVagas);
    getchar();

    printf("\n\t> Digite a quantidade de participantes: ");
    scanf("%d", &cursos[quantCurs].numPart);
    getchar();

    quantCurs++;
    salvarCursos();
    pausar();
}

void ediCurso(){

    getchar();
    system("cls");

    int codBusca = 0;
    int opC;
    int achou = 0;

    printf("\n");
    printf("\t+---------------------+\n");
    printf("\t|     EDITAR CURSO    |\n");
    printf("\t+---------------------+\n");

    printf("\t> Digite o codigo do curso: ");
    scanf("%d", &codBusca);

    for(int i=0; i<quantCurs; i++){
        if(codBusca == cursos[i].codigo){
            achou = 1;

            do{
                system("cls");

                printf("\n");
                printf("\t+----------------------+\n");
                printf("\t|   CURSO ENCONTRADO   |\n");
                printf("\t+----------------------+\n");

                printf("\t> Nome: %s\n", cursos[i].nomeCurso);
                printf("\t> Codigo: %d\n", cursos[i].codigo);
                printf("\t> horas: %d\n", cursos[i].horas);
                printf("\t> Vagas: %d\n", cursos[i].numVagas);
                printf("\t> Participantes: %d\n", cursos[i].numPart);

                printf("\n");

                printf("\t+-------------------------------------+\n");
                printf("\t|   Deseja editar os dados do curso   |\n");
                printf("\t+-------------------------------------+\n");
                printf("\t1 - SIM\n");
                printf("\t2 - NAO\n");
                printf("\t> informe a opcao: ");
                scanf("%d", &opC);

                printf("\n");

                switch(opC){

                case 1:
                    getchar();

                    printf("\n");
                    printf("\t+--------------------+\n");
                    printf("\t|    DADOS NOVOS     |\n");
                    printf("\t+--------------------+\n");

                    printf("\n\t> Digite o novo nome: ");
                    fgets(cursos[i].nomeCurso, 100, stdin);
                    cursos[i].nomeCurso[strcspn(cursos[i].nomeCurso, "\n")] = '\0';

                    printf("\n\t> Digite a nova quantidade de horas: ");
                    scanf("%d", &cursos[i].horas);
                    getchar();

                    printf("\n\t> Digite o novo numero de vagas: ");
                    scanf("%d", &cursos[i].numVagas);
                    getchar();

                    printf("\n\t> Digite o novo numero de participantes: ", cursos[i].numPart);
                    scanf("%d", &cursos[i].numPart);

                    salvarCursos();

                    printf("\tCurso editado com sucesso!\n");
                    pausar();
                    return;

                case 2:
                    printf("\n\tEdicao cancelada.\n");
                    pausar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    pausar();
                    break;

                }

            }while(1);



        }

   }

   if(achou == 0) {
        printf("\n\n\t[AVIOS] Curso com codigo %d nao encontrado! [AVISO]\n", codBusca);
        pausar();
    }

}

void excCurso(){

    getchar();

    int achou = 0;
    int codBusca = 0;
    int opC;

    system("cls");

    printf("\t+-------------------+\n");
    printf("\t|   EXCLUIR CURSO   |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o codigo do curso: ");
    scanf("%d", &codBusca);

    for(int i=0;i<quantCurs;i++){
      if(codBusca == cursos[i].codigo){
        achou = 1;

        do{
            system("cls");

            printf("\t+----------------------+\n");
            printf("\t|   CURSO ENCONTRADO   |\n");
            printf("\t+----------------------+\n");

            printf("\n\t>Nome: %s\n", cursos[i].nomeCurso);
            printf("\t>Codigo: %d\n", cursos[i].codigo);
            printf("\t>Horas: %d\n", cursos[i].horas);
            printf("\t>Num. vagas: %d\n", cursos[i].numVagas);
            printf("\t>Num. participantes: %d\n", cursos[i].numPart);

            printf("\n");

            printf("\t+--------------------------------------+\n");
            printf("\t|   Deseja excluir os dados do curso   |\n");
            printf("\t+--------------------------------------+\n");
            printf("\t1 - SIM\n");
            printf("\t2 - NAO\n");
            printf("\t> informe a opcao: ");
            scanf("%d", &opC);
            getchar();

            printf("\n");

            switch(opC){
            case 1:

                cursos[i] = cursos[quantCurs - 1];
                quantCurs--;
                salvarCursos();

                printf("\n\t[AVISO] Curso excluido com sucesso! [AVISO]\n");
                pausar();
                return;

            case 2:

                printf("\n\t[AVISO] Exclusao cancelada. [AVISO]\n");
                pausar();
                return;

            default:

                printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                pausar();
                break;

                }

            }while(1);

        }

    }if(achou == 0){
        printf("\n\t[AVISO] codigo do curso nao encontrado [AVISO]\n");
        pausar();
    }

}

void pesCurso(){

    getchar();

    int achou = 0;
    int codBusca = 0;

    system("cls");

    printf("\t+---------------------+\n");
    printf("\t|   PROCURAR CURSO   |\n");
    printf("\t+---------------------+\n");

    printf("\n\t> Digite o codigo do curso: ");
    scanf("%d", &codBusca);

    printf("\n");

    for(int i=0; i<quantCurs; i++){
        if(codBusca==cursos[i].codigo){
            achou = 1;

            printf("\t+-----------------------+\n");
            printf("\t|    CURSO ENCONTRADO   |\n");
            printf("\t+-----------------------+\n");

            printf("\n\t>Nome: %s\n", cursos[i].nomeCurso);
            printf("\t>Codigo: %d\n", cursos[i].codigo);
            printf("\t>Horas: %d\n", cursos[i].horas);
            printf("\t>Num. vagas: %d\n", cursos[i].numVagas);
            printf("\t>Num. participantes: %d\n", cursos[i].numPart);

            pausar();
        }

    }if(achou == 0){
        printf("\n\t[AVIOS] codigo do curso não encontrado [AVISO]\n");
        pausar();
    }

}

//==== ARQUIVOS CURSO ====

int salvarCursos(){

    FILE *c;

    c = fopen("cursos.txt", "w");

    if(c == NULL){

        printf("\t[ERRO] Arquivo não encontrado. [ERRO]\n");
        return 1;
    }

    for(int i=0; i<quantCurs; i++){
        fprintf(c, "%s;%d;%d;%d;%d\n", cursos[i].nomeCurso, cursos[i].codigo, cursos[i].horas,
                cursos[i].numVagas, cursos[i].numPart);

    }

    fclose(c);

    printf("\n\t[AVISO] Dados salvos com sucesso em cursos.txt! [AVISOs]\n");

    return 0;

}

void carregarCursos(){

    FILE *c;

    c = fopen("cursos.txt", "r");

    if(c == NULL){
        quantCurs  = 0;
        return;
    }

    while(fscanf(c, "%[^;];%d;%d;%d;%d\n",cursos[quantCurs].nomeCurso, &cursos[quantCurs].codigo, &cursos[quantCurs].horas,
                        &cursos[quantCurs].numVagas, &cursos[quantCurs].numPart) != EOF){

                        quantCurs++;

                        if(quantCurs >= MAXcurso){
                            break;
                        }

            }

            fclose(c);

}

//===== FUNÇÕES TURMA =====

void cadTurma(){

    getchar();

    if (quantTurm >= MAXturma){
        printf("\n\t[ERRO] Limite de turmas atingido! [ERRO]\n");
        pausar();
        return;
    }

    char cpfBusca[15];
    int codBusca, posDisc = -1, posCurso = -1;

    system("cls");
    printf("\n\t+-------------------+\n");
    printf("\t|  CADASTRO TURMA   |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o CPF do discente: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    for (int i = 0; i < quantDisc; i++) {
        if (strcmp(discentes[i].cpf, cpfBusca) == 0) {
            posDisc = i;
            break;
        }
    }

    if(posDisc == -1){
        printf("\n\t[ERRO] Discente nao encontrado! [ERRO]\n");
        pausar();
        return;
    }

    printf("\t> Digite o codigo do curso: ");
    scanf("%d", &codBusca);

    for(int i = 0; i < quantCurs; i++){
        if (cursos[i].codigo == codBusca) {
            posCurso = i;
            break;
        }
    }

    if(posCurso == -1){
        printf("\n\t[ERRO] Curso nao encontrado! [ERRO]\n");
        pausar();
        return;
    }

    printf("\n\t> Digite o numero da turma: ");
    scanf("%d", &turmas[quantTurm].numTurma);
    getchar();

    for(int i=0; i<quantTurm; i++){
        if(turmas[i].numTurma == turmas[quantTurm].numTurma && strcmp(turmas[i].aluno.cpf, cpfBusca) == 0){

            printf("\n\t[ERRO] Aluno ja matriculado nessa turma. [ERRO]\n");
            pausar();
            return;
        }
    }

    printf("\n\t> Digite o ano: ");
    scanf("%d", &turmas[quantTurm].ano);
    getchar();

    printf("\n\t> Digite a nota: ");
    scanf("%f", &turmas[quantTurm].nota);
    getchar();

    printf("\n\t> Horas de participacao: ");
    scanf("%f", &turmas[quantTurm].horasPart);
    getchar();

    turmas[quantTurm].aluno = discentes[posDisc];
    turmas[quantTurm].curso = cursos[posCurso];

    quantTurm++;
    salvarTurmas();

    printf("\t[AVISO] Discente matriculado com sucesso! [AVISO]\n");
    pausar();
}

void ediTurma(){

    int numBusca, achouTurma = 0, achouDisc = 0;
    char cpfEdita[15];

    system("cls");
    printf("\n");
    printf("\t+-------------------+\n");
    printf("\t|   EDITAR TURMA    |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o numero da turma: ");
    scanf("%d", &numBusca);
    getchar();

    system("cls");

    printf("\n");
    printf("\t+---------------------------------+\n");
    printf("\t| DISCENTES MATRICULADOS NA TURMA |\n");
    printf("\t+---------------------------------+\n");

    for(int i=0; i<quantTurm; i++){
        if(turmas[i].numTurma == numBusca){
            achouTurma = 1;

            printf("\n\tNome: %s -", turmas[i].aluno.nome);
            printf(" CPF : %s -", turmas[i].aluno.cpf);
            printf(" Nota: %.2f -", turmas[i].nota);
            printf(" Horas participacao: %.2f -", turmas[i].horasPart);
            printf(" Ano: %d", turmas[i].ano);
        }
    }

    if (achouTurma == 0) {
        printf("\n\t[AVISO] Nenhuma matricula encontrada para a turma %d [AVISO]\n", numBusca);
        pausar();
        return;
    }

    printf("\n\n\t> Digite o CPF do discente para editar: ");
    fgets(cpfEdita, 15, stdin);
    cpfEdita[strcspn(cpfEdita, "\n")] = '\0';

    for(int i=0; i<quantTurm; i++){
        if(turmas[i].numTurma == numBusca && strcmp(turmas[i].aluno.cpf, cpfEdita) == 0){

            achouDisc = 1;

            printf("\n\tAluno selecionado: %s\n", turmas[i].aluno.nome);

            printf("\n\t> Nova nota: ");
            scanf("%f", &turmas[i].nota);

            printf("\t> Novas horas participacao: ");
            scanf("%f", &turmas[i].horasPart);

            printf("\t> Novo ano: ");
            scanf("%d", &turmas[i].ano);

            salvarTurmas();

            printf("\n\t[AVISO]Registro editado com sucesso! [AVISO]\n");
            pausar();
            return;
        }
    }

    if (achouDisc == 0) {
        printf("\n\t[ERRO] O CPF %s nao pertence a turma %d.\n", cpfEdita, numBusca);
    }

   pausar();
   return;
}

void excTurma(){

    getchar();

    int buscaNum, opE;
    int achou = 0;
    int contAlunos = 0;

    system("cls");

    printf("\t+-------------------+\n");
    printf("\t|   EXCLUIR TURMA   |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o numero da turma que deseja excluir: ");
    scanf("%d", &buscaNum);
    getchar();

    for(int i = 0; i < quantTurm; i++){
        if(turmas[i].numTurma == buscaNum){
            achou = 1;

            printf("\n\tNome: %s -", turmas[i].aluno.nome);
            printf(" CPF : %s -", turmas[i].aluno.cpf);
            printf(" Nota: %.2f -", turmas[i].nota);
            printf(" Horas participacao: %.2f -", turmas[i].horasPart);
            printf(" Ano: %d", turmas[i].ano);

            contAlunos++;
        }
    }

    if(achou == 0){
        printf("\n\t[AVISO] Turma %d nao encontrada! [AVISO]\n", buscaNum);
        pausar();
        return;
    }

    printf("\n\n\tA turma %d possui %d discente(s) vinculado(s).\n", buscaNum, contAlunos);

    printf("\n\tDeseja realmente excluir TODOS os registros?");
    printf("\n\t1 - SIM");
    printf("\n\t2 - NAO");
    printf("\n\t> Opcao: ");
    scanf("%d", &opE);
    getchar();

    if(opE == 1){
        for(int i = 0; i < quantTurm; i++){
            if(turmas[i].numTurma == buscaNum){

                turmas[i] = turmas[quantTurm - 1];
                quantTurm--;
                i--;
            }
        }

        salvarTurmas();

        printf("\n\t[AVISO] Turma %d excluida! [AVISO]\n", buscaNum);

    }else{

        printf("\n\t[AVISO] Exclusao cancelada. [AVISO]\n");
    }

    pausar();
}

void pesTurma(){
    getchar();
    system("cls");

    int buscaNum;
    int achou = 0;

    printf("\t+--------------------+\n");
    printf("\t|   PROCURAR TURMA   |\n");
    printf("\t+--------------------+\n");

    printf("\n\t> Digite o numero da turma: ");
    scanf("%d", &buscaNum);
    getchar();

    printf("\n");
    for(int i = 0; i < quantTurm; i++){
        if(buscaNum == turmas[i].numTurma){
            if(achou == 0){

                printf("\t+----------------------+\n");
                printf("\t|   TURMA ENCONTRADA   |\n");
                printf("\t+----------------------+\n");

                printf("\n\t>TURMA %d (%d)\n",
                       turmas[i].numTurma,
                       turmas[i].ano);
            }
            achou = 1;

            printf("\n\t> Nome: %s", turmas[i].aluno.nome);
            printf(" - Cod. Curso: %d", turmas[i].curso.codigo);
            printf(" - CPF: %s", turmas[i].aluno.cpf);
            printf(" - Nota: %.1f", turmas[i].nota);
            printf(" - Horas Part.: %.1f", turmas[i].horasPart);
        }
    }

    if(achou == 0){
        printf("\n\t[AVISO] Numero da turma nao encontrado [AVISO]\n");
    }

    printf("\n\n");
    pausar();
}

//==== ARQUIVOS TURMA ====

int salvarTurmas(){

    FILE *t = fopen("turmas.txt", "w");

    if(t == NULL){
        printf("\n\t[ERRO] Falha ao abrir arquivo [ERRO]\n");
        return 1;
    }

    for(int i=0; i<quantTurm; i++){

        fprintf(t, "%d;%d;%s;%s;%d;%d;%s;%d;%d;%d;%.2f;%.2f\n",turmas[i].numTurma, turmas[i].ano, turmas[i].aluno.cpf,
            turmas[i].aluno.nome, turmas[i].aluno.idade, turmas[i].curso.codigo, turmas[i].curso.nomeCurso, turmas[i].curso.horas,
                turmas[i].curso.numVagas, turmas[i].curso.numPart, turmas[i].nota, turmas[i].horasPart);
    }

    fclose(t);
    printf("\n\t[AVISO] Dados salvos com sucesso em turmas.txt! [AVISO]\n");
    return 0;
}

void carregarTurmas(){

    FILE *t = fopen("turmas.txt", "r");

    if(t == NULL){
        quantTurm = 0;
        return;
    }

    while(fscanf(t,"%d;%d;%14[^;];%99[^;];%d;%d;%99[^;];%d;%d;%d;%f;%f\n",

        &turmas[quantTurm].numTurma, /*int*/
        &turmas[quantTurm].ano, /*int*/

        turmas[quantTurm].aluno.cpf, /*string*/
        turmas[quantTurm].aluno.nome, /*string*/
        &turmas[quantTurm].aluno.idade, /*int*/

        &turmas[quantTurm].curso.codigo, /*int*/
        turmas[quantTurm].curso.nomeCurso, /*string*/
        &turmas[quantTurm].curso.horas, /*int*/
        &turmas[quantTurm].curso.numVagas, /*int*/
        &turmas[quantTurm].curso.numPart, /*int*/

        &turmas[quantTurm].nota, /*float*/
        &turmas[quantTurm].horasPart /*flaot*/) != EOF){

        quantTurm++;

        if(quantTurm >= MAXturma)
            break;
    }

    fclose(t);
}

//===== FUNÇÕES RELATORIO =====

void A(){

    getchar();
    system("cls");

    if(quantDisc == 0){
        printf("\n\t[AVISO] Nenhum discente cadastrado no sistema [AVISO]");
        pausar();
    }

    printf("\n");
    printf("\t+---------------------+\n");
    printf("\t|   LISTAR DISCENTES  |\n");
    printf("\t+---------------------+\n");

    for(int i=0;i<quantDisc;i++){

        printf("\n\tNome: %s \n\tCPF: %s \n\tIdade: %d\n\n", discentes[i].nome, discentes[i].cpf, discentes[i].idade);
    }

    printf("\n\n\t[AVISO] Todos os discentes listados! [AVISO]\n");
    pausar();
}

void B(){

    getchar();
    system("cls");

    if(quantCurs == 0){
        printf("\n\t[AVISO] Nenhum curso cadastrado no sistema [AVISO]");
        pausar();
    }

    printf("\n");
    printf("\t+------------------+\n");
    printf("\t|   LISTAR CURSOS  |\n");
    printf("\t+------------------+\n");

    for(int i=0;i<quantCurs;i++){
        printf("\n\t-----------------------------------");
        printf("\n\tNome: %s \n\tCodigo: %d \n\tHoras: %d \n\tNum. vagas: %d \n\tNum. part.: %d", cursos[i].nomeCurso,
               cursos[i].codigo, cursos[i].horas, cursos[i].numVagas, cursos[i].numPart);
        printf("\n\t-----------------------------------\n");
    }

    printf("\n\n\t[AVISO] Todos os cursos listados [AVISO]\n");
    pausar();
}

void C(){
    getchar();
    system("cls");

    if(quantDisc == 0){
        printf("\n\t[AVISO] Nenhum discente cadastrado no sistema [AVISO]");
        pausar();
    }

    int achou = 0;
    char buscaNome[100];

    printf("\n");
    printf("\t+--------------------+\n");
    printf("\t|   BUSCAR DISCENTE  |\n");
    printf("\t+--------------------+\n");

    printf("\n\t>Digite o nome do discente: ");
    fgets(buscaNome, 100, stdin);
    buscaNome[strcspn(buscaNome, "\n")] = '\0';

    for(int i=0; i<quantDisc; i++){
        if(strcmp(buscaNome, discentes[i].nome)==0){
            achou = 1;

            printf("\n\tNome: %s \n\tCPF: %s \n\tIdade: %d\n\n", discentes[i].nome, discentes[i].cpf, discentes[i].idade);
        }
    }

    if(achou == 0){

        printf("\n\n\t[AVISO] Nome não cadastrado no sistema [AVISO]");
        pausar();
        return;

    }

    printf("\n\t[AVISO] Busca finalizada com sucesso! [AVISO]\n");
    pausar();
    getchar();
}

void D(){
    getchar();
    system("cls");

    printf("\n");
    printf("\t+------------------+\n");
    printf("\t|  LISTAR TURMAS   |\n");
    printf("\t+------------------+\n");

    if(quantTurm == 0){
        printf("\n\t[AVISO] Nenhuma turma cadastrada no sistema [AVISO]\n");
        pausar();
        return;
    }

    for(int i= 0; i < quantTurm; i++){

        printf("\n\t-------------------------------");
        printf("\n\tTurma: %d", turmas[i].numTurma);
        printf("\n\tCPF: %s", turmas[i].aluno.cpf);
        printf("\n\tNome: %s", turmas[i].aluno.nome);
        printf("\n\tNota: %.2f", turmas[i].nota);
        printf("\n\t------------------------------\n");
    }

    printf("\n\t[AVISO] Todas as turmas listadas [AVISO]\n");
    pausar();
}

void E(){
    getchar();
    system("cls");

    printf("\n");
    printf("\t+------------------+\n");
    printf("\t| LISTAR TURMAS 2  |\n");
    printf("\t+------------------+\n");

    if(quantTurm == 0){
        printf("\n\t[AVISO] Nenhuma turma cadastrada no sistema [AVISO]\n");
        pausar();
        return;
    }

    for(int i = 0; i < quantTurm; i++){

        printf("\n\t-----------------------------------");
        printf("\n\tTurma: %d", turmas[i].numTurma);
        printf("\n\tCPF: %s", turmas[i].aluno.cpf);
        printf("\n\tNome: %s", turmas[i].aluno.nome);
        printf("\n\tNota: %.2f", turmas[i].nota);
        printf("\n\tCod. Curso: %d", turmas[i].curso.codigo);
        printf("\n\tNome Curso: %s", turmas[i].curso.nomeCurso);
        printf("\n\t-----------------------------------\n");
    }

    printf("\n\t[AVISO] Listagem concluida! [AVISO]\n");
    pausar();
}

void F(){

    getchar();
    system("cls");

    int buscaNum;
    int achou = 0;

    printf("\t+--------------------+\n");
    printf("\t|   PROCURAR TURMA   |\n");
    printf("\t+--------------------+\n");

    printf("\n\t> Digite o numero da turma: ");
    scanf("%d", &buscaNum);
    getchar();

    printf("\n");
    for(int i = 0; i <quantTurm; i++){
        if(buscaNum == turmas[i].numTurma){
            if(achou == 0){

                printf("\t+----------------------+\n");
                printf("\t|   TURMA ENCONTRADA   |\n");
                printf("\t+----------------------+\n");

                printf("\n\t>TURMA %d (%d)\n",turmas[i].numTurma ,turmas[i].ano);
            }
            achou = 1;

            printf("\n\t> Nome: %s -", turmas[i].aluno.nome);
            printf(" Cod. Curso: %d -", turmas[i].curso.codigo);
            printf(" CPF: %s -", turmas[i].aluno.cpf);
            printf(" Nota: %.1f -", turmas[i].nota);
            printf(" Horas Part.: %.1f ", turmas[i].horasPart);
        }
    }

    if(achou == 0){
        printf("\n\t[AVISO] Numero da turma nao encontrado [AVISO]\n");
    }

    printf("\n\n");
    pausar();
}

void G(){

    getchar();
    system("cls");

    if(quantTurm == 0){
        printf("\n\t[AVISO] Nao ha turmas cadastradas para calcular media [AVISO]\n");
        pausar();
        return;
    }

    float somaNotas, mediaFinal;

    printf("\t+-----------------------+\n");
    printf("\t| MEDIA DE TODAS TURMAS |\n");
    printf("\t+-----------------------+\n");

    for(int i = 0; i < quantTurm; i++){

        int turmaAtual = turmas[i].numTurma;
        int repetida = 0;

        for(int j = 0; j < i; j++){
            if(turmas[j].numTurma == turmaAtual){
                repetida = 1;
                break;
            }
        }

        if(repetida == 0){

            somaNotas = 0;
            int contAlunos = 0;

            printf("\n\t----------------------------------");
            printf("\n\tTurma: %d", turmaAtual);

            for(int k = 0; k < quantTurm; k++){

                if(turmas[k].numTurma == turmaAtual){

                    somaNotas += turmas[k].nota;
                    contAlunos++;

                    printf("\n\t> %s - Nota: %.1f",turmas[k].aluno.nome ,turmas[k].nota);
                }
            }

            mediaFinal = somaNotas / contAlunos;

            printf("\n\t> Quantidade de alunos: %d", contAlunos);
            printf("\n\t> Media da turma: %.1f", mediaFinal);
            printf("\n\t----------------------------------\n");
        }
    }

    printf("\n\t[AVISO] Calculo concluido! [AVISO]\n");
    pausar();
}
