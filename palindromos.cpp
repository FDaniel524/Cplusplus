
#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

struct palindromo
{
	string cadena;
	int dif;	
};

main()
{
	palindromo var;
	int i,j,k,l;
	i=0;
	
	cout<<"Ingrese una cadena SIN espacios"<<endl;
	cin>>var.cadena;
	
	while(var.cadena[i]!='\0')
	{
		i++;
	}
	
	j=0;
	i=i-1;
	k=0;
	while(i>=0)
	{
		cout<<var.cadena[j]<<" VS "<<var.cadena[i]<<endl;
		if(var.cadena[j]==var.cadena[i])
		{
			k=k+1;//k++		
		}
            
		i--;
		j++;		
	}
	
	if(k==j)
	{
        cout<<"Tu palabra es un palindromo"<<endl;
    }
    
    else
    {
        cout<<"Tu palabra no es palindromo"<<endl;
    }
	
 system("pause");
 return 0;
	
}
