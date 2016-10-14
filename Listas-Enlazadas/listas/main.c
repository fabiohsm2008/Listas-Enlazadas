#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int value;
    struct nodo *next;
};

void crear_lista(struct nodo *inicio ,int n)
{
    struct nodo *prev, *actual;
    int i;
    prev = inicio;
    for (i = 2; i <= n; i++){
        actual = malloc(sizeof(struct nodo));
        actual -> value = i;
        prev -> next = actual;
        prev = actual;
    }
    prev -> next = NULL;

}

void eliminar(struct nodo *lista)
{
    int elemento;
    printf("\n Elemento a eliminar: ");
    scanf("%d", &elemento);
    struct nodo *prev, *actual;
    prev = lista;
    actual = prev -> next;
    if (lista -> value == elemento){
        lista = lista -> next;
        free(prev);
    }
    else{
        while(actual != NULL){
            if (actual -> value == elemento){
                prev -> next = actual -> next;
                free (actual);
                break;
            }
            prev = actual;
            actual = actual -> next;
        }
    }
    imprimir(lista);
}

void insertar_inicio(struct nodo *lista)
{
    int valor;
    printf("\n Valor a insertar al inicio: ");
    scanf("%d", &valor);
    struct nodo *insercion, *temp, *actual;
    insercion = malloc(sizeof(struct nodo));
    insercion -> value = valor;
    insercion -> next = NULL;
    actual = lista -> next;
    temp = lista;
    lista = insercion;
    insercion = temp;
    lista -> next = insercion;
    insercion -> next = actual;
    imprimir(lista);
}

void insertar_medio(struct nodo *lista)
{
    int posicion, valor;
    printf("\n Posicion donde se insertara el elemento: ");
    scanf("%d",&posicion);
    printf("\n Elemento a insertar: ");
    scanf("%d", &valor);
    if (posicion < 0){
        printf("Solo un rango positivo");
        return insertar_medio(lista);
    }
    struct nodo *prev, *actual, *insercion;
    insercion = malloc(sizeof(struct nodo));
    insercion -> value = valor;
    insercion -> next = NULL;
    prev = lista;
    actual = prev -> next;
    for (; posicion > 1; --posicion){
        prev = actual;
        actual = prev -> next;
        if (actual == NULL)
            break;
    }
    prev -> next = insercion;
    insercion -> next = actual;
    imprimir(lista);
}

void insertar_orden(struct nodo *lista)
{
    int elemento;
    printf("\n Elemento a insertar en orden: ");
    scanf("%d", &elemento);
    struct nodo *prev, *insercion, *actual, *temp;
    insercion = malloc(sizeof(struct nodo));
    insercion -> value = elemento;
    insercion -> next = NULL;
    prev = lista;
    actual = prev -> next;
    if (elemento <= lista -> value){
        temp = lista;
        lista = insercion;
        insercion = temp;
        lista -> next = insercion;
        insercion -> next = actual;

    }
    else{
        while(actual != NULL){
            if (elemento <= actual -> value){
                insercion -> next = actual;
                prev -> next = insercion;
                break;
            }
            prev = actual;
            actual = prev -> next;
            if (actual == NULL){
                prev -> next = insercion;
                insercion -> next = NULL;
                break;
            }
        }
    }
    imprimir(lista);

}

void concatenar (struct nodo *listaA, struct nodo *listaB)
{
    struct nodo *prev, *actual;
    prev = listaA;
    actual = prev -> next;
    while(actual != NULL){
        prev = actual;
        actual = prev -> next;
    }
    prev -> next = listaB;
    printf("\n");
    imprimir(listaA);
}

void imprimir(struct nodo *lista)
{
    printf("[");
    while (lista != NULL){
        if (lista -> next == NULL){
            printf("%d", lista -> value);
            lista = lista -> next;
        }
        else{
            printf("%d,", lista -> value);
            lista = lista -> next;
        }
    }
    printf("]");
}

int main()
{
    int largo;
    largo = 10;
    struct nodo *listaA;
    listaA = malloc(sizeof(struct nodo));
    listaA -> value = 1;
    listaA -> next = NULL;
    crear_lista(listaA,largo);
    imprimir(listaA);

    printf("\n");

    struct nodo *listaB;
    listaB = malloc(sizeof(struct nodo));
    listaB -> value = 1;
    listaB -> next = NULL;
    crear_lista(listaB,largo);
    imprimir(listaB);

    eliminar(listaA);
    insertar_inicio(listaA);
    insertar_medio(listaA);
    insertar_orden(listaA);
    concatenar(listaA, listaB);
    return 0;
}
