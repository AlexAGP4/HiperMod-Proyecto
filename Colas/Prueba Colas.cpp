#include <iostream>
#include <cstdlib>

using namespace std;

// Estructura para los nodos

struct Nodo
{
    int dato;
    Nodo *sig;
};

// Prototipos de funciones

void insertarCola(Nodo *&, Nodo *&, int);
void eliminarCola(Nodo *&);
void imprimirCola(Nodo *&);
bool colaVacia(Nodo *&);

int main(){

    // Inicialización de los apuntadores principales de la cola
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int ciclo = 0;
    int op = 0;
    int n = 0;

    do{
    
        cout<<"(1) Insertar un elemento en la cola\n";
        cout<<"(2) Extraer un elemento de la cola\n";
        cout<<"(3) Imprimir cola\n";
        cout<<"(4) Salir\n";
        cout<<"Seleccione una opcion: "; cin>>op;

        switch (op)
        {
            case 1: 
                system("cls");
                cout<<"Ingrese el numero que desea insertar en la cola"; 
                cin>>n;
                insertarCola(frente, fin, n);
                system("pause");
            break;

            case 2: 
                system("cls");
                eliminarCola(frente);
                system("pause");
            break;

            case 3: 
                system("cls");
                imprimirCola(frente);
                system("pause");
            break;

            case 4:
                ciclo = 1;
            break;

            default: cout<<"Opcion incorrecta";
        }

    }while(ciclo == 0);

    
    return 0;
}

void insertarCola (Nodo *&frente, Nodo *&fin, int n)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->sig = NULL;

    if (colaVacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->sig = nuevo_nodo;
    }

    fin = nuevo_nodo;

    cout<<"Elemento insetado con exito en la cola";

}

void eliminarCola(Nodo *&frente)
{
    Nodo *nodo_aux = new Nodo();

    nodo_aux = frente;
    frente = nodo_aux->sig;
    delete nodo_aux;
}

void imprimirCola(Nodo *&frente)
{
    Nodo *nodo_aux = new Nodo();

    nodo_aux = frente;

    while (nodo_aux != NULL)
    {
        cout<<"|"<<nodo_aux->dato<<"|";
        nodo_aux = nodo_aux->sig;
    }
}

bool colaVacia(Nodo *&frente)
{
    return (frente == NULL)? true : false;
}