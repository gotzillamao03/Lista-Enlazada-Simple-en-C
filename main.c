#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista lista = {NULL, 0};

    Libro l1 = {"Cien años de soledad", "Gabriel García Márquez", "1234567890123"};
    Libro l2 = {"El principito", "Antoine de Saint-Exupéry", "9876543210987"};
    Libro l3 = {"1984", "George Orwell", "1231231231231"};

    InsertarFinal(&lista, &l1);
    InsertarFinal(&lista, &l2);
    InsertarPrincipio(&lista, &l3);

    printf("Lista de libros:\n");
    for (int i = 0; i < Contar(&lista); i++) {
        Libro* libro = Obtener(i, &lista);
        printf("%d. %s - %s - %s\n", i + 1, libro->titulo, libro->autor, libro->isbn);
    }

    printf("\nEliminando el primer libro...\n");
    EliminarPrincipio(&lista);

    printf("\nLista actualizada:\n");
    for (int i = 0; i < Contar(&lista); i++) {
        Libro* libro = Obtener(i, &lista);
        printf("%d. %s - %s - %s\n", i + 1, libro->titulo, libro->autor, libro->isbn);
    }

    return 0;
}
