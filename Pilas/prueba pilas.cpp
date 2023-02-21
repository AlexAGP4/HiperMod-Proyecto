/*Ejercicio 2: Hacer un programa en C++, utilizando Pilas que contenga el siguiente 
menu: 

	1. Insertar un caracter a la pila
	2. Mostrar todos los elementos de la pila
	3. Salir
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstring>
#define TAM 5
using namespace std;

struct Nodo
{
	string nombreProducto;
	int precioProducto;
	int cantidadProducto;
	Nodo *siguiente;	
};

  Nodo auxiliar;
  Nodo *pila = NULL;
//Prototipo
void menu();
void agregarPila(Nodo *&,Nodo);
void mostrarPila(Nodo *&pila);
//void sacarPila(Nodo *&,char &);

int main(){
  
	menu();
	
	getch();
	return 0;
}

void menu(){
	
	
	int opcion;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insertar un caracter a la pila"<<endl;
		cout<<"2. Mostrar todos los elementos de la pila"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
                cout<<"\nIndique el nombre del producto: ";
				        cin>>auxiliar.nombreProducto;
                cin.clear();
                cout<<"\nIndique el precio del producto: ";
                cin>>auxiliar.precioProducto;
                cin.clear();
                cout<<"\nIndique la cantidad que va a comprar: ";
                cin>>auxiliar.cantidadProducto;
                cin.clear();
            	  agregarPila(pila,auxiliar);
                system("pause");
               break;

			case 2:
				
                mostrarPila(pila);
                system("pause");            
            break;
            
			case 3: break;
		}
		system("cls"); //limpiar pantalla
	}while(opcion != 3);
	
}

void agregarPila(Nodo *&pila,Nodo auxiliar){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo= &auxiliar;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
  cout<<"DATOS AGG CORRECTAMENTE";
  
}

void mostrarPila(Nodo *&pila)
{

    Nodo *temp_ptr= pila, *aux = pila;
    while (temp_ptr != NULL)
    {
    //cout << "\nproducto: " << i;
    cout << "\n nombre: " << temp_ptr->nombreProducto;
    cout << "\n precio: " << temp_ptr->precioProducto;
    cout << "\n cantidad: " << temp_ptr->cantidadProducto;
    aux = temp_ptr;
    temp_ptr = temp_ptr->siguiente;
    delete aux;
    
    }

    cout<<"\n";
}

// void sacarPila(Nodo *&pila,char &n){
// 	Nodo *aux = pila;
// 	n = aux->dato;
// 	pila = aux->siguiente;
// 	delete aux;
// }