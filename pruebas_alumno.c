#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_null(){
	printf("~~~ PRUEBA NULL ~~~\n");	
	lista_t* lista= NULL;
	print_test("Insertar lista principio NULL= false",lista_insertar_primero(lista,NULL)==false);
	print_test("Insertar lista final NULL= false", lista_insertar_ultimo(lista,NULL)==false);
	print_test("Borrar lista NULL = NULL", lista_borrar_primero(lista)==NULL);
	print_test("Tamaño Lista = 0", lista_largo(lista)==0);
	printf("~~~ PRUEBA VACIA ~~~\n");
	lista=lista_crear();
	print_test("Borrar lista Vacia = NULL", lista_borrar_primero(lista)==NULL);
	print_test("Tamaño Lista = 0", lista_largo(lista)==0);
	lista_destruir(lista, NULL);
}

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
			print_test("Tamaño Lista = 1", lista_largo(lista)==1);
			print_test("Elemento 1 esta primero", lista_ver_primero(lista) == &a);
			print_test("Elemento 1 esta ultimo", lista_ver_ultimo(lista) == &a);	
			print_test("Borrar primer elemento = 1",lista_borrar_primero(lista) == &a);
			print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
			print_test("Tamaño Lista = 0", lista_largo(lista)==0);
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
		print_test("Tamaño Lista = 3", lista_largo(lista)==3);
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
	
		//inserto muchos elementos elementos
		printf("insertando muchos elementos\n");
		for(int i=0; i<80; i++){
			lista_insertar_ultimo(lista, &a);
		}
		print_test("Lista NO esta vacia", lista_esta_vacia(lista) == false );
		
		//destruyo la lista
		lista_destruir(lista, NULL);
	}
	printf("En heap\n");
	lista= lista_crear();
	if (lista != NULL ){
		for (int i=0; i<1000; i++){
			int*p =malloc(sizeof(int));
			*p=i;
			lista_insertar_primero(lista,p);
		}
		
		//destrucción
		lista_destruir(lista, free);
	}
}	

void prueba_un_elemento_iter(){
	printf("~~~ PRUEBA 1 ELEMENTO  CON ITER~~~\n");
	//variables
	int a=1;
	lista_t* lista = lista_crear();
	lista_iter_t* iter=lista_iter_crear(lista);
	
	if (lista != NULL && iter != NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		print_test("Iter al final", lista_iter_al_final(iter)== true);
		print_test("Avanzar = False", lista_iter_avanzar(iter) == false);
		print_test("Insertar valor 1", lista_iter_insertar(iter,&a)== true);
		print_test("Inserción correcta",lista_ver_primero(lista)== &a);
		print_test("Tamaño Lista = 1", lista_largo(lista)==1);
		print_test("Avanzar = true", lista_iter_avanzar(iter) == true);
		print_test("Borrar elemento == NULL",lista_iter_borrar(iter)==NULL);
		print_test("Iter al final", lista_iter_al_final(iter)== true);
		lista_iter_destruir(iter);
		iter=lista_iter_crear(lista);
		printf("creacion de iter apuntando a primer elemento\n"); 
		print_test("Actual = 1", lista_iter_ver_actual(iter)== &a);
		print_test("Borrar elemento == 1",lista_iter_borrar(iter)== &a);
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		print_test("Tamaño Lista = 0", lista_largo(lista)==0);
	}	
	//destrucción
	lista_destruir(lista, NULL);
	lista_iter_destruir(iter);
}

