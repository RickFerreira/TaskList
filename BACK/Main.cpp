#include <iostream>
#include <string>
#include <fstream>

#include "Repositorio.h"

using namespace std;

int main(){
	int condicao;
	string sair = "n", buscar, atualizar, deletar;
		
	Repositorio repositorio = Repositorio();

	//menu de opções que o usuário queira fazer
	cout << "\n\n--------------------Task List--------------------" << endl;
	
	while(sair != "s"){
		cout << "Digite o número da opção que você fazer:" << endl;
		cout << "1- Criar tarefa." << endl;
		cout << "2- Buscar tarefa." << endl;
		cout << "3- Atualizar tarefa." << endl;
		cout << "4- Deletar tarefa." << endl;
		cout << "5- Imprimir todas as tarefas." << endl;
		cout << "6- Imprimir as tarefas por filtro tipo." << endl;
		cout << "0- Sair do programa." << endl;

		cin >> condicao;

		switch (condicao){
			//case 1 para chamar o método da classe repositório de criação de tarefas
			case 1:
				cout << repositorio.create() << endl;
				break;
			
			//case 2 para chamar o método da classe repositório de buscar por nome a tarefa se ela existe ou não
			case 2:
				cout << "\nDigite o nome da tarefa para verificar se ela existe. (Obs. digite o nome da tarefa corretamente!): ";
				cin.ignore();
				getline(cin, buscar);

				cout << repositorio.read(buscar) << endl;
				break;

			//case 3 para chamar o método da classe repositório de atualização de tarefa
			case 3:
				cout << "\nDigite o nome da tarefa para atualizar. (Obs. digite o nome da tarefa corretamente!): ";
				cin.ignore();
				getline(cin, atualizar);

				cout << repositorio.update(atualizar) << endl;
				break;
			
			//case 4 para chamar o método da classe repositório de deletar uma tarefa por nome
			case 4:
				cout << "\nDigite o nome da tarefa para deletar. (Obs. digite o nome da tarefa corretamente!): ";
				cin.ignore();
				getline(cin, deletar);

				cout << repositorio.deleteTarefa(deletar) << endl;
				break;

			//case 5 para chamar o método da classe repositório de imprimir todas as tarefas que existe
			case 5:
				repositorio.imprimirTarefas();

				break;
			
			//case 6 para chamar o método da classe repositório de imprimir todas as tarefas por prazo
			case 6:
				repositorio.imprimirPorTipo();

				break;

			//case 0 para sair do programa 
			case 0:
				cout << "\nObrigado por usar o programa. ^^\n" << endl;
				sair = "s";
				break;

			//default para caso o usuário digite opção inválida
			default:
				cout << "\nOpção invalida! Digite novamente:\n" << endl;
				break;
		}
	}
	return 0;
}
