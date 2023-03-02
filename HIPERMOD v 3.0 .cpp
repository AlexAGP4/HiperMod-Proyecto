#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAM 10

using namespace std;

// Estructuras
struct productos
{
	int id;
	char descripcion[15];
	int stock;
	float precio;
}prod[TAM];

struct Carro
{
	int idArticulo;
	string nombreProduct;
	float precioProductos; 
	float precioUnitario;
	int Car_Prod_T; // Variable para la cantidad de un mismo producto
	Carro *sig;
};

struct Nodo
{
	int idCliente; // esta variable es para el cliente
	Carro *carrito; // Variable de la pila carrito
	bool pagar;  // Variable para el cliente
	Nodo *sig;		//esta variable es para el nodo cola, y a su ves para el nodo carrito
	int Client_art_T; //esta es articulos totales para el cliente
};

// declaracion de funciones
void menu();
void menucompra(Nodo *&);
void listaProductos();
void crearProductos();
void crearClientesCola(Nodo *&, Nodo *&);
void compra(Nodo *&); // P
void menuModificarCarrito(Nodo *&); // P
void modEliminarArticulo(Nodo *&); // P
void modAgregarArticulo(Nodo *&); // P
void imprimirCarrito(Nodo *&); // ELIMINAR
void reporteClientes(Nodo *&); // P
void generarReporte(Nodo *&); // P
bool buscarIdProdCarrito(Nodo *&, int);
bool buscarIdProdInventario(int);
void completarCamposArti(Nodo *&, int ,int);
void animacionPresentacion();
void pagar(Nodo *&); // P

//Declaracion de variables globales
int ciclo = 0;
int opc = 0;
int clave_especial = 2023;
float ventaTotal = 0;
int cliente_solvente = 0;

//Funcion Principal
int main()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	crearClientesCola(frente,fin);
	crearProductos();
	//animacion de carga
	animacionPresentacion();
	do 
	{
		menu(); // Menú principal mostrado al iniciar el programa
		switch (opc)
		{
			case 1: 
				// Entrada al menú de usuario del cliente
				menucompra(frente);
				break;
			case 2: // Impresión del listado de productos disponibles
				system("cls");
				listaProductos();
				cout<<"\n\n\n ";
				system("pause");
				break;
			case 3: // Reporte del sistema diario
				system("cls");
				generarReporte(frente);
				break;
			case 4: // Listado de clientes
				system("cls");
				reporteClientes(frente);
				break;
			case 5: // Salir del programa
				ciclo = 1;
				break;
			default: 
				system("cls");
				cout<<" \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 5\x1b[0m\n\n\n\n\n";
				system("pause");
				cin.clear();	              
		}
	}while (ciclo==0);
	return 0;
}

//Definicion de Funciones
void menu ()
{
		system("cls");
		cout<<"\x1b[31m-------------------------------------\n";
		cout<< "-------------------------------------\n";
		cout<< "	       \x1b[0mHiperMod\n";
		cout<< "\x1b[31m-------------------------------------\n";
		cout<< "-------------------------------------\x1b[0m\n\n";
		cout<< " (1) Menu Compra\n";
		cout<< " (2) ver lista de Productos\n";
		cout<< " (3) Reporte de ventas\n";
		cout<< " (4) Reporte de clientes\n";
		cout<< " (5) Salir\n\n";
		cout<< "\x1b[31m-------------------------------------\n";
		cout<< "-------------------------------------\x1b[0m\n\n";
		cout<< " \n Introduzca su opcion: ";
		fflush(stdin);
		cin>>opc;
		printf ("\nUsted Selecciono el numero: %d\n\n",opc);
}

