#include <iostream>
#include <string>

#include "CurtoPrazo.h"
#include "Repositorio.h"

using namespace std;

int main(){
	int condicao, tipoCondicao;
	string sair = "n";

	string nomeTarefa, descricao, tipo, tempoLimite, busca;

	Tarefa tarefa = Tarefa("", "", "");
	Repositorio repositorio = Repositorio("");

	cout << "--------------------Task List--------------------" << endl;

	while(sair != "s"){
		cout << "Digite o número da opção que você fazer:" << endl;
		cout << "1- Criar tarefa curto prazo." << endl;
		cout << "2- Buscar tarefa." << endl;
		cout << "3- Atualizar tarefa." << endl;
		cout << "4- Deletar tarefa." << endl;
		cout << "5- Imprimir todas as tarefas." << endl;
		cout << "0- Sair do programa." << endl;

		cin >> condicao;

		switch (condicao){
			case 1:
				cout << "\nDigite o nome da sua tarefa: ";
				cin >> nomeTarefa;

				cout << "\nDigite a descrição da sua tarefa: ";
				cin >> descricao;

				cout << "\nDigite o tempo limite da sua tarefa(hh:mm): ";
				cin >> tempoLimite;

				cout << "\nDigite:" << endl;
				cout << "1- Curto prazo" << endl;
				cout << "2- Médio prazo" << endl;
				cout << "3- Longo prazo" << endl;
				cin >> tipoCondicao;
				if(tipoCondicao == 1){
					tipo = "CurtoPrazo";
				}else{
					if(tipoCondicao == 2){
						tipo = "MedioPrazo";
					}else{
						tipo = "LongoPrazo";
					}
				}
				tarefa.setNome(nomeTarefa);
				tarefa.setDescricao(descricao);
				tarefa.setTipo(tipo);
				repositorio.setTempoPrazo(tempoLimite);

				repositorio.create(tarefa);
				cout << "\nTarefa adicionada com sucesso!" << endl;
				break;

			case 2:				
				repositorio.read();
				break;

            case 3:
                

			case 0:
				cout << "\nObrigado por usar o programa. ^^" << endl;
				sair = "s";
				break;

			default:
				cout << "\nOpção invalida! Digite novamente;" << endl;
				break;
		}
	}
	return 0;
}

