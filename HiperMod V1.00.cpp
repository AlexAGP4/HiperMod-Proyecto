#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//constantes
#define TAM 10


//definicion de estructuras globales
//nodos de pila para el carrito
struct Nodo
{
	char nombreProducto [15];
	int precioProducto;
	int preciototalProducto;
	int cantidadProducto;
	Nodo *siguiente;	
};

//productos
struct productos{
	char id[5];
	char descripcion[15];
	int stock;
	float precio;
} prod[TAM];

//personas
struct personas{
int idCliente;
Nodo *carrito [TAM];
int totalArticulos;
} cliente[TAM];

//declaracion de Funciones
void crearProductos();
void menu();
void Compras();
void listaProductos();
void seleccionProductos(personas[],productos[]);
void pagar(personas cliente[]);


// variables globales
int opc = 0;
int ncliente = 0;
 Nodo *pila = NULL;
 Nodo auxiliar;

/*------------------------------------------
			funcion Principal
--------------------------------------------*/
int main()
{
	crearProductos();
  do 
	{
  menu();
  switch (opc)
	    {
	        case 1:
            //lamada a la funcion
            Compras();
		        system("pause");
		        opc=0;
		        break;
	        case 2:
	            system("cls");
	            cout<<"\nPRUEBA Funcion ver lista de Productos\n\n";
              listaProductos();
              system("pause");
	            opc=0;
	            break;
	        case 3:
	           	system("cls");
	        	cout<<"\n\n\nPRUEBA Funcion Generar Reporte\n\n\n\n";
	        	system("pause");
	        	opc=0;
	            break;
	        case 4:
				exit (-1);
				break;
	        default:
	           	system("cls");
	           	cout<<" \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 4\x1b[0m\n\n\n\n\n";
	          	system("pause");
              cin.clear();
	           	opc=0;    
	    }
      }while (opc==0);

  return 0;
}

//declaracion de funciones

// FUNCION PRODUCTOS
void menu ()
{

		system("cls");
		cout<<"\x1b[31m-------------------------------------\n";
		cout<< "-------------------------------------\n";
	  cout<< "	       \x1b[0mHiperMod\n";
	  cout<< "\x1b[31m-------------------------------------\n";
	  cout<< "-------------------------------------\x1b[0m\n\n";
	  cout<< " (1) Realizar Compra\n";
	  cout<< " (2) ver lista de Productos\n";
	  cout<< " (3) Generar Reporte\n";
	  cout<< " (4) Salir\n\n";
	  cout<< "\x1b[31m-------------------------------------\n";
	  cout<< "-------------------------------------\x1b[0m\n\n";
	  cout<< " \n Introduzca su opcion: ";
		fflush(stdin);
    cin>>opc;
		printf ("\nUsted Selecciono el numero: %d\n\n",opc);       

}

//FUNCION COMPRAS
void Compras()
{
  opc = 0;
  for (ncliente=0; ncliente < TAM-8; ncliente++)
  {
  *cliente[cliente[ncliente].idCliente].carrito=NULL;
    cliente[ncliente].idCliente = ncliente + 1;
    do
    {
      system("cls");
      cout << "\x1b[31m-------------------------------------\n";
      cout << "-------------------------------------\n";
      cout << "	       \x1b[0mHiperMod\n";
      cout << "\x1b[31m-------------------------------------\n";
      cout << "        Bienvenido cliente #" << cliente[ncliente].idCliente << "\n";
      cout << "-------------------------------------\x1b[0m\n\n";
      cout << " (1) Elegir Productos\n";
      cout << " (2) Modificar Carrito\n";
      cout << " (3) Pagar\n";
      cout << " (4) Salir\n\n";
      cout << "\x1b[31m-------------------------------------\n";
      cout << "-------------------------------------\x1b[0m\n\n";
      cout << " \n Introduzca su opcion: ";
      fflush(stdin);
      cin >> opc;

      switch (opc)
        {
          case 1:
            system("cls");
            cout << "\n\n PRUEBA SELECCIONAR PRODUCTOS\n\n\n\n";
            seleccionProductos(cliente,prod);
            system("pause");
            opc = 0;
            break;
          case 2:
            system("cls");
            cout << "\n\n\n Prueba Modificar Carrito\n\n\n\n";
            cout << "\n\n";
            system("pause");
            opc = 0;
            break;
          case 3:
            system("cls");
            cout << "\n\n\n Prueba Pagar\n\n\n\n";
            		pagar(cliente);
            system("pause");
            opc = 0;
            break;
          case 4:
            break;
          default:
            system("cls");
            cout << " \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 4\x1b[0m\n\n\n\n\n";
            system("pause");
            cin.clear();
            opc = 0;    
        }
    } while (opc == 0);
  }
}

