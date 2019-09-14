#include <iostream>
#include <string>
#include "Pilas.h"

using namespace std;

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

class Contenedor{
    private:

    public:
        Contenedor();

		int* buscarPila_conEspacio(Pilas *pilas, int M);
		void imprimir(Pilas *pilas, int M, int N);
		void buscarContenedor(Pilas *pilas, int M, int N,string dato);
		void moverContenedores(Pilas *pilas, int M, int N, string dato, int indiceM, int indiceN);
};		
#endif
