
#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<direct.h>
using namespace std ;
string ruta,nombre,pasword,user;
int opc=0;
char archiv_us[20],docu[20];
FILE *documento;
string temporal;
string ruta2;
string ruta_tarea,tarea,usuario,ruta_tarea2;


void login();
void registro_usuar();
void ingresar_usuario();
void menu_opciones();
void crear_tarea();
void mirar_tarea();
void eliminar_tarea();
void crear_lita();


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
  	  documento=fopen(temporal.c_str(),"a");
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
   	
   	 system("cls");
    ofstream archiv;
	ifstream fichero;


	cout<<" digite su usuario ";cin>>nombre;

	cout << " digite su password : ";cin>>pasword;
	
	usuario=nombre + ".txt";
	fichero.open(usuario.c_str(),ios::in);
	if(fichero.fail())
	{
		cout<<" el usuario no se encontro"<<endl;
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
	 	system("cls");
	cout<<" menu de opciones que se pueden realizar "<<endl;
	cout<<" digite 1.- agregar una nuevo tablero para tarea: "<<endl;
	cout<<" digite 2.- para agregar una lista nueva para tarea "<<endl;
	cout<<" digite 3.- para eliminar tableros de tareas: "<<endl;
	cout<<" digite 4.- para mirar tareas que tengo: "<<endl;
	cout<<" digite 5.- para salir  "<<endl;
	cout<<" digite la opcion que desea ";cin>>opc;
	  switch(opc)
	  {
	  	case 1: 
	  	      crear_tarea();
	  	      break;
	  	case 2:
	  		  crear_lita();
	  		  break;
	  	  case 3:
	  	  	eliminar_tarea();
	  	  	break;
	  	case 4:
	  		mirar_tarea();
	  		break;
	  		
	  	case 5:
	  	
	  	   login();
	  	   break;
	  	
	  }
	 }while(opc!=5);
}

void crear_tarea()
{
	 system("cls");
  ofstream documento1;
   ifstream fichero;
  
     
	cout << " nombre de la tarea:";cin>>tarea;
	ruta_tarea=ruta2 + tarea;
	  temporal=ruta2 + nombre;
	strcpy(docu,temporal.c_str());
	strcpy(archiv_us,ruta_tarea.c_str());
	fichero.open(archiv_us,ios::in);
	if(fichero.fail())
	{
		documento=fopen(ruta_tarea.c_str(),"a");	
		documento1.open(archiv_us,ios::app);
		documento1<<tarea<<endl;	
		cout <<" se creo una tarea" <<endl;
		system("pause");
	}
	else
	{
		cout<<"ohh la tarea ya existe "<<endl;
		system("pause");
	}		
	documento1.close();
	fichero.close();	
	
}

  void crear_lita()
  {
  	
  	 system("cls");
  	 ifstream fichero;
  	  ofstream documento1;
  	  string sub_tarea;

	cout<<"tarea ala que pertenece ";cin>>tarea;
	 temporal=ruta2 + tarea;
	strcpy(archiv_us,temporal.c_str());
	cout<< " crear subtarea";cin>>sub_tarea;
	
	ruta_tarea2= ruta2 + sub_tarea;
	fichero.open(archiv_us,ios::in);
	if (fichero.fail())
	{
		cout<<"ohho no se pudo crear la sub tarea";
	     system("pause");
	}
	else
	{
		fichero.close();
		fichero.open(ruta_tarea2.c_str(),ios::in);
		if(fichero.fail())
		{
			documento1.open(archiv_us,ios::app);
			documento1<<sub_tarea<<'\n';
			documento=fopen(ruta_tarea2.c_str(),"a");
			
			cout<<"se ha credo la sub tarea "<<endl;
			system("pause");
		}
		else
		{
			cout<<"el nombre de la sub tarea ya existe digite otro nombre para evitar ambiguedades"<<'\n';
			system("pause");
		}		
		
	}
	fichero.close();
	documento1.close();	
  	    
  	
  }
  

void eliminar_tarea()
{
	
}

void mirar_tarea()
{
	
}