void menucompra (Nodo*& frente)
{
	Nodo *client = new Nodo(); // esto crea el espacio de memoria para el cliente
	client = frente;						// aqui apunto al primer cliente
	while (client != NULL)
	{
		do
		{
			system("cls");
			cout<<"\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\n";
			cout<< "	       \x1b[0mHiperMod\n              MENU COMPRA\n";
			cout<< "\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\x1b[0m\n";
			cout << "	\x1b[0mBienvenido cliente # " << client->idCliente<<"\n";
			cout<< "\x1b[31m-------------------------------------\x1b[0m\n\n";
			cout<< " (1) Seleccionar Articulos\n";
			cout<< " (2) Modificar Productos\n";
			cout<< " (3) Pagar Productos\n";
			cout<< " (4) Atras (\x1b[31mSOLO PARA EL CAJERO\x1b[0m)\n\n";
			cout<< "\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\x1b[0m\n\n";
			cout<< " \n Introduzca su opcion: ";
			fflush(stdin);
			cin>>opc;
			printf ("\nUsted Selecciono el numero: %d\n\n",opc);
			
			switch (opc)
			{
				case 1:
					compra(client);
					opc=0;
					break;
				case 2:
					system("cls");
					menuModificarCarrito(client);
					opc=0;
					break;
				case 3:
					system("cls");
					pagar(client);
					cout << "\n\nPago recibido, Muchas Grascias por su compra\n\n ";
					client = client->sig;
					Sleep(1500);
					break;
				case 4:
					system("cls");
					cout << "\n\nPorfavor ingrese su calve especial\n"<< " : ";
					int clavetemp;
					cin >> clavetemp;
					if (clavetemp==clave_especial)
					{
						return;
					}
					else
					{
						cout << "\n SU clave es incorrecta\n";
						Sleep(1000);
						break;
					}
					break;
				case 5: 
					system ("cls");
					imprimirCarrito(client);
					opc=0;
					break;
				default:
					system("cls");
					cout<<" \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 4\x1b[0m\n\n\n\n\n";
					system("pause");
					cin.clear();
					opc=0;
			}
		}while (opc==0);
	}
}

