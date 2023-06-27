#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

double f(double t, double y,double h)
{
	double f[3],Y;

	f[0]=(0.7*y-pow(t,2)+1);
	f[1]=(-2*t+0.7*f[0]);
	f[2]=(-2-2*0.7*t+pow(0.7,2)*f[0]);
	f[3]=(-2*0.7-2*pow(0.7,2)*t+pow(0.7,3)*f[0]);
	
	cout<<f[0]<<endl;
	cout<<f[1]<<endl;
	cout<<f[2]<<endl;
	cout<<f[3]<<endl;
	cout<<y<<endl;
	cout<<t<<endl;
	cout<<h<<endl;
	
	
	Y=y+h*(f[0]+(h/2)*f[1]+(pow(h,2)/6)*f[2]+(pow(h,3)/24)*f[3]);
	return Y;
}

main()
{
	int m=3;
	double a,b,h;
	double y[100],t[100];
	int i,n;
	
	cout<<"Metodo de Taylor de orden m"<<endl;
	cout<<"a= ";
	cin>>a;
	
	cout<<"b= ";
	cin>>b;
	
	cout<<"n= ";
	cin>>n;
	
	h=(b-a)/n;
	t[0]=a;
	y[0]=a;

	cout<<"\n\ti\tt0\ty0"<<endl;
	cout<<"\t0\t"<<t[0]<<"\t"<<y[0]<<endl;
	
	for(i=1;i<=2;i++)
	{
		cout<<endl<<endl<<"Vuelta "<<i<<endl;
		y[i]=f(t[i-1],y[i-1],h);
		t[i]=a+i*h;
		y[i-1]=y[i];
		cout<<"\t"<<i<<"\t"<<t[i]<<"\t"<<y[i-1]<<endl;
	}
	
	system("pause");
	return 0;
}
