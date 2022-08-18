#ifndef MEDIOPRAZO_H_
#define MEDIOPRAZO_H_

#include "Tarefa.h"

#include <iostream>
#include <string>

using namespace std;

//herança da classe Tarefa
class MedioPrazo : public Tarefa{
	//ATTRIBUTES
	private:
		string horario;
		string data;

	//CONSTRUCTOR
	public:
		MedioPrazo(string nome, string descricao, string tipo, string horario, string data);

	//METHODS
		string getHorario();
		void setHorario(string horario);

		string getData();
		void setData(string data);
};

#endif /* MEDIOPRAZO_H_ */
