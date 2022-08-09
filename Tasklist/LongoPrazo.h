#ifndef LONGOPRAZO_H_
#define LONGOPRAZO_H_

#include "Tarefa.h"

#include <iostream>
#include <string>

using namespace std;

class LongoPrazo : public Tarefa{
	//ATTRIBUTES
	private:
		string data;

	//CONSTRUCTOR
	public:
		LongoPrazo(string nome, string descricao, string tipo, string data);

	//METHODS
		string getData();
		void setData(string data);
};

#endif /* LONGOPRAZO_H_ */
