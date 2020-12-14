
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

struct nodo{
	string nombre;
	int prioridad;
	int numero;
};

class cola{

	private:
		int Limite;
		int Tope;
		nodo VEC[8];
	public:
		cola(){
			nodo VEC[8];
			Limite = 7;
			Tope = -1;
		}
		void encolaR(nodo aux){
			if(ColaLlena() == false){
				Tope++;
				VEC[Tope] = aux;
			}
			else{
				cout << "\a\n\tLA COLA ESTA LLENA!\n\t";
				system("pause");
			}
		}
		nodo desencolar(){
			int i = 1;
			nodo auxi;
			if(ColaVacia() == false){
				auxi = VEC[0];
				while(i <= Tope){
					VEC[i-1] = VEC[i];
					i++;
				}
				Tope--;
			}
			else{
				cout << "\a\n\tHA DESENCOLADO TODOS LOS DATOS DE LA COLA!\n\t";
				system("pause");
			}
			return auxi;
		}	
		bool ColaLlena(){
			if(Tope == Limite){
				return true;
			}
			else{
				return false;	
			}
		}
		bool ColaVacia(){
			if(Tope == -1){
				return true;
			}
			else{
				return false;
			}
		}
		void LlenarCola(cola C){
			nodo aux;
			while(C.ColaVacia() == false){
				aux = C.desencolar();
				encolaR(aux);
			}
		}
		void mostrarCola(){
			cola C;
			nodo r;
			cout << endl;
			while(ColaVacia() == false){
				r = desencolar();
				cout << "\t" << r.nombre << " " << r.numero << " " << r.prioridad << endl;
				C.encolaR(r);
			}
			LlenarCola(C);
		}		
		void mostrarCola1(){
			cola C;
			nodo r;
			cout << "\n\tG R U P O  1" << endl;
			cout << "\t--------------------" << endl;			
			while(ColaVacia() == false){
				r = desencolar();
				if(r.prioridad == 1){
					cout << "\n\tNOMBRE: " << r.nombre <<endl;
					cout << "\tTELEFONO: " << r.numero << endl;
					cout << "\tGRUPO: " << r.prioridad << endl;					
					cout << "\t--------------------" << endl;	
				}
				C.encolaR(r);
			}
			LlenarCola(C);
			cout << "\n\t";
			system("Pause");
		}
		void mostrarCola2(){
			cola C;
			nodo r;
			cout << "\n\tG R U P O  2" << endl;
			cout << "\t--------------------" << endl;			
			while(ColaVacia() == false){
				r = desencolar();
				if(r.prioridad == 2){
					cout << "\n\tNOMBRE: " << r.nombre <<endl;
					cout << "\tTELEFONO: " << r.numero << endl;
					cout << "\tGRUPO: " << r.prioridad << endl;					
					cout << "\t--------------------" << endl;	
				}
				C.encolaR(r);
			}
			LlenarCola(C);
			cout << "\n\t";
			system("Pause");
		}
		void mostrarCola3(){
			cola C;
			nodo r;
			cout << "\n\tG R U P O  3" << endl;
			cout << "\t--------------------" << endl;
			while(ColaVacia() == false){
				r = desencolar();
				if(r.prioridad == 3){
					cout << "\n\tNOMBRE: " << r.nombre <<endl;
					cout << "\tTELEFONO: " << r.numero << endl;
					cout << "\tGRUPO: " << r.prioridad << endl;					
					cout << "\t--------------------" << endl;					
				}
				C.encolaR(r);
			}
			LlenarCola(C);
			cout << "\n\t";
			system("Pause");
		}				
		void encolarArchivo(){
			ifstream archivo;
			nodo aux;
			archivo.open("agenda.txt",ios::in);	//ABRIR ARCHIVO EN MODO LECTURA
			if(archivo.fail()){
				cout << "\n\tNO SE PUDO ABRIR EL ARCHIVO";
			}
			else{
				while(!archivo.eof()){				//MIENTRAS NO SEA EL FINAL DEL ARCHIVO
					archivo >> aux.nombre;
					archivo >> aux.numero;
					archivo >> aux.prioridad;
					encolaR(aux);									//<===================== ACA ESTA EL ERROR
				}
				archivo.close();
			}
		}
		void mostrarPersonas(int op){
			switch(op){
				case 1:
					mostrarCola1();
				break;
				case 2:
					mostrarCola2();	
				break;
				case 3:
					mostrarCola3();	
				break;
				default: 
					cout << "\n\t\aEL GRUPO NO EXISTE!\n\t";
					system("pause");
				break;
			}			
		}			
		void mostrarPersonasTel(int tel){
			nodo r;
			cola C;
			while(ColaVacia() == false){
				r = desencolar();
				if(r.numero == tel){
					cout << "\n\tNOMBRE: " << r.nombre <<endl;
					cout << "\tTELEFONO: " << r.numero << endl;
					cout << "\tGRUPO: " << r.prioridad << endl;					
					cout << "\t--------------------" << endl;
					break;	
				}
				C.encolaR(r);
			}
			if(r.numero != tel){
				system("cls");
				cout << "\n\tNO HAY UNA PERSONA QUE TENGA DICHO NUMERO!";
			}
			LlenarCola(C);
			cout << "\n\t";
			system("Pause");			
		}	
		~cola(){		//DESTRUCTOR
		}		
};
