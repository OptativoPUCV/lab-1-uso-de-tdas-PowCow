#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for (int k = 1 ; k <= 10 ; k++){
      int* numero = (int*)malloc(sizeof(int)) ;
      *numero = k ;
      pushBack(L, numero) ;
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0 ;
   int *valor ;
   valor = (int*)first(L) ;
   while (valor != NULL){
      suma += *valor ;
      valor = (int*)next(L) ;
   }
   return suma ;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *num = (int*)first(L);
   while (num != NULL){
      if (*num == elem){
         popCurrent(L) ;
         num = (int*)first(L) ;
      }
      else {
         num = (int*)next(L) ;}
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* pilaAux = create_stack() ;
   while (top(P1) != NULL){
      push(pilaAux, top(P1)) ;
      pop(P1) ;
   }
   while (top(pilaAux) != NULL){
      push(P2, top(pilaAux)) ;
      push(P1, top(pilaAux)) ;
      pop(pilaAux) ;
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   char *pila = NULL ;
   int cont = -1 ;

   for (int k = 0 ; cadena[k] != '\0' ; k++) {
      char par = cadena[k] ;

      if (par == '(' || par == '{' || par == '[') {
         cont++;
         char *mom = (char *)realloc(pila, (cont + 1) * sizeof(char));
         if (!mom) {
            free(pila);
            return 0;
         }
         pila = mom;
         pila[cont] = par;
      } else if (par == ')' || par == '}' || par == ']') {
         if (cont == -1) {  
            free(pila);
            return 0;
         }
         char tope = pila[cont];
         if ((par == ')' && tope != '(') || (par == ']' && tope != '[') || (par == '}' && tope != '{')) {
            free(pila);
            return 0;  
         }
         cont--; 
      }
   }

   int resultado = (cont == -1) ? 1 : 0;
   free(pila);
   return resultado;
}

