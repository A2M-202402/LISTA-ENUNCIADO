#include <stdlib.h>
#include <string.h>
#include "src/lista.h"

struct pokemon {
	char *nombre;
	char tipo;
	int fuerza;
	int destreza;
	int resistencia;
};

int comparar_nombre_pokemon(void *_p1, void *_p2)
{
	struct pokemon *p1 = _p1;
	struct pokemon *p2 = _p2;

	return strcmp(p1->nombre, p2->nombre);
}

int main(int argc, char *argv[])
{
	//recibir un archivo por linea de comandos
	//abrir el archivo csv y parsear pokemones
	//agregar los pokemones a una lista
	//
	//El usuario puede elegir una de dos opciones
	//
	//1. Ingrear por teclado un nombre y el programa busca el pokemon en la lista
	//2. Listar todos los pokemones de la pokedex
	//
	//
	struct pokemon p1;
	struct pokemon p2;
	//obvio que los inicializo

	Lista *pokedex = lista_crear();

	//agregar_pokemon_desde_archivo(pokedex, "poke.csv");

	lista_agregar_al_final(pokedex, &p1);
	lista_agregar_al_final(pokedex, &p2);

	struct pokemon buscado = { .nombre = "Pikachu" };
	struct pokemon *encontrado = lista_buscar_elemento(
		pokedex, &buscado, comparar_nombre_pokemon);

	//struct pokemon *quitado;
	//lista_quitar_elemento(pokedex, 1 , (void**)&quitado);

	struct pokemon *en_posicion;
	lista_obtener_elemento(pokedex, 1, (void **)&en_posicion);

	//Recorrer lista
	//Posibilidad 1
	//1+2+3+4+5+6.....+n-1+n
	//puede ser O(n), O(n²) para enlazada
	for (size_t i = 0; //O(1)
	     i < lista_cantidad_elementos(pokedex); //O(1)
	     i++) { //O(1)
		struct pokemon *p;
		lista_obtener_elemento(pokedex, i, (void **)&p); //O(n)
		///hacer algo
	}

	//Recorrer lista
	//Posibilidad 2
	void *ctx = NULL;
	//O(n)
	lista_iterar_elementos(pokedex, hacer_algo, ctx);

	//Recorrer lista
	//Posibilidad 3
	//TDA iterador externo
	Lista_iterador *i;
	for (i = lista_iterador_crear(pokedex); //O(1)
	     lista_iterador_hay_siguiente(i); //O(1)
	     lista_iterador_avanzar(i)) { //O(1)
		struct pokemon *p;
		p = lista_iterador_obtener_elemento_actual(i); //O(1)
		///hacer algo
	}
	lista_iterador_destruir(i);

	//lista_iterar_elementos(pokedex, liberar_pokemon, NULL);
	//lista_destruir(pokedex);
	lista_destruir_todo(pokedex, liberar_pokemon);
	return 0;
}
