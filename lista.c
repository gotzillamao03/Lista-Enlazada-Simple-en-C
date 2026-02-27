#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* ----------- Función interna ----------- */
static Nodo* CrearNodo(Libro* libro) {
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nodo) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(nodo->libro.titulo, libro->titulo, MAX_TITULO - 1);
    nodo->libro.titulo[MAX_TITULO - 1] = '\0';

    strncpy(nodo->libro.autor, libro->autor, MAX_AUTOR - 1);
    nodo->libro.autor[MAX_AUTOR - 1] = '\0';

    strncpy(nodo->libro.isbn, libro->isbn, MAX_ISBN - 1);
    nodo->libro.isbn[MAX_ISBN - 1] = '\0';

    nodo->siguiente = NULL;
    return nodo;
}

/* ----------- Inicialización ----------- */
void InicializarLista(Lista* lista) {
    lista->cabeza = NULL;
    lista->longitud = 0;
}

void DestruirLista(Lista* lista) {
    while (!EstaVacia(lista)) {
        EliminarPrincipio(lista);
    }
}

/* ----------- Inserciones ----------- */
void InsertarPrincipio(Lista* lista, Libro* libro) {
    Nodo* nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, Libro* libro) {
    Nodo* nodo = CrearNodo(libro);

    if (EstaVacia(lista)) {
        lista->cabeza = nodo;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo;
    }

    lista->longitud++;
}

/* ----------- Eliminaciones ----------- */
void EliminarPrincipio(Lista* lista) {
    if (!EstaVacia(lista)) {
        Nodo* temp = lista->cabeza;
        lista->cabeza = temp->siguiente;
        free(temp);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista* lista) {
    if (EstaVacia(lista)) return;

    if (lista->cabeza->siguiente == NULL) {
        free(lista->cabeza);
        lista->cabeza = NULL;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente->siguiente != NULL) {
            actual = actual->siguiente;
        }
        free(actual->siguiente);
        actual->siguiente = NULL;
    }

    lista->longitud--;
}

void EliminarElemento(Lista* lista, int indice) {
    if (indice < 0 || indice >= lista->longitud) return;

    if (indice == 0) {
        EliminarPrincipio(lista);
        return;
    }

    Nodo* actual = lista->cabeza;
    for (int i = 0; i < indice - 1; i++) {
        actual = actual->siguiente;
    }

    Nodo* temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);
    lista->longitud--;
}

/* ----------- Acceso ----------- */
Libro* Obtener(Lista* lista, int indice) {
    if (indice < 0 || indice >= lista->longitud) return NULL;

    Nodo* actual = lista->cabeza;
    for (int i = 0; i < indice; i++) {
        actual = actual->siguiente;
    }

    return &actual->libro;
}

/* ----------- Utilidad ----------- */
int EstaVacia(Lista* lista) {
    return lista->cabeza == NULL;
}

int Contar(Lista* lista) {
    return lista->longitud;
}

void MostrarLista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    int i = 1;

    while (actual != NULL) {
        printf("%d. %s - %s - %s\n",
               i,
               actual->libro.titulo,
               actual->libro.autor,
               actual->libro.isbn);
        actual = actual->siguiente;
        i++;
    }
}