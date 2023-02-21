#include <iostream>
#include <stdlib.h>

using namespace std; 

struct Nodo 
{
    int dato;
    Nodo *siguiente;
};

Nodo *fin = NULL;
Nodo *frente = NULL;

void eliminar (Nodo *&frente);
void insertar(Nodo *&frente, Nodo*&fin, int n);
bool cola_vacia(Nodo *frente);
void mostrar_cola(Nodo *&frente);

int main()
{
    int n = 10, n1=12, n2=20;

    insertar(frente, fin, n);
    insertar(frente, fin, n1);
    insertar(frente, fin, n2);
    mostrar_cola(frente);
    eliminar(frente);
    cout<<"\n";
    mostrar_cola(frente);
    eliminar(frente);
    cout<<"\n";
    mostrar_cola(frente);
    eliminar(frente);
    cout<<"\n";
    mostrar_cola(frente);


    
    system ("pause");
    return 0;


}

void insertar(Nodo *&frente, Nodo *&fin, int n)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente=NULL;

    if (cola_vacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
       fin->siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
}

void eliminar (Nodo *&frente)
{
    Nodo *nodo_aux = frente;

    if (cola_vacia(frente))
    {
        cout<<"La cola ya se encuentra vacia";
    }
    else 
    {
        frente = nodo_aux->siguiente;
        delete nodo_aux;
    }
}

bool cola_vacia(Nodo *frente)
{
    return (frente == NULL)? true : false;
}

void mostrar_cola(Nodo *&frente)
{
    Nodo *nuevo_nodo = frente;

    while (!(cola_vacia(nuevo_nodo)))
    {
        cout<<nuevo_nodo->dato<<" - ";
        nuevo_nodo=nuevo_nodo->siguiente;
    }

}