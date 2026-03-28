#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <locale.h>

#define MAXdiscente 10
#define MAXcurso 4
#define MAXturma 2

typedef struct{

    char nome[100];
    char cpf[15]; //<---
    int idade;

}Discente;

typedef struct{

    char nomeCurso[100];
    int horas, numVagas, numPart;
    int codigo; //<----

}Curso;

typedef struct{

    int numTurma, horasTurma, ano;
    int codigo;  //<---
    char cpf[15]; //<---
    float nota, horasPart;
}Turma;

Discente discentes[MAXdiscente];
Curso cursos[MAXcurso];
Turma turmas[MAXturma];

int quantDisc = 0;
int quantCurs = 0;
int quantTurm = 0;

void menuPrincipal();
void menuDiscente();
void menuCurso();
void menuTurma();

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

int validarTurma();

int salvarDiscentes();
void carregarDiscentes();
int salvarCursos();
void carregarCursos();


int main(){

    setlocale(LC_ALL, "Portuguese");

    carregarDiscentes();
    carregarCursos();

    menuPrincipal();

    return 0;
}

void menuPrincipal(){

   int op = 0;

   do{
       system("cls");

       printf("\t+-----------------+\n");
       printf("\t| MENU PRINCIPAL  |\n");
       printf("\t+-----------------+\n\n");

       printf("\t+-----------------+\n");
       printf("\t| 1 - Discentes   |\n");
       printf("\t| 2 - Cursos      |\n");
       printf("\t| 3 - Turmnas     |\n");
       printf("\t| 4 - Relatorios  | \n");
       printf("\t| 5 - Sair        |\n");
       printf("\t+-----------------+\n");

       printf("\n\t> informe a opcao: ");

       if(scanf("%d", &op) != 1){
            fflush(stdin);
       }

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
        //menuRelatorios();
        break;

    case 5:
        printf("\tEncerrando programa...\n");
        break;

    default:
        printf("\n\t!! Opção invalida !!\n");
        system("pause");
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

       if(scanf("%d", &opD) != 1){
            fflush(stdin);
       }

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
        printf("\n\t!! Opção invalida !!\n");
        system("pause");
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

       if(scanf("%d", &opC) != 1){
            fflush(stdin);
       }

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
        printf("\n\t!! Opção invalida !!\n");
        system("pause");
        break;
    }


  }while(opC != 5);


}

void menuTurma(){

    if(validarTurma() == 0){
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

       if(scanf("%d", &opT) != 1){
            fflush(stdin);
       }

       printf("\n");

    switch (opT){

    case 1:
        //cadTurma();
        break;

    case 2:
        //editarTurma();
        break;

    case 3:
        //excluirTurma();
        break;

    case 4:
        //pesqTurma();
        break;

    case 5:

        break;

    default:
        printf("\n\t!! Opção invalida !!\n");
        system("pause");
        break;
    }


  }while(opT != 5);


}

int validarTurma(){

    if(quantCurs == 0){

        printf("\n\t[ERRO] Nao existem cursos cadastrados. Cadastre um curso antes de criar uma turma.\n");
        system("pause");
        return 0;
    }

    if (quantDisc == 0) {
        printf("\n\t[Erro] Nao ha discentes cadastrados. Cadastre um discente antes de criar uma turma.\n");
        system("pause");
        return 0;
    }

    return 1;

}

//===== FUNÇÕES DISCENTES =====