void prueba_elementos_iter(){
	printf("~~~ PRUEBA VARIOS ELEMENTOS CON ITER ~~~\n");
	printf("En stack \n");
	//variables
	int a=1,b=2,c=3;
	lista_t* lista = lista_crear();
	lista_iter_t* iter= lista_iter_crear(lista);
	if (lista != NULL && iter!= NULL){
		print_test("Lista esta vacia", lista_esta_vacia(lista) == true );
		print_test("Inserción de elemento 1",lista_iter_insertar(iter,&a)==true);
		print_test("Inserción de elemento 2",lista_iter_insertar(iter,&b)==true);
		print_test("Inserción de elemento 3",lista_iter_insertar(iter,&c)==true);
		print_test("Tamaño Lista = 3", lista_largo(lista)==3);
		print_test("Primero = 3", lista_ver_primero(lista)== &c);
		print_test("Iter avanzar",lista_iter_avanzar(iter)==true);
		print_test("Actual = 2", lista_iter_ver_actual(iter)== &b);
		print_test("Iter avanzar",lista_iter_avanzar(iter)==true);
		print_test("Actual = 1", lista_iter_ver_actual(iter)== &a);
		print_test("Iter avanzar",lista_iter_avanzar(iter)==true);
		print_test("Iter al final",lista_iter_al_final(iter)==true);
		//destrucción
		lista_destruir(lista, NULL);
		lista_iter_destruir(iter);
	}

		
}

void prueba_volumen_iter(){
	printf("~~~ PRUEBA VOLUMEN CON ITER ~~~\n");
	printf("En stack \n");
	//variables
	lista_t* lista = lista_crear();
	lista_iter_t* iter= lista_iter_crear(lista);
	
	if (lista != NULL && iter!= NULL){
		for(int i=0; i<1000; i++){
				lista_iter_insertar(iter,&i);
		}
		//destrucción
		lista_destruir(lista, NULL);
		lista_iter_destruir(iter);
	}	
	printf("En heap \n");
	lista= lista_crear();
	iter=lista_iter_crear(lista);
	if (lista != NULL && iter!= NULL){
		for (int i=0; i<1000; i++){
			int*p =malloc(sizeof(int));
			*p=i;
			lista_iter_insertar(iter, p);
		}
		while( !lista_iter_al_final(iter) ){
				void* p= lista_iter_borrar(iter);
				free(p);
		} 
		//destrucción
		lista_destruir(lista, NULL);
		lista_iter_destruir(iter);
	}	
	
}

bool multiplicar(void* dato, void* extra){
	int* elemento= dato;
	int* operacion=extra;
	*elemento= *operacion*(*elemento);
	return true;
}
bool borrar(void* dato, void*extra){
		int*contador=extra;
		free(dato);
		++(*contador);
		if (*contador == 2 )return false;
		return true;
	
}

void prueba_interno(){
	printf("~~~ PRUEBA ITERADOR INTERNO ~~~\n");
	//variables
	lista_t* lista = lista_crear();
	int a=1,b=2,c=3;
	int operando=2,contador=0;
	if (lista != NULL){
		printf("Duplicado:\n");
		lista_insertar_ultimo(lista,&a);
		lista_insertar_ultimo(lista,&b);
		lista_insertar_ultimo(lista,&c);
		lista_iterar(lista, multiplicar, &operando);
		int* p= lista_borrar_primero(lista);
		print_test("Elemento 1 duplicado",*p == 2);
		int* p1= lista_borrar_primero(lista);
		print_test("Elemento 2 duplicado",*p1 == 4);
		int* p2= lista_borrar_primero(lista);
		print_test("Elemento 3 duplicado",*p2 == 6);
		
		printf("free de datos\n");		
		for (int i=0; i<3; i++){
			int*p4 =malloc(sizeof(int));
			*p4=i;
			lista_insertar_ultimo(lista, p4);
		}
		printf("Se insertaron 3 punteros\n");
		lista_iterar(lista, borrar, &contador);
		printf("Se liberaron 2 punteros\n");
		lista_borrar_primero(lista);
		lista_borrar_primero(lista);
		
	}
	//destrucción
	lista_destruir(lista, free);
	
}


void pruebas_lista_alumno() {
    lista_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
		
	//pruebas sin iterador
	prueba_null();
	prueba_un_elemento();
	prueba_elementos();
	prueba_destruccion();
	prueba_volumen();
	//pruebas con iterador externo
	prueba_un_elemento_iter();
	prueba_elementos_iter();
	prueba_volumen_iter();
	//prueba con iterador interno
	prueba_interno();
}

