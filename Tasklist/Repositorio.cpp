#include "Repositorio.h"

#include <fstream>
#include <string.h>

#include "CurtoPrazo.h"
#include "MedioPrazo.h"
#include "LongoPrazo.h"

using namespace std;

//CONSTRUCTOR
Repositorio::Repositorio(){
	
}

//METHODS

string Repositorio::create(){
	string nomeTarefa, descricao, tipo, horario, data;
	int tipoCondicao, laco = 1;

	ofstream arquivo("Tarefa.txt", ios::app);
	cin.ignore();
	cout << "\nDigite o nome da sua tarefa: ";
	
	getline(cin, nomeTarefa);

	cout << "\nDigite a descrição da sua tarefa: ";
	getline(cin, descricao);
	
	while(laco == 1){
		cout << "\nDigite:" << endl;
		cout << "1- Curto prazo" << endl;
		cout << "2- Médio prazo" << endl;
		cout << "3- Longo prazo" << endl;
		cin >> tipoCondicao;

		switch (tipoCondicao)
		{
			case 1:
				tipo = "Curto Prazo";
				laco = 0;
				break;
			
			case 2:
				tipo = "Medio Prazo";
				laco = 0;
				break;

			case 3:
				tipo = "Longo Prazo";
				laco = 0;
				break;

			default:
				cout << "\nOpção invalida! Digite novamente:\n" << endl;
				break;
		}
	}

	if(tipo == "Curto Prazo"){
		if(arquivo.is_open()){

			cin.ignore();
			cout << "\nDigite o horario da sua tarefa(hh:mm): ";
			getline(cin, horario);

			CurtoPrazo curtoPrazo = CurtoPrazo(nomeTarefa, descricao, tipo, horario);

			arquivo << "Nome: " <<  curtoPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << curtoPrazo.getDescricao() << "," << endl;
			arquivo << "Horario: " << curtoPrazo.getHorario() << "," << endl;
			arquivo << "Tipo: " << curtoPrazo.getTipo() << ".\n" << endl;
			arquivo.close();
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	if(tipo == "Medio Prazo"){
		if(arquivo.is_open()){
			cin.ignore();
			cout << "\nDigite o horario da sua tarefa(hh:mm): ";
			getline(cin, horario);
			cout << "\nDigite a data da sua tarefa(dd/mm/aaaa): ";
			getline(cin, data);

			MedioPrazo medioPrazo = MedioPrazo(nomeTarefa, descricao, tipo, horario, data);

			arquivo << "Nome: " <<  medioPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << medioPrazo.getDescricao() << "," << endl;
			arquivo << "Horario: " << medioPrazo.getHorario() << ",";
			arquivo << " Data: " << medioPrazo.getData() << "," << endl;
			arquivo << "Tipo: " << medioPrazo.getTipo() << ".\n" << endl;
			arquivo.close();
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	if(tipo == "Longo Prazo"){
		if(arquivo.is_open()){
			cin.ignore();
			cout << "\nDigite a data da sua tarefa(dd/mm/aaaa): ";
			getline(cin, data);

			LongoPrazo longoPrazo = LongoPrazo(nomeTarefa, descricao, tipo, data);

			arquivo << "Nome: " <<  longoPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << longoPrazo.getDescricao() << "," << endl;
			arquivo << "Data: " << longoPrazo.getData() << "," << endl;
			arquivo << "Tipo: " << longoPrazo.getTipo() << ".\n" << endl;
			arquivo.close();
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	return "\nTarefa não foi adicionada!\n";
}

string Repositorio::read(string buscar){
	string aux;

	ifstream arquivoIn("Tarefa.txt");

	string buscarFormatado = "Nome: " + buscar + ",";
	
	if(arquivoIn){
		while(getline(arquivoIn, aux)){
			if(aux == buscarFormatado){
				return "\nTarefa \"" + buscar + "\" existe!\n";
			}
		}
	}
	return "\nTarefa \"" + buscar + "\" não existe!\nVerifique se escreveu o nome da tarefa correto, utilizando a opção 5 do menu principal!\n";
}

string Repositorio::update(string atualizar){
	string saida = this->deleteTarefa(atualizar);

	if(saida.length() < 40){
		cout << "\nAperte enter!\n" << endl;
		this->create();
		return "\nTarefa \"" + atualizar + "\" atualizada com sucesso!\n";
	}

	return "\nTarefa \"" + atualizar + "\" não foi atualizada!\n";
}

string Repositorio::deleteTarefa(string deletar){
	string aux;
	
	int condicao = 0;

	ifstream arquivoIn("Tarefa.txt");

	ofstream auxArquivo("aux.txt", ios::app);	

	string deletarFormatado = "Nome: " + deletar + ",";
	
	while(getline(arquivoIn, aux)){
		if(aux == deletarFormatado){
			condicao = 1;
			break;
		}
		else{
			auxArquivo << aux << endl;
		}
	}
	if(condicao == 1){
		for(int i = 0; i < 4; i++){
			getline(arquivoIn, aux);
		}
	}

	while(getline(arquivoIn, aux)){
		auxArquivo << aux << endl;
	}

	rename("aux.txt", "Tarefa.txt");

	if(condicao == 0){
		return "\nTarefa \"" + deletar + "\" não existe!\nVerifique se escreveu o nome da tarefa correto, utilizando a opção 5 do menu principal!\n";
	}

	
	return "\nTarefa \"" + deletar + "\" apagado com sucesso!\n";
}

void Repositorio::imprimirTarefas(){
	string aux;
	int contador = 0;

	ifstream arquivoIn("Tarefa.txt");
	
	cout << endl;

	if(arquivoIn){
		while(getline(arquivoIn, aux)){
			cout << aux << endl;
			contador++;
		}
	}
	if(contador < 4){
		cout << "Nenhuma tarefa existente!\n" << endl;
	}
}

void Repositorio::imprimirPorTipo(){
	string aux, lista[4] = {"", "", "", ""}, tipo, tipoFormatado;
	int laco = 1, tipoCondicao, contador = 0;

	ifstream arquivoIn("Tarefa.txt");

	while(laco == 1){
		cout << "\nDigite:" << endl;
		cout << "1- Curto prazo" << endl;
		cout << "2- Médio prazo" << endl;
		cout << "3- Longo prazo" << endl;
		cin >> tipoCondicao;

		switch (tipoCondicao)
		{
			case 1:
				tipo = "Curto Prazo";
				laco = 0;
				break;
			
			case 2:
				tipo = "Medio Prazo";
				laco = 0;
				break;

			case 3:
				tipo = "Longo Prazo";
				laco = 0;
				break;

			default:
				cout << "\nOpção invalida! Digite novamente:\n" << endl;
				break;
		}
	}

	tipoFormatado = "Tipo: " + tipo + ".";
	
	cout << endl;

	if(arquivoIn){
		while(! arquivoIn.eof()){
			for(int i = 0; i < 4; i++){
				getline(arquivoIn, aux);
				lista[i] = aux;

				if(aux == tipoFormatado){
					cout << lista[0] << endl;
					cout << lista[1] << endl;
					cout << lista[2] << endl;
					cout << lista[3] << endl;
					cout << endl;
					contador++;
					break;
				}
			}
		}
		if(contador == 0){
			cout << "Não existe nenhuma tarefa do tipo \"" << tipo << "\"\n" << endl;
		}
	}
}