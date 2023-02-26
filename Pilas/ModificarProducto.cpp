/*
Confeccionar una programa que administre una lista tipo pila (se debe poder insertar, extraer e imprimir los datos de la pila).
*/
/*
Agregar al problema anterior otras dos funciones: que retorne la cantidad de nodos y otro que indique si esta vacía (1=vacía y 0=no vacía).
*/

/*
Agregar otra función al programa desarrollado para administrar una pila que retorne la información del primer nodo de la Pila sin borrarlo.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

Nodo *pila_p = NULL;
Nodo *pila_aux = NULL;


// declaracion de funciones
void insertar(int);
int extraer ();
void imprimir();
int cantNodos();
int vacia();
int primerNodo();
void modificarNodo();
void imprimir_pila_respaldo ();

int main(){

  int op=0, ciclo = 0, n = 0;

  do {
    system("cls");
    cout<<"0. Salir";
    cout<<"\n1. Insertar";
    cout<<"\n2. Extraer";
    cout<<"\n3. Imprimir";
    cout<<"\n4. Mostrar la cantidad de nodos";
    cout<<"\n5. Verificar si esta vacia la pila";
    cout<<"\n6. Mostrar primer nodo de la pila";
    cout<<"\n7. Eliminar un numero de la pila";
    cout<<"\nElija una opcion: "; cin>>op;

    switch (op)
    {
        case 0: 
            ciclo = 1;
        break;

        case 1: system("cls");
            cout<<"Ingrese un numero: "; cin>>n;
            insertar(n);
        break;

        case 2: system("cls");
            cout<<"Numero "<<extraer()<<" extraido con exito de la pila";
            cout<<"\n";
            system("pause");
        break;

        case 3: system("cls");
            imprimir();
            cout<<"\n";
            system("pause");
        break;

        case 4: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else
            {
                cout<<"La pila tiene "<<cantNodos()<<" nodos";
            }     

            cout<<"\n";
            system("pause");
        break;

        case 5: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else 
            {
                cout<<"La pila tiene "<<cantNodos()<< " elementos";
            }

            cout<<"\n";
            system("pause");
        break;

        case 6: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else
            {
                cout<<"Primer nodo de la pila:  "<<primerNodo();
            }     

            cout<<"\n";
            system("pause");

        break;

        case 7: system("cls");
            //cout<<"Ingrese el numero que desea eliminar: "; cin>>n;
            modificarNodo();
            //cout<<"\n";
            system("pause");
        break;
        case 8:
            system("cls");
            imprimir_pila_respaldo ();
            cout<<"\n";
            system("pause");
        break;
        default: 
        cout<<"\nOpcion incorrecta!"; 
        cout<<"\n";
        system("pause");

    }   
  } while (ciclo == 0);



    return 0;
}

void insertar(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->sig = pila_p; 
    pila_p = nuevo_nodo;
}

int extraer (){
    Nodo *nuevo_nodo = new Nodo();

    int informacion = pila_p->dato;

    if (pila_p != NULL)
    {
        nuevo_nodo = pila_p;
        pila_p = pila_p->sig;
        delete nuevo_nodo;
        return informacion;
    }
    else
    {
        return -1;
    }

}

void imprimir(){

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo = pila_p;
      if(nuevo_nodo != NULL){
        while (nuevo_nodo != NULL)
        {
            cout<<"|"<<nuevo_nodo->dato<<"|";
            nuevo_nodo = nuevo_nodo->sig;
            cout<<"\n";
        }
      }else{
            cout << "\n esta pila principal esta vacia\n";
        }
}
void imprimir_pila_respaldo(){

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo = pila_aux;
if(nuevo_nodo != NULL){
     while (nuevo_nodo != NULL)
      {
          cout<<"|"<<nuevo_nodo->dato<<"|";
          nuevo_nodo = nuevo_nodo->sig;
          cout<<"\n";
      }
     }else{
            cout << "\n esta pila principal esta vacia\n";
        }
}

int cantNodos(){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo = pila_p;

    int cant = 0;

    if (nuevo_nodo == NULL)
    {
        return cant;
    }

    else
    {
        while (nuevo_nodo != NULL)
        {
            cant++;
            nuevo_nodo = nuevo_nodo->sig;
        }

        return cant;
    }
}

int vacia(){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo = pila_p;
    
    if (nuevo_nodo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int primerNodo(){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo = pila_p;

    int primero = 0;

    if (nuevo_nodo->sig == NULL)
    {
        primero = nuevo_nodo->dato;
        return primero;
    }
    else
    {
        while(nuevo_nodo->sig != NULL)
        {
            nuevo_nodo = nuevo_nodo->sig;
        }

        primero = nuevo_nodo->dato;
        return primero;
        
    }

}

void modificarNodo(){

    int n;
    cout << "Ingrese el dato que va a eliminar";
    cin >> n;
    
    // Eliminar objetivo si es primer nodo

    if(pila_p->dato == n){
      Nodo *aux = new Nodo();
      aux = pila_p;
      pila_p = pila_p->sig;
      delete aux;
      cout << "\nDato eliminado correctamente\n";
      system("pause");
    }else{
      // busqueda y respaldo
      while (pila_p->dato != n)
        {
            Nodo *aux = new Nodo();
            Nodo *aux2 = new Nodo();
            aux = pila_p;
            aux2->dato = aux->dato;
            aux2->sig = pila_aux;
            pila_aux = aux2;
            pila_p = pila_p->sig;
            delete aux;
        }
      
      // eliminar objetivo

      Nodo *aux = new Nodo();
      aux = pila_p;
      pila_p = pila_p->sig;
      delete aux;

      cout << "\nDato eliminado correctamente\n";
      system("pause");
    }

    // restaurar pila

while (pila_aux != NULL)
{
  Nodo *aux = new Nodo();
  Nodo *aux2 = new Nodo();
  aux=pila_aux;
  aux2->dato = aux->dato;
  aux2->sig = pila_p;
  pila_p = aux2;
  pila_aux = pila_aux->sig;
  delete aux;
}

    cout << "\npila transportada correctamente\n";
    system("pause");
} 