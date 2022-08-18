#ifndef CURTO_H_
#define CURTO_H_

#include "Tarefa.h"

#include <iostream>
#include <string>

using namespace std;

//herança da classe Tarefa
class CurtoPrazo : public Tarefa{
    //ATTRIBUTES
    private:
        string horario;
		
    //CONSTRUCTOR
    public:
        CurtoPrazo(string nome, string descricao, string tipo, string horario);

    //METHODS
        string getHorario();
        void setHorario(string horario);

};

#endif /* CURTOPRAZO_H_ */
