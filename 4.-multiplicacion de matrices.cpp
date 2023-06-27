#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

main()
{
	double A[20][20],B[20][20],C[20][20],M[20][20];
	int m,n,o;
	int i,j,k;
	
	cout<<"Filas de matriz A?"<<endl;
	cin>>m;
	
	cout<<"columnas de matriz A y filas de matriz B"<<endl;
	cin>>n;
	
	cout<<"Columnas de matriz B"<<endl;
	cin>>o;
	
	cout<<"Ingresa los valores de la matriz A"<<endl;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]=";
			cin>>A[i][j];
		}
	}
	
	cout<<endl<<"Ingresa los valores de la matriz B"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=o;j++)
		{
			cout<<"B["<<i<<"]["<<j<<"]=";
			cin>>B[i][j];
		}
	}
	
	system("cls");
	//PROCESO DE IMPRESION DE MATRICES
	cout<<"Matriz A"<<endl;
	for(i=1;i<=m;i++)
	{
		cout<<"(";
		for(j=1;j<=n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	cout<<endl<<"Matriz B"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"(";
		for(j=1;j<=o;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<"\b)"<<endl;
	}
	
	cout<<endl<<"Matriz Resultante C"<<endl;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=o;j++)
		{
			C[i][j]=0;
			for(k=1;k<=n;k++)
			{
				fflush(stdin);
				fflush(stdout);
				if(A[i][k]==0||B[k][j]==0)
				{
					C[i][j]=C[i][j];
				}
				
				else
				{
					C[i][j]=C[i][j]+A[i][k]*B[k][j];
				}
				cout<<"C="<<A[i][k]<<"*"<<B[k][j]<<"="<<C[i][j]<<endl;	
			}
			cout<<endl;
		}
	}
	
	//IMPRESION DE LA MATRIZ RESULTANTE C
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=o;j++)
		{
			cout<<"C["<<i<<"]["<<j<<"]="<<C[i][j]<<endl;
		}
	}
return 0;
system("pause");	
}
