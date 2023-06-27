#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

float a[100][100];
int i,j,n;

void vista()
{
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
			if(j==n)
			{
				cout<<"| "<<a[i][j]<<")"<<endl;
			}
		}
	}
}

main()
{	
	cout<<"Cuantas ecuaciones desea ingresar?"<<endl;
	cin>>n;
	
	cout<<endl<<"Ingresa las variables x,y,z"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"Ecuacion "<<i<<", variable "<<j<<": ";
			cin>>a[i][j];
			if(j==n)
			{
				cout<<"igualdad de la ec "<<i<<": ";
				cin>>a[i][j+1];				
			}	
		}
		cout<<endl;
	}
	
	cout<<"Matriz Generada"<<endl;
	vista();
	
	//INICIA ELIMINACION GAUSSIANA
	for(j=1;j<=n+1;j++)
	{
		cout<<"Ingreso "<<j<<endl;
		a[1][j]=a[1][j]/a[1][1];
		cout<<a[1][j]<<endl;
	}
	
	cout<<"Paso 1: Dividir entre A[1][1]"<<endl;
	vista();
	
	return 0;
	system("pause");
}
