#ifndef TAREFA_H_
#define TAREFA_H_

#include <iostream>
#include <string>

using namespace std;

class Tarefa{
    //ATTRIBUTES
    private:
        string nome;
        string descricao;
        string tipo;

    //CONSTRUCTOR
    public:
        Tarefa(string nome, string descricao, string tipo);

    //METHODS
        string getNome();
        void setNome(string nome);
        string getDescricao();
        void setDescricao(string descricao);
        string getTipo();
        void setTipo(string tipo);

};

#endif /* TAREFA_H_ */
