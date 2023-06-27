#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>//gets y getline
#include<string.h>
#define texto "No se ha encontrado el nombre citado"

using namespace std;

main ()
{
  string nombre[100];
  string nombre2;
  char aux[40];
  int n,i,j,ban=0;
  
  cout<<"Cuantos registros desea realizar?"<<endl;
  cin>>n;
  
  for(i=0;i<n;i++)
  {
  	cout<<"Nombre "<<i+1<<": ";
  	fflush(stdin);
  	getline(cin,nombre[i]);	  
  }
  
  cout<<"Que nombre esta buscando?"<<endl;
  fflush(stdin);
  getline(cin,nombre2);
  
  for(i=0;i<n;i++)
  {
  	if(nombre[i]==nombre2)
  	{
  	   strcpy(aux,nombre[i].c_str());
	   j=0;
	   ban=1;
		while(aux[j]!='\0')
		{
		 j++;
		}
	   cout<<aux[0]<<aux[1];
	  	j=2;
		while(aux[j]!='\0')
		{
			if(aux[j]==' ')
			{
			  cout<<" ";
			  j++;
			}
			
			else
			{
			  cout<<"*";
			  j++;	
			}
		}
		cout<<endl;		
	}
  }
  if(ban==0)
  {
  	cout<<texto<<endl;
  }
  system("pause");
}
