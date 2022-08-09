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
		string create(Tarefa tarefa);
		string read(Tarefa tarefa);
		string update(Tarefa tarefaParaAtualizar, Tarefa novaTarefa);
		string deleteTarefa(Tarefa tarefa);
		void imprimirTarefa();
};

#endif /* REPOSITORIO_H_ */