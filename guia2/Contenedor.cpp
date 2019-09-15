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
	int *arrayAux = new int[2];
	
    cout << "¿Cantidad de columna con contenedores ?: ";cin >> M;
    cout << "¿Cantidad de de filas con contenedores  ?: ";cin >> N;
    
    Pilas *pilas = new Pilas[M];
    
    for(int i=0; i<M; i++){
		Pilas p = Pilas(0, N);
		pilas[i] = p;
		
	}
	
	while(stop != 1){
		cout << "" <<endl;
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
			cout << "Ingrese nombre del contenedor de la forma numero-letra: ";cin >> dato;
			arrayAux=buscarPila_conEspacio(pilas, M);
			if(arrayAux[1] == 1){
				pilas[arrayAux[0]].push(dato);
			}
				
			imprimir(pilas, M, N);
		}
		else if(opc == 2){
			cout << "Ingrese nombre de contenedor de la forma numero-letra: ";cin >> dato;
			buscarContenedor(pilas, M, N, dato);
			imprimir(pilas, M, N);
		}
		else if(opc == 3){
			imprimir(pilas, M, N);
		}
	}
}
void Contenedor::moverContenedores(Pilas *pilas, int M, int N, string dato, int indiceM, int indiceN){
	
	int tope = 0;
	tope = ( pilas[indiceM].getTope() - 1);
	int *arrayAux2 = new int[2];
	string *arrayAux = new string[N];
	arrayAux = pilas[indiceM].getArray();
	while( indiceN != tope ){
		arrayAux2 = buscarPila_conEspacio(pilas, M);
		if(arrayAux2[1] == 1){
			pilas[arrayAux2[0]].push(arrayAux[tope]);
			pilas[indiceM].pop();
			tope = ( pilas[indiceM].getTope() - 1);
			imprimir(pilas, M, N);
		}
		else if(arrayAux2[1] == 0){
			break;
		}
	}
	if(indiceN == tope){
		pilas[indiceM].pop();
	}
}

void Contenedor::buscarContenedor(Pilas *pilas, int M, int N, string dato){
	
	string *arrayAux = new string[N];
	
	for(int i=0; i<M; i++){
		arrayAux =  pilas[i].getArray();		
		for(int k=0; k<N; k++){
			if(arrayAux[k] == dato){
				cout << "Se ha encontrado el contenedor en la pila: "<< i+1 <<endl;
				cout << "En la posicion: "<< k+1 <<endl;
				cout << "Se procederá a eliminarlo."<<endl;
				moverContenedores(pilas, M, N, dato, i, k);
			}
		}
	}
}

int* Contenedor::buscarPila_conEspacio(Pilas *pilas, int M){
	bool band = NULL;
	int aux=0;
	int noMatch = 0;
	int *arrayAux = new int[2];
	
	for(int i=0; i<M; i++){
		band = pilas[i].pilaLlena();
		if(band == true){
			cout << "No hay espacio en la pila " << i+1 <<endl;
			noMatch = noMatch + 1;
		}
		else if(band == false){
			cout << "Se encontro espacio en la pila " << i+1 <<endl;
			aux = i;
			cout << "aux: " << aux <<endl;
			arrayAux[0] = aux;
			arrayAux[1] = 1;
			i=M;
		}
	}
	
	if(noMatch == M){
		cout << "No se ha encontrado espacio."<<endl;
		arrayAux[0] = 0;
		arrayAux[1] = 0;
	}
	
	return arrayAux;
}

void Contenedor::imprimir(Pilas *pilas, int M, int N){

	string *arrayAux2= new string[M*N];
	string *arrayAux = new string[N];
	
	int indice=0;
	
	for(int i=0; i<M; i++){
		arrayAux =  pilas[i].getArray();	
		for(int k=0; k<N; k++){
			arrayAux2[indice] = arrayAux[k];
			indice = indice +1;
		}
	}
	
	for(int i=0; i<(M*N); i++){
		cout << arrayAux2[i] << " ";

	}
}


