#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
char usuario[30],contra[30],acum_usuario[30],acum_contra[30];

int longitud=0,contador=0,opc=0;
void crear_usu()
{
	 system("cls");
	cout<<"digite su usuario: ";cin>>usuario;
    acum_usuario[30]=usuario[30];
    cout<<" digite su pasword: ";cin>>contra;
                                                       //funcion crear usuario es prueba 
    longitud=strlen(contra);
    if(longitud>4)
    {
    	cout<<"digite un pasword que sea menor a 4";
    	
	}
	else
	{
		acum_contra[30]=contra[30];
	}
}


int main()
{
	cout<<"------------------------------------------------------"<<'\n';
	cout<<" *****bienvenido a tu administrador de tareas****** "<<'\n';
	cout<<"------------------------------------------------------"<<'\n';
    cout<<"digite su usuario: ";cin>>usuario;
    cout<<"digite su pasword: ";cin>>contra;
   	
	
    if(usuario == "axel" && contra =="1234")
    {
    	do{
    		cout<<"bienvenido usuario "<<usuario<<'\n';
		    cout<<"digite 1.- si quiere crear una tarea "<<'\n';
		    cout<<"digite 2.- si quiere craer una subtarea "<<'\n';
		    cout<<" digite 3.- para ver la realizacion de tareas"<<'\n';
		    cout<<" digite 4.- para eliminar tarea "<<'\n';
		    cout<<"digite 5.- para salir "<<'\n';
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
		    		
		    	
			}//fin del switch
	
	
	}while(opc!=5);		

	}
    
    	else
	{
		 contador=contador+1;
		cout<<"usuario no encontrado "<<'\n';

		
	}


	return 0;
}
