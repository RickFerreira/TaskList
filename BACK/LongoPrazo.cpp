#include "LongoPrazo.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
LongoPrazo::LongoPrazo(string nome, string descricao, string tipo, string data) : Tarefa (nome, descricao, tipo){
	this -> data = data;
}

//METHODS
//métodos get e set
string LongoPrazo::getData(){
	return this -> data;
}

void LongoPrazo::setData(string data){
	this -> data = data;
}