//FUNCION CREAR PRODUCTOS
void crearProductos() 
{	//prducto 1
	strcpy(prod[0].id, "1001");
	strcpy (prod[0].descripcion, "Harina");
	prod[0].stock=20;
	prod[0].precio=30;

	//prducto 2
	strcpy(prod[1].id, "1002");
	strcpy (prod[1].descripcion, "Harina de trigo");
	prod[1].stock=20;
	prod[1].precio=33;

	//prducto 3
	strcpy(prod[2].id, "1003");
	strcpy (prod[2].descripcion, "Aceite");
	prod[2].stock=20;
	prod[2].precio=40;

	//prducto 4
	strcpy(prod[3].id, "1004");
	strcpy (prod[3].descripcion, "Mantequilla");
	prod[3].stock=20;
	prod[3].precio=30;
	
	//prducto 5
	strcpy(prod[4].id, "1005");
	strcpy (prod[4].descripcion, "Fructus");
	prod[4].stock=20;
	prod[4].precio=30;

	//prducto 6
	strcpy(prod[5].id, "1006");
	strcpy (prod[5].descripcion, "Panelada");
	prod[5].stock=20;
	prod[5].precio=30;

	//prducto 7
	strcpy(prod[6].id, "1007");
	strcpy (prod[6].descripcion, "Sal");
	prod[6].stock=20;
	prod[6].precio=30;

	//prducto 8
	strcpy(prod[7].id, "1008");
	strcpy (prod[7].descripcion, "Azucar");
	prod[7].stock=20;
	prod[7].precio=30;

	//prducto 9		
	strcpy(prod[8].id, "1009");
	strcpy (prod[8].descripcion, "Cafe");
	prod[8].stock=20;
	prod[8].precio=30;

	//prducto 10
	strcpy(prod[9].id, "1010");
	strcpy (prod[9].descripcion, "Arroz");
	prod[9].stock=20;
	prod[9].precio=30;
}

//FUNCION LISTA DE PRODUCTOS EN INVENTARIO
void listaProductos()
{
  cout<<"\n Codigo   Nombre                    Stock     Precio";
	cout<<"\n-------------------------------------------------\n";
	for (int i=0; i<TAM; i++)
		{
			printf("%5s", prod[i].id);
			printf("  %-15s", prod[i].descripcion);
			printf("%*i ",15, prod[i].stock);
			printf("%*.2f",10, prod[i].precio);
			cout<<"\n";
		}
	cout<<"\n";
}


