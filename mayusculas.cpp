#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

struct conversor
{
    string texto;
};

main()
{
    conversor var;
    int i;
    
    cout<<"Ingresa una palabra"<<endl;
    cin>>var.texto;
    
    if(var.texto>="A"&&var.texto<="Z")
    {
      cout<<"El texto: "<<var.texto<<" ya esta en mayusculas"<<endl;
    } 
      
    else
    {
        i=0;
        
        while(var.texto[i]!='\0')//mauro\0
        {
          if(var.texto[i]>='a'&&var.texto[i]<='z')//m (a-z)? si
          {
            var.texto[i]=var.texto[i]-32;//M A
          }  
          i++;                           
        }
    cout<<"Tu palabra es: "<<var.texto<<endl;
    }
    
    system("pause");
    return 0;
}

/*
PARTES MAS ESENCIALES
-CALCULOS
-BUCLES
-CONDICIONALES
-RETORNOS
-VARIABLES DE USUARIO
-GUARDAR COMO "ARCHIVO.h"
*/
