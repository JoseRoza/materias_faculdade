#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_dados Node;
typedef struct list List;
bool isNull(const List *l);
Node *create_node (char caracter);
List *create_list();
void insere_dados(List *l, char letra);
//void exluir_lista(List **ref_l);

int main (){
    FILE *arq;
    arq = fopen("arq.c", "r");

    List *lista[50];

    int i=0; // contador da lista, cada i vai ser uma palavra
    
    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }

    lista[0] = create_list();

    char aux = fgetc(arq);
    while(aux != EOF){ 

        if(aux != ' ' && aux != '\n' && aux != '\t'){
            printf("%c", aux);
            insere_dados(lista[i], aux);
            aux = fgetc(arq);
        }
        else {
            if (aux == '\n') {
                aux = fgetc(arq);
                aux = fgetc(arq);
                aux = fgetc(arq);
                aux = fgetc(arq);
            }
            i++;
            lista[i] = create_list();
        }

    }
    fclose(arq);
    printf("\n\n");

    return 0;
}

// criar uma funcao para definir os token do arquivo de saida

typedef struct  node_dados {
    char letras;
    struct node_dados *next;
}Node;

typedef struct list {
    Node *inicio, *fim;
    long int size;
} List;

bool isNull(const List *l){
    return l->inicio == NULL;
}

Node *create_node (char caracter){
    Node *aux = (Node*)calloc(1, sizeof(Node));
    aux->letras = caracter;
    aux->next = NULL;

    return aux;
}

List *create_list() {
    List *l = (List*)calloc(1, sizeof(List));
    l->inicio = NULL;
    l->fim = NULL;
    l->size = 0;

    return l;
}

void insere_dados(List *l, char letra){ // adicionando apenas no final, pq ? pq eh uma palavra!
    Node *alpha = create_node(letra);
    if (isNull(l)) l->inicio = alpha;
    else {
        Node *aux = l->inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = alpha;
    }
    printf("%c", letra);
    l->size ++;
}
/*
void exluir_lista(List **ref_l){
    List *l = *ref_l;
    Node *pont = l->inicio;
    Node *aux = NULL;

    while(pont != NULL){
        aux = pont;
        pont = pont->next;
        free(aux);
    }
    free(l);
    *ref_l = NULL;
    printf("\nlista totalmente desalocada!\n");
}*/