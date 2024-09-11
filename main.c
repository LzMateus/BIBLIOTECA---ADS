#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h" // BIBLIOTECA DO MENU
#include "renovar.h" //BIBLIOTECA DAS DEMAIS FUNCOES CONFIGURACOES
/*----------------------------------------------------------------------------------------------------------------------------------------*/
#define MAX_SOCIOS 100 // Define o número máximo de sócios
#define MAX_LIVROS 100 // Define o número máximo de livros
#define MAX_EXEMPLARES 100 // Define o número máximo de exemplares
#define MAX_EMPRESTIMOS 100 // Define o número máximo de empréstimos
#define MAX_NOME 100 // Define o tamanho máximo para o nome
#define STRTAM 30 // Define um tamanho padrão para strings

int main() {
    //setlocale(LC_ALL, "Portuguese"); // Configura a localidade para suportar caracteres especiais do português

    int opcao; // armazenar a opção escolhida pelo usuário

    do {
        montaMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                cadastrarSocio(); 
                break;
            case 2:
                cadastrarLivro();
                break;
           case 3:
               cadastrarExemplar();
               break;
            case 4:
                realizarEmprestimo();
                break;
            case 5:
                devolverExemplar();
                break;
            case 6:
                renovarEmprestimo();
                break;
                case 7:
                listarSocios();
                break;
                case 8:
                listarLivros();
                break;
                case 9:
                realizarEmprestimo();
salvarComprovanteEmprestimo(numEmprestimos); // Salva o comprovante do último empréstimo realizado
            break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
                
        }
    } while (opcao != 0);
    

    return 0;
}
