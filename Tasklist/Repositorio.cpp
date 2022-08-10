#include "Repositorio.h"

#include <fstream>

#include "CurtoPrazo.h"
#include "MedioPrazo.h"
#include "LongoPrazo.h"

using namespace std;

//CONSTRUCTOR
Repositorio::Repositorio(string tempoPrazo){
	this -> tempoPrazo = tempoPrazo;
}

//METHODS
void Repositorio::setTempoPrazo(string prazo){
	this -> tempoPrazo = prazo;
}

void Repositorio::create(Tarefa tarefa){
	string horario, data, condicao = tarefa.getTipo();
	if(condicao == "CurtoPrazo"){

		ofstream arquivoCurtoPrazo("CurtoPrazo.txt", ios::app);

		if(arquivoCurtoPrazo.is_open()){

			cout << "\nDigite o horario da sua tarefa(hh:mm):";
			cin >> horario;

			CurtoPrazo curtoPrazo = CurtoPrazo(tarefa.getNome(), tarefa.getDescricao(), tarefa.getTipo(), horario);

			arquivoCurtoPrazo << "{Nome: " <<  curtoPrazo.getNome() << endl;
			arquivoCurtoPrazo << "Descrição: " << curtoPrazo.getDescricao() << endl;
			arquivoCurtoPrazo << "Tipo: " << curtoPrazo.getTipo() << endl;
			arquivoCurtoPrazo << "Horario: " << curtoPrazo.getHorario() << "}\n" << endl;
			arquivoCurtoPrazo.close();
		}
	}

	else{
		if(condicao == "MedioPrazo"){
			ofstream arquivoMedioPrazo("MedioPrazo.txt", ios::app);

			if(arquivoMedioPrazo.is_open()){

				cout << "\nDigite o horario da sua tarefa(hh:mm):";
				cin >> horario;
				cout << "\nDigite a data da sua tarefa(dd/MM/aaaa)";
				cin >> data;

				MedioPrazo medioPrazo = MedioPrazo(tarefa.getNome(), tarefa.getDescricao(), tarefa.getTipo(), horario, data);

				arquivoMedioPrazo << "{Nome: " << medioPrazo.getNome() << endl;;
				arquivoMedioPrazo << "Descrição: " << medioPrazo.getDescricao() << endl;
				arquivoMedioPrazo << "Tipo: " << medioPrazo.getTipo() << endl;
				arquivoMedioPrazo << "Horario: " << medioPrazo.getHorario() << endl;
				arquivoMedioPrazo << "Data: " << medioPrazo.getData() << "}\n" << endl;
				arquivoMedioPrazo.close();

			}
		}

		else{
			if(condicao == "LongoPrazo"){
			ofstream arquivoLongoPrazo("LongoPrazo.txt", ios::app);

				if(arquivoLongoPrazo.is_open()){

					cout << "\nDigite a data da sua tarefa(dd/MM/aaaa)";
					cin >> data;

					LongoPrazo longoPrazo = LongoPrazo(tarefa.getNome(), tarefa.getDescricao(), tarefa.getTipo(), data);

					arquivoLongoPrazo << "{Nome: " << longoPrazo.getNome() << endl;
					arquivoLongoPrazo << "Descrição: " << longoPrazo.getDescricao() << endl;
					arquivoLongoPrazo << "Tipo: " << longoPrazo.getTipo() << endl;
					arquivoLongoPrazo << "Data: " << longoPrazo.getData() << "}\n" << endl;
					arquivoLongoPrazo.close();

				}
			}
		}
	}
}

string Repositorio::read(){
	string aux, busca;
	cout << "\nDigite o nome da tarefa para buscar no banco de dados!" << endl;
	cin >> busca;

    busca = "{Nome: " + busca;
	
	ifstream arquivoCurtoPrazo("CurtoPrazo.txt");
    ifstream arquivoMedioPrazo("MedioPrazo.txt");
    ifstream arquivoLongoPrazo("LongoPrazo.txt");

	if (arquivoCurtoPrazo){

		while(getline(arquivoCurtoPrazo, aux)){
            if(busca == aux){
                return "Tarefa existe!";
            }
		}
	}else{

        if(arquivoMedioPrazo){
            while(getline(arquivoMedioPrazo, aux)){
                if(busca == aux){
                    return "Tarefa existe!";
                }
		    }
        }else{
			
			if(arquivoLongoPrazo){
				while(getline(arquivoLongoPrazo, aux)){
					if(busca == aux){
						return "Tarefa existe!";
					}
            	}
			} 
        }
    }
	return "Tarefa inexistente";
}

void Repositorio::update(Tarefa tarefaParaAtualizar, Tarefa novaTarefa){
	string aux, atualizar = tarefaParaAtualizar.getNome();

	atualizar = "{Nome: " + atualizar;

	if (tarefaParaAtualizar.getTipo() == "CurtoPrazo"){
		ifstream arquivosCurtoPrazo("CurtoPrazo.txt");
		ofstream arquivonCurtoPrazo("CurtoPrazo.txt");
		if(arquivosCurtoPrazo && arquivonCurtoPrazo){
			while(arquivosCurtoPrazo >> aux){
				if(aux == atualizar){
					arquivonCurtoPrazo << "{Nome: " << novaTarefa.getNome() << endl;
					arquivonCurtoPrazo << "Descrição: " << novaTarefa.getDescricao() << endl;
					arquivonCurtoPrazo << "Tipo: " << novaTarefa.getTipo() << endl;
					arquivonCurtoPrazo << "Horario: " << novaTarefa.getNome() << "}\n" << endl;
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
void Repositorio::deleteTarefa(Tarefa tarefa){
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