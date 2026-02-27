#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    InicializarLista(&lista);

    Libro l1 = {"Cien anios de soledad", "Gabriel Garcia Marquez", "1234567890123"};
    Libro l2 = {"El principito", "Antoine de Saint-Exupery", "9876543210987"};
    Libro l3 = {"1984", "George Orwell", "1231231231231"};

    InsertarFinal(&lista, &l1);
    InsertarFinal(&lista, &l2);
    InsertarPrincipio(&lista, &l3);

    printf("Lista inicial:\n");
    MostrarLista(&lista);

    printf("\nEliminando el primer libro...\n");
    EliminarPrincipio(&lista);

    printf("\nLista actualizada:\n");
    MostrarLista(&lista);

    DestruirLista(&lista);
    return 0;
}