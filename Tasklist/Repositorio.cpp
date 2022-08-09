#include "Repositorio.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//CONSTRUCTOR
Repositorio::Repositorio(string tempoPrazo){
	this -> tempoPrazo = tempoPrazo;
}

//METHODS
string Repositorio::create(Tarefa tarefa){
	if (tarefa.getTipo() == "CurtoPrazo"){

		ofstream arquivoCurtoPrazo("CurtoPrazo.txt", ios::app);
		if(arquivoCurtoPrazo){
			arquivoCurtoPrazo << tarefa << endl;
			arquivoCurtoPrazo.close();
			return "Tarefa adicionada com sucesso";
		}
	}
	else{
		if (tarefa.getTipo() == "MedioPrazo"){

			ofstream arquivoMedioPrazo("MedioPrazo.txt", ios::app);
				if(arquivoMedioPrazo){
					arquivoMedioPrazo << tarefa << endl;
					arquivoMedioPrazo.close();
					return "Tarefa adicionada com sucesso";
				}
		}
		else{

			ofstream arquivoLongoPrazo("LongoPrazo.txt", ios::app);
				if(arquivoLongoPrazo){
					arquivoLongoPrazo << tarefa << endl;
					arquivoLongoPrazo.close();
					return "Tarefa adicionada com sucesso";
				}
		}
	}
}

string Repositorio::read(Tarefa tarefa){
	Tarefa aux;

	if(tarefa.getTipo() == "CurtoPrazo"){
		ifstream arquivoCurtoPrazo("CurtoPrazo.txt");

		if (arquivoCurtoPrazo){
			while(arquivoCurtoPrazo >> aux){
				if(aux == tarefa){
					arquivoCurtoPrazo.close();
					return "Tarefa existente!";
				}
			}
			arquivoCurtoPrazo.close();
			return "Tarefa inexistente";
		}
	}
	else{
		if(tarefa.getTipo() == "MedioPrazo"){
			ifstream arquivoMedioPrazo("MedioPrazo.txt");

			if (arquivoMedioPrazo){
				while(arquivoMedioPrazo >> aux){
					if(aux == tarefa){
						arquivoMedioPrazo.close();
						return "Tarefa existente!";
					}
				}
				arquivoMedioPrazo.close();
				return "Tarefa inexistente";
			}
		}
		else{
			if(tarefa.getTipo() == "LongoPrazo"){
				ifstream arquivoLongoPrazo("LongoPrazo.txt");

				if (arquivoLongoPrazo){
					while(arquivoLongoPrazo >> aux){
						if(aux == tarefa){
							arquivoLongoPrazo.close();
							return "Tarefa existente!";
						}
					}
					arquivoLongoPrazo.close();
					return "Tarefa inexistente";
				}
			}
		}
	}
	return "Tarefa inexistente";
}

string Repositorio::update(Tarefa tarefaParaAtualizar, Tarefa novaTarefa){
	Tarefa aux;
	if (tarefaParaAtualizar.getTipo() == "CurtoPrazo"){
		ifstream arquivosCurtoPrazo("CurtoPrazo.txt");
		ofstream arquivonCurtoPrazo("CurtoPrazo.txt");

		if(arquivosCurtoPrazo && arquivonCurtoPrazo){
			while(arquivosCurtoPrazo >> aux){
				if(aux == tarefaParaAtualizar){
					arquivonCurtoPrazo << novaTarefa;
				}
				else{
					arquivonCurtoPrazo << aux;
				}
			}
			arquivosCurtoPrazo.close();
			return "Tarefa atualizada com sucesso!";
		}
	}
	else{
		if (tarefaParaAtualizar.getTipo() == "MedioPrazo"){
			ifstream arquivosMedioPrazo("MedioPrazo.txt");
			ofstream arquivonMedioPrazo("MedioPrazo.txt");

			if(arquivosMedioPrazo && arquivonMedioPrazo){
				while(arquivosMedioPrazo >> aux){
					if(aux == tarefaParaAtualizar){
						arquivonMedioPrazo << novaTarefa;
					}
					else{
						arquivonMedioPrazo << aux;
					}
				}
				arquivosMedioPrazo.close();
				return "Tarefa atualizada com sucesso!";
			}
		}
		else{
			if (tarefaParaAtualizar.getTipo() == "LongoPrazo"){
				ifstream arquivosLongoPrazo("LongoPrazo.txt");
				ofstream arquivonLongoPrazo("LongoPrazo.txt");

				if(arquivosLongoPrazo && arquivonLongoPrazo){
					while(arquivosLongoPrazo >> aux){
						if(aux == tarefaParaAtualizar){
							arquivonLongoPrazo << novaTarefa;
						}
						else{
							arquivonLongoPrazo << aux;
						}
					}
					arquivosLongoPrazo.close();
					return "Tarefa atualizada com sucesso!";
				}
			}
		}
	}
}

string Repositorio::deleteTarefa(Tarefa tarefa){

	Tarefa aux;
	if(tarefa.getTipo() == "CurtoPrazo"){
		ifstream arquivosCurtoPrazo("CurtoPrazo.txt");
		ofstream arquivonCurtoPrazo("CurtoPrazo.txt");

		if(arquivosCurtoPrazo && arquivonCurtoPrazo){
			while(arquivosCurtoPrazo >> aux){
				if(aux != tarefa){
					arquivonCurtoPrazo << aux;
				}
			}
			arquivosCurtoPrazo.close();
			return "Tarefa deletada com sucesso!";
		}
	}
	else{
		if(tarefa.getTipo() == "MedioPrazo"){
			ifstream arquivosMedioPrazo("MedioPrazo.txt");
			ofstream arquivonMedioPrazo("MedioPrazo.txt");
			if(arquivosMedioPrazo && arquivonMedioPrazo){
				while(arquivosMedioPrazo >> aux){
					if(aux != tarefa){
						arquivonMedioPrazo << aux;
					}
				}
				arquivosMedioPrazo.close();
				return "Tarefa deletada com sucesso!";
			}
		}
		else{
			if(tarefa.getTipo() == "LongoPrazo"){
				ifstream arquivosLongoPrazo("LongoPrazo.txt");
				ofstream arquivonLongoPrazo("LongoPrazo.txt");
				if(arquivosLongoPrazo && arquivonLongoPrazo){
					while(arquivosLongoPrazo >> aux){
						if(aux != tarefa){
							arquivonLongoPrazo << aux;
						}
					}
					arquivosLongoPrazo.close();
					return "Tarefa deletada com sucesso!";
				}
			}
		}
	}
	return "Tarefa não deletada!";
}

void Repositorio::imprimirTarefas(){

	ifstream arquivoCurtoPrazo("CurtoPrazo.txt");
	ifstream arquivoMedioPrazo("MedioPrazo.txt");
	ifstream arquivoLongoPrazo("LongoPrazo.txt");
	Tarefa tarefa;

	if(arquivoCurtoPrazo){

		while(getline(arquivoCurtoPrazo, tarefa)){
			cout << tarefa << endl;
		}
		arquivoCurtoPrazo.close();
	}
	if(arquivoMedioPrazo){

		while(getline(arquivoMedioPrazo, tarefa)){
			cout << tarefa << endl;
		}
		arquivoMedioPrazo.close();
	}
	if(arquivoLongoPrazo){

		while(getline(arquivoLongoPrazo, tarefa)){
			cout << tarefa << endl;
		}
		arquivoLongoPrazo.close();
	}
}