/*PROYECTO AP2

Cargue un archivo .txt que tenga almacenada una agenda que contenga un registro de personas las cuales poseen nombre, telefono y grupo al 
que pertencen. Almacene la agenda en una cola con prioridad el grupo al que pertence cada persona. Luego mostrar la agenda segun el grupo 
que se quiera mostrar, y dado un telefono decir a quien pertence.*/


#include "CLASE_COLA.h"
#include <iostream>

void MENU(cola );
int main(){

	cola C1;
	C1.encolarArchivo();
	MENU(C1);
	
	return 0;
}

void MENU(cola C1){
	int opcion = 0, op = 0, tel = 0;
	do{
		system("cls");
		C1.mostrarCola();
		cout << "\t--------------------------" << endl;
		cout << "\n\tMENU AGENDA" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t1. IMPRIMIR PERSONAS SEGUN EL GRUPO" << endl;
		cout << "\t2. IMPRIMIR PERSONA SEGUN EL NUMERO" << endl;
		cout << "\t3. SALIR" << endl;
		cout << "\tESCOJA UNA OPCION: ";
		cin >> opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout << "\n\tQUE GRUPO DESEA MOSTRAR?: ";
				cin >> op;
				C1.mostrarPersonas(op);
			break;
			case 2:
				system("cls");
				cout << "\n\tQUE NUMERO DESEA BUSCAR: ";
				cin >> tel;
				C1.mostrarPersonasTel(tel);
			break;
			default:
				if(opcion != 3){
					system("cls");
					cout << "\n\tINGRESE UNA OPCION CORRECTA!\n\t";
					system("pause");
				}
			break;
		}
	}while(opcion != 3);	
	
}
