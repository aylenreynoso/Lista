#include "lista.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#define VOLUMEN 100000

/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

//Pruebas para una lista vacía.

void pruebas_lista_vacia_alumno() {

    printf("\nINICIO DE PRUEBAS CON lista VACÍA\n");

    lista_t* lista = lista_crear();
    char b;

    // Pruebo creación y estado
    print_test("crear lista vacía", lista != NULL);
    print_test("estado lista vacia (true)", lista_esta_vacia(lista) == true);
    print_test("ver largo lista", lista_largo(lista) == 0);

    // Pruebo mostrar primer y último elemento de una lista vacía devuelven NULL

    print_test("mostrar primero lista vacía",lista_ver_primero(lista) == NULL);
    print_test("mostrar último lista vacía", lista_ver_ultimo(lista) == NULL);

    // Pruebo que puedo insertar un elemento en una lista vacía
    print_test("insertar primero en lista vacía (true)", lista_insertar_primero(lista, &b) == true);
    print_test("mostrar primero lista con un elemento",lista_ver_primero(lista) == &b);
    print_test("mostrar último lista con un elemento", lista_ver_ultimo(lista) == &b);
    print_test("eliminar primero", lista_borrar_primero(lista) == &b);
    print_test("mostrar primero ", lista_ver_primero(lista) == NULL);
    print_test("mostrar último ", lista_ver_ultimo(lista) == NULL);

    // Pruebo que puedo insertar un elemento en una lista vacía

    print_test("insertar último en lista vacía es true", lista_insertar_ultimo(lista, &b) == true);
    print_test("mostrar último lista con un elemento",lista_ver_ultimo(lista) == &b);
    print_test("mostrar primero lista con un elemento", lista_ver_primero(lista) == &b);
    print_test("eliminar primero", lista_borrar_primero(lista) == &b);
    print_test("mostrar primero ", lista_ver_primero(lista) == NULL);
    print_test("mostrar último ", lista_ver_ultimo(lista) == NULL);

    // Destruyo la lista (vacía)
    lista_destruir(lista, NULL);
    print_test("la lista fue destruida", true);
}

void pruebas_lista_null_alumno() {

    printf("\nINICIO DE PRUEBAS CON NULL\n");

    lista_t* lista = lista_crear();
    int a;

    /* Pruebo que insertar NULL es una operación válida*/
    print_test("insertar NULL es válido", lista_insertar_primero(lista, NULL) == true);


    /* Pruebo estado y mostrar primer elemento*/
    print_test("lista vacia (false)", lista_esta_vacia(lista) == false);
    print_test("mostrar primero (NULL))", lista_ver_primero(lista) == NULL);

    lista_insertar_ultimo(lista, &a); //ahora lista tiene a Null y a *a
    print_test("mostrar último", lista_ver_ultimo(lista) == &a);

    /* Pruebo borrar a NULL*/
    print_test("borro a NULL", lista_borrar_primero(lista) == NULL);
    print_test("mostrar nuevo primero", lista_ver_primero(lista) == &a);
    print_test("mostrar nuevo último", lista_ver_ultimo(lista) == &a);

    /* Destruyo la lista (no vacía)*/
    lista_destruir(lista, NULL);
    print_test("la lista fue destruida", true);
}

void pruebas_lista_un_elemento_alumno() {

    printf("\nINICIO DE PRUEBAS CON UN ELEMENTO \n");

    lista_t* lista = lista_crear();
    long a;

    /* Pruebo que insertar un elemento*/
    print_test("insertar", lista_insertar_ultimo(lista, &a) == true);

    /* Pruebo estado y mostrar primer elemento*/
    print_test("lista vacia (false)", lista_esta_vacia(lista) == false);
    print_test("mostrar primero ", lista_ver_primero(lista) == &a);
    print_test("mostrar último ", lista_ver_ultimo(lista) == &a);
    print_test("ver largo lista", lista_largo(lista) == 1);

    // Pruebo borrar único elemento
    print_test("borrar único elemento", lista_borrar_primero(lista) == &a);

    // Pruebo estado y mostrar primer elemento

    print_test("estado lista vacia (true)", lista_esta_vacia(lista) == true);
    print_test("mostrar nuevo primero (NULL)", lista_ver_primero(lista) == NULL);
    print_test("mostrar último (NULL)", lista_ver_ultimo(lista) == NULL);

    // Destruyo la lista
    lista_destruir(lista, NULL);
    print_test("la lista fue destruida", true);
}

