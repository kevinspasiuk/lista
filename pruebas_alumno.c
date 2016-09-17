#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
//// CHECKEAR TAMANÑOOO!!!

void prueba_un_elemento(){
	printf("~~~ PRUEBA 1 ELEMENTO ~~~\n");
	//variables
	int a=1;
	lista_t* lista = lista_crear();
	
	if (lista != NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		
		//inserto un elemento al principio
		if (lista_insertar_primero(lista,&a)){
			printf("Insertar lista primero elemento 1 = True \n");
			print_test("Lista NO esta vacia", lista_esta_vacia(lista) == false );
			print_test("Elemento 1 esta primero", lista_ver_primero(lista) == &a);
			print_test("Elemento 1 esta ultimo", lista_ver_ultimo(lista) == &a);	
			print_test("Borrar primer elemento = 1",lista_borrar_primero(lista) == &a);
			print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		}
		//inserto un elemento al final
		if (lista_insertar_ultimo(lista,&a)){
			printf("Insertar lista ultimo elemento 1 = True \n");
			print_test("Lista NO esta vacia", lista_esta_vacia(lista) == false );
			print_test("Elemento 1 esta primero", lista_ver_primero(lista) == &a);
			print_test("Elemento 1 esta ultimo", lista_ver_ultimo(lista) == &a);	
			print_test("Borrar primer elemento = 1",lista_borrar_primero(lista) == &a);
			print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		}
		//destruyo la lista
		lista_destruir(lista, NULL);
		
	}	

}

void prueba_elementos(){
	printf("~~~ PRUEBA VARIOS ELEMENTOS ~~~\n");
	printf("En stack \n");
	//variables
	int a=1,b=2,c=3;
	lista_t* lista = lista_crear();
	
	if (lista != NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
	

		
		//inserto algunos elementos 1->2->3
		if (lista_insertar_primero(lista,&a)){
			printf("elemento 1 al principio de la lista = True \n");
		}	
		if (lista_insertar_ultimo(lista,&b)){
			printf("elemento 2 al final de la lista = True \n");
		}
		if (lista_insertar_ultimo(lista,&c)){
			printf("elemento 3 al final de la lista = True \n");
		}

		print_test("ver primero = 1 ",lista_ver_primero(lista)== &a);
		print_test("ver ultimo = 3 ", lista_ver_ultimo(lista)== &c);
		print_test("Borrar primer elemento = 1",lista_borrar_primero(lista) == &a);
		print_test("ver primero = 2 ",lista_ver_primero(lista)== &b);
		print_test("ver ultimo = 3 ", lista_ver_ultimo(lista)== &c);	
		print_test("Borrar primer elemento = 2",lista_borrar_primero(lista) == &b);
		print_test("ver primero = 3 ",lista_ver_primero(lista)== &c);
		print_test("ver ultimo = 3 ", lista_ver_ultimo(lista)== &c);
		print_test("Borrar primer elemento = 3",lista_borrar_primero(lista) == &c);
		print_test("ver primero = NULL ",lista_ver_primero(lista)== NULL);	
		print_test("ver ultimo = NULL", lista_ver_ultimo(lista)== NULL);
	
		//inserto algunos elementos 3->2->1
		if (lista_insertar_ultimo(lista,&a)){
			printf("elemento 1 al final de la lista = True \n");
		}	
		if (lista_insertar_primero(lista,&b)){
			printf("elemento 2 al principio de la lista = True \n");
		}
		if (lista_insertar_primero(lista,&c)){
			printf("elemento 3 al principio de la lista= True \n");
		}		
		print_test("ver primero = 3 ",lista_ver_primero(lista)== &c);
		print_test("ver ultimo = 1 ", lista_ver_ultimo(lista)== &a);
		print_test("Borrar primer elemento = 3",lista_borrar_primero(lista) == &c);
		print_test("ver primero = 2 ",lista_ver_primero(lista)== &b);
		print_test("ver ultimo = 1 ", lista_ver_ultimo(lista)== &a);	
		print_test("Borrar primer elemento = 2",lista_borrar_primero(lista) == &b);
		print_test("ver primero = 1 ",lista_ver_primero(lista)== &a);
		print_test("ver ultimo = 1 ", lista_ver_ultimo(lista)== &a);
		print_test("Borrar primer elemento = 1",lista_borrar_primero(lista) == &a);
		print_test("ver primero = NULL ",lista_ver_primero(lista)== NULL);	
		print_test("ver ultimo = NULL", lista_ver_ultimo(lista)== NULL);
		
		//destruyo la lista
		lista_destruir(lista, NULL);
	}

		
}

void prueba_destruccion(){
	printf("~~~ PRUEBA DE DESTRUCCION ~~~\n");
	
	//variables
	int a=1;
	lista_t* lista = lista_crear();
	
	if (lista != NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		
		// inserto algunos elementos
		for(int i=0; i<5; i++){
			lista_insertar_primero(lista, &a);
		}
		printf("Se apilaron algunos elementos \n");
		//destruyo lista
		lista_destruir(lista, NULL);
	}	
	printf("En heap \n");
	
	//variables
	int* b= malloc(sizeof(int)); 
	int* c= malloc(sizeof(int)); 
	int* d= malloc(sizeof(int)); 		
	lista_t* lista2 = lista_crear();
	*b=3;
	*c=4;
	*d=5;
	if (lista2 != NULL){
		print_test("lista esta vacia", lista_esta_vacia(lista2) == true );
		
		//inserto algunos punteros
		lista_insertar_primero(lista2, b);
		lista_insertar_primero(lista2, c);
		lista_insertar_primero(lista2, d);
		printf("Se apilaron punteros \n");
		//destruyo la lista
		lista_destruir(lista2, free);
	}
}


void prueba_volumen(){
	printf("~~~ PRUEBA DE VOLUMEN ~~~\n");
	
	//variables
	int a=1;
	lista_t* lista = lista_crear();
	
	if (lista != NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
	}	
		//inserto muchos elementos elementos
		printf("insertando muchos elementos\n");
		for(int i=0; i<80; i++){
			lista_insertar_ultimo(lista, &a);
		}
		print_test("Lista NO esta vacia", lista_esta_vacia(lista) == false );
		
		//destruyo la lista
		lista_destruir(lista, NULL);
}	



void pruebas_lista_alumno() {
    lista_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
		
	//inicio de pruebas
	prueba_un_elemento();
	prueba_elementos();
	prueba_destruccion();
	prueba_volumen();
}

