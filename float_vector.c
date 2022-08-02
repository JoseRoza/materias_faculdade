#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isfull(FloatVector *vector)
{
    return capacity == size;
    /*jeito do beto --> vector->capacity == vector->size */
}
struct float_vector
{
    int capacity; //numero maximo de elementos
    int size; //controlar a quantidade atual de elementos
    float *data; //vetor de float
};

/**
*@brief Cria(aloca) um vetor de flaot com uma dada capacidade
*
* @param tam
* @return FloatVector* ponteiro de um vetor de floats
**/

FloatVector *create (int tam) //aloca dinamicamente
{
FloatVector *vet = (FloatVector*)calloc(1, sizeof(FloatVector)); //quantidade
vet -> capacity = tam;
vet -> size = 0;
vet -> data = (float*) calloc(vet->capacity, sizeof(float));
//vet -> data = (float*) malloc(quantidade de vetor * tam)

return vet;
}

void destroy (FloatVector **vet_ref)
{
    FloatVector *vet = *vet_ref;
    free(vet->data); //pegou a strutura e dentro dela, entrou na var data e destruiu ela
    free(vet); //aqui destruiu a estrutura inteira
    *vet_ref = NULL; //setamo null no valor da função main para não causar um mal subito no pc 
}

//maneira mais "facil de retornar o valor", poderiamos usar um sizeof, todavia seria mais compliado, ainda que funcione
int size(const FloatVector *vector)
{
    return vector -> size;
}

int capacity (const FloatVector *vector)
{
    return vector->capacity;
}

//trata o erro, quando não sabe o que tem dentro
float at(const FloatVector *vector, int pos)
{
    if (pos < 0 || pos >= vector->size)
    {
        fprintf(stderr, "Erro: posicao invalida\n");
        fprintf(stderr, "Index [%d] is out of bounds\n");
        exit(EXIT_FAILURE);//programa termina de maneira subta com erro
    }
    return vector->data[pos];
}

//não trata o erro, quando sabe extamente o que esta dentro do vetor... e quando voce sabe isso ? quando o vetor está cheio
// como saber se o vetor está cheio ? usando a caácidade
float get(const FloatVector *vector, int index)
{
    return vector->data[index];
}

void append(FloatVector *vector, float n)
{
    if(_isfull(vector))
    {
        fprintf(stderr, "Erros: nao eh possivel inserir dados");
        exit(EXIT_FAILURE);
    }
    vector->data[vector->size++] = n;

    /*if(capacity == size)printf("ERRO: nao eh possivel inserir dados");
    exit(1);*/
}

void print(const FloatVector *vector)
{
    for(int i = 0; i  < vector->size; i++)
    {
        printf("[%d]", vector->data[i]);
    }
}

void set(const FloatVector *vector)
{
    // vetor atual = novos dados ?
    printf("dados substituidos!\n");
    for(int i = 0; i < vector->size; i++)
    {
        printf("[%d]", vector->data[i]);
    }
}