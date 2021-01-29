
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
string temporal,temporal2;
string ruta2;
string ruta_tarea,tarea,usuario,ruta_tarea2;
char tar[20], archiv_us1[20], archiv_us2[20],archi_us3[20],archiv_us4[20];
string sub_tarea=" ";
int x=0,y=0,z=0,h=4;
char lectura[20];
string lec="";
void login();
void registro_usuar();
void ingresar_usuario();
void menu_opciones();
void crear_tarea();
void mirar_tarea();
void eliminar_tarea();
void crear_lita();
void eliminar_sub_tarea();

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
	cout<<" digite 4.- para eliminar sub_tareas : "<<endl;
	cout<<" digite 5.- para mirar tareas que tengo: "<<endl;
	cout<<" digite 6.- para salir  "<<endl;
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
	  	  		eliminar_sub_tarea();
	  	  		break;
	  	case 5:
	  	 	mirar_tarea();
	  		break;
	  		
	  	case 6:
	  	
	  	   login();
	  	   break;
	  	
	  }
	 }while(opc!=6);
}

void crear_tarea()
{
	 system("cls");
  ofstream documento1;
   ifstream fichero;
  
     
	cout << " nombre de la tarea: ";cin>>tarea;
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
 

	cout<<"tarea ala que pertenece ";cin>>tarea;
	 temporal=ruta2 + tarea;
	strcpy(archiv_us,temporal.c_str());
	cout<< " crear subtarea: ";cin>>sub_tarea;
	
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
	ifstream fichero;
	ofstream documento1;

   system("cls");

	cout<<" tablero de la tarea que quieres eliminar: ";cin>>tarea;

	temporal=ruta2 + tarea;
	strcpy(tar,temporal.c_str());
	remove(temporal.c_str());
	strcpy(tar, tarea.c_str());
	temporal=ruta2 + nombre;
	strcpy(archiv_us2,temporal.c_str());
	temporal2=ruta2+" temporal";
	strcpy(archiv_us2,temporal2.c_str());
	fichero.open(archiv_us1,ios::in);
	documento1.open(archiv_us2,ios::app);
	while(getline(fichero,ruta))
	{
		if(tar!=ruta)
		{
			documento1<<ruta<<endl;	
		}		
	}
	documento=fopen(archiv_us1,"a");
	fichero.close();
	documento1.close();
	fichero.open(archiv_us2,ios::in);
	documento1.open(archiv_us1,ios::app);
	while(getline(fichero,ruta))
	{
		documento1<<ruta<<endl;
	}
	documento=fopen(archiv_us2, "a");
	fichero.close();
	documento1.close();
	
	cout<<"se a eliminado con exito"<<endl;
	system("pause");
}

 void eliminar_sub_tarea()
 {
 		system("cls");
	ifstream fichero;
	ofstream documento1;

	


	cout<<" tarea en la que pretenece esa subtarea : ";cin>>tarea;
	temporal=ruta2+tarea;
	strcpy(archiv_us1,temporal.c_str());
	cout<<" subtarea  ";cin>>sub_tarea;
	temporal=ruta2 + sub_tarea;
	strcpy(archiv_us1,temporal.c_str());
	remove(temporal.c_str());
	strcpy(tar, tarea.c_str());
	temporal2=ruta2;
	strcpy(archiv_us2,temporal.c_str());
	fichero.open(archiv_us1,ios::in);
	documento1.open(archiv_us2,ios::app);
	while(getline(fichero,ruta))
	{
		if(tar!=ruta)
		{
			documento1<<ruta<<endl;	
		}		
	}
	
	fichero.close();
	documento1.close();
	documento=fopen(archiv_us1,"a");
	fichero.open(archiv_us2,ios::in);
	documento1.open(archiv_us1,ios::app);
	while(getline(fichero,ruta))
	{
		documento1<<ruta<<endl;
	}
	
	documento=fopen(archiv_us2, " a");
	fichero.close();
	documento1.close();
cout<<" sea eliminado la subtarea "<<endl;
system("pause");
 	
 }

void mirar_tarea()
{
	system("cls");
	
	ifstream fichero;
	ifstream documento1;
	ifstream documento2;


	
	
	 temporal=ruta2 + nombre;
	strcpy(archi_us3,temporal.c_str());
	fichero.open(archi_us3,ios::in);
	
	while(getline(fichero,lec)){
		cout<<" la tarea es: "<<lec<<endl;
			
		documento1.close();
		temporal=ruta2 + lec;
		strcpy(archiv_us4,temporal.c_str());
		
		documento2.open(archiv_us4,ios::in);
			while(getline(documento2,lec))
			{
			
				cout<<lectura<<endl;				
			}
			documento2.close();	
	}	
	
	system("pause");
	
}



