#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include <direct.h> //directiva para crear carpetas 
#include<ctime>
#include<windows.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

string pasword,usua,temporal,user;
FILE *archiv;
char archi[50], fich[50], archiv2[50], archiv3[50], archiv4[50], archiv5[50];
string nombre_archiv;
string nom_usua,temp_pasword;
bool busqueda= false ;


int longitud=0,contador=0,opc=0;
void menu();

void hora()
{
   char fecha[25];//ctime devuelve 26 caracteres pero tambien se podría usar un puntero de char
    time_t current_time;
    current_time=time(NULL);
    ctime(&current_time);
    strcpy(fecha, ctime(&current_time));
    cout<<fecha;

}
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 void buscar_usuario()
 {
 	 fstream fiche2; //variable para abrir archivo
 	 string auxiliar;
 	 busqueda=false;
	
 	 fiche2.open(nombre_archiv.c_str());
     fiche2>>auxiliar;  
     if(pasword==auxiliar)
     {
     	busqueda=true;
     	
     	
	 }
	 fiche2.close();

	 
	 
 	
 }

void crear_usuario()
{
	 
	system("cls");
	cout<<"***** crea tu usario nuevo******"<<endl;
	ofstream fiche;
	cout << " ingrese el usuario "<<endl;
	cin>>usua;
	cout << " ingrese su pasword ";
	cin>>pasword;
	strcpy(archiv2,usua.c_str());
   	if (mkdir(usua.c_str()) == 0) //funcion para crear la carpeta 
	   {   
   		
   	      nombre_archiv=usua + ".txt";//se le da formato al archivo
	    fiche.open(nombre_archiv.c_str(),ios::app);
   		fiche<<pasword<<endl;
   		fiche.close();	
   		cout << " registro exitoso " << endl;	
	}
	else
	{
	 	cout << " Usuario Ya Existente " << endl;
	
	}
   	
   	
	} 
	
	void login()
	{
		 system("cls");
	cout<<"ingrese su usuario: ";cin>>usua;
	cout<<" ingrese su pasword: ";cin>>pasword;
	nombre_archiv=usua + ".txt";
	 buscar_usuario();
	 if(busqueda)
	 {
	menu();
	 	
	 	
	 }
	 else
	 {
	 	cout<<"no se encontro el usuario "<<endl;
	 	system("pause");
	 	crear_usuario();
	 	
	 }
	 	
    }
    
     void menu()
     {
     	 system("cls");
     	
     	do
     	{
           cout<<"*********** menu de actividades **************** "<<endl;
           cout<<"digite 1.- para agregar tareas "<<endl;
           cout<<"digite 2.- para agregar subtareas "<<endl;
           cout<<"digite 3.- para ver tareas realizadas "<<endl;
           cout<<"digite 4.- para eliminar tareas "<<endl;
           cout<<"digite 5.- para salir "<<endl;
           cout<<"digite su opcion: ";cin>>opc;
           switch(opc)
           {
           	 case 1: 
           	   break;
           	case 2:
           	break;
           	case 3:
           		break;
           	case 4:
           	break;
           	
           	case 5:
           		break;
           		break;
           	default:
           		cout<<"opcion invalida "<<endl;
           		break;
           		
           	
		   }
		system("pause>null"); 
		system("cls");
		}while(opc!=5);
     
     	
	 }

int main()
{
	
	 do
	 {
	 	
 system("cls");
     gotoxy(80,1);	cout<<" fecha y hora: "; hora();
   gotoxy(30,0);	cout<<"***** bienvenido a tu administrador de tarea ******** "<<endl;
	cout<<"digite 1.- para ingresar usuario "<<'\n';
	cout<<"digite 2.- para crear usuario "<<'\n';
	cout<<"digite 3.- para salir "<<'\n';
	cout<<" digite su opcion ";cin>>opc;
	switch(opc)
	{
		case 1: 
	    login();
		   
		break;
		
		case 2:
			crear_usuario();
		break;
		
		case 3:
			cout<<" adios espero averte ayudado "<<'\n';
			break;
			break;
		default:
			cout<<"opcin invalida "<<endl;
			break;
		
		//cierre del switch
	}
	system("pause>null"); 
    }while(opc!=3);
	
}//cierre del int main



