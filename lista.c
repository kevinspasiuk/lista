#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/* ******************************************************************
 *               	 DEFINICION DE ESTRUCTURAS
 * *****************************************************************/

typedef struct nodo_lista {
	void* dato;
	struct nodo_lista* siguiente;
}nodo_lista_t;

struct lista {
	nodo_lista_t* primero;
	nodo_lista_t* ultimo;
	size_t largo;
};

struct lista_iter{
	nodo_lista_t* actual;
	nodo_lista_t* anterior;
	lista_t* lista;
};


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void){
	
	lista_t* lista= malloc(sizeof(lista_t));
    if (lista == NULL) {
        return NULL;
    }
	lista->primero=NULL;
	lista->ultimo=NULL;
    lista->largo=0;
    return lista;		
}

nodo_lista_t * nodo_crear(void){
		
	nodo_lista_t* nodo = malloc(sizeof(nodo_lista_t));
	if (nodo == NULL ) {
		return NULL;
	}
	nodo->siguiente=NULL;
	return nodo;
}
	
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	
	if (lista == NULL) return;
	while ( !lista_esta_vacia(lista)){
		void* p = lista_borrar_primero(lista);
		if (destruir_dato != NULL){
			destruir_dato(p);
		}	
	}
	free(lista);
	
}

bool lista_esta_vacia(const lista_t *lista){
	if (lista==NULL) return true;
	
	if (lista->primero == NULL){
		 return true;
	}  
	return false;
}

bool lista_insertar_primero(lista_t *lista, void *dato){
	if (lista==NULL) return false;
	nodo_lista_t* nodo = nodo_crear();
	if (nodo == NULL){
		return false;
	}
	nodo->dato = dato;
	nodo->siguiente = lista->primero;
	lista->primero = nodo;
	if (lista_largo(lista)== 0){
		lista->ultimo = nodo;
	}
	lista->largo++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){
	if (lista==NULL) return false;
	
	nodo_lista_t* nodo = nodo_crear();
	if (nodo == NULL){
		return false;
	}
	nodo->dato = dato;
	if (lista_largo(lista)== 0){
		lista->primero = nodo;
	}
	else{
		lista->ultimo->siguiente= nodo;
	}
	lista->ultimo= nodo;
	lista->largo++;
	return true;	

}

void *lista_borrar_primero(lista_t *lista){
	
	if (lista_esta_vacia(lista)){
		return NULL;
	}
	nodo_lista_t* aux= lista->primero;
	lista->primero= aux->siguiente;
	void* dato= aux->dato;
	if (aux->siguiente == NULL){// solo un elemento
		lista->ultimo= NULL;
	}
	lista->largo--;	
	free(aux);
	return dato;
}


void *lista_ver_primero(const lista_t *lista){
	
	if (lista_esta_vacia(lista)){
		return NULL;
	}
	return lista->primero->dato;
	
}

void *lista_ver_ultimo(const lista_t* lista){
	
	if (lista_esta_vacia(lista)){
		return NULL;
	}
	return lista->ultimo->dato;	
}

size_t lista_largo(const lista_t *lista){
		if (lista_esta_vacia(lista)) return 0;
		return lista->largo;
}

/* *****************************************************************
 *                  PRIMITIVAS DEl ITERADOR EXTERNO
 * *****************************************************************/

lista_iter_t *lista_iter_crear(lista_t *lista){
	
	lista_iter_t* iter= malloc(sizeof(lista_iter_t));
	if (iter == NULL || lista == NULL){
		return NULL;
	}
	//si lista vacia, primero = NULL.
	iter->lista = lista;
	iter->actual= lista->primero;
	iter->anterior= NULL;
	return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter){
	
	if (iter->lista == NULL || lista_iter_al_final(iter)){
			return false;
	}
	iter->anterior= iter->actual;
	iter->actual= iter->actual->siguiente;
	return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
	
	if (lista_esta_vacia(iter->lista) || lista_iter_al_final(iter)){
			return NULL;
	}	
	return iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter){
	
	if (iter->actual== NULL  || lista_esta_vacia(iter->lista) ){
		return true;
	}
	return false;
}

void lista_iter_destruir(lista_iter_t *iter){
	
	if (iter != NULL){
			free(iter);
	}
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato){

	nodo_lista_t* nodo = nodo_crear();
	if (nodo == NULL){
		return false;
	}
	nodo->dato = dato;
	if (lista_iter_al_final(iter)){
			iter->lista->ultimo=nodo;
	}
	nodo->siguiente= iter->actual;
	iter->actual=nodo;
	//si esta al principio 
	if (iter->anterior == NULL){
		iter->lista->primero=nodo;
	}
	else{
		iter->anterior->siguiente=nodo;
	}	
	iter->lista->largo++;
	return true;
}

void *lista_iter_borrar(lista_iter_t *iter){
	
	//si está al final de la lista o si lista vacia
	if (lista_iter_al_final(iter) || lista_esta_vacia(iter->lista) ){
		return NULL;
	}

	nodo_lista_t* aux = iter->actual;
	void* dato= aux->dato;
	
	//si el iter está en el último elemento de la lista
	if (iter->actual == iter->lista->ultimo){
			iter->lista->ultimo= iter->anterior;
	}
	iter->actual= aux->siguiente;
	//si el iter está al principio de la lista
	if (iter->anterior == NULL){
		iter->lista->primero= iter->actual;
	}
	else{
		iter->anterior->siguiente= iter->actual;
	}
	iter->lista->largo--; 
	free(aux);
	return dato;
}

/* *****************************************************************
 *                  PRIMITIVAS DEl ITERADOR INTERNO
 * *****************************************************************/

void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra){

	nodo_lista_t* aux=lista->primero;
	while(aux != NULL && visitar(aux->dato,extra)){
			aux=aux->siguiente;
	}	
}
