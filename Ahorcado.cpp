#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct juego
{
	char cabeza[30];
	char cabeza2[30];
	char cuerpo[30];
	char manos[30];
	char piernas[30];
};

monito (int x)
{
	struct juego ahorcado;
	//x=0;
	
	strcpy(ahorcado.cabeza,"  (O.O)");
	strcpy(ahorcado.cuerpo,"    l");
	strcpy(ahorcado.manos," _([.])_");
	strcpy(ahorcado.piernas,"   l l");
	strcpy(ahorcado.cabeza2,"  (X.X)");
	
	switch (x)
        {
        	case 1:
        		printf("_______\n");
        		printf("    |\n    |\n    |\n    |\n");
        		printf("    W\n");
				cout<<ahorcado.cabeza<<endl<<endl;
				printf("Esa no es la palabra, intentalo de nuevo\n");  
        	break;
        	
        	case 2:
        		printf("_______\n");
        		printf("    |\n    |\n    |\n    |\n");
        		printf("    W\n");
				cout<<ahorcado.cabeza<<endl;
				cout<<ahorcado.cuerpo<<endl<<endl;
				printf("Esa no es la palabra, intentalo de nuevo\n");  
        	break;
        	
        	case 3:
        		printf("_______\n");
        		printf("    |\n    |\n    |\n    |\n");
        		printf("    W\n");
				cout<<ahorcado.cabeza<<endl;
				cout<<ahorcado.cuerpo<<endl;
				cout<<ahorcado.manos<<endl<<endl;
				printf("Esa no es la palabra, intentalo de nuevo\n");  
        	break;
        	
        	case 4:
        		printf("_______\n");
        		printf("    |\n    |\n    |\n    |\n");
        		printf("    W\n");
				cout<<ahorcado.cabeza2<<endl;
				cout<<ahorcado.cuerpo<<endl;
				cout<<ahorcado.manos<<endl;
				cout<<ahorcado.piernas<<endl<<endl;  
				cout<<"PERDISTE, LO MATASTE"<<endl;
        	break;
		}
}

int main()
{
	int j;
	do 
	{
	struct juego ahorcado;
    int x=0;
	int i=0,opc;
    char buffer[80]; 
    char cadena[80]="SUPER"; 
	system("cls"); 
	char cadena0[80]="GAMBITO";
	char cadena1[80]="MR FANTASTICO";
	char cadena2[80]="DR STRANGE";
	char cadena3[80]="DAREDEVIL";
	char cadena4[80]="CYCLOPE"; 
	char cadena5[80]="SPIDERMAN";
	char cadena6[80]="BRUJA ESCARLATA"; 
	char cadena7[80]="WASP";  
	char cadena8[80]="JEAN GREY";
	char cadena9[80]="ELEKTRA";
	srand(time(NULL));
	
	opc=rand()%9;
	cout<<opc;
	//system ("pause");
	
	switch (opc)
	{
		case 0:
			strcpy(cadena,cadena0);
		break;
		
		case 1:
			strcpy(cadena,cadena1);
		break;
		
		case 2:
			strcpy(cadena,cadena2);
		break;
		
		case 3:
			strcpy(cadena,cadena3);
		break;
		
		case 4: 
			strcpy(cadena,cadena4);
		break;
		
		case 5:
			strcpy(cadena,cadena5);   
		break;
		
		case 6:
			strcpy(cadena,cadena6); 
		break;
		
		case 7:
			strcpy(cadena,cadena7);   
		break;
		
		case 8:
			strcpy(cadena,cadena8);  
		break;
		
		case 9:
			strcpy(cadena,cadena9);  
		break;
	}
		do                              
	    { 
	         system("cls");      
			 printf("Bienvenido al Juego del Ahorcado \n\n"); 
			 cout<<x<<endl;
			 monito (x); 
			 if (x<4)
			 {
			 	printf("Escribe el nombre de mi super heroe favorito de MARVEL: ");
			 	fflush(stdin);
			 }                                 
	         fflush(stdout);                                            
	         gets(buffer);                                             
	         x++;                      
	    }
	    while (strcmp (cadena,buffer)!=0 && x<=4);  
	    if(x<=4)                                 
	    {
	    	puts("\n\nFelicidades, GANASTE!!!");
		}   
		cout<<"EL HEROE ERA: "<<cadena<<endl;
		cout<<"DESEAS JUGAR DE NUEVO: \n1) SI \n2) NO"<<endl;
		cin>>j;
	}
	while (j==1);                
    getch(); 
    return 0;  
}  
