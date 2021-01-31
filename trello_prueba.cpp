#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<direct.h>

using namespace  std;

string respuesta="",nombre_usuario="",usuario="",password="";
fstream  archivo;
bool busqueda=false;
string nombre_archivo;
int opc=0;
int contador=0;
const int elemento=99;
int num_tar;
int dia=0,ano=0,mes=0,hora=0,minuts=0;
 bool buscar_nom=false;

 void obtener_fechas(int contador);
struct fechas
{
	int dias;
	int mese;
	int year;
	int  hour;
    int  minutos;
};
 
struct tareas
{
	string nombre;
	string descri;
	fechas date;
	
};

tareas vector[elemento][elemento];

void crear_tareas()
{
  system("cls");
    
	cout<<" ingrese el nombre de la tarea: ";cin>>vector[contador][1].nombre;
	
	cout<<"ingresa el numero de  sub tareas que deseas realizar ";cin>>num_tar;
	 
	for(int y=0; y<num_tar;y++)
	 
	{
		
		cout<<" ingrese el nombre de la subtarea: ";cin>>vector[contador][y].descri;
		
		
		
		
	}
		
	obtener_fechas( contador);
    ++contador;
	
}

void tareas_pendientes()
{
	
	for(int y=0; y<elemento;y++)
	
	{
    	for(int x=0; x<elemento;x++)
		 if(vector[y][x].descri!="\0")
	  	{
	 	 cout<<"Tablero "<<vector[y][1].nombre<<" Subtarea: "<<vector[y][x].descri<<"  fecha:  "<<vector[y][1].date.dias <<" / "<< vector[y][1].date.mese<< " / "<<vector[y][1].date.year<<" / "<< vector[y][1].date.hour<<" : "<< vector[y][1].date.minutos<<endl;	
	 	    
		  
	    }	
	}


system("pause");
	}
	
	
	
	void obtener_fechas(int contador)
{
	
	   do
   	  {
   	   cout<<" Ingrese el dia: ";cin>>dia;
	 }while(dia<=0 || dia>=32);
	 
	 do
	 {
	   	 cout<<"Ingrese el mes: ";cin>>mes;	
	 }while(mes<=0 || mes>=13);
	 
	 do
	 {
	 	cout<<"Ingrese el year: ";cin>>ano;
	 }while(ano<=1980 || ano>=2099);
    
     do
     {
     	cout<<"Ingrese hora: ";cin>>hora;
     	
     	
	 }while(hora<=0 || hora>=25);
	 
	 do
	 {
	 	cout<<"Digite los minutos: ";cin>>minuts;
	 }while(minuts<0 || minuts>=61);
     
     if(minuts==60)
     {
     	hora+=1;
     	minuts=0;
     	
	 }
	 if(hora>24)
	 {
	 	hora=hora-24;
	 	
	 }
	 else if(hora==24)
	 {
	 	hora=0;
	 }
	
  vector[contador][1].date.dias=dia;
  vector[contador][1].date.mese=mes;
  vector[contador][1].date.year=ano;
  vector[contador][1].date.hour=hora;
  vector[contador][1].date.minutos=minuts;
  
	
	
}



 int buscar_tablero(string nombre2)
 {
 	 
 	 for(int y=0;y<elemento;y++)
	 {
	 	if(nombre2==vector[y][1].nombre)
	 	{
	 	 buscar_nom=true;
	 		return y;
		 }
		 
	 }
	
 	
 }


int buscar_subtarea(string nombre2,int pos)
 {
 	 
 	 for(int y=0;y<elemento;y++)
	 {
	 	if(nombre2==vector[pos][y].nombre)
	 	{
	 	 buscar_nom=true;
	 		return y;
		 }
		 
	 }
	
 	
 }
