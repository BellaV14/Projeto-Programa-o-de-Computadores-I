#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
        char titulo [200];
        int id;
        int ano;
        char categoria [100];
        char estrela [6];
    } Livro;

 //essa funçao vai procurar se ja ha um id x adcionado (um id por livro)   
int search_id (Livro *vetor, int total_livros, int id){
    for (int i = 0; i < total_livros; i++){
        if (vetor[i].id == id ){
            return 1;
        }
    } 
    return 0;
}

void cadastrar_livro ( Livro **vetor, int *total_livros ) { 
    char r;
    Livro livro ;
    do {

        printf ("CADASTRE O LIVRO: \n");


        printf ("ID da obra: \n");
        scanf ("%d", &livro.id);

            while ( search_id (*vetor, *total_livros, livro.id)) {
            printf("O ID %d ja esta cadastrado. Digite outro ID: ", livro.id);
            scanf("%d", &livro.id);
            } //chama uma função que verificará se aquele id ja existe

        printf ("Título da obra: \n");
        fgets (livro.titulo, sizeof (livro.titulo), stdin);

        printf ("Ano de publicação da obra: \n");
        scanf ("%d", &livro.ano);

        printf ("Qual a categoria da obra: \n");
        fgets (livro.categoria, sizeof (livro.categoria), stdin);

        printf ("Estrelas para a obra (*): \n");
        fgets (livro.estrela, sizeof (livro.estrela), stdin);

        //irá tentar realocar memória na heap para o novo livro que foi cadastrado
        //realloc esta passando o vetor antigo e o tamanho do vetor novo
        //realloc retornará um novo ponteiro que aponta para a nova região de memória
        Livro *temporario = realloc (*vetor, (*total_livros + 1) * sizeof(Livro));

            if ( temporario == NULL) {
                printf ("Memória insuficiênte");
                return ;
            }

            *vetor = temporario; //recebe o novo ponteiro com a nova região de memória
            *total_livros += 1;
            (*vetor)[*total_livros] = livro; //coloca o novo livro adc no final vetor dinamico no qual o indice é *total_livros 

        printf ("Deseja cadastrar mais um livro ?\n");
        scanf (" %c",&r);
    
    } while ( r == 's' || r == 'S'); 

    printf("cadastro encerrado");
}


void listar_livros (Livro **vetor, int *total){
    int opcao;

    if (*total ==0){
        printf("Não há livros adcionados :( \n");
    }

    do {

        printf("----- Lista de todos os livros -----\n");
        printf("Opções: \n");
        printf("1 - Ordenar por título\n");
        printf("2 - Ordenar por ano\n");
        printf("3 - sair\n");
        scanf("%d",&opcao);

        if (opcao == 1){ //bubble sort com letras da string .titulo
            char prim [200]; //vetor auxiliar da inversão

             for (int i = 0; i < *total; i++){
                for (int j = 0; j < *total; j++){
                    if (strcmp ((*vetor)[j].titulo, (*vetor)[j+1].titulo > 0)){//compara 2 strings e retorna 0 se a 1ºvier DEPOIS da 2º
                        strcpy (prim, (*vetor)[j].titulo);//essa funçao copia uma string para dentro da outra
                        strcpy ((*vetor)[j].titulo,(*vetor)[j+1].titulo);
                        strcpy ((*vetor)[j+1].titulo,prim);//no final esta invertendo a posiçao de j com j+1 (deixar na ordem alfab.)
                    }

                }
             }

             printf("Listagem por título: ");//com o vetor ja todo ordenado, aq vai imprimir na ordem certa
            for (int i = 0; i < *total; i++){
                printf("%s\n",(*vetor)[i].titulo);
            }
             
        }

        if (opcao == 2){    //bubble sort com números (anos)
            int maior;

            for (int i = 0; i < *total; i++){
                for (int j = 0; j < *total; j++){
                    if ((*vetor)[j].ano > (*vetor)[j+1].ano) {
                        maior = (*vetor)[j].ano;
                    (*vetor)[j].ano = (*vetor)[j+1].ano;
                        (*vetor)[j+1].ano= maior;
                    }
                }    
            }
        }

            printf("Listagem Antigo -> Recente: ");//apos organizar p ordem de anos,imprime os livros
            for (int i = 0; i < *total; i++){
                printf("%d",(*vetor)[i].ano);
            }
        

    } while (opcao != 3);


void estrelas(int *vetor, int *total){

printf("-----Avaliação com Estrelas GIsas-----\n");
printf("Sumário:\n");
printf("*   RUIM\n");
printf("**   MEDIANO\n");
printf("***   BOM\n");
printf("****   ÓTIMO\n");
printf("*****   EXCELENTE\n");

if (*total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

printf("Listagem por título: ");
    for (int i = 0; i < *total; i++){
        printf("%s\n",(*vetor)[i].titulo);
        printf("%s\n",(*vetor)[i].estrela);
    }
}

int buscar_livros (int **vetor, int *total_livros){
    int opcao;
    char frase[200], escritor[200], genero[200];

     do {

        printf("----- Buscar por livro -----\n");
        printf("Opções: \n")
        printf("1 - Buscar por título\n");
        printf("2 - Buscar por autor\n");
        printf("3 - Buscar por categoria\n");
        printf("4 - Sair\n");
        scanf("%d",&opcao);

        switch (opcao){

            case 1:
                printf("Digite o título: \n");
                fgets(frase, sizeof (frase),stdin);

                char *resultado = strstr ((*vetor).titulo, frase);

                if (resultado != NULL){
                    printf("%s\n",resultado);

                } else {

                    printf("Título não encontrado\n");
                }    

            break;

            case 2:
                printf("Digite o autor: \n");
                fgets(escritor, sizeof(escritor),stdin);

                char *result = strstr ((*vetor).autor, escritor);

                if (result != NULL){
                    printf("%s\n",result);
                } else {
                    printf("Autor não encontrado\n");
                }

            break;

            case 3:
                printf("Digite a categoria: \n");
                fgets(genero, sizeof(genero),stdin);

                char *resposta = strstr ((*vetor).categoria, genero);

                if (resposta != NULL){

                    printf("%s\n",resposta);
                }else {

                    printf("Categoria não encontrada\n");
                }

            break;
        
        default:
            break;
        }

      } while (opcao = 4);
}

int main () {
    int opcao, total_livros = 0;
    Livro *vetor = NULL;

    do {

        printf("Seja bem-vindo à Biblioteca GIsa\n");
        printf ("------ MENU PRINCIPAL ------\n");
        printf ("1 - Cadastrar livro\n");
        printf ("2 - Listar todos os livros\n");
        printf ("3 - Buscar livros\n");
        printf ("4 - Remover livro por ID\n");
        printf ("5 - Avaliação");
        printf ("6 - Sair\n");
        printf ("Escolha a opção desejada:\n");

        scanf ("%d",&opcao);

       switch (opcao){

            case 1 :
                cadastrar_livro ( &vetor, &total_livros);
                break;

            case 2 :
                listar_livros (&vetor, &total_livros);
                break;

            case 3 :
                buscar_livros (&vetor, &total_livros);
                break;

            case 4 :
                remover_livros ();
                break;

            case 5:
                estrelas (&vetor, &total_livros);
                break;

            case 6 :
                Printf("Programa finalizado.");
                free(vetor);    //liberar a memória da heap
                return 0;

            default:
                printf("Opcao invalida.\n");

       }
    } while (opcao != 5);

    return 0;
}