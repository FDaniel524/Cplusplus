#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

main()
{
 //DECLARACION DE LOS TIPOS DE VARIABLES DEFINIDAS
 typedef int inventario[100];
 typedef float precio[100];
 typedef char nombre[100];
 typedef double concentracion[100];
 
 int n,i,c;
 
 //CREAMOS VARIABLES DE LOS TIPOS QUE DEFINIMOS
 inventario cantidad;		//int
 precio pesosmxn;			//float
 nombre quimico[100];		//char
 concentracion mililitros;	//double
 
 do
 {
 	 system("cls");
	 system("color 0F");
	 cout<<"Cantidad de productos a registrar: ";
	 cin>>n;
	 
	 for(i=1;i<=n;i++)
	 {
	  cout<<"Nombre del producto: ";
	  fflush(stdin);
	  gets(quimico[i]);
		 
	  cout<<"Precio: ";
	  cin>>pesosmxn[i];
	  
	  cout<<"Concentracion: ";
	  cin>>mililitros[i];
	  
	  cout<<"Cantidad disponible: ";
	  cin>>cantidad[i];
	  cout<<endl;
	 }
	 
	 system("cls");
	 system("color 5F");
	 
	 cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	 cout<<"°       GENOMA LAB DE MEXICO          °"<<endl;
	 cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	 
	 for(i=1;i<=n;i++)
	 {
	  cout<<"Nombre: "<<quimico[i]<<endl;
	  cout<<"Precio: "<<pesosmxn[i]<<" MXN"<<endl;  
	  cout<<"Concentracion: "<<mililitros[i]<<" ml/mol"<<endl;  
	  cout<<"Cantidad: "<<cantidad[i]<<endl<<endl;
	 }
	 
	 cout<<"Desea registrar mas productos? SI:1 NO:2"<<endl;
	 cin>>c;
 }while(c==1);
 return 0;	
}
