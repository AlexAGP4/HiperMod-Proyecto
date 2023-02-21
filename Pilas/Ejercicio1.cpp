#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int valor;
    struct Nodo *sig;
};

Nodo *pila = NULL;

void insertar(Nodo *&, int);
void mostrarPila(Nodo *&);
int eliminar(Nodo *&);

int main()
{
    
    int n1=10, n2=12;

    insertar(pila, n1);
    insertar(pila, n2);
    mostrarPila(pila);
    eliminar(pila);
    cout<<"\n";
    mostrarPila(pila);
    eliminar(pila);
    mostrarPila(pila);


    cout<<"\n";
    system ("pause");
    return 0;
}

void insertar(Nodo *&pila, int n)
{

    Nodo *temp_ptr = new Nodo();

    temp_ptr->valor = n;

    temp_ptr->sig = pila;
    pila = temp_ptr;

}

void mostrarPila(Nodo *&pila)
{
    Nodo *temp_ptr = pila;
    while (temp_ptr != NULL)
    {
        cout << temp_ptr->valor << "-";
        temp_ptr = temp_ptr->sig;
        
    }
}

int eliminar(Nodo *&pila)
{
    if (pila != NULL)
    {
        int informacion = pila->valor;
        Nodo *temp_ptr = pila;
        pila = temp_ptr->sig;
        delete temp_ptr;
        return informacion;  
    }
    else 
    {
        return -1;
    }
}