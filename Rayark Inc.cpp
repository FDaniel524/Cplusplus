#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<locale.h>
#include<windows.h>

int i,n,res;

using namespace std;

struct RAYARK {
	char titulo[30];
	string nombre[100];
	string edad[100];
	string RFC[100];
	string sueldo[100];
};

void cabecera() {
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"°                     RAYARK INC.                            °"<<endl;
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl<<endl;
}

void crear() {
	//VARIABLES DE CONSOLA
	RAYARK var;
	int i,n;

	cout<<"Titulo del documento a crear: ";
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//CREAR UN NUEVO ARCHIVO .txt con nombre: var.nombre
	ofstream fs(var.titulo);

	printf("¿Cuántos registros desea realizar?: ");
	cin>>n;

	cout<<"\nIngresa los datos del registro"<<endl<<endl;

	for(i=1; i<=n; i++) {
		cout<<"Nombre "<<i<<": ";  //SOLICITAMOS EL DATO
		fflush(stdin);			   	 //LIMPIAMOS MEMORIA
		getline(cin,var.nombre[i]); //GUARDAMOS DATOS EN BDD
		fs<<var.nombre[i]<<"\n"; 	 //GUARDAMOS DATOS EN TXT

		cout<<"Edad: "; 			 //SOLICITAMOS EL DATO
		getline(cin,var.edad[i]);   //GUARDAMOS DATOS EN BDD
		fs<<var.edad[i]<<"\n"; 	 //GUARDAMOS DATOS EN TXT

		cout<<"RFC: ";  			 //SOLICITAMOS EL DATO
		getline(cin,var.RFC[i]); 	 //GUARDAMOS DATOS EN BDD
		fs<<var.RFC[i]<<"\n"; 		 //GUARDAMOS DATOS EN TXT

		cout<<"Sueldo: ";   		 //SOLICITAMOS EL DATO
		getline(cin,var.sueldo[i]); //GUARDAMOS DATOS EN BDD
		fs<<var.sueldo[i]; 		 //GUARDAMOS DATOS EN TXT
		if(i<n) {
			fs<<"\n";
		}
		cout<<endl;
	}
	fs.close();
	printf("Se ha creado el archivo %c",34);
	printf(var.titulo);
	printf("%c\n",34);

	system("pause");
	fs.close();
}

void leer() {
	//VARIABLES DE ARCHIVO
	ifstream archivo;

	//VARIABLES DE CONSOLA
	string texto;

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	cout<<"Que archivo desea buscar? (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);

	strcat(var.titulo,".txt");

	archivo.open(var.titulo,ios::in);//ABRIMOS EL ARCHIVO EN MODO READ

	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	i=1;
	cout<<endl;
	while(!archivo.eof()) { //mientras no sea el final del archivo fstream
		getline(archivo,texto);//copio lo del archivo a texto
		cout<<texto<<endl;
		i++;
		if(i==5) {
			i=1;
			cout<<endl;
		}
	}
	archivo.close();//SE CIERRA EL ARCHIVO
	system("pause");
}

void actualizar() {
//VARIABLES DE ARCHIVO
	ifstream archivo;
	ofstream temp;

	//VARIABLES DE CONSOLA
	string texto;
	string editar;

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//ABRIMOS EL ARCHIVO ORIGINAL EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	//SOLICITAMOS EL REGISTRO PARA ELIMINAR
	cout<<"Que registro desea modificar? :";
	fflush(stdin);
	getline(cin,editar);

	//CREAMOS Y ABRIMOS EL ARCHIVO TEMPORAL
	temp.open("temp.txt");

	i=0;
	//CICLO DE LECTURA DE TXT
	while(!archivo.eof()) {
		getline(archivo,texto);//RECUPERA LINEAS
		if(texto==editar&&i==0) {
			system("cls");
			cabecera();
			cout<<"Es esta la persona que buscas?\n1.-SI\n2.-NO"<<endl<<endl;
			cout<<"Nombre: "<<texto<<endl;
			var.nombre[1]=texto;

			getline(archivo,texto);//RECUPERA LINEAS
			cout<<"Edad: "<<texto<<endl;
			var.edad[1]=texto;

			getline(archivo,texto);//RECUPERA LINEAS
			cout<<"RFC: "<<texto<<endl;
			var.RFC[1]=texto;

			getline(archivo,texto);//RECUPERA LINEAS
			cout<<"Sueldo: "<<texto<<endl;
			var.sueldo[1]=texto;
			cin>>res;

			if(res==1) {
				cout<<"Ingresa el nuevo nombre"<<endl;
				fflush(stdin);
				getline(cin,texto);
				temp<<texto<<"\n";

				cout<<"\nIngresa la edad"<<endl;
				getline(cin,texto);//RECUPERA LA EDAD
				temp<<texto<<"\n";

				cout<<"\nIngresa el RFC"<<endl;
				getline(cin,texto);//RECUPERA RFC
				temp<<texto<<"\n";

				cout<<"\nIngresa el sueldo"<<endl;
				getline(cin,texto);//RECUPERA SUELDO
				temp<<texto;
				if(!archivo.eof()) { //VERIFICAR SALTO DE LINEA
					temp<<"\n";
				}

				i=1;
				cout<<"Se ha editado la informacion solicitada"<<endl;
				system("pause");
			}

			else {
				temp<<var.nombre[1]<<"\n";
				temp<<var.edad[1]<<"\n";
				temp<<var.RFC[1]<<"\n";
				temp<<var.sueldo[1];
				if(!archivo.eof()) { //VERIFICA RSALTO DE LINEA
					temp<<"\n";
				}
			}

		}

		else {
			temp<<texto;
			if(!archivo.eof()) { //VERIFICAR SI TERMINO EL DOC PARA ULTIMO ENTER
				temp<<"\n";
			}
		}
	}

	archivo.close();//SE CIERRA EL ARCHIVO ORIGINAL
	temp.close();//SE CIERRA EL ARCHIVO TEMPORAL

	remove(var.titulo);//ELIMINAMOS EL ARCHIVO ORIGINAL
	rename("temp.txt",var.titulo);//RENOMBRAMOS EL TEMPORAL COMO EL ORIGINAL
}

