#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

double f(double x)
{
	return (sqrt(x+6));
}

main()
{
	int i,n,ban=0;
	double pt,p0,p1,p2,tol,aux;
	
	cout<<"Escribe los datos"<<endl;
	cout<<"P0=";
	cin>>p0;
	
	cout<<"\nTol=";
	cin>>tol;
	
	cout<<"\nCiclos=";
	cin>>n;
	
	cout<<"\tCiclo\tRaiz\tError"<<endl;
	for(i=1;i<=n;i++)
	{
		aux=p0;
		p1=f(p0);
		p2=f(p1);
		pt=p0-(pow((p1-p2),2)/(p2-2*p1+p0));
		
		cout<<"\t"<<i<<"\t"<<pt<<"\t"<<fabs(pt-p0)<<endl;
		if(fabs(pt-p0)<=tol)
		{
			cout<<"Raiz encontrada en "<<pt<<endl;
			ban=1;
			break;
		}
		
		else
		{
			p0=pt;
		}
	}
	
	if(ban==0)
	{
		cout<<"El metodo no encontro raices con los datos especificados"<<endl;
	}
	system("pause");
	return 0;
}
