#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* *********************************************
 *                    NODO
 * *********************************************/
 struct nodo;
typedef struct nodo nodo_t;

struct nodo{
  void* dato; //puntero al dato almacenado
  nodo_t* next; //puntero al nodo siguiente
};

nodo_t* crear_nodo(void* valor){

  nodo_t* nodo = malloc(sizeof(nodo_t));
  if (!nodo){
    return NULL;
  }
  nodo->dato = valor;
  nodo->next = NULL;
  return nodo;
}

//--------------------------------------------------------

struct lista {
  nodo_t* first;
  nodo_t* last;
  size_t len;
};

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void){
  lista_t* lista = malloc(sizeof(lista_t));
  if (!lista) return NULL;
  lista->first = NULL;
  lista->last = NULL;
  lista->len = 0;
  return lista;
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)){
  while (!lista_esta_vacia(lista)){
    void* desenlistado = lista_borrar_primero(lista);
    if(destruir_dato != NULL){
      destruir_dato(desenlistado);
    }
  }
  free(lista);
}

bool lista_esta_vacia(const lista_t *lista){
  return (lista->len == 0);
}

bool lista_insertar_primero(lista_t *lista, void *dato){
  nodo_t* nuevo_nodo = crear_nodo(dato);
  if (!nuevo_nodo) return false;

  if (lista_esta_vacia(lista)){
    lista->last = nuevo_nodo;

  } else {
    nuevo_nodo->next = lista->first;
  }

  lista->first = nuevo_nodo;
  (lista->len)++;
  return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){

  nodo_t* nuevo_nodo = crear_nodo(dato);
  if (!nuevo_nodo) return false;

  if (lista_esta_vacia(lista)){
    lista->first = nuevo_nodo;
  } else {
    lista->last->next = nuevo_nodo; //anterior último
  }

  lista->last = nuevo_nodo;
  (lista->len)++;

  return true;
}

void *lista_ver_primero(const lista_t *lista){
  if (lista_esta_vacia(lista)) return NULL;
  return (lista->first->dato);
}

void *lista_ver_ultimo(const lista_t* lista){
  if (lista_esta_vacia(lista)) return NULL;
  return (lista->last->dato);
}

void *lista_borrar_primero(lista_t *lista){
  if (lista_esta_vacia(lista)) return NULL;
  void* desenlistado = lista_ver_primero(lista);
  nodo_t* nuevo_primero = lista->first->next;

  if (lista->first == lista->last){
    lista->last = NULL;
  }
  free(lista->first);
  lista->first = nuevo_primero;
  (lista->len)--;
  return desenlistado;
}

size_t lista_largo(const lista_t *lista){
  return(lista->len);
}


/* *********************************************
*               ITERADOR EXTERNO
* *********************************************/

struct lista_iter{
  lista_t* lista;
  nodo_t* anterior;
  nodo_t* actual;
};

lista_iter_t *lista_iter_crear(lista_t *lista){

  lista_iter_t* iter = malloc(sizeof(lista_iter_t));

  if (!iter) return NULL;
  iter->lista = lista;
  iter->anterior = NULL;
  iter->actual = iter->lista->first;
  return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter){

  if(!iter->actual) return false;

  iter->anterior = iter->actual;
  nodo_t* nuevo_actual = iter->actual->next;
  iter->actual = nuevo_actual;
  return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
  if (iter->actual){
    return iter->actual->dato;
  }
  return NULL;
}

bool lista_iter_al_final(const lista_iter_t *iter){
  return(iter->actual==NULL);
}

void lista_iter_destruir(lista_iter_t *iter){
  free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato){

  nodo_t* nuevo_nodo = crear_nodo(dato);
  if(!nuevo_nodo) return false;

  nuevo_nodo->next = iter->actual;

  if(!iter->anterior){
    iter->lista->first = nuevo_nodo;
  } else {
    iter->anterior->next = nuevo_nodo;
  }
  if(lista_iter_al_final(iter)){
    iter->lista->last = nuevo_nodo;
  }

  iter->actual = nuevo_nodo;
  (iter->lista->len)++;
  return true;
}


void *lista_iter_borrar(lista_iter_t *iter){

  if(lista_iter_al_final(iter)) return NULL;
  void* dato = iter->actual->dato;
  nodo_t* nuevo_actual = iter->actual->next;

  if(iter->actual == iter->lista->first){ //caso primer nodo
    iter->lista->first = nuevo_actual;
  } else if(iter->actual == iter->lista->last){ //caso último nodo
    iter->lista->last= iter->anterior;
  } else {
    iter->anterior->next = nuevo_actual;
  }

  free(iter->actual);
  iter->actual = nuevo_actual;
  (iter->lista->len)--;
  return dato;
}

/* *********************************************
*               ITERADOR INTERNO
* *********************************************/

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){

  bool estado = true;
  nodo_t* nodo = lista->first;

  while ((nodo!=NULL) && estado){
    estado = visitar(nodo->dato,extra);
    nodo = nodo->next;
  }
}
