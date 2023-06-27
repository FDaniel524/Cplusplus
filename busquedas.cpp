//BUSQUEDA SECUENCIAL
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<locale.h>
#include<windows.h>

using namespace std;

main()
{
	int vector[100],i,n,ban=0,x;
	//CONFIGURAMOS A ESPAÑOL EL MUESTREO DE DATOS
	setlocale(LC_CTYPE,"Spanish");
	
	cout<<"Cuántos valores desa ingresar?"<<endl;
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cout<<"Valor "<<i<<": ";
		cin>>vector[i];
	}
	
	cout<<"Qué Número busca?"<<endl;
	cin>>x;
	
	for(i=1;i<=n;i++)
	{
		if(x==vector[i])
		{
			cout<<"Se encontró el número "<<x<<" en la posición #"<<i<<endl;
			ban=1;
		}
	}
	
	if(ban==0)
	{
		cout<<"No se encontraron coincidencias"<<endl;		
	}
	system("pause");
}
