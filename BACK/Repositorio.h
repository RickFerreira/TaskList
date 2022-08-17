#ifndef REPOSITORIO_H_
#define REPOSITORIO_H_

#include <iostream>
#include <string>

using namespace std;

class Repositorio{
	//ATTRIBUTES

	//CONSTRUCTOR
	public:
		Repositorio();

	//METHODS
		string create();
		string read(string buscar);
		string update(string atualizar);
		string deleteTarefa(string deletar);
		void imprimirTarefas();
		void imprimirPorTipo();
};

#endif
