#ifndef PILA_H_
#define PILA_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct pila Pila;

Pila *pila_crear();
void pila_destruir(Pila *);
void pila_destruir_todo(Pila *, void (*f)(void *));

//cada una de estas funciones es O(1)
size_t pila_cantidad(Pila *);
void *pila_tope(Pila *);
bool pila_apilar(Pila *, void *);
void *pila_desapilar(Pila *);
bool pila_esta_vacía(Pila *);

#endif // PILA_H_
