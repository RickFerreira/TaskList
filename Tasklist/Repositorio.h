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
		void create(Tarefa tarefa);
		string read();
		void update(Tarefa tarefaParaAtualizar, Tarefa novaTarefa);
		void deleteTarefa(Tarefa tarefa);
		void imprimirTarefa();
};

#endif