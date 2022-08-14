#ifndef REPOSITORIO_H_
#define REPOSITORIO_H_

#include "Tarefa.h"

#include <iostream>
#include <string>

using namespace std;

class Repositorio{
	//ATTRIBUTES
	private:
		string tempoPrazo;

	//CONSTRUCTOR
	public:
		Repositorio(string tempoPrazo);

	//METHODS
		void setTempoPrazo(string prazo);
		string create();
		string read(string buscar);
		string update(string atualizar);
		string deleteTarefa(string deletar);
		void imprimirTarefa();
};

#endif
