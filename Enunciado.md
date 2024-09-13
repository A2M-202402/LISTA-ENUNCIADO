<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# Lista simplemente enlazada y amigos

Se pide implementar un **TDA Lista** utilizando **nodos simplemente enlazados**. Para ello se brindan las firmas de las funciones públicas a implementar y se deja a criterio del alumno la creación de las funciones privadas del **TDA** para el correcto funcionamiento de la **Lista** cumpliendo con las buenas prácticas de programación. Adicionalmente se pide la creación de un **iterador interno y uno externo** para la lista, como así también **REUTILIZAR** la implementación de lista simplemente enlazada para implementar los **TDAS Pila y Cola**.

El TDA entregado deberá compilar y pasar las pruebas dispuestas por la cátedra sin errores, adicionalmente estas pruebas deberán ser ejecutadas **sin pérdida de memoria**.

Adicionalmente se debe completar la implementación de **tp_lista.c** que debe cumplir los siguientes requisitos:

- Recibir un archivo por línea de comandos
- Parsear pokemones de dicho archivo y almacenarlos en una lista
- Darle la opcion al usuario de realizar una de dos operaciones:
  -  Ingresar el nombre de un pokemon por entrada estandar y buscarlo (mostrar el resultado)
  -  Mostrar todos los pokemon leidos del archivo por pantalla
- Una vez realizada la operación seleccionada, el programa finaliza


---

## Consejos para la elaboración del trabajo

Intenta comprender primero el funcionamiento de los nodos enlazados. Propone una lista de elementos y dibujá a mano (lápiz y papel) varias operaciones de inserción y eliminación de la lista. Dibujá cada uno de los nodos enlazados con sus punteros y datos. Una vez hecho el dibujo, intenta aplicar sobre el mismo cada una de las operaciones propuestas para el TDA. Poder dibujar el problema exitosamente y entender cómo funciona va a ser fundamental a la hora de la implementación.

En general, para todo el código: utilizá nombres claros de variables y funciones auxiliares. Una variable con el nombre **cantidad\_elementos\_recorridos** o incluso **cantidad** es mucho mas claro que una variable con el nombre **n**, **cant**, o **rec**. Intentá darle un significado el nombre de cada variable, dentro de lo posible (por supuesto, quedan excluidos casos como i, j para bucles, v para un vector, str para un string, etc).

**NO** escribas código a lo loco sin compilar cada tanto. Implementá la solución de a poco y compilando a cada paso. Dejar la compilación para el final es uno de los peores errores que podés cometer. Para la compilación del trabajo se provee un **Makefile**. Utilizá el comando **make** frecuentemente para compilar y correr el programa.

**NO** avances en la implementación si quedan errores sin resolver en alguna prueba. Cada vez que escribas una prueba implementá toda la funcionalidad necesaria para que funcione correctamente. Esto incluye liberar memoria y accesos inválidos a la misma. Solamente una vez que hayas logrado que la prueba pase exitosamente es que podés comenzar a escribir la próxima prueba para continuar el trabajo.

**NO** está permitido modificar los archivos **.h**. Se pueden hacer modificaciones al **makefile**, pero recordá que el trabajo debe ser compilado por el sistema de entregas con las cabeceras y el **makefile** original. Caso contrario el trabajo se da por desaprobado.

**TIP**: Quizás no sea necesario definir estructuras para la pila y la cola si se reutiliza por completo la lista. Léase también: casteo de punteros.

---

## Puntos teóricos

 - ¿Qué es una lista/pila/cola? Explicar con diagramas.
 - Explica y analiza las diferencias de complejidad entre las implementaciones de lista simplemente enlazada, doblemente enlazada y vector dinámico para las operaciones:
   - Insertar/obtener/eliminar al inicio
   - Insertar/obtener/eliminar al final
   - Insertar/obtener/eliminar al medio
 - Explica la complejidad de las operaciones implementadas en tu trabajo para la pila y la cola.

---

## Criterios mínimos de corrección
Verifica la siguiente lista antes de entregar tu TP

### General

-   [ ] Cada malloc tiene su verificación
-   [ ] Libera(cierra) memoria(archivos) en los casos de error
-   [ ] Reallocs sobre punteros auxiliares
-   [ ] No hay fragmentos de código comentado (si no se usa, se borra)
-   [ ] No hay printfs donde no es necesario
-   [ ] Los entregables compilan y corren sin error
-   [ ] Verifica los punteros recibidos
-   [ ] No hay variables globales
-   [ ] No reserva memoria cuando no es necesario
-   [ ] Usa constantes y tienen sentido.

### Estilo

-   [ ] Los nombres de función me dicen lo que hacen
-   [ ] No hay variables con nombre confuso

### Lista

-   [ ] Reutiliza funciones donde es apropiado
-   [ ] Las complejidades son adecuadas
    -   Push/Pop **deben** ser **O(1)**
    -   Lo mismo con Encolar/Desencolar.
-   [ ] El iterador interno es **O(n)**
-   [ ] El iterador interno NO usa el externo 
-   [ ] El iterador externo es **O(n)**
-   [ ] Responde las preguntas teóricas en el informe.

