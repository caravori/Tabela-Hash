/*
    A main não necessita de comentários, afinal é apenas um switch.
    Praticamente tudo está definido nesta biblioteca, exceto o merge sort.
*/


#ifndef LIB_HAS
#define LIB_HAS
#define SIZE 4
#include <stdlib.h>
#include <stdio.h>


//Declara a struct utilizada.
typedef struct dados {
    float content;//pode ser substituido por int sem perca
    struct dados *next;
}dados;

void init_dados(dados **vetor){//inicializa o vetor de dados para SIZE valores
    for(int i = 0;i<SIZE;i++){
        vetor[i]=NULL;
    }
}
void insere_dados(dados **vetor,float num){//insersão comum de dados encadeados. Basicamente caminha pela vetor ate encontrar NULL e aloca no final
    int mod = (int)num%SIZE;               //Por alocar no final é linear O(1)
    dados *new_data = malloc(sizeof(dados));//por algum motivo c++ não aceita esse tipo de colocação. 
    
    new_data->content = num;
    new_data->next    = NULL;

    dados *aux = vetor[mod];
    if(aux==NULL){
        vetor[mod] = new_data;
    }
    else{
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = new_data;
    }
}

void print_dados(dados **vetor){//Percorre todo o hash, printando cada um de seus elementos
    dados *aux;
    for(int i = 0;i<SIZE;i++){
        if(vetor[i]==NULL){//se não tiver dados printa NULL
            printf("[ %d ] -- NULL\n",i);
        }
        else{
            aux = vetor[i];
            printf("[ %d ] -- %f",i,aux->content);
            while(aux->next!=NULL){
                aux = aux->next;
                printf(" -- %f",aux->content);
            }
            printf("\n");
        }
    }
}


void busca_dados(dados **vetor,float num){//Busca de multiplos dados, funciona ate 100 dados iguais. Mais do que isso recomendo alocar dinamicamente.
    int found = 0;
    int a_iter[100];
    float a_content[100];
    dados *aux;
    int iter=0;
    int mod = (int)num%SIZE;
    if(vetor[mod]==NULL){//Se for NULL mod vazio
        printf("Não encontrado, tamanho da busca (%d)\n",iter);
        return;
    }
    aux = vetor[mod];
    if(aux->content==num){//Existe na primeira posição
        printf("Encontrado [ %d ] -- %f\n",mod,aux->content);
    }
    if(aux->next!=NULL){//existe outras posições
        while(aux->next!=NULL){
            iter++;
            aux = aux->next;
            if(aux->content==num){//Existe outros valores válidos, armazena eles utilizando vetores auxiliares.
                found = 1;//Flag 
                a_iter[iter] = iter;
                a_content[iter] = aux->content;
                
            }
        }
        if(found==1){//Se existe mais de 1, mostra todos
            for (int i = 1;i<=iter;i++){
                printf("Encontrado [ %d ] -- (..%d..) -- %f\n",mod,a_iter[i],a_content[i]);
            }
            return;
        }
        else{//ultimo caso, se não existir e mostra sua complexidade o(i)
            printf("Não encontrado, tamanho da busca (%d)\n",iter);
        }
    }
    

}


void remove_dados(dados **vetor,float num){
    int  mod = (int)num%SIZE;
    if(vetor[mod]==NULL){//verifica se é nulo, se for... o valor não existe. 
        return;
    }
    dados *aux = vetor[mod];
    dados *anterior;
    if(vetor[mod]->content==num){//O valor existe e está na primeira posição
        vetor[mod] = vetor[mod]->next;
        free(aux);//Destroi aux que apontava para a primeira posição de vetor[mod]
        return;
    }
    else{
        while(aux->next!=NULL){//O valor talvez exista mas não está na primeira posição
            anterior = aux;
            aux = aux->next;
            if(aux->content==num){//se encontar, pega o anterior, libera o aux e liga o proximo ao anterior.
                anterior->next = aux->next;
                free(aux);
                return;
            }

        }
    }
}

dados *removerNo(dados *vetor){
    dados* aux = vetor;
    if(vetor == NULL){
        return vetor;
    }
    else{
        vetor = aux->next;
        free(aux);
    }
    return vetor;
}
#endif
