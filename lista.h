#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* Lista de punteros genéricos. */
typedef struct lista lista_t;

/*iterador externo*/
typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));

// Devuelve verdadero o falso, según si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al comienzo
// de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del último elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del último, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el último elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento le da lista, la lista
// contiene un elemento menos, si la lista no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Muestra la cantidad de elemento que contiene la lista.
// Pre: la lista fue creada.
// Post: se devolvió la cantidad de elementos contenidos en la lista.
size_t lista_largo(const lista_t *lista);

/* ******************************************************************
 *                 PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

 // Crea un iterador.
 // Post: devuelve un iterador posicionado en el primer nodo de la lista.
 lista_iter_t *lista_iter_crear(lista_t *lista);

 // Hace que el iteraror apunte a un siguiente elemento en de la lista.
 // retorna false en caso de error.
 // Pre: el iterador y la lista fueron creados
 bool lista_iter_avanzar(lista_iter_t *iter);

 // Obtiene el valor del de la lista al que apunta el iterador actualmente.
 // Pre: el iterador y la lista fueron creados
 // Post: se devolvió el primer elemento de la lista, cuando no está vacía.
 void *lista_iter_ver_actual(const lista_iter_t *iter);

 // Devuelve verdadero o falso, según si el iterador llegó al final de la lista (NULL), o no.
 // Pre: el iterador y la lista fueron creados
 bool lista_iter_al_final(const lista_iter_t *iter);

 // Destruye el iterador.
 // Pre: el iterador fue creado.
 // Post: se destruyó el iterador.
 void lista_iter_destruir(lista_iter_t *iter);

 // Agrega un nuevo elemento a la lista a la izquierda del lugar de la lista al
 //que apunta el iterador actualmente. Devuelve falso en caso de error.
 //el iterador apunta al elemento insertado
 // Pre: el iterador y la lista fueron creados
 // Post: se agregó un nuevo elemento a la lista, valor se encuentra a la izquierda
 // del lugar señalado por el iterador
 bool lista_iter_insertar(lista_iter_t *iter, void *dato);

 // Saca de la lista el elemento actual señalado por el iterador y retorna su valor
 //NULL en caso de que el iterador haya llegado al final.
 //el iterador ahora apunta al siguiente elemento de la lista
 // Pre: el iterador y la lista fueron creados
 // Post: se devolvió el valor del elemento eliminado, la lista
 // contiene un elemento menos, si la lista no estaba vacía.
 void *lista_iter_borrar(lista_iter_t *iter);

 /* ******************************************************************
  *                 PRIMITIVA ITERADOR INTERNO
  * *****************************************************************/
//Itera una lista hasta que la función recibida lo indique y aplica la función
//a cada elemento iterado de la lista.

 void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

void pruebas_lista_alumno(void);

#endif // LISTA_H
