

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Carro
{
int idArticulo;
int Car_Prod_T;
Carro *sig;
};

struct Nodo{
    int idCliente; // esta variable es para el cliente
    Carro *carrito; // esta variable es la pila carrito
		bool pagar;  // esta variable es para el cliente
		Nodo *sig;		//esta variable es para el nodo cola, y a su ves para el nodo carrito
		int Client_art_T; //esta es articulos totales para el cliente
};

// declaracion de funciones
void compra(Nodo *&); //esto va a recibir es el frente y el fin de la cola
void crearClientesCola(Nodo *&, Nodo *&);
void verClientesCola(Nodo *&);
void generarReporte(Nodo *&);
bool buscarIdProducto(Carro *&, int);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
		int op = 0, ciclo = 0;
		crearClientesCola(frente,fin);
    do
    {
      system("cls");
      cout << "0. Salir";
      cout << "\n1. Compra";
    	cout << "\n2. Generar reporte de compra";
			cout << "\n3. Imprimir Cola Clientes";
      cout << "\nElija una opcion: ";
      cin >> op;

      switch (op)
      {
      case 0:
        ciclo = 1;
        break;

        case 1: system("cls");
             compra(frente);
        break;

				case 2:
				generarReporte(frente);
				break;

				case 3:
					system("cls");
					verClientesCola(frente);
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

//generar e imprimir carritos
void compra (Nodo *& frente){
    int idArticulo;
    int cant_prod_totales;
    Nodo *client_node = new Nodo(); // esto crea el espacio de memoria para el cliente
		client_node = frente;						// aqui apunto al primer cliente
		int respuesta = 0;

		while (client_node != NULL)
		{
      REPETIR:
      while ((client_node->pagar == false))
      {	
          Carro *node_pila = new Carro();  //esto crea el espacio de memoria para el carrito del cliente
          system("cls");

          //pido los articulos del carrito
          AGGPRODUCTO:
          cout << "\nBienvenido cliente # " << client_node->idCliente;
          cout << "\n porfavor ingrese el id del producto a meter en carrito\n";
          cout << "\n\n1001 harina"
              << "\n1002 arroz"
              << "\n1003 pasta"
              << "\n1004 azucar"
              << "\n1005 pollo"
              << "\n1006 jabon\n\n";
          fflush(stdin);
          cin>>idArticulo;

          // estas variables son para recorrer la busqueda en caso de id articulos repetidos
          Carro *aux = new Carro();
          aux = client_node->carrito;
         
          //aqui empiezan las validaciones y llenado de datos segun lo cumplido
          
          if(buscarIdProducto(aux, idArticulo)==true)
          {
            system("cls");
            cout << "\n\n este articulo ya esta agregado a su carrito, no puede tener mas de dos tipos de productos en el carrito";
            cout << "\n si desea modificar la cantidad del producto que elegigio valla a la opcion modificar";
            cout << "\n elimine el producto que desea modificar y luego insertelo nuevamente con las cantidades correctas\n";
            system("pause");
            goto AGGPRODUCTO;
          }else
          {
            if(client_node->Client_art_T==30)
            {
              cout << "\n\n su carrito esta lleno no puede agregar mas productos porfavor pague su deuda";
              goto PAGAR;
            } else
            {
              if(client_node->Client_art_T<30)
              {
                //asigno el id del producto al carrito
                node_pila->idArticulo = idArticulo;

                //pido la cantidad del producto
                 do
                  {
                    ARTICULOS:
                    cout << "\n su carrito tiene ya: "<<(client_node->Client_art_T) <<" articulos alamacenados en total";
                    cout << "\n\n Porfavor escriba la cantidad de producto a llevar \n\x1b[31mMaximo 5 por producto!\n Cantidad: \x1b[0m  ";
                    fflush(stdin);
                    cin >> cant_prod_totales;
                    cin.clear();
                  } while (!(cant_prod_totales <= 5 && cant_prod_totales > 0));
                  ///pendiente de corregir
              }
              
               if((client_node->Client_art_T+cant_prod_totales)>30)
                {
                  cout << "\n\n usted no puede meter esa cantidad de articulos porque su carrito";
                  cout << "\n tiene ya: "<<(client_node->Client_art_T) <<" articulos";
                  cout << "\n y su carrito solo permite 30 articulos";
                  system("pause");
                  goto ARTICULOS;
                }else
                {
                  if((client_node->Client_art_T+cant_prod_totales)==30)
                  {
                    cout << "\n\n articulos agregados con exito, SU carrito ya esta lleno, dirijase a pagar su deuda";
                    node_pila->Car_Prod_T = cant_prod_totales;
                    client_node->Client_art_T += cant_prod_totales;
                    system("pause");
                    goto PAGAR;
                  }else
                  {
                    if((client_node->Client_art_T+cant_prod_totales)<30)
                    {
                      cout << "\n\n articulos agregados con exito";
                      cout << "\n\n aun puede meter en su carrito"<<((client_node->Client_art_T-30))<<"articulos mas";
                      node_pila->Car_Prod_T = cant_prod_totales;
                      client_node->Client_art_T += cant_prod_totales;
                      system("pause");
                    }
                  }
                }
              
            }
          }
        //aqui terminan las validaciones y empieza la carga del nodo a la pila
         
          node_pila->sig = client_node->carrito; //lleno el puntero del nodo carrito 
          client_node->carrito = node_pila;  //a carrito le asigno la direccion de memoria de node pila
         
         //zona de pago temporal
          PAGAR:
          cout << "\n\n Desea pagar la cuenta? SI= 1 y NO= 0 \n ";
          cout << ": ";
          fflush(stdin);
          cin >> respuesta;
          cin.clear();
          switch (respuesta) // este switch evalua el pago
            {
              case 1:
                  client_node->pagar = true;
                  break;
              case 2:
                  goto REPETIR;
              default:
                  cout << "dato invalido";
                  fflush(stdin);
            }
      }
      // Cambio de cliente (avanzamos al siguiente cliente)
      client_node = client_node->sig;
      cout << "\n ahora es Turno del cliente # " << client_node->idCliente;
      system("pause");
	  }
}
void generarReporte (Nodo *& frente){	
	system("cls");
	Nodo *client_node = new Nodo();  //esto crea el espacio de memoria para el cliente
	client_node = frente;  //aqui apunto al primer cliente
	cout << "\n\n1001 harina"
						 << "\n1002 arroz"
						 << "\n1003 pasta"
						 << "\n1004 azucar"
						 << "\n1005 pollo"
						 << "\n1006 jabon\n\n";
	while (client_node != NULL)
	{		
		cout << "\ncompra del cliente # " << client_node->idCliente; //aqui me da el id del cliente
		cout << "\n articulo       "<< "precio\n";
		Carro *node_pila = new Carro();// esto crea el espacio de memoria para el carrito del cliente
		node_pila = client_node->carrito; //aqui apunto al primer articulo del cliente
		while ((node_pila != NULL))
		{
						// imprimo los datos de la compra del cliente

						cout <<" "<<node_pila->idArticulo <<"        30Bs";

						node_pila = node_pila->sig; // aqui avanzo al siguente articulo
		}
			client_node = client_node->sig; // aqui avanzo al siguiente cliente
			cout << "\n-----------------------------\n";
			
	}
	system("pause");
}

//generar cola de pago y clientes
void crearClientesCola(Nodo *&frente, Nodo *&fin )
{
		int idCLiente = 101;
	
	while (idCLiente < 104)
	{
		//primer paso crear espacio en memoria
		Nodo *new_node = new Nodo();
		// segundo paso llenar datos del nodo creado
		new_node->idCliente = idCLiente;
		new_node->carrito = NULL;
		new_node->sig = NULL;
		new_node->pagar = false;
		new_node->Client_art_T = 0;
    idCLiente=idCLiente+1;

		if (frente==NULL)
		{
			frente = new_node;
		}else
		{
			fin->sig = new_node;
		}
		fin = new_node;
	}
}
void verClientesCola(Nodo *&frente)
{
	//primer paso creo nuevo nodo y lo igualo a frente
	Nodo *new_node = new Nodo();
		new_node = frente;
	while (new_node != NULL)
	{
		//segundo paso imprimo los datos en pantalla
		cout << "|id cliente: " << new_node->idCliente << "| |carrito: " << new_node->carrito << "|\n";

		//tercer paso avanso en mi -> siguiente 
		new_node = new_node->sig;
	}
	cout << "\n Datos impresos correctamente\n\n";
	system("pause");
}

bool buscarIdProducto(Carro *&aux, int idArticulo)
{
  
    //si esta en el primer nodo
  if (aux==NULL)
  {
    return false;
  }
  else 
  {
    while(aux!=NULL)
      {
  
        if (aux->idArticulo==idArticulo)
          {
                  return true;
          }
          aux = aux->sig;
      }
      return false;
  }
   
}