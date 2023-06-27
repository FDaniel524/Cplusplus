#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int m,n;
int pot,x;
int i,j;
double M[9][9], A[9][9], B[9][9];

int leer(int m, int n)
{
 cout<<"\n\nIngresa los datos de la matrices:"<<endl;
 for(i=1;i<=m;i++)
 {
  for(j=1;j<=n;j++)
  {
   cout<<"A["<<i<<"]["<<j<<"]= ";
   cin>>A[i][j];
   M[i][j]=0;
  }
  cout<<endl;
 }
 
 cout<<"Potencia de tu matriz: ";
 cin>>pot;
}

void potencia()
{
/*MULTIPLICACION (CUADRATURA DE M*/
 cout<<endl;
 for(i=1;i<=m;i++)//FILAS DE A
 {
  for(j=1;j<=n;j++)//COLUMNAS DE B
  {
    M[i][j]+=A[i][j]*A[j][i];
    cout<<M[i][j]<<endl;
  }
  cout<<endl;
 }
 
/*POTENCIACION DE M*/
 for(x=1;x<(pot-1);x++)
 {            
 for(i=1;i<=m;i++)//FILAS DE A
 {
  for(j=1;j<=n;j++)//COLUMNAS DE B
  {
   B[i][j]=0;
    //cout<<M[i][k]<<"*"<<A[k][j]<<" + ";
    B[i][j]+=A[i][j]*M[j][i];
  }
 }
 
 /*ASIGNACION DE VALORES A M*/
  for(i=1;i<=m;i++)
  {
   for(j=1;j<=n;j++)
   {
    M[i][j]=B[i][j];
   }
  }//FIN DE CICLO POTENCIADOR
 }

}

void impresion()
{
/*IMPRESION DE A*/
 cout<<"MATRIZ A"<<endl;
 for(i=1;i<=m;i++)
 {
 cout<<"(";
  for(j=1;j<=n;j++)
  {
   cout<<A[i][j]<<" ";
  }
  cout<<"\b)"<<endl;
 }
 
 /*IMPRESION DE M*/
 cout<<"\nMATRIZ M^"<<pot<<endl;
 for(i=1;i<=m;i++)
 {
 cout<<"(";
  for(j=1;j<=n;j++)
  {
   cout<<M[i][j]<<" ";
  }
  cout<<"\b)"<<endl;
 }
}

main()
{
      
 do
 {
  cout<<"Filas de A: ";
  cin>>m;
 
  cout<<"Columnas de A: ";
  cin>>n;
 
  if(n!=m)
  {
   cout<<"La matriz debe ser cuadrada para obtener su potencia, intenta de nuevo por favor"<<endl;
   system("pause");
   system("cls");
  }

  else
  {
   leer(m,n);
   system("cls");
  
   potencia();
   impresion();
  }
 }while(m!=n);
  
 system("pause");
 return 0;
}