void borrar() {
//VARIABLES DE ARCHIVO
	ifstream archivo;
	ofstream temp;

	//VARIABLES DE CONSOLA
	string texto;
	string buscador;

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//ABRIMOS EL ARCHIVO ORIGINAL EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	//SOLICITAMOS EL REGISTRO PARA ELIMINAR
	cout<<"Que registro desea eliminar? :";
	fflush(stdin);
	getline(cin,buscador);

	//CREAMOS Y ABRIMOS EL ARCHIVO TEMPORAL
	temp.open("temp.txt");

	//INICIAMOS CON LA LECTURA DEL ARCHIVO ORIGINAL
	while(!archivo.eof()) {
		getline(archivo,texto);//RECUPERA LINEAS
		if(texto==buscador) {
			getline(archivo,texto);//RECUPERA LA EDAD
			getline(archivo,texto);//RECUPERA RFC
			getline(archivo,texto);//RECUPERA SUELDO

			cout<<"Se ha eliminado tu registro"<<endl;
		}

		else {
			temp<<texto;
			if(!archivo.eof()) { //VERIFICAR SALTO DE LINEA
				temp<<"\n";
			}
		}
	}

	archivo.close();//SE CIERRA EL ARCHIVO ORIGINAL
	temp.close();//SE CIERRA EL ARCHIVO TEMPORAL

	remove(var.titulo);//ELIMINAMOS EL ARCHIVO ORIGINAL
	rename("temp.txt",var.titulo);//RENOMBRAMOS EL TEMPORAL COMO EL ORIGINAL
	system("pause");

}

void buscar() {
//VARIABLES DE ARCHIVO
	ifstream archivo;

	//VARIABLES DE CONSOLA
	string texto;
	string buscador;

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//SOLICITAMOS EL REGISTRO PARA ELIMINAR
	cout<<"Que registro busca? :";
	fflush(stdin);
	getline(cin,buscador);

	//ABRIMOS EL ARCHIVO ORIGINAL EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	//INICIAMOS CON LA LECTURA DEL ARCHIVO ORIGINAL
	while(!archivo.eof()) {
		getline(archivo,texto);//RECUPERA LINEAS
		if(strcmpi(texto.c_str(),buscador.c_str())==0) {
			cout<<"Nombre: "<<texto<<endl;

			getline(archivo,texto);//RECUPERA LA EDAD
			cout<<"Edad: "<<texto<<endl;

			getline(archivo,texto);//RECUPERA RFC
			cout<<"RFC: "<<texto<<endl;

			getline(archivo,texto);//RECUPERA SUELDO
			cout<<"Sueldo: "<<texto<<endl;
		}
	}

	archivo.close();//SE CIERRA EL ARCHIVO ORIGINAL
	system("pause");
}

void renombrar() {
//VARIABLES DE ARCHIVO
	ifstream archivo;
	ofstream temp;

	//VARIABLES DE CONSOLA
	string texto;
	char nombre[25];

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//SOLICITAMOS EL REGISTRO PARA ELIMINAR
	cout<<"Nuevo nombre: ";
	fflush(stdin);
	gets(nombre);

	//ABRIMOS EL ARCHIVO ORIGINAL EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	archivo.close();

	rename(var.titulo,nombre);//RENOMBRAMOS EL TEMPORAL COMO EL ORIGINAL
	system("pause");
}