void terminar_subtarea()
{
	string nombre,nombre2;
	cout<<" qure tarea deseas terminar " ;cin>>nombre;
 	 int pos=buscar_tablero(nombre);
 	 if(buscar_nom)
 	 {
 	 	
 	 	cout<<"Que Subtarea deseas terminar:"; cin>>nombre2;
 	 	int pos2=buscar_subtarea(nombre2,pos);
 	 	if(buscar_nom)
 	 	{
 	 		vector[pos][1].nombre="";
 	 		vector[pos][pos2].descri="";
 	 		
 	
 	 		//Agrega los registros de que tarea realizaste con su fecha 
 	 		cout<<"La tarea se ha agregado en tableros realizados!!"<<endl;
		  }
	  }
	  else cout<<"El tablero no se encontro!!!!!!"<<endl;
	  
	  system("pause");
 	 
		
}




void guardar_datos()
{
	
	archivo.open(nombre_archivo.c_str());
	archivo<<password<<'\n';
	
	archivo.close();
}

void leer_datos()
{
	 archivo.open(nombre_archivo.c_str());
	 
	 archivo>>password;
	 
	 
	 archivo.close();
	
}

void crear_usuario()
{
	cout<<" ingrese el nombre de usuario ";cin>>usuario;
	nombre_usuario=usuario+".txt";
	do
   	 {
   	cout<<" digite su password: ";cin>>password;
	}while(password.length()<=3);
	archivo.open(nombre_usuario.c_str(),ios::app);
	archivo<<password<<'\n';
	archivo.close();
   	
}
//____________________________________________________________________________________
void pregunta()
{
	cout<<" quieres crear un usuario digite si.- para crear uno nuevo ";cin>>respuesta;
	if(respuesta=="si")
	{
		crear_usuario();
	}
	else
	{
		return;
	}
}

 void buscar_contra()
 {
 	string auxiliar;
 	 archivo.open(nombre_archivo.c_str());
     archivo>>auxiliar;  
     if(password==auxiliar)
     {
     	busqueda=true;
     	
     	
	 }
	 archivo.close();

 }


int main()
{

	 while(true)
	 {
	 pregunta();
	 system("cls");
	 
	 regreso:
	 	
	 	cout<<" digite  su usuario ";cin>>usuario;
	 	cout<<" digite su password ";cin>>password;
	 	nombre_archivo=usuario+".txt";
	 	system("cls");
	 	buscar_contra();
	 	if(busqueda)
	 	{
	 		do
	 		{
	 			 system("cls");
	 			
	 			leer_datos();
	 			cout<<" bienvenido a su administrador de tarea: "<<endl;
	 			cout<<" digite 1.- para crear tableros "<<endl;
	 			cout<<" digite 2.- para ver tareas pendintes "<<endl;
	 			cout<<" digite 3.- para eliminar tableros "<<endl;
	 			cout<<" digite 4.- para eliminar listas tareas "<<endl;
	 			cout<<" digite 5.- para cambiar la fecha "<<endl;
	 			cout<<"  digite 6.- para remplazar tareas "<<endl;
	 			cout<<" digite 7.- para cambiar de usuario "<<endl;
	 			cout<<" digite 8.- para cerrar cesion "<<endl;
	 			cout<<" digite su opcion ";cin>>opc;
	 			switch(opc)
	 			{
	 			   case 1:
	 			   	system("cls");
	 			   	  crear_tareas();
					break;
					
					case 2:
						system("cls");
						tareas_pendientes();
					break;
					
					case 3:
						terminar_subtarea();
					break;
					
					case 4:
					break;
					
					case 5:
					break;
					
					case 6:
					break;
					
					case 7:
						goto regreso;
						break;
						
					case 8:
						return 0;
						break;
						
	 				
	 				
				}//cierre del switch
	 			
			 } while(opc!=8);
			 system("cls");
	 		
		 }//fin del if de busqueda
		 
		 else
		 {
		 	cout<<" no se encontro al usuario "<<endl;
		 }
	 
	 }
	
	
	
	
	
}
