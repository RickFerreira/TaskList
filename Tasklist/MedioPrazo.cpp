#include "MedioPrazo.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
MedioPrazo::MedioPrazo(string nome, string descricao, string tipo, string horario, string data) : Tarefa (nome, descricao, tipo){
	this -> horario = horario;
	this -> data = data;
}

//METHODS
string MedioPrazo::getHorario(){
	return this -> horario;
}

void MedioPrazo::setHorario(string horario){
	this -> horario = horario;
}

string MedioPrazo::getData(){
	return this -> data;
}

void MedioPrazo::setData(string data){
	this -> data = data;
}