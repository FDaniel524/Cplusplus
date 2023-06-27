#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

main()
{
      double a[100],b[100],c[100],p,q,e,P,Q,x1,x2;
      int i,n,k;
      
      cout<<"Cuantos coeficientes"<<endl;
      cin>>n;
      
      cout<<"Valor p"<<endl;
      cin>>p;
      
      cout<<"Valor q"<<endl;
      cin>>q;
      
      cout<<"Error permitido"<<endl;
      cin>>e;
      
      cout<<"Ingrese coeficientes"<<endl<<endl;
      for(i=1;i<=n;i++)
      {
       cout<<"a["<<i<<"]=";
       cin>>a[i];
       cout<<endl;
      }
      
      cout<<endl<<"Ecuacion Ingresada:"<<endl;
      for(i=n;i>=1;i--)
      {
       cout<<a[i]<<"x^"<<i-1<<"+";
      }
      
      for(k=n;k>=1;k--)
      {
       b[n+1]=0;
       b[n+2]=0;
       b[k]=a[k]-p*b[k+1]-q*b[k+2];                
      } 
      
      for(i=n;i>=n;i--)
      {
       c[n+1]=0;
       c[n+2]=0;
       c[i]=b[i]-p*c[i+1]-q*b[i+2];
      }
      
      P=(b[1]*c[4]-b[2]*c[3])/(c[2]*c[4]-pow(c[3],2));
      Q=(b[2]*c[2]-b[1]*c[3])/(c[2]*c[4]-pow(c[3],2));
      
      if(P>e && Q>e)
      {
          p=p+P;
          q=q+Q;
          
          for(k=n;k>=1;k--)
          {
           b[k]=a[k]-p*b[k+1]-q*b[k+2];
           b[n+1]=0;
           b[n+2]=0;                
          }
          
          for(i=n;i>=n;i--)
          {
           c[i]=b[i]-p*c[i+1]-q*b[i+2];
           c[n+1]=0;
           c[n+2]=0;
          }
          
          P=(b[1]*c[4]-b[2]*c[3])/(c[2]*c[4]-pow(c[3],2));
          Q=(b[2]*c[2]-b[1]*c[3])/(c[2]*c[4]-pow(c[3],2));
      }
      
      p=p+P;
      q=q+Q;
      
      x1=(-p+sqrt(pow(p,2)-4*q))/2;
      x2=(-p-sqrt(pow(p,2)-4*q))/2;
      
      cout<<endl<<endl;
      cout<<"X1="<<x1<<endl;
      cout<<"X2="<<x2<<endl;

      system("pause");
}
