#ifndef COLA_H_
#define COLA_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct cola Cola;

Cola *cola_crear();
void cola_destruir(Cola *);
void cola_destruir_todo(Cola *, void (*f)(void *));

//cada una de estas funciones es O(1)
size_t cola_cantidad(Cola *);
void *cola_frente(Cola *);
bool cola_encolar(Cola *, void *);
void *cola_desencolar(Cola *);
bool cola_esta_vacía(Cola *);

#endif // COLA_H_
