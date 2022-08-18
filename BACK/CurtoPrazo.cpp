#include "CurtoPrazo.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
CurtoPrazo::CurtoPrazo(string nome, string descricao, string tipo, string horario) : Tarefa (nome, descricao, tipo){
    this -> horario = horario;
}

//METHODS
//métodos get e set
string CurtoPrazo::getHorario(){
    return this -> horario;
}

void CurtoPrazo::setHorario(string horario){
    this -> horario = horario;
}
