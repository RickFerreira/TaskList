#include "Tarefa.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
Tarefa::Tarefa(string nome, string descricao, string tipo){
    this -> nome = nome;
    this -> descricao = descricao;
    this -> tipo = tipo;
}

//METHODS
//métodos get e set
string Tarefa::getNome(){
    return this -> nome;
}

void Tarefa::setNome(string nome){
    this -> nome = nome;
}

string Tarefa::getDescricao(){
    return this -> descricao;
}

void Tarefa::setDescricao(string descricao){
    this -> descricao = descricao;
}

string Tarefa::getTipo(){
    return this -> tipo;
}

void Tarefa::setTipo(string tipo){
    this -> tipo = tipo;
}
