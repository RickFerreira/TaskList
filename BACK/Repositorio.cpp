#include "Repositorio.h"

//inclusão da biblioteca fstream para manipulação de arquivos
#include <fstream>
#include <string.h>

//relacionamento com as classes...
#include "CurtoPrazo.h"
#include "MedioPrazo.h"
#include "LongoPrazo.h"

using namespace std;

//CONSTRUCTOR
Repositorio::Repositorio(){
	
}

//METHODS

//método de criação de tarefa
string Repositorio::create(){
	string nomeTarefa, descricao, tipo, horario, data;
	int tipoCondicao, laco = 1;

	//chamada para criar ou atribuir o arquivo txt para adicionar no final strings
	ofstream arquivo("Tarefa.txt", ios::app);
	
	cin.ignore();
	cout << "\nDigite o nome da sua tarefa: ";
	getline(cin, nomeTarefa);

	cout << "\nDigite a descrição da sua tarefa: ";
	getline(cin, descricao);
	
	//opções que o usuário pode escolher para o tipo de prazo
	while(laco == 1){
		cout << "\nDigite:" << endl;
		cout << "1- Curto prazo" << endl;
		cout << "2- Médio prazo" << endl;
		cout << "3- Longo prazo" << endl;
		cin >> tipoCondicao;

		switch (tipoCondicao)
		{
			//case 1 para curto prazo
			case 1:
				tipo = "Curto Prazo";
				laco = 0;
				break;
			
			//case 2 para médio prazo
			case 2:
				tipo = "Medio Prazo";
				laco = 0;
				break;

			//case 4 para longo prazo
			case 3:
				tipo = "Longo Prazo";
				laco = 0;
				break;

			//default caso o usuário escolha uma opção inválida
			default:
				cout << "\nOpção invalida! Digite novamente:\n" << endl;
				break;
		}
	}

	//condição para caso o usuário escolha curto prazo
	if(tipo == "Curto Prazo"){
		//condição para verificar se o arquivo está aberto
		if(arquivo.is_open()){

			cin.ignore();
			cout << "\nDigite o horario da sua tarefa(hh:mm): ";
			getline(cin, horario);

			//criação de objeto curtoPrazo com o nome da tarefa, descrição, tipo e horário
			CurtoPrazo curtoPrazo = CurtoPrazo(nomeTarefa, descricao, tipo, horario);
			
			//formatação para adicionar no arquivo txt
			arquivo << "Nome: " <<  curtoPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << curtoPrazo.getDescricao() << "," << endl;
			arquivo << "Horario: " << curtoPrazo.getHorario() << "," << endl;
			arquivo << "Tipo: " << curtoPrazo.getTipo() << ".\n" << endl;

			//fechando o arquivo para não ter problemas de arquivo corrompido
			arquivo.close();

			//mensagem de retorno para o usuário saber que foi adicionada tarefa
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	//condição para caso o usuário escolha médio prazo
	if(tipo == "Medio Prazo"){
		//condição para verificar se o arquivo está aberto
		if(arquivo.is_open()){

			cin.ignore();
			cout << "\nDigite o horario da sua tarefa(hh:mm): ";
			getline(cin, horario);

			cout << "\nDigite a data da sua tarefa(dd/mm/aaaa): ";
			getline(cin, data);

			//criação de objeto medioPrazo com o nome da tarefa, descrição, tipo, horário e data
			MedioPrazo medioPrazo = MedioPrazo(nomeTarefa, descricao, tipo, horario, data);

			//formatação para adicionar no arquivo txt
			arquivo << "Nome: " <<  medioPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << medioPrazo.getDescricao() << "," << endl;
			arquivo << "Horario: " << medioPrazo.getHorario() << ",";
			arquivo << " Data: " << medioPrazo.getData() << "," << endl;
			arquivo << "Tipo: " << medioPrazo.getTipo() << ".\n" << endl;

			//fechando o arquivo para não ter problemas de arquivo corrompido
			arquivo.close();
			
			//mensagem de retorno para o usuário saber que foi adicionada tarefa
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	//condição para caso o usuário escolha longo prazo
	if(tipo == "Longo Prazo"){
		//condição para verificar se o arquivo está aberto
		if(arquivo.is_open()){

			cin.ignore();
			cout << "\nDigite a data da sua tarefa(dd/mm/aaaa): ";
			getline(cin, data);

			//criação de objeto longoPrazo com o nome da tarefa, descrição, tipo e data
			LongoPrazo longoPrazo = LongoPrazo(nomeTarefa, descricao, tipo, data);

			arquivo << "Nome: " <<  longoPrazo.getNome() << "," << endl;
			arquivo << "Descrição: " << longoPrazo.getDescricao() << "," << endl;
			arquivo << "Data: " << longoPrazo.getData() << "," << endl;
			arquivo << "Tipo: " << longoPrazo.getTipo() << ".\n" << endl;

			//fechando o arquivo para não ter problemas de arquivo corrompido
			arquivo.close();

			//mensagem de retorno para o usuário saber que foi adicionada tarefa
			return "\nTarefa \"" + nomeTarefa + "\" adicionada com sucesso!\n";
		}
	}
	//mensagem de retorno para o usuário caso tarefa não for adicionada adicionada tarefa
	return "\nTarefa não foi adicionada!\n";
}

//método para buscar por nome uma tarefa e se ela existe ou não
string Repositorio::read(string buscar){
	string aux;

	//chamada para atribuir na variável o arquivo txt para dar input
	ifstream arquivoIn("Tarefa.txt");

	//variável para buscar o nome do jeito que foi formatado na criação da tarefa
	string buscarFormatado = "Nome: " + buscar + ",";
	
	//condição para saber se o arquivo está aberto
	if(arquivoIn){

		//laço de repetição para atribuir cada linha do arquivo txt para variável aux
		while(getline(arquivoIn, aux)){

			//condição para comparar a linha com o que o usuário está procurando
			//caso seja igual retorna a própria linha e as seguintes da tarefa
			if(aux == buscarFormatado){
				cout << "\n" << aux << endl;
				for(int i = 0; i < 3; i++){
					getline(arquivoIn, aux);
					cout <<  aux << endl;
				}
				//retornando mensagem para informar que a tarefa existe
				return "\nTarefa \"" + buscar + "\" existe!\n";
			}
		}
	}
	//retornando mensagem para informar que a tarefa não existe
	return "\nTarefa \"" + buscar + "\" não existe!\nVerifique se escreveu o nome da tarefa correto, utilizando a opção 5 do menu principal!\n";
}

//método para atualizar alguma tarefa
string Repositorio::update(string atualizar){
	//atribuindo a variável a mensagem de retorna do método deleteTarefa e deletando 
	//a tarefa caso exista
	string saida = this->deleteTarefa(atualizar);

	//condição para saber se a mensagem é de existencia da tarefa ou não
	//caso exista é chamado o método de criação de nova tarefa
	if(saida.length() < 40){
		cout << "\nAperte enter!\n" << endl;
		this->create();

		//retornando mensagem informando que atualizou tarefa
		return "\nTarefa \"" + atualizar + "\" atualizada com sucesso!\n";
	}

	//retornando mensagem informando que não atualizou tarefa
	return "\nTarefa \"" + atualizar + "\" não foi atualizada!\n";
}

//método para deletar alguma tarefa
string Repositorio::deleteTarefa(string deletar){
	string aux;
	
	int condicao = 0;
	
	//chamada para atribuir na variável o arquivo txt para dar input
	ifstream arquivoIn("Tarefa.txt");

	//chamada para criar ou atribuir o arquivo txt para adicionar no final strings
	ofstream auxArquivo("aux.txt", ios::app);	

	//variável para buscar o nome do jeito que foi formatado na criação da tarefa
	string deletarFormatado = "Nome: " + deletar + ",";
	
	//laço de repetição para atribuir cada linha do arquivo txt para variável aux
	while(getline(arquivoIn, aux)){
		//condição para comparar a linha com o que o usuário está procurando
		//caso for igual atribui 1 a variável condicao e o laço é quebrado
		//caso não seja igual é atribuído a linha que estava no arquivo ao arquivo auxiliar
		if(aux == deletarFormatado){
			condicao = 1;
			break;
		}
		else{
			auxArquivo << aux << endl;
		}
	}

	if(condicao == 1){
		//laço para as próximas linhas do arquivo que faz parte da tarefa que vai ser deletada
		//passe e não seja salvos no arquivo auxiliar
		for(int i = 0; i < 4; i++){
			getline(arquivoIn, aux);
		}
	}
	//laço para continuar na linha seguinte e adicionar ao arquivo as outras tarefas que não
	//é pra apagar
	while(getline(arquivoIn, aux)){
		auxArquivo << aux << endl;
	}

	//renomeando o nome do arquivo auxiliar que está sem a tarefa que o usuário queria apagar
	//para o nome do arquivo principal e substituir
	rename("aux.txt", "Tarefa.txt");

	//condição para retornar uma mensagem informando que a tarefa não existe
	if(condicao == 0){
		return "\nTarefa \"" + deletar + "\" não existe!\nVerifique se escreveu o nome da tarefa correto, utilizando a opção 5 do menu principal!\n";
	}

	//condição para retornar uma mensagem informando que a tarefa foi apagada
	return "\nTarefa \"" + deletar + "\" apagado com sucesso!\n";
}

//método para imprimir todas as tarefas
void Repositorio::imprimirTarefas(){
	string aux;
	int contador = 0;

	//chamada para atribuir na variável o arquivo txt para dar input
	ifstream arquivoIn("Tarefa.txt");
	
	cout << endl;

	//condição para saber se o arquivo está aberto
	if(arquivoIn){
		//laço de repetição para atribuir cada linha do arquivo txt para variável aux
		while(getline(arquivoIn, aux)){
			cout << aux << endl;
			contador++;
		}
	}
	//condição caso não exista nenhuma tarefa
	if(contador < 4){
		cout << "Nenhuma tarefa existente!\n" << endl;
	}
}

//método para imprimir pelo tipo de prazo
void Repositorio::imprimirPorTipo(){
	string aux, lista[4] = {"", "", "", ""}, tipo, tipoFormatado;
	int laco = 1, tipoCondicao, contador = 0;

	//chamada para atribuir na variável o arquivo txt para dar input
	ifstream arquivoIn("Tarefa.txt");

	//opções que o usuário pode escolher para o tipo de prazo
	while(laco == 1){
		cout << "\nDigite:" << endl;
		cout << "1- Curto prazo" << endl;
		cout << "2- Médio prazo" << endl;
		cout << "3- Longo prazo" << endl;
		cin >> tipoCondicao;

		switch (tipoCondicao)
		{
			//case 1 para curto prazo
			case 1:
				tipo = "Curto Prazo";
				laco = 0;
				break;
			
			//case 2 para médio prazo
			case 2:
				tipo = "Medio Prazo";
				laco = 0;
				break;

			//case 3 para longo prazo
			case 3:
				tipo = "Longo Prazo";
				laco = 0;
				break;

			//default caso o usuário escolha uma opção inválida
			default:
				cout << "\nOpção invalida! Digite novamente:\n" << endl;
				break;
		}
	}

	//variável para buscar o tipo de prazo do jeito que foi formatado na criação da tarefa
	tipoFormatado = "Tipo: " + tipo + ".";
	
	cout << endl;

	//condição para saber se o arquivo está aberto
	if(arquivoIn){
		//laço que vai se repetir até que o arquivo chegue no ultimo item
		while(! arquivoIn.eof()){
			//laço que adiciona na lista os itens da tarefa
			//caso o última linha da tarefa que é o tipo seja igual ao prazo correto 
			//o programa imprime a tarefa e quebra o laço voltando aonde parou
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
		
		//caso não existir nenhuma tarefa do prazo que o usuário escolheu
		if(contador == 0){
			cout << "Não existe nenhuma tarefa do tipo \"" << tipo << "\"\n" << endl;
		}
	}
}