void compra (Nodo *&cliente)
{
	int idArticulo; // Variable utilizada para verificar si el articulo existe dentro de la pila del carrito
	int cant_prod_totales;
	bool aggArticulos = false;
	Nodo *client_node = new Nodo(); // esto crea el espacio de memoria para el cliente
	client_node = cliente;	// aqui apunto al primer cliente

	if (client_node->carrito==NULL)
	{
		int respuesta = 0;
      
		while ((aggArticulos == false))
		{	
			PEDIRARTICULOS:
			//PIDO LOS ARTICULOS DEL CARRITO
			system("cls");
			cout << "\n Cliente # " << client_node->idCliente<<"\n"; //saludo al cliente
			listaProductos(); //Imprimo la lista de articulos
			cout << "\n Para Volver al menu anterior escriba 5 \n";
			cout << "\n porfavor ingrese el id del producto a meter en carrito\n";
			cout << " : ";
			cin >>idArticulo;
			fflush(stdin);
			cin.clear();

			// opcion para salir al menu anterior
			if (idArticulo==5)
			{
				return;
			}
			
			// validacion Encuentra el codigo producto y valida que el codigo exista en el inventario
			if (buscarIdProdInventario(idArticulo))
			{ 
				//aqui empiezan las validaciones y llenado de datos segun lo cumplido
				if(buscarIdProdCarrito(client_node, idArticulo)==true) //esto valida que el articulo no este repetido en el carrito
				{ 
					system("cls");
					cout << "\n\n este articulo ya esta agregado a su carrito, no puede tener mas de dos tipos de productos en el carrito";
					cout << "\n si desea modificar la cantidad del producto que elegio vaya a la opcion modificar";
					cout << "\n elimine el producto que desea modificar y luego insertelo nuevamente con las cantidades correctas\n\n";
					system("pause");
					goto PEDIRARTICULOS;
				}
				else
				{
					if(client_node->Client_art_T==30) //esto valida que el cliente no meta mas de 30 articulos
					{
						system("cls");
						cout << "\n\n su carrito esta lleno no puede agregar mas productos porfavor pague su deuda\n\n";
						system("pause");
						return;
					} 

					if(client_node->Client_art_T<30) //si el cliente tiene menos de 30 articulos ingresa el articulo al carritos
					{
						//pido la cantidad del producto
						do
						{
							ARTICULOS:
							system("cls");
							//pido la cantidad de productos a meter en el carrito 
							cout << "\n su carrito tiene ya: " << (client_node->Client_art_T) << " articulos alamacenados en total\n";
							cout << "\n Porfavor escriba la cantidad del producto ( " <<idArticulo<<" ) a llevar \n\x1b[31m \n Maximo 5 por producto!\n Cantidad: \x1b[0m  ";
							fflush(stdin);
							cin >> cant_prod_totales;
							cin.clear();
							if (!(cant_prod_totales <= 5 && cant_prod_totales > 0))
							{
								cout << " Porfavor escriba un valor entre 1 y 5 (NADA MAS)\n ";
								system("pause");
							}
						}while (!(cant_prod_totales <= 5 && cant_prod_totales > 0));
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, supera los 30 articulos permitidos
					if((client_node->Client_art_T+cant_prod_totales)>30) 
					{
						cout << "\n\n usted no puede meter esa cantidad de articulos porque su carrito";
						cout << "\n tiene ya: "<<(client_node->Client_art_T) <<" articulos";
						cout << "\n y su carrito solo permite 30 articulos\n\n";
						system("pause");
						goto ARTICULOS;
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, alcanza los 30 articulos permitidos 
					if((client_node->Client_art_T+cant_prod_totales)==30)
					{
						//aqui lleno todos los campos del carrito para el articulo seleccionado
						completarCamposArti(client_node,idArticulo,cant_prod_totales);
						client_node->Client_art_T = (client_node->Client_art_T + cant_prod_totales);
						cout << "\n\n Articulos agregados con exito, Su carrito ya esta lleno, dirijase a pagar su deuda\n\n";
						system("pause");
						return;
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, alcanza los 30 articulos permitidos
					if((client_node->Client_art_T+cant_prod_totales)<30)
					{
						//aqui lleno todos los campos del carrito para el articulo seleccionado
						completarCamposArti(client_node,idArticulo,cant_prod_totales);
						client_node->Client_art_T = (client_node->Client_art_T + cant_prod_totales);
						cout << "\n\n articulos agregados con exito";
						cout << "\n\n aun puede meter en su carrito "<<((30-client_node->Client_art_T))<<" articulos mas\n\n";
					}
				}

			}
			else
			{
				cout << "\n E Codigo id del producto no existe en nuestra base de datos, porfavor lea la lista";
				cout << "\n y elija un codigo correcto \n\n\n ";
				system("pause");
				goto PEDIRARTICULOS;
			}
			// aqui terminan las validaciones y empieza la carga del nodo a la pila
			// pregunto si desea agg mas articulos
			cout << "\n\n desea agregar otro producto? SI= 1 y NO= 0 \n ";
			cout << ": ";
			fflush(stdin);
			cin.clear();
			cin >> respuesta;
			switch (respuesta) // este switch evalua el pago
			{
				case 0:
					aggArticulos = true;
					break;
				case 1:
					goto PEDIRARTICULOS;
				default:
				cout << "\n Dato invalido\n\n";
				system("pause");
				cin.clear();
				fflush(stdin);
			}
		}
	}
	else
	{
		system("cls");
		cout<<"\n Su carrito ya contiene articulos vaya a la opcion (2) Modificar Productos\n";
		Sleep (1000);
	}
}

void menuModificarCarrito(Nodo *&cliente)
{
	if (cliente->carrito != NULL)
	{
		do
		{
			system("cls");
			cout<<"\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\n";
			cout<< "	       \x1b[0mHiperMod\n             MENU MODIFICAR\n";
			cout<< "\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\x1b[0m\n";
			cout << "	\x1b[0mBienvenido cliente # " << cliente->idCliente<<"\n";
			cout<< "\x1b[31m-------------------------------------\x1b[0m\n\n";
			cout<< " (1) Eliminar articulo del carrito\n";
			cout<< " (2) Agregar articulo al carrito\n";
			cout<< " (3) Atras\n\n";
			cout<< "\x1b[31m-------------------------------------\n";
			cout<< "-------------------------------------\x1b[0m\n\n";
			cout<< " \n Introduzca su opcion: ";
			fflush(stdin);
			cin>>opc;
			printf ("\nUsted Selecciono el numero: %d\n\n",opc);
			
			switch (opc)
			{
				case 1:
				system("cls");
				modEliminarArticulo(cliente);
				system("pause");
				opc = 0;
				break;
				case 2:
					system("cls");
					modAgregarArticulo(cliente);
					system("pause");
					opc=0;
					break;
				case 3:
					return;
					break;
				default:
					system("cls");
					cout<<" \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 3\x1b[0m\n\n\n\n\n";
					system("pause");
					cin.clear();
					opc=0;
			}
		}while (opc==0);
	}
	else
	{
		cout << " Su pila esta vacia. Por favor dirijase a la opcion (1) Seleccionar Articulos.\n\n ";
		system("pause");
	}

}

void modEliminarArticulo(Nodo *&client_node)
{
				Carro *carrito_aux = NULL;
				int idArticulop;


				listaProductos();
				system("pause");

				cout << "Por favor digite el codigo del producto que va a eliminar\n : ";
				cin >> idArticulop;

				cout << " esto lo escribio el usuario " << idArticulop<<"\n\n";
				system("pause");
				cout << " esto es lo que tierne el carritoo:  " << client_node->carrito->idArticulo<<"\n\n";
				system("pause");
				

				if (buscarIdProdCarrito(client_node, idArticulop))
				{
					cout <<"encontro el codigo";
					system("pause");
						// si esta en la cima
							if (client_node->carrito->idArticulo==idArticulop )
							{
								cout <<"encontro el codigo en la cima";
								Carro *aux = new Carro();
								aux = client_node->carrito;
								client_node->carrito = client_node->carrito->sig;
								delete aux;
								cout << "\nDato eliminado correctamente\n";
								system("pause");
							}
							else
							{
								cout << "no esta en la cima";
								system("pause");
								
								//busqueda y respaldo
								//mientras idarticulo sea diferente a la cima
								while (client_node->carrito->idArticulo != idArticulop)
								{
										Carro *aux = new Carro();
										Carro *aux2 = new Carro();

										aux = client_node->carrito;

										// respaldo los datos que no necesito en aux 2
										aux2->idArticulo = aux->idArticulo;
										aux2->Car_Prod_T = aux->Car_Prod_T;
										aux2->nombreProduct = aux->nombreProduct;
										aux2->precioProductos = aux->precioProductos;
										aux2->precioUnitario = aux->precioUnitario;

										// guardando en mi pila de respaldo el nodo aux2
										aux2->sig = carrito_aux;
										carrito_aux = aux2;

										//avanzo al siguiente nodo de mi carrito princuipal
										client_node->carrito = client_node->carrito->sig;
										
										// elimino la cima ya revisada y guardada
										delete aux;
								}
			
								// eliminar objetivo

								Carro *aux = new Carro();
								//igualo a la cima
								aux = client_node->carrito;

									//avanzo al siguiente nodo de mi carrito princuipal
								client_node->carrito = client_node->carrito->sig;

								//elimino el objetivo
								delete aux;
								cout << "\n Dato eliminado correctamente";
								system("pause");
					
								//restaurar pila principal
							while (carrito_aux != NULL)
							{
								Carro *aux = new Carro();
								Carro *aux2 = new Carro();

								aux = carrito_aux;
								
								aux2->idArticulo = aux->idArticulo;
								aux2->Car_Prod_T = aux->Car_Prod_T;
								aux2->nombreProduct = aux->nombreProduct;
								aux2->precioProductos = aux->precioProductos;
								aux2->precioUnitario = aux->precioUnitario;
								
								aux2->sig = client_node->carrito;
								client_node->carrito = aux2;

								carrito_aux = carrito_aux->sig;
								delete aux;
							}

							cout << "\n pila transportada correctamente\n";
							system("pause");
								
							}

						 

				}
				else
				{
					cout<<" Este articulo no existe en su carrito.";
					system("pause");
				}
}

void modAgregarArticulo(Nodo *&client_node)
{

	cout <<"entro a la funcion";
	system("pause");

	int idArticulo; // Variable utilizada para verificar si el articulo existe dentro de la pila del carrito
	int cant_prod_totales;
	bool aggArticulos = false;

		int respuesta = 0;

		if(client_node->Client_art_T==30) //esto valida que el cliente no meta mas de 30 articulos
		{
			system("cls");
			cout << "\n\n su carrito esta lleno no puede agregar mas productos porfavor pague su deuda\n\n";
			system("pause");
			return;
		} 
      
		while ((aggArticulos == false))
		{	
			cout <<"entro a pedir los articulos";
			system("pause");

			PEDIRARTICULOS:
			//PIDO LOS ARTICULOS DEL CARRITO
			system("cls");
			cout << "\n Cliente # " << client_node->idCliente<<"\n"; //saludo al cliente
			listaProductos(); //Imprimo la lista de articulos
			cout << "\n Para Volver al menu anterior escriba 5 \n";
			cout << "\n porfavor ingrese el id del producto a meter en carrito\n";
			cout << " : ";
			cin >>idArticulo;
			fflush(stdin);
			cin.clear();

			// opcion para salir al menu anterior
			if (idArticulo==5)
			{
				return;
			}
			
			// validacion Encuentra el codigo producto y valida que el codigo exista en el inventario
			if (buscarIdProdInventario(idArticulo))
			{ 
				//aqui empiezan las validaciones y llenado de datos segun lo cumplido
				if(buscarIdProdCarrito(client_node, idArticulo)==true) //esto valida que el articulo no este repetido en el carrito
				{ 
					system("cls");
					cout << "\n\n este articulo ya esta agregado a su carrito, no puede tener mas de dos tipos de productos en el carrito";
					cout << "\n si desea modificar la cantidad del producto que elegio vaya a la opcion modificar";
					cout << "\n elimine el producto que desea modificar y luego insertelo nuevamente con las cantidades correctas\n\n";
					system("pause");
					goto PEDIRARTICULOS;
				}
				else
				{					
					if(client_node->Client_art_T<30) //si el cliente tiene menos de 30 articulos ingresa el articulo al carritos
					{
						//pido la cantidad del producto
						do
						{
							ARTICULOS:
							system("cls");
							//pido la cantidad de productos a meter en el carrito 
							cout << "\n su carrito tiene ya: " << (client_node->Client_art_T) << " articulos alamacenados en total\n";
							cout << "\n Porfavor escriba la cantidad del producto ( " <<idArticulo<<" ) a llevar \n\x1b[31m \n Maximo 5 por producto!\n Cantidad: \x1b[0m  ";
							fflush(stdin);
							cin >> cant_prod_totales;
							cin.clear();
							if (!(cant_prod_totales <= 5 && cant_prod_totales > 0))
							{
								cout << " Porfavor escriba un valor entre 1 y 5 (NADA MAS)\n ";
								system("pause");
							}
						}while (!(cant_prod_totales <= 5 && cant_prod_totales > 0));
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, supera los 30 articulos permitidos
					if((client_node->Client_art_T+cant_prod_totales)>30) 
					{
						cout << "\n\n usted no puede meter esa cantidad de articulos porque su carrito";
						cout << "\n tiene ya: "<<(client_node->Client_art_T) <<" articulos";
						cout << "\n y su carrito solo permite 30 articulos\n\n";
						system("pause");
						goto ARTICULOS;
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, alcanza los 30 articulos permitidos 
					if((client_node->Client_art_T+cant_prod_totales)==30)
					{
						//aqui lleno todos los campos del carrito para el articulo seleccionado
						completarCamposArti(client_node,idArticulo,cant_prod_totales);
						client_node->Client_art_T = (client_node->Client_art_T + cant_prod_totales);
						cout << "\n\n Articulos agregados con exito, Su carrito ya esta lleno, dirijase a pagar su deuda\n\n";
						system("pause");
						return;
					}
					//si la suma de los articulos del cliente, mas lo que quiere agregar, alcanza los 30 articulos permitidos
					if((client_node->Client_art_T+cant_prod_totales)<30)
					{
						//aqui lleno todos los campos del carrito para el articulo seleccionado
						completarCamposArti(client_node,idArticulo,cant_prod_totales);
						client_node->Client_art_T = (client_node->Client_art_T + cant_prod_totales);
						cout << "\n\n articulos agregados con exito";
						cout << "\n\n aun puede meter en su carrito "<<((30-client_node->Client_art_T))<<" articulos mas\n\n";
					}
				}

			}
			else
			{
				cout << "\n E Codigo id del producto no existe en nuestra base de datos, porfavor lea la lista";
				cout << "\n y elija un codigo correcto \n\n\n ";
				system("pause");
				goto PEDIRARTICULOS;
			}
			// aqui terminan las validaciones y empieza la carga del nodo a la pila
			// pregunto si desea agg mas articulos
			cout << "\n\n desea agregar otro producto? SI= 1 y NO= 0 \n ";
			cout << ": ";
			fflush(stdin);
			cin.clear();
			cin >> respuesta;
			switch (respuesta) // este switch evalua el pago
			{
				case 0:
					aggArticulos = true;
					break;
				case 1:
					goto PEDIRARTICULOS;
				default:
				cout << "\n Dato invalido\n\n";
				system("pause");
				cin.clear();
				fflush(stdin);
			}
		}
	
}

void generarReporte (Nodo *& frente)
{	
	system("cls");
	cout << "Entro en la funcion";
	system("pause");
	Nodo *client_node = new Nodo();  //esto crea el espacio de memoria para el cliente
	client_node = frente;  //aqui apunto al primer cliente
	if(client_node->carrito == NULL)
	{
		cout << "Vacio";
		system("pause");
	}
	else{
	
	if (client_node->carrito != NULL)
  {
		while ((client_node != NULL) && (client_node->carrito != NULL) )
		{
			cout << "\n-------------------------------------------\n";
			cout << "\n compra del cliente # " << client_node->idCliente; //aqui me da el id del cliente
			cout << "\n\n articulo       Cantitad        Precio Total\n\n";

			Carro *node_pila = new Carro();// esto crea el espacio de memoria para el carrito del cliente
			node_pila = client_node->carrito; //aqui apunto al primer articulo del cliente
			while ((node_pila != NULL))
			{
				// imprimo los datos de la compra del cliente
				cout<<node_pila->nombreProduct<<"              ";
				cout<<node_pila->Car_Prod_T<<"              ";
				cout<< node_pila->precioProductos;
				cout<<"\n";
				node_pila = node_pila->sig; // aqui avanzo al siguente articulo
      }
			client_node = client_node->sig; // aqui avanzo al siguiente cliente
			cout << "\n-------------------------------------------\n\n"; 
    }
		cout << "\n"; 
	  system("pause");
  }
	}
}

void crearClientesCola(Nodo *&frente, Nodo *&fin )
{
	int idCLiente = 101;
	while (idCLiente < 121)
	{
		//primer paso crear espacio en memoria
		Nodo *new_node = new Nodo();
		// segundo paso llenar datos del nodo creado
		new_node->idCliente = idCLiente;
		new_node->carrito = NULL;
		new_node->sig = NULL;
		new_node->pagar = false;
		new_node->Client_art_T = 0;
    idCLiente+=1;
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

void reporteClientes(Nodo *&frente)
{
	//primer paso creo nuevo nodo y lo igualo a frente
	Nodo *new_node = new Nodo();
	new_node = frente;

	cout << "\n Listado de clientes que visitaron la tienda\n\n";

	while (new_node != NULL)
	{
		//segundo paso imprimo los datos en pantalla
		cout << " |id cliente: " << new_node->idCliente << "|\n";

		//tercer paso avanso en mi -> siguiente 
		new_node = new_node->sig;
	}

	cout << "--------------------------------------------------";
	cout << "\n";
	cout << " Total de clientes que asistieron a la tienda: ";
	cout << "20\n";
	cout << "--------------------------------------------------";
	cout << "\n Cantidad de clientes que compraron: ";
	cout << cliente_solvente;
	cout << "\n--------------------------------------------------\n\n";

	system("pause");
}

bool buscarIdProdCarrito(Nodo *&client_node, int idArticulo)
{
	Carro *aux = new Carro();
	aux = client_node->carrito;
	// si esta en el primer nodo
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

bool buscarIdProdInventario(int idArticulo )
{
	if (idArticulo==0)
	{
		return false;
	}
	for (int i = 0;i <=TAM; i++)
	{
		if (idArticulo == prod[i].id)
		{
			return true;
		}
	}
	return false;
}

void completarCamposArti(Nodo *&client_node, int idArticulo,int cant_prod_totales)
{
	Carro *aux = new Carro();
	aux->sig = client_node->carrito;
	client_node->carrito = aux;
  
	// llenamos los datos que correspponden al nodo
	switch (idArticulo)
  {
    case 1001:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[0].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[0].precio;
			client_node->carrito->precioProductos = cant_prod_totales * prod[0].precio;
			prod[0].stock = (prod[0].stock - cant_prod_totales);
			break;

    case 1002:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[1].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[1].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[1].precio;
			prod[1].stock = (prod[1].stock - cant_prod_totales);
      break;

    case 1003:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[2].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[2].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[2].precio;
			prod[2].stock = (prod[2].stock - cant_prod_totales);
      break;

    case 1004:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[3].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[3].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[3].precio;
			prod[3].stock = (prod[3].stock - cant_prod_totales);
      break;

    case 1005:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[4].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[4].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[4].precio;
			prod[4].stock = (prod[4].stock - cant_prod_totales);
      break;

    case 1006:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[5].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[5].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[5].precio;
			prod[5].stock = (prod[5].stock - cant_prod_totales);
      break;

    case 1007:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[6].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[6].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[6].precio;
			prod[6].stock = (prod[6].stock - cant_prod_totales);
      break;

    case 1008:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[7].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[7].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[7].precio;
			prod[7].stock = (prod[7].stock - cant_prod_totales);
      break;

    case 1009:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[8].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[8].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[8].precio;
			prod[8].stock = (prod[8].stock - cant_prod_totales);
      break;

    case 1010:
      client_node->carrito->idArticulo = idArticulo;
      client_node->carrito->nombreProduct= prod[9].descripcion;
      client_node->carrito->Car_Prod_T = cant_prod_totales;
			client_node->carrito->precioUnitario = prod[9].precio;
      client_node->carrito->precioProductos = cant_prod_totales * prod[9].precio;
			prod[9].stock = (prod[9].stock - cant_prod_totales);
      break;
  } 
}

void listaProductos()
{ 
	cout<<"\n-----------------------------------------------------";	
	cout<<"\n            LISTADO DE PRODUCTOS";
	cout<<"\n-----------------------------------------------------";
	cout<<"\n Codigo   Nombre                    Stock     Precio";
	cout<<"\n-----------------------------------------------------\n";
	for (int i=0; i<10; i++)
	{
		fflush(stdin);
		printf(" %*i",5, prod[i].id);
		printf("  %-15s", prod[i].descripcion);
		printf("%*i ",15, prod[i].stock);
		printf("%*.2f",10, prod[i].precio);
		cout<<"\n";
	}
}

void crearProductos() 
{	//prducto 1
	prod[0].id= 1001;
	strcpy (prod[0].descripcion, "Harina");
	prod[0].stock=20;
	prod[0].precio=30;

	//prducto 2
	prod[1].id= 1002;
	strcpy (prod[1].descripcion, "Harina de trigo");
	prod[1].stock=20;
	prod[1].precio=33;

	//prducto 3
	prod[2].id= 1003;
	strcpy (prod[2].descripcion, "Aceite");
	prod[2].stock=20;
	prod[2].precio=40;

	//prducto 4
	prod[3].id= 1004;
	strcpy (prod[3].descripcion, "Mantequilla");
	prod[3].stock=20;
	prod[3].precio=30;
	
	//prducto 5
	prod[4].id= 1005;
	strcpy (prod[4].descripcion, "Fructus");
	prod[4].stock=20;
	prod[4].precio=30;

	//prducto 6
	prod[5].id= 1006;
	strcpy (prod[5].descripcion, "Panelada");
	prod[5].stock=20;
	prod[5].precio=30;

	//prducto 7
	prod[6].id= 1007;
	strcpy (prod[6].descripcion, "Sal");
	prod[6].stock=20;
	prod[6].precio=30;

	//prducto 8
	prod[7].id= 1008;
	strcpy (prod[7].descripcion, "Azucar");
	prod[7].stock=20;
	prod[7].precio=30;

	//prducto 9		
	prod[8].id= 1009;
	strcpy (prod[8].descripcion, "Cafe");
	prod[8].stock=20;
	prod[8].precio=30;

	//prducto 10
	prod[9].id= 1010;
	strcpy (prod[9].descripcion, "Arroz");
	prod[9].stock=20;
	prod[9].precio=30;
}

void animacionPresentacion ()
{
   //ANIMACION DE CARGA
  //frame 1
  fflush(stdin);
  system("cls");
  cout << " \n Bienvenido al Programa HIPERMOD\n";
  cout << " \n NO presione ninguna tecla \x1b[31mESPERE 4 segundos...\x1b[0m\n";
  cout << "\n Cargando archivos .......";
  Sleep(1000);

  //frame 2
  system("cls");
  cout << " \n Bienvenido al Programa HIPERMOD\n";
  cout << " \n NO presione ninguna tecla \x1b[31mESPERE 3 segundos...\x1b[0m\n";
  cout << "\n Cargando archivos ..................";
  Sleep(1000);

  //frame 3
  system("cls");
  cout << " \n Bienvenido al Programa HIPERMOD\n";
  cout << " \n NO presione ninguna tecla \x1b[31mESPERE 2 segundos...\x1b[0m\n";
  cout << "\n Cargando archivos ..........................................";
  Sleep(1000);

  //frame 4
  system("cls");
  cout << " \n Bienvenido al Programa HIPERMOD\n";
  cout << " \n NO presione ninguna tecla \x1b[31mESPERE 1 segundos...\x1b[0m\n";
  cout << "\n Carga Completa";
  Sleep(1000);

  //frame 5
  system("cls");
  cout << " \n Bienvenido al Programa HIPERMOD\n";
  cout << " \n Cajero n#: \x1b[31m1A001\x1b[0m\n";
  cout <<"\n Su clave especial es : \x1b[31m"<< clave_especial<<"\x1b[0m\n";
  cout << "\n\n Anotela en un lugar seguro porfavor\n\n";
  system("pause");
  system("cls");
}

void imprimirCarrito(Nodo *&cliente)
{
  Carro *nodo_aux = new Carro();

  nodo_aux = cliente->carrito;

  if (nodo_aux != NULL)
  {
    while (nodo_aux != NULL)
    {
      cout<<"----------------------------\n";
      cout<<"|"<<nodo_aux->idArticulo<<"|\n";
      cout<<"|"<<nodo_aux->nombreProduct<<"|\n";
      cout<<"|"<<nodo_aux->precioProductos<<"|\n";
      cout<<"|"<<nodo_aux->Car_Prod_T<<"|\n";
      cout<<"----------------------------\n";
      nodo_aux = nodo_aux -> sig;
      cout<<"\n";

    }
  }

}

void pagar(Nodo *&client_node)
{
	if (client_node->carrito == NULL)
	{
		cout << "Carrito vacio";
		system("pause");
	}
	else
	{
	Carro *aux = new Carro();
	aux = client_node->carrito;

	int total = 0;
	cout << "\n---------------------------------------------------------------------------";
	cout << "\n                                HIPERMOD";
	cout << "\n                                FACTURA";
	cout << "\n---------------------------------------------------------------------------";
	cout << "\n Codigo      Nombre             Cantidad      Precio Unitario     SubTotal";
	cout << "\n---------------------------------------------------------------------------\n";
	while (aux != NULL)
	{
		fflush(stdin);
		printf(" %*i",-10, aux->idArticulo);
		printf("%-15s", aux->nombreProduct.c_str());
		printf("%*i ",15, aux->Car_Prod_T);
		printf("%*.2f",10, aux->precioUnitario);
		printf("%*.2f",10, aux->precioProductos);
		cout<<"\n";
		total = total + aux->precioProductos;
		aux = aux->sig;
	}
	cout << "\n---------------------------------------------------------------------------\n";
	cout << "\n\n                                                                Total";
	cout << "\n                                                                  "<<total;
	cout << "\n---------------------------------------------------------------------------\n\n";
	system("pause");
	ventaTotal = (ventaTotal + total);
	cliente_solvente++;
	}
}