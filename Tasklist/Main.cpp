#include <iostream>
#include <string>
#include <fstream>

#include "CurtoPrazo.h"
#include "Repositorio.h"

using namespace std;

int main(){
	int condicao;
	string sair = "n";
		
	Repositorio repositorio = Repositorio("");

	cout << "--------------------Task List--------------------" << endl;
	
	while(sair != "s"){
		cout << "Digite o número da opção que você fazer:" << endl;
		cout << "1- Criar tarefa." << endl;
		cout << "2- Buscar tarefa." << endl;
		//cout << "3- Atualizar tarefa." << endl;
		cout << "4- Deletar tarefa." << endl;
		//cout << "5- Imprimir todas as tarefas." << endl;
		cout << "0- Sair do programa." << endl;

		cin >> condicao;

		switch (condicao){
			case 1:
				cout << repositorio.create() << endl;
				break;

			case 2:
				cout << repositorio.read() << endl;
				break;

			case 4:
				cout << repositorio.deleteTarefa() << endl;
				break;

			case 0:
				cout << "\nObrigado por usar o programa. ^^\n" << endl;
				sair = "s";
				break;

			default:
				cout << "\nOpção invalida! Digite novamente;\n" << endl;
				break;
		}
	}
	return 0;
}