void cadDiscente(){

    getchar();

    if (quantDisc >= MAXdiscente) {
        printf("\n\t[ERRO] Limite de cadastros atingido!\n");
        system("pause");
        return;
    }

    system("cls");
    int achou = 0;

    printf("\n\t+-------------------+\n");
    printf("\t| CADASTRO DISCENTE |\n");
    printf("\t+-------------------+\n");

    printf("\n\t> Digite o CPF: ");
    fgets(discentes[quantDisc].cpf, 15, stdin);
    discentes[quantDisc].cpf[strcspn(discentes[quantDisc].cpf, "\n")] = '\0';

    int soNumeros = 1;
    for (int i = 0; i < strlen(discentes[quantDisc].cpf); i++) {
        if (!isdigit(discentes[quantDisc].cpf[i])) {
            soNumeros = 0;
            break;
        }
    }

    if (soNumeros == 0) {
        printf("\n\t[AVISO] O CPF deve conter apenas numeros (sem letras ou pontos)[AVISO]\n");
        printf("\tPressione qualquer tecla para voltar...");
        fflush(stdin);
        getchar();
        return;
    }

    for(int i=0; i<quantDisc; i++){
        if(strcmp(discentes[quantDisc].cpf, discentes[i].cpf) == 0){
            achou = 1;

            printf("\n\t[AVISO] CPF %s já cadastrado no sistema [AVISO''']\n", discentes[quantDisc].cpf);
            printf("\tPressione qualquer tecla para voltar ao menu principal...");
            fflush(stdin);
            getchar();

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

    printf("\tPressione qualquer tecla para voltar ao menu principal...");
    fflush(stdin);
    getchar();

}

void excDiscente(){

    char cpfBusca[15];
    int achou = 0;

    getchar();
    system("cls");

    printf("\n\t+-----------------------+\n");
    printf("\t|   EXCLUIR DISCENTE    |\n");
    printf("\t+-----------------------+\n");
    printf("\n\t> Digite o CPF do discente que deseja excluir: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

    int opE;

    for(int i = 0; i < quantDisc; i++){
         if(strcmp(discentes[i].cpf, cpfBusca) == 0){
            achou = 1;

            do{
                system("cls");

                printf("\n\t+------------------------+\n");
                printf("\t|   DISCENTE ENCONTRADO  |\n");
                printf("\t+------------------------+\n");
                printf("\n\t>Nome: %s\n", discentes[i].nome);
                printf("\t>idade: %d\n", discentes[i].idade);
                printf("\t>CPF: %s\n", discentes[i].cpf);

                printf("\n");

                printf("\t+-------------------------------------+\n");
                printf("\t| Deseja excluir os dados do discente |\n");
                printf("\t+-------------------------------------+\n");
                printf("\t1 - SIM\n");
                printf("\t2 - NAO\n");
                printf("\t> informe a opcao: ");

                if(scanf("%d", &opE) != 1){
                fflush(stdin);
                }

                printf("\n");

                switch(opE){

                case 1:

                    for(int j = i; j < quantDisc - 1; j++){
                            discentes[j] = discentes[j + 1];
                    }

                    quantDisc--;
                    salvarDiscentes();

                    printf("\n\tDiscente excluido com sucesso!\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                    continue;

                case 2:
                    printf("\n\tExclusao cancelada.\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    printf("\tPressione qualquer tecla para voltar...");
                    fflush(stdin);
                    getchar();
                    break;

                }

            }while(1);



        }

   }

   if(achou == 0) {
        printf("\n\n\t[AVIOS] Discente com CPF %s nao encontrado! [AVISO]\n", cpfBusca);
        printf("\tPressione qualquer tecla para voltar ao menu principal...");
        fflush(stdin);
        getchar();
    }

}

void ediDiscente(){

    getchar();

    char cpfBusca[15];
    int achou = 0;
    int opD;

    system("cls");

    printf("\n\t+---------------------+\n");
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

                printf("\n\t+-----------------------+\n");
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

                if(scanf("%d", &opD) != 1){
                fflush(stdin);
                }

                printf("\n");

                switch(opD){
                case 1:
                    getchar();

                    printf("\n\t+---------------+\n");
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
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                    continue;

                case 2:
                    printf("\n\tEdição cancelada.\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    printf("\tPressione qualquer tecla para voltar...");
                    fflush(stdin);
                    getchar();
                    break;

                }

            }while(1);

        }

    }

    if(achou == 0){
        printf("\n\t[AVISO] CPF do discente não encontrado [AVISO]\n");
        printf("\tPressione qualquer tecla para voltar ao menu principal...");
        fflush(stdin);
        getchar();

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

            printf("\t\nPressione qualquer tecla para voltar ao menu principal...");
            fflush(stdin);
            getchar();

        }
    }
    if(achou == 0){
        printf("\n\t[AVIOS] CPF do discente não encontrado [AVISO]\n");
        printf("\tPressione qualquer tecla para voltar ao menu principal...");
        fflush(stdin);
        getchar();
    }



}

//===== ARQUIVOS DISCENTE =====

int salvarDiscentes(){

    FILE *d = fopen("discentes.txt", "w");

    if(d == NULL){

        printf("\t[ERRO] Arquivo não encontrado.\n");
        return 1;
    }

    for(int i=0; i<quantDisc; i++){

        fprintf(d, "%s;%s;%d\n", discentes[i].cpf, discentes[i].nome, discentes[i].idade);

    }

    fclose(d);

    printf("\n\tDados salvos com sucesso em discentes.txt!\n");

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

//==== FUNCÕES CURSOS =====

void cadCurso(){

    getchar();

    if (quantCurs >= MAXcurso){
        printf("\n\t[ERRO] Limite de cadastros atingido!\n");
        system("pause");
        return;
    }

    system("cls");

    int achouNome = 0;

    printf("\n\t+--------------------+\n");
    printf("\t|   CADASTRO CURSO   |\n");
    printf("\t+--------------------+\n");

    printf("\t> Digite o nome: ");
    fgets(cursos[quantCurs].nomeCurso, 100, stdin);
    cursos[quantCurs].nomeCurso[strcspn(cursos[quantCurs].nomeCurso, "\n")] = '\0';

    if(quantCurs != 0){
        for(int i=0; i<quantCurs; i++){
            if(strcmp(cursos[quantCurs].nomeCurso, cursos[i].nomeCurso) == 0){
                achouNome = 1;
                printf("\n\t[AVISO] Curso %s ja cadastrado [AVISO]\n", cursos[quantCurs].nomeCurso);
                printf("\tPressione qualquer tecla para voltar ao menu principal...");
                fflush(stdin);
                getchar();

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
            printf("\tPressione qualquer tecla para voltar ao menu principal...");
            fflush(stdin);
            getchar();

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

    printf("\tPressione qualquer tecla para voltar ao menu principal...");
    fflush(stdin);
    getchar();

}

int salvarCursos(){

    FILE *c;

    c = fopen("cursos.txt", "w");

    if(c == NULL){

        printf("\t[ERRO] Arquivo não encontrado.\n");
        return 1;
    }

    for(int i=0; i<quantCurs; i++){
        fprintf(c, "%s;%d;%d;%d;%d\n", cursos[i].nomeCurso, cursos[i].codigo, cursos[i].horas, cursos[i].numVagas, cursos[i].numPart);

    }

    fclose(c);

    printf("\n\tDados salvos com sucesso em cursos.txt!\n");

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

                if(scanf("%d", &opC) != 1){
                fflush(stdin);
                }

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
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                    continue;


                case 2:
                    printf("\n\tEdição cancelada.\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    printf("\tPressione qualquer tecla para voltar...");
                    fflush(stdin);
                    getchar();
                    break;

                }

            }while(1);



        }

   }

   if(achou == 0) {
        printf("\n\n\t[AVIOS] Curso com codigo %d nao encontrado! [AVISO]\n", codBusca);
        printf("\tPressione qualquer tecla para voltar ao menu principal...");
        fflush(stdin);
        getchar();
    }

}

void pesCurso(){

    getchar();

    int achou = 0;
    int codBusca = 0;

    system("cls");

    printf("\t+---------------------+\n");
    printf("\t|   PROUCURAR CURSO   |\n");
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


            printf("\n\tPressione qualquer tecla para voltar ao menu principal...");
            fflush(stdin);
            getchar();

        }

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

            if(scanf("%d", &opC) != 1){
            fflush(stdin);
            }

            printf("\n");

            switch(opC){
            case 1:

                for(int j = i; j < quantCurs - 1; j++){
                            cursos[j] = cursos[j + 1];
                    }

                    quantCurs--;
                    salvarCursos();

                    printf("\n\tCurso excluido com sucesso!\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                    continue;
            case 2:
                    printf("\n\tExclusao cancelada.\n");
                    printf("\tPressione qualquer tecla para voltar ao menu principal...");
                    fflush(stdin);
                    getchar();
                    return;

                default:
                    printf("\t[AVISO] Opcao invalida... [AVISO]\n");
                    printf("\tPressione qualquer tecla para voltar...");
                    fflush(stdin);
                    getchar();
                    break;

                }

            }while(1);

        }

    }

}