void pruebas_lista_destruir_free() {

    printf("\nINICIO DE PRUEBAS DESTRUIR LISTA PASANDO FREE \n");

    lista_t* lista = lista_crear();

    void* a = malloc(sizeof(int)*10);
    void* b = malloc(sizeof(long)*5);
    void* c = malloc(sizeof(char)*20);
    void* d = malloc(sizeof(int)*200);
    void* e = malloc(sizeof(int)*50);

    lista_insertar_ultimo(lista, &a);
    lista_insertar_ultimo(lista, &b);
    lista_insertar_ultimo(lista, &c);
    lista_insertar_ultimo(lista, &d);
    lista_insertar_ultimo(lista, &e);

    // Destruyo la lista (no vacía)

    lista_destruir(lista, free);
    print_test("la lista fue destruida", true);
}

// Pruebas de guardar y obtener algunos elementos

void pruebas_lista_algunos_elementos_alumno() {

    printf("\nINICIO DE PRUEBAS CON ALGUNOS ELEMENTOS \n");

    lista_t* lista = lista_crear();
    long a;
    int b;
    char c;
    size_t d;

    // Pruebo insertar elementos

    print_test("insertar", lista_insertar_primero(lista, &a) == true);
    print_test("insertar", lista_insertar_ultimo(lista, &b) == true);
    print_test("insertar", lista_insertar_ultimo(lista, &c) == true);
    print_test("insertar", lista_insertar_ultimo(lista, &d) == true);

    // Pruebo estado y mostrar primer elemento

    print_test("lista vacia (false)", lista_esta_vacia(lista) == false);
    print_test("mostrar primero ", lista_ver_primero(lista) == &a);
    print_test("mostrar último ", lista_ver_ultimo(lista) == &d);
    print_test("ver largo lista", lista_largo(lista) == 4);

    // Pruebo borrar primer elemento
    print_test("borrar primer elemento", lista_borrar_primero(lista) == &a);

    // Pruebo estado y mostrar primer elemento

    print_test("lista vacia (false)", lista_esta_vacia(lista) == false);
    print_test("mostrar primero ", lista_ver_primero(lista) == &b);
    print_test("ver largo lista", lista_largo(lista) == 3);

    //Pruebo insertar un nuevo primer elemento

    print_test("insertar", lista_insertar_primero(lista, &d) == true);
    print_test("mostrar primero ", lista_ver_primero(lista) == &d);
    print_test("ver largo lista", lista_largo(lista) == 4);

    //Ahora la lista contiene a d,b,c,d

    // Destruyo la lista (no vacía)

    lista_destruir(lista, NULL);
    print_test("la lista fue destruida", true);
}

//Pruebas de la lista al trabajar con un volumen grande de elementos

void pruebas_lista_volumen_alumno() {

    printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");

    lista_t* lista_vol = lista_crear();
    bool ok;

    /* Pruebo insertar primeros todos los elementos */
    ok = true;
    int* vector = malloc(VOLUMEN * sizeof(int*));
    for (size_t i=0 ; i < VOLUMEN; i++){
      vector[i] = (int)i;
      // Si algun elemento no se pudo guardar correctamente, ok sera false
      ok &= lista_insertar_primero(lista_vol, &vector[i]);
    }
    free(vector);

    /* Pruebo insertar ultimos todos los elementos */
    ok = true;
    int* vector1 = malloc(VOLUMEN * sizeof(int*));
    for (size_t i=0 ; i < VOLUMEN; i++){
      vector1[i] = (int)i;
      // Si algun elemento no se pudo guardar correctamente, ok sera false
      ok &= lista_insertar_ultimo(lista_vol, &vector1[i]);
    }
    free(vector1);

    print_test("se pudieron insertar todos los elementos", ok);
    print_test("ver largo ", lista_largo(lista_vol) == VOLUMEN*2);

    /* Pruebo que al borrar el primero anterior coincide con el elemento a  */
    ok = true;
    int* valor;
    int* first;

    for (size_t j = VOLUMEN*2; j>0 ; j--) {
        first = lista_ver_primero(lista_vol);
        valor = lista_borrar_primero(lista_vol);
        ok &= ((valor == first));
    }
    print_test("se pudieron borrar todos los elementos", ok);

    /* Pruebo que al borrar todos los elementos,
    la lista tiene el comportamiento de estar vacía*/

    print_test("estado vacia (true)", lista_esta_vacia(lista_vol) == true);
    print_test("borrar en lista vacía", lista_borrar_primero(lista_vol) == NULL);
    print_test("mostrar primero lista vacía", lista_ver_primero(lista_vol) == NULL);
    print_test("ver largo ", lista_largo(lista_vol) == 0);

    /* Destruyo la lista (vacía)*/
    lista_destruir(lista_vol, NULL);
    print_test("la lista fue detruida", true);
}

