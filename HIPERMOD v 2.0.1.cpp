#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAM 10


using namespace std;
//productos
struct productos{
	int id;
	char descripcion[15];
	int stock;
	float precio;
} prod[10];

struct Carro
{
  int idArticulo;
  string nombreProducto;
  float precio; 
  int Car_Prod_T; // Variable para la cantidad de un mismo producto
  Carro *sig;
};

struct Nodo{
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
void compra(Nodo *&); //esto va a recibir es el frente y el fin de la cola
void modificarCarrito(Nodo *&);
void imprimirCarrito(Nodo *&);
void verClientesCola(Nodo *&);
void generarReporte(Nodo *&);
bool buscarIdProducto(Carro *&, int);
void animacionPresentacion();

int ciclo = 0;
int opc = 0;
int clave_especial = 2023;
    
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
	        case 1: // Entrada al menú de usuario del cliente
            //llamada a la funcion
            menucompra(frente);
		        system("pause");
		        break;

	        case 2: // Impresión del listado de productos disponibles
	          system("cls");
	          cout<<"\nPRUEBA Funcion ver lista de Productos\n\n";
            listaProductos();
            system("pause");
	          break;

	        case 3: // Reporte del sistema diario
	          system("cls");
	        	cout<<"\n\n\nPRUEBA Funcion Generar Reporte\n\n\n\n";
            generarReporte(frente);
            system("pause");
	          break;

            case 4: // Listado de clientes
	          system("cls");
	        	cout<<"\n\n\nPRUEBA Funcion Imprimir CLientes\n\n\n\n";
            verClientesCola(frente);
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
	  cout<< " (3) Generar Reporte\n";
    cout<< " (4) Ver Clientes en Cola\n";
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
                  cout << "\n\nLLAMADA A LA FUNCION COMPRA\n";
                    compra(client);
                    system("pause");
                    opc=0;
                    break;
                  case 2:
                    system("cls");
                    cout << "\n\nLLAMADA A LA FUNCION MODIFICAR\n";                   
                    modificarCarrito(client);
                    system("pause");
                    opc=0;
                  break;
                  case 3:
                    system("cls");
                    cout << "\n\nPago recibido, Muchas Grascias por su compra\n";
                    client = client->sig;
                    system("pause");
                  break;
                  case 4:
                    system("cls");
                    cout << "\n\nporfavor ingrese su calve especial\n"<< " : ";
                    int clavetemp;
                    cin >> clavetemp;
                    if (clavetemp==clave_especial)
                    {
                      return;
                    }else
                    {
                      cout << "\n SU clave es incorrecta\n";
                      Sleep(1000);
                      break;
                    }
                    break;
                    case 5: 
                    system ("cls");
                    imprimirCarrito(client);
                    system("pause");
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

        //output de control (ELIMINAR LUEGO)
          cout <<"\n aqui saliste del while que genera los clientes ";
              Sleep(1000);
  
     }
     //output de control (ELIMINAR LUEGO)
      cout <<"\n aqui saliste dela funcion menu compra ";
       Sleep(1000);

}

