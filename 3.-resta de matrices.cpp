#include<conio.h>
#include<stdio.h>
#include<iostream>

using namespace std;

main()
{
	int A[20][20],B[20][20],C[20][20];
	int m,n;
	int i,j;
	
	cout<<"Cuantas filas tienen las matrices?"<<endl;
	cin>>n;
	
	cout<<"Cuantas columnas tienen las matrices?"<<endl;
	cin>>m;
	
	cout<<"Ingresa los valores de la matriz A"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]=";
			cin>>A[i][j];
		}
	}
	
	cout<<endl<<"Ingresa los valores de la matriz B"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"B["<<i<<"]["<<j<<"]=";
			cin>>B[i][j];
		}
	}
	
	system("cls");
	//PROCESO DE IMPRESION DE MATRICES
	cout<<"Matriz A"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	cout<<endl<<"Matriz B"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=m;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	cout<<endl<<"Matriz Resultante C"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=m;j++)
		{
			C[i][j]=A[i][j]-B[i][j];
			cout<<C[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	
	
system("pause");	
}
