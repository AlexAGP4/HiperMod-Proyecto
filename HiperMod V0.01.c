#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes
#define TAM 10
#define TAMCAR 30
#define CLIENT 10

//definicion de estructuras globales
struct productos{

	char id[5];
	char descripcion[20];
	int stock;
	float precio;

}prod[TAM], carrito[TAMCAR];

struct personas{

	char nombre[10];
	struct productos carrito[TAMCAR];

}clientes[CLIENT];


//declaracion de Funciones
void menu();
void crearProductos();


//variables globales
int opc=0;

/*------------------------------------------
			funcion Principal
--------------------------------------------*/
int main()
{
	crearProductos();
	menu();		
	return 0;
}

//declaracion de funciones

//FUNCION MENU
void menu()
{
	do 
	{
		system("cls");
		printf("\x1b[31m-------------------------------------\n");
		printf( "-------------------------------------\n");
	  printf( "	       \x1b[0mHiperMod\n");
	  printf( "\x1b[31m-------------------------------------\n");
	  printf( "-------------------------------------\x1b[0m\n\n");
	  printf( " (1) Realizar Compra\n");
	  printf( " (2) ver lista de Productos\n");
	  printf( " (3) Generar Reporte\n");
	  printf( " (4) Salir\n\n");
	  printf( "\x1b[31m-------------------------------------\n");
	  printf( "-------------------------------------\x1b[0m\n\n");
	  printf( " \n Introduzca su opcion: ");
		fflush(stdin);
		scanf ("%d",&opc);
		printf ("\nUsted Selecciono el numero: %d\n\n",opc);

		switch (opc)
	    {
	        case 1:
		        system("cls");
		        printf("\n\n PRUEBA Funcion Compra\n\n\n\n");
		        system("pause");
		        opc=0;
		        break;
	        case 2:
	            system("cls");
	            printf("\nPRUEBA Funcion ver lista de Productos\n\n");
	            printf("\n id    Nombre                    Stock     Precio");
	            printf("\n-------------------------------------------------\n");
	            for (int i=0; i<TAM; i++)
				{
					printf    	("%5s", prod[i].id);
					printf("  %-15s", prod[i].descripcion);
					printf("%*i ",15, prod[i].stock);
					printf("%*.2f",10, prod[i].precio);
					printf("\n");
				}
				printf("\n\n");
	            system("pause");
	            opc=0;
	            break;
	        case 3:
	           	system("cls");
	        	printf("\n\n\nPRUEBA Funcion Generar Reporte\n\n\n\n");
	        	system("pause");
	        	opc=0;
	            break;
	        case 4:
				exit (-1);
				break;
	        default:
	           	system("cls");
	           	printf(" \n\n \x1b[31mDATO INVALIDO!\n\n Porfavor introduzca un digito entre el 1 y 4\x1b[0m\n\n\n\n\n");
	          	system("pause");
	           	opc=0;    
	    }
	        
	}while (opc==0);
}

// FUNCION PRODUCTOS
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

void cargarClientes 
{
	strcpy(clientes[0].nombre, "Cliente 1")
	
}