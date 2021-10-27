/*
    Criado por Gab Zancheta Scavazini
    User: Caravori
    Materia: Estrutura de dados II
    Segue a licença GNUv3, ou seja UTILIZE E REAPROVEITE
    Quaisquer dúvidas fique livre para me chamar gabriel.scavazini@unesp.br
*/


#include <stdlib.h>
#include <stdio.h>
#include "libHas.h"
#include "libSort.h"


int main(void){

    dados *vetor[SIZE];
    float num;

    init_dados(vetor);
    int options=10;
    while(options!=0){
        printf( "\n\nMenu:\n\t-------Tabela Hash-------\n\t|\t1-Inserir\t|\n\t|\t2-Buscar\t|\n\t|\t3-Remover\t|\n\t|\t4-Mostrar Lista\t|\n\t|\t5-Ordenar\t|\n\t|\t0-Sair\t\t|\n\t-------------------------\nOpção: ");
        scanf(" %d",&options);
        switch(options){
            case 1:{
                printf("\nDigite o número: ");
                scanf(" %f",&num);
                insere_dados(vetor,num);
               break;
            }
                
            case 2:{
                
                printf( "\nDigite o número: ");
                scanf(" %f",&num);
                busca_dados(vetor,num);
               break;
            }
            case 3:{
                printf( "\nDigite o número: ");
                scanf(" %f",&num);
                remove_dados(vetor,num);
                break;
            }
            case 4:{
                printf("\n");
                print_dados(vetor);
                break;
            }
            case 5:{
                for(int i=0;i<SIZE;i++){
                    MergeSort(&vetor[i]);
                }
                break;
            }
            case 0:{
                for(int i=0;i<SIZE;i++){
                    while(vetor[i]!=NULL){
                        vetor[i] = removerNo(vetor[i]);
                    }
                }
                exit(0);
            }
            default:
                printf("Opção inválida!");
                break;
        }
    }
}