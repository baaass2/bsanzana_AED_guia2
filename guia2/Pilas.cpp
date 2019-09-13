#include <iostream>
#include <string>
#include "Pilas.h"

using namespace std;


Pilas::Pilas(){
}

Pilas::Pilas(int tope, int max){
    this->tope = tope;
    this->max = max;
	this->array = new string[this->max];
}

bool Pilas::pilaVacias(){
	
	bool band = NULL;
	
	if( this->tope = 0){
		band = true;
	}
	else{
		band = false;
	}
	return band;	
}

bool Pilas::pilaLlena(){
	
	bool band = NULL;

	if( this->tope == this->max){
		band = true;
	}
	else if(this->tope < this->max){
		band = false;
	}
	return band;
}

void Pilas::push(string dato){
	
	bool band = NULL;
	
	band = pilaLlena();
	if(band == true){
		cout << "Desbordamiento, pila llena" <<endl;
	}
	else if (band == false){
		this->array[this->tope] = dato;
		this->tope = this->tope + 1;
	}
}

void Pilas::pop(){
	
	bool band = NULL;
	
	if(band == true ){
		cout << "Desbordamiento, pila vacía" <<endl;
	}
	else if(band ==false){
		this->array[this->tope] = "";
		this->tope = this-> tope -1;
	}
	
	if(this-> tope < 0){
		this -> tope = 0;
	}
}

int Pilas::getTope(){
	return this->tope;
}

string* Pilas::getArray(){
	return this->array;
}
		
