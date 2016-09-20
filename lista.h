#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stddef.h>


/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La lista está planteada como una lista de punteros genéricos. */

//struct lista;
typedef struct lista lista_t;


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

// Agrega un nuevo elemento a la lista en la primera posición.
// Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al 
// principio de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista en la última posición.
// Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al 
// final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// ELimina el primer elemento de la lista y lo devuelve. Si esta vacía 
// devuelve NULL.
// Pre: la lista fue creada.
// Post: si la lista no está vacia, se elimina el primer elemento.
void *lista_borrar_primero(lista_t *lista);

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

// Devuelve la cantidad de elementos de la lista. 
// Pre: la lista fue creada.
// Post: devuelve la cantidad de elementos (0 para lista vacía).
size_t lista_largo(const lista_t *lista);

/* ******************************************************************
 *                  PRIMITIVAS DEL ITERADOR EXTERNO	
 * *****************************************************************/

// Crea un iterador asociado a una lista. Si la lista tiene elementos el
// iterador apunta al primer elemento, en caso contrario apunta al último
// Pre: una lista creada
// Post: devuelve un iterador asociado a la lista
lista_iter_t *lista_iter_crear(lista_t *lista);

// El iterador se mueve una posicion. Devuelve false en caso de que el
// iterador está al final.
// Pre: un iterador creado.
// Post: el iterador avanzó un lugar (en caso de true).
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el puntero del actual. En caso de estar al final devuelve
// NULL.
// Pre: un iterador creado.
// Post: devuelve el dato del actual.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve true si el iterador se encuentra al final. 
// Pre: un iterador creado.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: un iterador creado.
void lista_iter_destruir(lista_iter_t *iter);

// Inserta el dato en la lista en la posicion actual del iterador.
// Devuelve false si no se pude insertar el dato.
// Pre: iter creado.
// Post: si es true el elemento fue insertado.
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra el elemento apuntado por el iter en la posicion actual y devuelve
// el valor. Si el iter está al final devuelve NULL.
// Pre:iter creado.
// Post: devuelve valor o NULL.
void *lista_iter_borrar(lista_iter_t *iter);

/* ******************************************************************
 *                  PRIMITIVA DEL ITERADOR INTERNO 
 * *****************************************************************/

// Aplica la funcion visitar a cada elemento de la lista hasta que devuelva
// false o no haya mas elementos. El extra se usa para cualquier proposito que
// se crea necesario.
// Pre: una lista.
// Post: lista con la funcion visitar apliada.
void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra);

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación del alumno.
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_lista_alumno(void);

#endif // LISTA_H
