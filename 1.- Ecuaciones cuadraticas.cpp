#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<windows.h>

using namespace std;

main()
{
	double a,b,c;
	double x1,x2,raiz;
	
	//CONFIGURAMOS A ESPAÑOL EL MUESTREO DE DATOS
	setlocale(LC_CTYPE,"Spanish");
	
	cout<<"Métodos Numéricos"<<endl;
	cout<<"Algoritmo que calcula las raíces de una ecuación cuadrática"<<endl<<endl;
	
	cout<<"Ingresa el valor de tus variables"<<endl;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;
	
	
	//CONFIRMANDO QUE LA ECUACION ES CUADRATICA
	if(a!=0)
	{
		raiz=pow(b,2)-4*a*c;
	
		if(raiz<0)
		{
			cout<<"Raices Complejas"<<endl;
			raiz=sqrt(raiz*(-1));
			
			x1=-b/2;
			x2=x1;
			
			cout<<"X1="<<x1<<"+"<<raiz<<"i"<<endl;
			cout<<"X2="<<x2<<"+"<<raiz<<"i"<<endl;
		}
		
		else
		{
			x1=(-b+sqrt(raiz))/(2*a);
			x2=(-b-sqrt(raiz))/(2*a);
			
			cout<<"X1="<<x1<<endl;
			cout<<"X2="<<x2<<endl;
		}
		
	}
	
	else
	{
		cout<<"Estos valores no corresponden a una ecuación cuadrática"<<endl;
	}
	system("pause");
}