/* ******************************************************************
 *                        PRUEBAS ITERADORES
 * *****************************************************************/

//PRUEBAS ITERADOR EXTERNO

void pruebas_iter_externo_alumno() {

  printf("\nINICIO DE PRUEBAS ITERADOR EXTERNO\n");

  lista_t* lista = lista_crear();
  long a;
  int b;
  char c;
  size_t d;

  lista_insertar_primero(lista, &a);
  lista_insertar_ultimo(lista, &b);
  lista_insertar_ultimo(lista, &c);
  lista_insertar_ultimo(lista, &d);


  lista_iter_t* iter = lista_iter_crear(lista);

  print_test("crear iterador", iter != NULL);
  print_test("mostrar inicio del iterador",lista_iter_ver_actual(iter) == &a);
  print_test("iterado llegó al final (false)",lista_iter_al_final(iter) == false);

  print_test("avanzar",lista_iter_avanzar(iter) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &b);
  print_test("iterado llegó al final (false)",lista_iter_al_final(iter) == false);

  print_test("avanzar",lista_iter_avanzar(iter) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &c);
  print_test("iterado llegó al final (false)",lista_iter_al_final(iter) == false);

  print_test("avanzar",lista_iter_avanzar(iter) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &d);
  print_test("iterado llegó al final (false)",lista_iter_al_final(iter) == false);

  print_test("avanzar",lista_iter_avanzar(iter) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == NULL);
  print_test("iterado llegó al final",lista_iter_al_final(iter) == true);

  print_test("avanzar",lista_iter_avanzar(iter) == false);

  lista_iter_destruir(iter);
  print_test("el iterador fue destruido", true);
  lista_destruir(lista,NULL);

}

void pruebas_iter_externo_insertar_alumno() {

  printf("\nINICIO DE PRUEBAS ITERADOR EXTERNO INSERTAR\n");

  lista_t* lista = lista_crear();
  long a;
  int b;
  char c;
  size_t d;

  lista_iter_t* iter = lista_iter_crear(lista);

  //pruebo insertar con iterador en lista vacia

  print_test("inserto en lista vacía", lista_iter_insertar(iter,&a) == true);
  print_test("veo si la lista actualizo su primer elemento", lista_ver_primero(lista) == &a);
  print_test("veo si la lista actualizo su último elemento", lista_ver_ultimo(lista) == &a);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &a);
  print_test("ver largo lista", lista_largo(lista) == 1);

  //pruebo insertar en la primera posicion

  print_test("inserto en primera posición", lista_iter_insertar(iter,&b) == true);
  print_test("veo si la lista actualizo su primer elemento", lista_ver_primero(lista) == &b);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &b);
  print_test("ver largo lista", lista_largo(lista) == 2);

  print_test("inserto en primera posición", lista_iter_insertar(iter,&c) == true);
  print_test("veo si la lista actualizo su primer elemento", lista_ver_primero(lista) == &c);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &c);
  print_test("ver largo lista", lista_largo(lista) == 3);

  lista_iter_avanzar(iter); //&b
  lista_iter_avanzar(iter); //&a
  lista_iter_avanzar(iter); //NULLCON lista VACÍA

  //pruebo insertar un nuevo último nodo

  print_test("inserto en última posición", lista_iter_insertar(iter,&d) == true);
  print_test("veo si la lista actualizo su último elemento", lista_ver_ultimo(lista) == &d);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &d);
  print_test("ver largo lista", lista_largo(lista) == 4);

  lista_iter_destruir(iter);
  print_test("el iterador fue destruido", true);
  lista_destruir(lista,NULL);
}

void pruebas_iter_externo_borrar_borde_alumno() {

  printf("\nINICIO DE PRUEBAS ITERADOR EXTERNO INSERTAR (BORDE)\n");

  lista_t* lista = lista_crear();
  long a;
  int b;
  char c;
  size_t d;

  lista_insertar_primero(lista, &a);
  lista_insertar_ultimo(lista, &b);
  lista_insertar_ultimo(lista, &c);
  lista_insertar_ultimo(lista, &d);

  lista_iter_t* iter = lista_iter_crear(lista);

   //Pruebo borrar primero
  print_test("borro primer elemento", lista_iter_borrar(iter) == &a);
  print_test("veo si la lista actualizo su primer elemento", lista_ver_primero(lista) == &b);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &b);
  print_test("ver largo lista", lista_largo(lista) == 3);

  lista_iter_avanzar(iter); // c
  lista_iter_avanzar(iter); // d

   //Pruebo borrar último
  print_test("borro último elemento", lista_iter_borrar(iter) == &d);
  print_test("veo si la lista actualizo su último elemento", lista_ver_ultimo(lista) == &c);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == NULL);
  print_test("ver largo lista", lista_largo(lista) == 2);
  print_test("llego al final de la lista",lista_iter_al_final(iter) == true);

   //pruebo borrar cuando el iterador llegó al final de la lista (false)

  print_test("borro último elemento (NULL)", lista_iter_borrar(iter) == NULL);

  lista_iter_destruir(iter);
  print_test("el iterador fue destruido", true);
  lista_destruir(lista,NULL);
}

