#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void add(no **inicio, int dado)
{
    no *novo = (no*) malloc(sizeof(no));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}

bool remover(no **inicio, int dado)
{
    no *atual = *inicio;
    no *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
                *inicio = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void imprimir(no **inicio)
{
    no *atual = *inicio;
    while(atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void destruir(no **inicio)
{
    no *atual = *inicio;
    no *prox;
    while (atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

int buscarValor(no **inicio, int valor)
{
    no *atual = *inicio;
    int idLista = 0;
    while(atual != NULL)
    {
        if (atual->dado == valor)
            return idLista;
        idLista++;
        atual = atual->proximo;
    }
    return -1;
}