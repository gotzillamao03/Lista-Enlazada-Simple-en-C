#ifndef LISTA_H
#define LISTA_H

#include "libro.h"

typedef struct Nodo {
    Libro libro;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int longitud;
} Lista;

/* Inicialización y destrucción */
void InicializarLista(Lista* lista);
void DestruirLista(Lista* lista);

/* Operaciones básicas */
void InsertarPrincipio(Lista* lista, Libro* libro);
void InsertarFinal(Lista* lista, Libro* libro);
Libro* Obtener(Lista* lista, int indice);
void EliminarPrincipio(Lista* lista);
void EliminarUltimo(Lista* lista);
void EliminarElemento(Lista* lista, int indice);

/* Utilidad */
int EstaVacia(Lista* lista);
int Contar(Lista* lista);
void MostrarLista(Lista* lista);

#endif