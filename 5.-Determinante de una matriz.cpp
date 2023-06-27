#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

main()
{
	double A[20][20];
	float det;
	int m,n;
	int i,j,k,l;
	
	cout<<"El determinante de una matriz se calcula SOLO para matrices cuadradas"<<endl;
	cout<<"De que dimension es tu matriz?"<<endl;
	cin>>n;
	
	m=n-1;
	cout<<"Ingresa los valores de la matriz A"<<endl;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]=";
			cin>>A[i][j];
		}
	}
		
	system("cls");
	//PROCESO DE IMPRESION DE MATRIZ
	cout<<"Matriz A"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	det=A[1][1];
	for(k=1;k<=m;k++)
	{
		l=k+1;
		for(i=l;i<=n;i++)
		{
			for(j=l;j<=n;j++)
			{
				A[i][j]=(A[k][k]*A[i][j]-A[k][j]*A[i][k])/A[k][k];
			}
		}
		det=det*A[k+1][k+1];
	}
	cout<<endl<<"Determinante: "<<det<<endl;

return 0;
system("pause");	
}
