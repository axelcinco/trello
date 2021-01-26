
#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<direct.h>
using namespace std ;
string ruta,nombre,pasword,user;
int opc=0;
char archiv_us[20];
FILE *documento;
string temporal;
string ruta2;

void login();
void registro_usuar();
void ingresar_usuario();
void menu_opciones();
void crear_tarea();
void mirar_tarea();
void eliminar_tarea();


int main()
{
	login();
	return 0;
}

  void registro_usuar()
  {
  	ofstream archiv;
  	system("cls");
  	
  	cout<<"\t digite su usuario: ";cin>>nombre;
  	cout<<"\t digite su password ";cin>>pasword;
  	
  	strcpy(archiv_us,nombre.c_str());
  	if(mkdir(nombre.c_str())==0)
  	{
  	  
  	  temporal=nombre;
  	  nombre=nombre + ".txt";
  	  archiv.open(nombre.c_str(),ios::app); //abrimos el archivo
  	  archiv<<pasword<<endl;
  	  archiv.close();// cerramos el archivo
  	  
  	  cout<<"registro de usuarios exitoso "<<endl;
  	  documento=fopen(temporal.c_str(),"w");
  }
  	  else
  	  {
  	  	  cout<<" el usuario ya esta registrado "<<endl;
  	  	  login();
  	  	  
	  }
  	  
  	   login();
  	  
  	  
	  }
  	
  
   void ingresar_usuario()
   {
    ofstream archiv;
	ifstream fichero;
	string usuario;
	getline(cin, usuario);
	cout<<" digite su usuario "; 
	getline(cin, nombre  );
	cout << " digite su password : ";
	getline(cin, pasword);
	usuario=nombre + ".txt";
	fichero.open(usuario.c_str(),ios::in);
	if(fichero.fail()){
		cout<<" el usuario no se encontro";
		system("pause");

		login();
	}
	else{
		string linea;
		getline(fichero, ruta);
		if(pasword!=ruta){
			cout<<" la contraseña es incorrecta "<<endl;
		
			login();
		}
		ruta2=nombre;
		menu_opciones();
	}
   	  
   	
   }

void login()
{
	 system ("cls");
	cout<<"******* bienvenido a su administrador de tareas ********* "<<endl;
	cout<<" digite 1.- para registrarse "<<endl;
	cout<<" digite 2.-  para ingresra al menu "<<endl;
	cout<<" digite 3.- para salir "<<endl;
	cout<<"digite la opcion que desea: ";cin>>opc;
	switch(opc)
	{
		case 1: 
		       registro_usuar();
		       break;
		       
		case 2: 
		     ingresar_usuario();
		    break;
		    
		case 3:
			break;
			break;
		
		
		
	}
	
}

void menu_opciones()
{
	 system("cls");
	 
	 do
	 {
	cout<<" menu de opciones que se pueden realizar "<<endl;
	cout<<" digite 1.- agregar una nueva tarea: "<<endl;
	cout<<" digite 2.- para eliminar tareas: "<<endl;
	cout<<" digite 3.- para mirar tareas que tengo: "<<endl;
	cout<<"  digite 4.- para salir  "<<endl;
	cout<<" digite la opcion que desea ";cin>>opc;
	  switch(opc)
	  {
	  	case 1: 
	  	      crear_tarea();
	  	      break;
	  	  case 2:
	  	  	eliminar_tarea();
	  	  	break;
	  	case 3:
	  		mirar_tarea();
	  		break;
	  		
	  	case 4:
	  	
	  	   login();
	  	   break;
	  	
	  }
	 }while(opc!=4);
}

void crear_tarea()
{
	
}

void eliminar_tarea()
{
	
}

void mirar_tarea()
{
	
}



