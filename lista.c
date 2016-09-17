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
		if (destruir_dato != NULL && p!=NULL){
			destruir_dato(p);
		}	
	}
	free(lista);
	
}

bool lista_esta_vacia(const lista_t *lista){
	//Lista !=NULL
	if (lista->primero == NULL && lista->ultimo== NULL){
		 return true;
	}  
	return false;
}

bool lista_insertar_primero(lista_t *lista, void *dato){
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
		return lista->largo;
}
