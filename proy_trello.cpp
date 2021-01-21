#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
char usuario[30],contra[30],acum_usuario[30],acum_contra[30];
string pasword,usua;

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
    
   	while(contador!=10)
{
    cout<<"digite su usuario: ";cin>>usua;
    cout<<"digite su pasword: ";cin>>pasword;
		 
		if (usua=="axel" && pasword=="1234")
		{
			
	   system("cls");		
	do{
		 contador=0;

		{
			
			
			cout<<"_______________________________";
			cout<<endl;
			cout<<"presione 1.- para crear tareas "<<'\n';           //hacemos un menu para el usuario
			cout<<"presione 2.- para hacer una subtarea "<<'\n';
			cout<<"presion 3.- para ver resultados de la tarea"<<'\n';
			cout<<"presione 4.- para eliminar tareas"<<'\n';
			cout<<"presione 5.- para salir"<<'\n';
			cout<<"____________________________________"<<'\n';
		
			cout<<"elija una opcion: ";cin>>opc; //leemos la opcion para el menu
			system("cls");
			switch(opc)
			
			{
				  
				case 1:	 
				break;
				
					
				case 2:	
				break;
					
				case 3:
			     break;
						 
					case 5:
						cout<<"hasta luego usuario "<<usua;
					break;
					break;
					
				default:
					cout<<"opcion invalida"<<endl;
					
				break;
						
				
			}   //termina el switch
			cout<<endl;	
			system("pause");
			system("cls");
		}			
				
}while(opc!=5); // termino del ciclo while condicion para que cuando el usuario de mas de 10 intentos se cierre el programa	}while(respuesta!=2);	

}
	else 
			{
				 
				 contador=contador+1;
				 	cout<<"  datos erroneos: "<<endl;
				 	cout<<" ADVERTENCIA, tienes tan solo 10 intentento y llevas "<<contador; 
				 	cout<<endl;
					
}		
		}
	
    


	return 0;
}
