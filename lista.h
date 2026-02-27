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

// Prototipos
Nodo* CrearNodo(Libro* libro);
void DestruirNodo(Nodo* nodo);
void InsertarPrincipio(Lista* lista, Libro* libro);
void InsertarFinal(Lista* lista, Libro* libro);
void InsertarDespues(int n, Lista* lista, Libro* libro);
Libro* Obtener(int n, Lista* lista);
int Contar(Lista* lista);
int EstaVacia(Lista* lista);
void EliminarPrincipio(Lista* lista);
void EliminarUltimo(Lista* lista);
void EliminarElemento(int n, Lista* lista);

#endif
