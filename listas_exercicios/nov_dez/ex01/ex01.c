#include "ex01.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node{
    int alt, idade;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_list{
    Node *inicio;
    Node *fim;
    size_t size, capacity;
}List, List;

Node *create_node(int altura, int idade){
    Node *node = (Node*)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->alt = altura;
    node->idade = idade;

    return node;
}

List *create_list(){
    List *list = (List*)calloc(1, sizeof(List));

    list->inicio = NULL;
    list->fim = NULL;
    list->size = 0;
    list->capacity = 10000;

    return list;
}

bool _isNull_dupla(const List *list){
    return list->size == 0;
}

bool _isFull_dupla(const List *list){
    return list->capacity == 10000;
}

void destroy_dupla(List **ref_list){
    List *aux_list = *ref_list;
    
    Node *p = aux_list->inicio;
    while(p != NULL){
        Node *aux = p;
        aux = p;
        p = p->next;
        free(aux);
    }
    free(aux_list);
    *ref_list = NULL;
    printf("lista totalmente desalocada!\n");
}

void add_final_dupla(List *list, int alt, int idd){
    Node *aux = create_node(alt, idd);

    if(_isNull_dupla(list))list->inicio = list->fim = aux;
    else{

        if(list->size <= list->capacity){
            list->fim->next = aux;
            aux->prev = list->fim; 
            list->fim = aux;
        } else fprintf(stderr, "capacidade maxima excedida!\ntotal de %ld pessoas cadastradas", list->capacity);
    }
    list->size++;
}

void imprimir_lista(const List *list){
    Node *aux = list->inicio;

    printf(" IDADE | ALTURA |\n");
    while(aux != NULL){
        printf("\t%d\t|\t%d\t\n", aux->idade, aux->alt);
        aux = aux->next; //passa para imprimir o elemento a frente
    }
    printf("quantidade de cadastros: %ld", list->size);
}