//generar e imprimir carritos
void compra (Nodo *&cliente){
    int idArticulo; // Variable utilizada para verificar si el articulo existe dentro de la pila del carrito
    int cant_prod_totales;
    //bool band=false;)
    Nodo *client_node = new Nodo(); // esto crea el espacio de memoria para el cliente
		client_node = cliente;	// aqui apunto al primer cliente
    if (client_node->carrito==NULL)
    {
      int respuesta = 0;
      
        while ((client_node->pagar == false))
        {	
            Carro *node_pila = new Carro();  //esto crea el espacio de memoria para el carrito del cliente    

            //pido los articulos del carrito
            system("cls");
            cout << "\n Cliente # " << client_node->idCliente<<"\n";
            //llamada la funcion lista productos

            listaProductos();
            cout << "\n porfavor ingrese el id del producto a meter en carrito\n"
                << " :\n";
            fflush(stdin);
            cin>>idArticulo;
            cin.clear();
            
      
          // ESTA VALIDACION ASUN TIENE FALLOS POR ESO SE DESACTIVO
          // validacion Encuentra el codigo producto y valida que el codigo exista
          
          /*  for (int j = 0; j < TAM; j++)
            {
                fflush(stdin);
                cin.clear();

                if (idArticulo == prod[j].id)
                {
                      band = true;
                      fflush(stdin);
                    cin.clear();
                      goto VALI1;
                    }
                

                if ((idArticulo != prod[j].id) && (band == false))
                {
                  cout<<"\nEste producto no existe, elija uno de la lista!\n";
                  cin.clear();
                  system("pause");
                  goto AGGPRODUCTO;
            
                } 
          }*/
            //VALI1:

            // estas variables son para recorrer la busqueda en caso de id articulos repetidos
            Carro *aux = new Carro();
            aux = client_node->carrito;
          
            //aqui empiezan las validaciones y llenado de datos segun lo cumplido
            
            if(buscarIdProducto(aux, idArticulo)==true)
            {
              system("cls");
              cout << "\n\n este articulo ya esta agregado a su carrito, no puede tener mas de dos tipos de productos en el carrito";
              cout << "\n si desea modificar la cantidad del producto que elegio vaya a la opcion modificar";
              cout << "\n elimine el producto que desea modificar y luego insertelo nuevamente con las cantidades correctas\n";
              system("pause");
              continue;
            }else
            {
              if(client_node->Client_art_T==30)
              {
                cout << "\n\n su carrito esta lleno no puede agregar mas productos porfavor pague su deuda";
              } 
              else
              {
                if(client_node->Client_art_T<30)
                {
                  //asigno el id del producto al carrito
                  node_pila->idArticulo = idArticulo;

                  //pido la cantidad del producto
                  do
                    {
                      ARTICULOS:
                        system("cls");
                        cout << "\n su carrito tiene ya: " << (client_node->Client_art_T) << " articulos alamacenados en total\n";
                        cout << "\n Porfavor escriba la cantidad del producto ( " <<node_pila->idArticulo<<" ) a llevar \n\x1b[31m \nMaximo 5 por producto!\n Cantidad: \x1b[0m  ";
                        fflush(stdin);
                        cin >> cant_prod_totales;
                        cin.clear();
                        if (!(cant_prod_totales <= 5 && cant_prod_totales > 0))
                        {
                          cout << "Porfavor escriba un valor entre 1 y 5 (NADA MAS)\n";
                          system("pause");
                        }
                    } while (!(cant_prod_totales <= 5 && cant_prod_totales > 0));
                    
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
                      client_node->Client_art_T = (client_node->Client_art_T + node_pila->Car_Prod_T);

                      system("pause");
                    }else
                    {
                      if((client_node->Client_art_T+cant_prod_totales)<30)
                      {
                        cout << "\n\n articulos agregados con exito";

                        node_pila->Car_Prod_T = cant_prod_totales;
                        client_node->Client_art_T = (client_node->Client_art_T + node_pila->Car_Prod_T);

                        cout << "\n\n aun puede meter en su carrito "<<((30-client_node->Client_art_T))<<" articulos mas\n\n";
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
            
            cout << "\n\n desea agregar otro producto? SI= 1 y NO= 0 \n ";
            cout << ": ";
            fflush(stdin);
            cin.clear();
            cin >> respuesta;
            
            switch (respuesta) // este switch evalua el pago
              {
                case 0:
                    client_node->pagar = true;
                    break;
                case 1:
                    continue;
                default:
                    cout << "dato invalido";
                    fflush(stdin);
              }
        
        system("pause");
      }
  }
    else
    {
    system("cls");
    cout<<"\n Su carrito ya contiene articulos valla a la opcion modificar\n";
    Sleep (1000);
    }
}

void modificarCarrito(Nodo *&cliente)
{

  Carro *pila_aux = NULL;

  Nodo *client_node = new Nodo();
  client_node = cliente;
 
  Carro *pila = new Carro();
  pila = client_node->carrito;

  int idArticulo = 0;
  cout<<"Ingrese el codigo del producto que desea eliminar: ";
  cin>>idArticulo;

  // Eliminar objetivo si es primer nodo

  if (pila->idArticulo == idArticulo)
  {
    Carro *aux = new Carro();
    aux = pila;
    pila = pila->sig;
    delete aux;
    cout<<"\nDato eliminado correctamente\n";
    system("pause");
  }
  else
  {
    // busqueda y respaldo de datos
    while (pila->idArticulo != idArticulo)
    {
      Carro *aux = new Carro();
      Carro *aux2 = new Carro();
      aux = pila;
      aux2->idArticulo = aux->idArticulo;
      aux2->nombreProducto = aux->nombreProducto;
      aux2->precio = aux->precio;
      aux2->Car_Prod_T = aux->Car_Prod_T;
      aux2->sig = pila_aux;
      pila_aux = aux2;
      pila = pila->sig;
      delete aux;
    }

    // eliminar objetivo

    Carro *aux = new Carro();
    aux = pila;
    pila = pila->sig;
    delete aux;

    cout<<"\nDato eliminado correctamente\n";
    system("pause");

    // restaurar pila

    while (pila_aux != NULL)
    {
      Carro *aux = new Carro();
      Carro *aux2 = new Carro();
      aux = pila_aux;
      aux2->idArticulo = aux->idArticulo;
      aux2->nombreProducto = aux->nombreProducto;
      aux2->precio = aux->precio;
      aux2->Car_Prod_T = aux->Car_Prod_T;
      aux2->sig = pila;
      pila = aux2;
      pila_aux = pila_aux->sig;
      delete aux;
    }

    cout<<"\nPila transportada correctamente\n";
    system("pause");

  }

}

void generarReporte (Nodo *& frente){	
	system("cls");
	Nodo *client_node = new Nodo();  //esto crea el espacio de memoria para el cliente
	client_node = frente;  //aqui apunto al primer cliente
	if (client_node->carrito != NULL)
  {
    while (client_node != NULL)
    {		
      cout << "\n-------------------------------------------\n";
      cout << "\n compra del cliente # " << client_node->idCliente; //aqui me da el id del cliente
      cout << "\n\n articulo       precio        cantidad\n\n";
      Carro *node_pila = new Carro();// esto crea el espacio de memoria para el carrito del cliente
      node_pila = client_node->carrito; //aqui apunto al primer articulo del cliente
      while ((node_pila != NULL))
      {
              // imprimo los datos de la compra del cliente

              cout <<" "<<node_pila->idArticulo <<"            30Bs            "<<node_pila->Car_Prod_T<<"\n";

              node_pila = node_pila->sig; // aqui avanzo al siguente articulo
      }
        client_node = client_node->sig; // aqui avanzo al siguiente cliente
        cout << "\\n-------------------------------------------\n";
        
    }
	  system("pause");
  }
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

void listaProductos()
{ cout<<"\n-----------------------------------------------------";
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
	cout<<"\n";
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
  cout << "\n Cargando archivos ..................\n";
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
  cout << "\n Carga Completa\n";
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
      cout<<"|"<<nodo_aux->nombreProducto<<"|\n";
      cout<<"|"<<nodo_aux->precio<<"|\n";
      cout<<"|"<<nodo_aux->Car_Prod_T<<"|\n";
      cout<<"----------------------------\n";
      nodo_aux = nodo_aux -> sig;
      cout<<"\n";

    }
  }

}