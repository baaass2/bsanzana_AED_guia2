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

		void buscarPila_conEspacio(Pilas *pilas, int M, string dato);
		void imprimir(Pilas *pilas, int M, int N);
		
};		
#endif
