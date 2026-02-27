# 📚 Linked List Library Management (C)

Implementación de una **lista enlazada simple en C** para gestionar una colección de libros en memoria.

Este proyecto demuestra el uso de:

- Estructuras (`struct`)
- Memoria dinámica (`malloc`, `free`)
- Modularización con archivos `.h` y `.c`
- Manejo seguro de cadenas (`strncpy`)
- Operaciones básicas sobre listas enlazadas

---

## 🧠 Estructuras de Datos

### Libro
Cada nodo almacena la siguiente información:

- Título
- Autor
- ISBN

```c
typedef struct {
    char titulo[50];
    char autor[50];
    char isbn[14];
} Libro;
