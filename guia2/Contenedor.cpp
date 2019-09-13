#include <iostream>
#include <string>
#include "Pilas.h"
#include "Contenedor.h"

using namespace std;


Contenedor::Contenedor(){
	
	int N = 0;
	int M = 0;
	int stop= 0;
	int opc = 0;
	string dato= "";
	
    cout << "¿Cantidad de pilas ?: ";cin >> M;
    cout << "¿Tamaño de las pilas ?: ";cin >> N;
    
    Pilas *pilas = new Pilas[M];
    
    for(int i=0; i<M; i++){
		Pilas p = Pilas(0, N);
		pilas[i] = p;
		
	}
	
	while(stop != 1){
		cout << "-----------------------" <<endl;
		cout << "Agregar/push [1]" <<endl;
		cout << "Remover/pop [2]" <<endl;
		cout << "Ver contenedor [3]" <<endl;
		cout << "Salir[0]" <<endl;
		cout << "¿Ingrese opc: ";cin >> opc;
		
		if(opc==0){
			stop=1;
		}
		else if(opc ==1){
			cout << "Ingrese nombre de contenedor de la forma numero-letra: ";cin >> dato;
			buscarPila_conEspacio(pilas, M, dato);
		}
		else if(opc == 2){
		}
		else if(opc == 3){
			imprimir(pilas, M, N);
		}
	}
}


void Contenedor::buscarPila_conEspacio(Pilas *pilas, int M, string dato){
	bool band = NULL;
	int aux=0;
	int noMatch = 0;
	
	for(int i=0; i<M; i++){
		band = pilas[i].pilaLlena();
		if(band == true){
			cout << "No hay espacio en la pila " << i <<endl;
			noMatch = noMatch + 1;
		}
		else if(band == false){
			cout << "Se encontro espacio en la pila " << i <<endl;
			aux = i;
			cout << "aux: " << aux <<endl;
			pilas[aux].push(dato);
			i=M;
		}
	}
	
	if(noMatch == M){
		cout << "No se ha encontrado espacio."<<endl;
	}
}

void Contenedor::imprimir(Pilas *pilas, int M, int N){
	int tope = 0;
	string* pAux;
	for(int i=0; i<M; i++){
		tope = pilas[i].getTope();
		pAux =  pilas[i].getArray();
		cout << "Tope: "<< tope <<endl;
		cout << "Tope: "<< tope <<endl;
		for(int k=0; k<N; k++){
			cout << pAux[k] <<endl;
		}
	}
	
	//for(int i= ((this->tope)-1); i>=0; i--){
		//if( ((this->tope)-1) != -1){
			//cout << this->array[i]<< endl;
		//}
	//}
}