void pruebas_iter_externo_borrar_alumno() {

  printf("\nINICIO DE PRUEBAS ITERADOR EXTERNO BORRAR\n");

  lista_t* lista = lista_crear();
  long a;
  int b;
  char c;
  size_t d;

  lista_insertar_primero(lista, &a);
  lista_insertar_ultimo(lista, &b);
  lista_insertar_ultimo(lista, &c);
  lista_insertar_ultimo(lista, &d);

  lista_iter_t* iter = lista_iter_crear(lista);

  lista_t* lista2 = lista_crear();

  lista_insertar_primero(lista2, &a);
  lista_insertar_ultimo(lista2, &b);
  lista_insertar_ultimo(lista2, &c);
  lista_insertar_ultimo(lista2, &d);


  lista_iter_t* iter2 = lista_iter_crear(lista2);

  //pruebo borrar un elemento del medio de la lista_t

  lista_iter_avanzar(iter); //b

  print_test("borro elemento", lista_iter_borrar(iter) == &b);
  //print_test("busco elemento", buscar(lista,&b) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &c);
  print_test("ver largo lista", lista_largo(lista) == 3);

  print_test("borro otro elemento", lista_iter_borrar(iter) == &c);
  //print_test("busco elemento", buscar(lista,&b) == true);
  print_test("mostrar actual del iterador",lista_iter_ver_actual(iter) == &d);
  print_test("ver largo lista", lista_largo(lista) == 2);

  //pruebo borrar todos los elementos restantes

  while(!lista_iter_al_final(iter2)){
    lista_iter_borrar(iter2);
  }
  print_test("ver largo lista", lista_largo(lista2) == 0);
  print_test("lista está vacia", lista_esta_vacia(lista2) == true);

  lista_iter_destruir(iter);
  print_test("el iterador fue destruido", true);
  lista_destruir(lista,NULL);

  lista_iter_destruir(iter2);
  print_test("el iterador fue destruido", true);
  lista_destruir(lista2,NULL);
}

//PRUEBAS ITERADOR INTERNO

//struct extra

typedef struct extra_suma{
  int suma;
  int contador;
}extra_suma_t;

//visitar

bool sumar_todos(void *elemento, void *extra){

    *(int*)extra += *(int*)elemento;

    return true;
}

bool sumar_primeros_tres(void *elemento, void *extra){

  if ((*(extra_suma_t*) extra).contador >= 3) return false;
  (*(extra_suma_t*) extra).suma += *(int*)elemento;
  (*(extra_suma_t*) extra).contador ++;

  return true;
}

void pruebas_iter_interno() {

  printf("\nINICIO DE PRUEBAS ITERADOR INTERNO\n");

  lista_t* lista = lista_crear();

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;

  lista_insertar_primero(lista, &a);
  lista_insertar_ultimo(lista, &b);
  lista_insertar_ultimo(lista, &c);
  lista_insertar_ultimo(lista, &d);
  lista_insertar_ultimo(lista, &e);

  //sin corte

  int suma_items = 0;
  lista_iterar(lista, sumar_todos , &suma_items);

  print_test("Suma de todos los elementos, resultado correcto", suma_items == 15);

  //con corte

  extra_suma_t extra;
  extra.suma = 0;
  extra.contador = 0;

  lista_iterar(lista, sumar_primeros_tres , &extra);

  print_test("Suma de los primeros 3 elementos, resultado correcto", extra.suma == 6);

  lista_destruir(lista, NULL);
}

//--------------------------------------------------------------------
void pruebas_lista_alumno() {

    lista_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL", ejemplo == NULL);

    pruebas_lista_vacia_alumno();
    pruebas_lista_null_alumno();
    pruebas_lista_un_elemento_alumno();
    pruebas_lista_algunos_elementos_alumno();
    pruebas_lista_volumen_alumno();
    pruebas_iter_externo_alumno();
    pruebas_iter_externo_borrar_borde_alumno();
    pruebas_iter_externo_borrar_alumno();
    pruebas_iter_externo_insertar_alumno();
    pruebas_iter_interno();

}