//FUNCION LLENADO DEL CARRITO
void seleccionProductos(personas cliente[],productos prod[])
{
  char idProducto[5];
  int cantProducto;
  int totalArticulos;
  bool band=false;
  if (cliente[cliente[ncliente].idCliente].totalArticulos>=0 && cliente[cliente[ncliente].idCliente].totalArticulos<30)
  {
    // seleccion de producto y validacion de codigo correcto
    do
    {
      system("cls");
      listaProductos();
      cout << "\n\n Porfavor escriba el codigo del producto que desea meter al carrito: ";
      fflush(stdin);
      cin >> idProducto;
      
      // Encuentra el codigo producto y valida que el codigo exista
      for (int j = 0; j < TAM; j++)
      {
        if (strcmp(idProducto, prod[j].id) == 0)
        {
          band = true;
          goto VALI1;
        }
      }

      if (band == false)
      {
        cout<<"\nEste producto no existe, elija uno de la lista!\n";
        system("pause");
      }

      VALI1:
      if (band==true)
      {
        do
        {
          cout << "\n\n Porfavor escriba la cantidad de producto a llevar \n\x1b[31mMaximo 5 por producto!\n Cantidad:\x1b[0m  ";
          fflush(stdin);
          cin >> cantProducto;
          cin.clear();
        } while (((!(cantProducto <= 5 && cantProducto > 0))&&(cliente[cliente[ncliente].idCliente].totalArticulos>=0 && cliente[cliente[ncliente].idCliente].totalArticulos<30)));
        goto VALI;
      } 
    }while (band == false);
    VALI:
    system("pause");
    totalArticulos = 0;
    totalArticulos += cantProducto;


    //creacion del nuevo nodo
    Nodo *nuevo_nodo = new Nodo();
    
    // llenamos los datos que correspponden al nodo
      int controlSCH= (int) strtol(idProducto,NULL,10);
      switch (controlSCH)
      { 
        case 1001:
        strcpy (nuevo_nodo->nombreProducto,prod[0].descripcion);
        nuevo_nodo->precioProducto=prod[0].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[0].precio;
        break;
        case 1002:
        strcpy (nuevo_nodo->nombreProducto,prod[1].descripcion);
        nuevo_nodo->precioProducto=prod[1].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[1].precio;
        break;
        case 1003:
        strcpy (nuevo_nodo->nombreProducto,prod[2].descripcion);
        nuevo_nodo->precioProducto=prod[2].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[2].precio;
        break;
        case 1004:
        strcpy (nuevo_nodo->nombreProducto,prod[3].descripcion);
        nuevo_nodo->precioProducto=prod[3].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[3].precio;
        break;
        case 1005:
        strcpy (nuevo_nodo->nombreProducto,prod[4].descripcion);
        nuevo_nodo->precioProducto=prod[4].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[4].precio;
        break;
        case 1006:
        strcpy (nuevo_nodo->nombreProducto,prod[5].descripcion);
        nuevo_nodo->precioProducto=prod[5].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[5].precio;
        break;
        case 1007:
        strcpy (nuevo_nodo->nombreProducto,prod[6].descripcion);
        nuevo_nodo->precioProducto=prod[6].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[6].precio;
        break;
        case 1008:
        strcpy (nuevo_nodo->nombreProducto,prod[7].descripcion);
        nuevo_nodo->precioProducto=prod[7].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[7].precio;
        break;
        case 1009:
        strcpy (nuevo_nodo->nombreProducto,prod[8].descripcion);
        nuevo_nodo->precioProducto=prod[8].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[8].precio;
        break;
        case 1010:
        strcpy (nuevo_nodo->nombreProducto,prod[9].descripcion);
        nuevo_nodo->precioProducto=prod[9].precio;
        nuevo_nodo->cantidadProducto=cantProducto;
        nuevo_nodo->preciototalProducto=cantProducto*prod[9].precio;
        break;
      
      
      } 

      system("cls");
      cout<<"\nArticulo añadido con exito al carrito!: ";
      cout<<"\n nombre: "<<nuevo_nodo->nombreProducto;
      cout<<"\n precio producto: "<<nuevo_nodo->precioProducto;
      cout<<" \n cantidad: "<<nuevo_nodo->cantidadProducto;
      cout<<"\n precio total: "<<nuevo_nodo->preciototalProducto;
      
      
    // llenamos el ultimo dato del nodo el cual es el "siguiente" que se encarga de apuntar al nodo anterior
    nuevo_nodo->siguiente = *cliente[cliente[ncliente].idCliente].carrito;
    
    //asignamos nuevo nodo a pila para que pila apunte ahora al tope
    *cliente[cliente[ncliente].idCliente].carrito = nuevo_nodo;
  }
}

void pagar(personas cliente[])
{
	int nProductos=1;
	if (*cliente[cliente[ncliente].idCliente].carrito == NULL)
	{
		cout<< "\n\npila vacia";
		system ("pause");
	}
	else
	{
	//esta variable se crea para respaldar la direccion de memoria de pila
    Nodo *aux1=*cliente[cliente[ncliente].idCliente].carrito;
    // validacion  fondo de la pila
    while (aux1 != NULL)
    {
    	//impresion de datos
    cout << "\nProducto: #" << nProductos;
		cout<<"\n nombre: "<<aux1->nombreProducto;
		cout<<"\n precio producto: "<<aux1->precioProducto;
		cout<<" \n cantidad: "<<aux1->cantidadProducto;
		cout<<"\n precio total: "<<aux1->preciototalProducto;
    cout<<"\n\nDatos mostrados correctamente";
    
    //se avanza al siguiente noso de la pila
	aux1 = aux1->siguiente;
    
    //contador de productos mostrados
	nProductos++;
    cout <<"\n";
    system ("pause");
    
    
    }
    
    cout<<"\n";
}
}