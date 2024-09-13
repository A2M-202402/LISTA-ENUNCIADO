#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct lista Lista;
typedef struct lista_iterador Lista_iterador;

Lista *lista_crear();
void lista_destruir(Lista *);

/**
 * Destruye la lista aplicando la funcion destructora (si no es NULL) a cada elemento.
 * */
void lista_destruir_todo(Lista *, void (*destructor)(void *));

/*
 * Devuelve la cantidad de elementos de la lista.
 * Una lista NULL tiene 0 elementos.
 */
size_t lista_cantidad_elementos(Lista *);

/**
 * Inserta un elemento en la lista en la posicion dada.
 *
 * Si la posición es mayor a la cantidad de elementos, es un error.
 *
 * Devuelve true si pudo, false en caso de error.
 *
 */
bool lista_agregar_elemento(Lista *lista, size_t posicion, void *cosa);

/**
  * Inserta un elemento al final de la lista.
  */
bool lista_agregar_al_final(Lista *lista, void *cosa);

/**
 * Elimina un elemento de la posicion dada.
 *
 * El elemento quitado se guarda en elemento_quitado (si se puede quitar y si no es null).
 *
 * En caso de error devuelve false, caso contrario true.
 */
bool lista_quitar_elemento(Lista *lista, size_t posicion,
			   void **elemento_quitado);

/**
 * Busca el elemento buscado en la lista y lo devuelve si lo encuentra.
 *
 * Para buscar el elemento, se aplica la función de comparacion.
 *
 * En caso de no encontrarlo devuelve NULL.
 */
void *lista_buscar_elemento(Lista *lista, void *buscado,
			    int (*comparador)(void *, void *));

/**
 * Obtiene el elemento almacenado en una posición
 *
 * Si la posicion es inválida es un error.
 *
 * El elemento encontrado se almacena en elemento_encontrado (a menos que sea NULL);
 *
 * Devuelve true si pudo obtener el elemento o false en caso de error.
 */
bool lista_obtener_elemento(Lista *lista, size_t posicion,
			    void **elemento_encontrado);

/**
 * Recorre la lista aplicando la funcion f a cada elemento en orden.
 *
 * ctx se le pasa como segundo parámetro a f.
 *
 * Si la funcion devuelve true se debe seguir iterando, caso contrario no.
 *
 * Devuelve la cantidad de elementos iterados.
 * */
size_t lista_iterar_elementos(Lista *lista, bool (*f)(void *, void *),
			      void *ctx);

/**
 * Crea un iterador externo para una lista
 *
 * En caso de error devuelve NULL
 */
Lista_iterador *lista_iterador_crear(Lista *lista);

/**
 * Devuelve true si hay siguiente.
 */
bool lista_iterador_hay_siguiente(Lista_iterador *);

/**
 *
 * Hace que el iterador avance al siguiente elemento de la lista.
 *
 */
void lista_iterador_avanzar(Lista_iterador *);

/**
 * Devuelve el elemento iterado
 */
void *lista_iterador_obtener_elemento_actual(Lista_iterador *);

/**
 * Eso
 */
void lista_iterador_destruir(Lista_iterador *);

#endif /* LISTA_H */