void agregar() {
//VARIABLES DE ARCHIVO
	ofstream temp;
	ifstream archivo;

	//VARIABLES DE CONSOLA
	string texto;
	string buscador;

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//ABRIMOS EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	printf("¿Cuántos registros desea realizar?: ");
	cin>>n;

	cout<<"\nIngresa los datos del registro"<<endl<<endl;
	temp.open("temp.txt");

	while(!archivo.eof()) {
		getline(archivo,texto);
		temp<<texto<<"\n";
	}

	for(i=1; i<=n; i++) {
		cout<<"Nombre "<<i<<": ";  //SOLICITAMOS EL DATO
		fflush(stdin);			   	 //LIMPIAMOS MEMORIA
		getline(cin,var.nombre[i]); //GUARDAMOS DATOS EN BDD
		temp<<var.nombre[i]<<"\n";  //GUARDAMOS DATOS EN TXT

		cout<<"Edad: "; 			 //SOLICITAMOS EL DATO
		getline(cin,var.edad[i]);   //GUARDAMOS DATOS EN BDD
		temp<<var.edad[i]<<"\n"; 	 //GUARDAMOS DATOS EN TXT

		cout<<"RFC: ";  			 //SOLICITAMOS EL DATO
		getline(cin,var.RFC[i]); 	 //GUARDAMOS DATOS EN BDD
		temp<<var.RFC[i]<<"\n"; 		 //GUARDAMOS DATOS EN TXT

		cout<<"Sueldo: ";   		 //SOLICITAMOS EL DATO
		getline(cin,var.sueldo[i]); //GUARDAMOS DATOS EN BDD
		temp<<var.sueldo[i];      //GUARDAMOS DATOS EN TXT
		if(i<n) {
			temp<<"\n";
		}
		cout<<endl;
	}
	cout<<"Los datos se han ingresado a la BDD sin complicaciones"<<endl;

	archivo.close();//SE CIERRA EL ARCHIVO ORIGINAL
	temp.close();//SE CIERRA EL ARCHIVO TEMPORAL

	remove(var.titulo);//ELIMINAMOS EL ARCHIVO ORIGINAL
	rename("temp.txt",var.titulo);//RENOMBRAMOS EL TEMPORAL COMO EL ORIGINAL
	;
}

void copiar() {
//VARIABLES DE ARCHIVO
	ifstream archivo;
	ofstream nuevo;

	//VARIABLES DE CONSOLA
	string texto;
	char copia[25];

	//VARIABLES DE ESTRUCTURA
	RAYARK var;

	//SOLICITAMOS EL TITULO DE TXT A BUSCAR
	cout<<"Escriba el titulo del documento (no incluir la extension)"<<endl;
	fflush(stdin);
	gets(var.titulo);
	strcat(var.titulo,".txt");

	//TITULO DE LA COPIA
	cout<<"Titulo de la copia"<<endl;
	fflush(stdin);
	gets(copia);
	strcat(copia,".txt");

	//ABRIMOS EL ARCHIVO ORIGINAL EN MODO READ
	archivo.open(var.titulo,ios::in);

	//VERIFICAMOS QUE SE HAYA ABIERTO EL ARCHIVO
	if(archivo.fail()==true) {
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	//CREAMOS Y ABRIMOS EL ARCHIVO TEMPORAL
	nuevo.open(copia);

	//INICIAMOS CON LA LECTURA DEL ARCHIVO ORIGINAL
	while(!archivo.eof()) {
		getline(archivo,texto);//RECUPERA LINEAS
		nuevo<<texto<<"\n";

	}

	archivo.close();//SE CIERRA EL ARCHIVO ORIGINAL
	nuevo.close();//SE CIERRA EL ARCHIVO TEMPORAL

	system("pause");
}

void cerrar() {
	exit (1);
}

main() {
//VARIABLES DE STRUCT
	RAYARK var;

//VARIABLES DE CONSOLA
	int res;

	do {
		system("cls");
		cabecera();
		printf("Por favor, elija una opci%cn",162);

		cout<<endl<<"1.-Crear un nuevo archivo"<<endl;
		cout<<"2.-Lectura general de datos"<<endl;
		printf("3.-Actualizaci%cn de datos\n",162);
		cout<<"4.-Eliminar un registro"<<endl;
		printf("5.-Busqueda espec%cfica\n",161);
		cout<<"6.-Renombrar un archivo de texto"<<endl;
		printf("7.-A%cadir registro en archivo existente\n",164);
		cout<<"8.-Copiar un archivo"<<endl;
		cout<<"9.-Cerrar programa"<<endl<<endl;

		cin>>res;

		//CONFIGURAMOS A ESPAÑOL EL MUESTREO DE DATOS
		setlocale(LC_CTYPE,"Spanish");
		
		system("cls");
		cabecera();
		switch(res) {
			case 1:
				crear();		//C
				break;

			case 2:
				leer();			//R
				break;

			case 3:
				actualizar();	//U
				break;

			case 4:
				borrar();		//D
				break;

			case 5:
				buscar();
				break;

			case 6:
				renombrar();
				break;

			case 7:
				agregar();
				break;

			case 8:
				copiar();
				break;

			case 9:
				cerrar();
				break;

			default:
				cout<<"Opcion no valida"<<endl;
				system("pause");
		}

	} while(1);

	system("pause");
	return 0;
}
