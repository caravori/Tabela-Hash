#ifndef LIB_SORT
#define LIB_SORT
#include "libHas.h"

//NAO MEXER, qualquer adição e/ou modificação irá quebrar o código. 
void FrontBackSplit(dados* source,
                    dados** frontRef, dados** backRef)
{
    dados* prox;
    dados* ante;
    ante = source;
    prox = source->next;
 
    while (prox != NULL) {
        prox = prox->next;
        if (prox != NULL) {
            ante = ante->next;
            prox = prox->next;
        }
    }
  
    *frontRef = source;
    *backRef = ante->next;
    ante->next = NULL;
}
 
dados* SortedMerge(dados* a, dados* b)
{
    dados* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (a->content <= b->content) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}


void MergeSort(dados** headRef)
{
    dados* head = *headRef;
    dados* a;
    dados* b;
 
    
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    FrontBackSplit(head, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);
 
    *headRef = SortedMerge(a, b);
}
 


#endif