#ifndef LIBRO_H
#define LIBRO_H

#define MAX_TITULO 50
#define MAX_AUTOR 50
#define MAX_ISBN 14  // 13 + '\0'

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    char isbn[MAX_ISBN];
} Libro;

#endif