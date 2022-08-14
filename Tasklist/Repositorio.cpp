#include "Repositorio.h"

#include <fstream>
#include <string.h>

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

string Repositorio::create(){
	string nomeTarefa, descricao, tipo, horario, data;
	int tipoCondicao;

	ofstream arquivo("Tarefa.txt", ios::app);
	cin.ignore();
	cout << "\nDigite o nome da sua tarefa: ";
	
	getline(cin, nomeTarefa);

	cout << "\nDigite a descrição da sua tarefa: ";
	getline(cin, descricao);
	
	cout << "\nDigite:" << endl;
	cout << "1- Curto prazo" << endl;
	cout << "2- Médio prazo" << endl;
	cout << "3- Longo prazo" << endl;
	cin >> tipoCondicao;

	if(tipoCondicao == 1){
		tipo = "Curto Prazo";
	}else{
		if(tipoCondicao == 2){
			tipo = "Medio Prazo";
		}else{
			tipo = "Longo Prazo";
		}
	}

	if(tipo == "Curto Prazo"){
		if(arquivo.is_open()){

			cin.ignore();
			cout << "\nDigite o horario da sua tarefa(hh:mm): ";
			getline(cin, horario);

			CurtoPrazo curtoPrazo = CurtoPrazo(nomeTarefa, descricao, tipo, horario);

			arquivo << "{\"Nome\": \"" <<  curtoPrazo.getNome() << "\"," << endl;
			arquivo << "\"Descrição\": \"" << curtoPrazo.getDescricao() << "\"," << endl;
			arquivo << "\"Tipo\": \"" << curtoPrazo.getTipo() << "\"," << endl;
			arquivo << "\"Horario: \"" << curtoPrazo.getHorario() << "\"}\n" << endl;
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

			arquivo << "{\"Nome\": \"" <<  medioPrazo.getNome() << "\"," << endl;
			arquivo << "\"Descrição\": \"" << medioPrazo.getDescricao() << "\"," << endl;
			arquivo << "\"Tipo\": \"" << medioPrazo.getTipo() << "\"," << endl;
			arquivo << "\"Horario\": \"" << medioPrazo.getHorario() << "\",";
			arquivo << " \"Data: \"" << medioPrazo.getData() << "\"}\n" << endl;
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

			arquivo << "{\"Nome\": \"" <<  longoPrazo.getNome() << "\"," << endl;
			arquivo << "\"Descrição\": \"" << longoPrazo.getDescricao() << "\"," << endl;
			arquivo << "\"Tipo\": \"" << longoPrazo.getTipo() << "\"," << endl;
			arquivo << "\"Data: \"" << longoPrazo.getData() << "\"}\n" << endl;
			arquivo.close();
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	return "\nTarefa não foi adicionada!\n";
}

string Repositorio::read(string buscar){
	string aux;

	ifstream arquivoIn("Tarefa.txt");

	string buscarFormatado = "{\"Nome\": \"" + buscar + "\",";
	
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
	cout << saida.length() << endl;
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

	string deletarFormatado = "{\"Nome\": \"" + deletar + "\",";
	
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