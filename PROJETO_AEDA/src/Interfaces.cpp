#include "Includes.h"
#include "Sistema.h"
#include "Utente.h"
#include "Exceções.h"

void registo_utente(Sistema & BS);
void menu_interface(Sistema &BS);
void admin_interface(Sistema &BS);
vector<int> ExtraData(Sistema &ER,int index);


void alugaBike(Sistema &ER,int index,vector<int> distancias) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;


	if(ER.getUtentes().at(index)->getAvailable() == false)
	{
		cout << "Não é possível alugar duas bicicletas em simultãneo !"  << endl << endl;

		system("pause");
		system("cls");
		return;

	}
	else
	{
		cout << "Aluga Biciclea: " << endl << endl;

		//string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano)

		string bikeType;
		Data d1;
		int numHours{};
		int value {};
		string option {};

		cout << "Tipos de bicicleta: " << endl;
		cout << "     1 - Urbana" << endl;
		cout << "     2 - Urbana Simples" << endl;
		cout << "     3 - Corrida" << endl;
		cout << "     4 - Infantil" << endl << endl;


		while(1)
		{
			try{
				cout << endl << "Introduza uma opcao (1-4): ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 4)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		if(value == 1)
			bikeType = "Urbana";
		else if(value == 2)
			bikeType = "Urbana Simples";
		else if(value == 3)
			bikeType = "Corrida";
		else
			bikeType = "Infantil";


		while(1)
		{
			try{
				cout << endl << "Número de horas: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 24)
					throw OpcaoInvalida<int>(value);

				numHours = value;
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		while(1)
		{
			try{
				cout << endl << "Ano: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 2017)
					throw OpcaoInvalida<int>(value);

				d1.setAno(value);
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		while(1)
		{
			try{
				cout << endl << "Mes[1-12]: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 12)
					throw OpcaoInvalida<int>(value);

				d1.setMes(value);
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		while(1)
		{
			try{
				cout << endl << "Dia: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(d1.getMes() == 2)
				{
					if(value < 1 || value > 28)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
				else if((d1.getMes() == 1) ||(d1.getMes() == 3) ||(d1.getMes() == 5) ||(d1.getMes() == 7) ||(d1.getMes() == 8) ||(d1.getMes() == 10) ||(d1.getMes() == 12))
				{
					if(value < 1 || value > 31)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
				else
				{
					if(value < 1 || value > 30)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		int idPP {-1};
		vector<string> bikesType;

		//Verifica se tem o tipo de bicleta pretendida por ordem de distancia
		for (unsigned int i=0 ; i < distancias.size(); i++){
			bikesType = ER.getPontosPartilha().at(distancias.at(i))->getBikeTypes();

			for (unsigned int k = 0; k < bikesType.size(); k++){
				if(bikesType.at(k)== bikeType){
					idPP=distancias.at(i);
					break;
				}
			}
		}

		if(idPP == -1)
		{
			cout << endl << "Neste momento não existe nenhuma bicicleta do tipo " << bikeType << " disponivel." << endl << endl;
		}
		else
		{

			if(bikeType == "Urbana")
				ER.getUtentes().at(index)->setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(0).at(0));
			else if(bikeType == "Urbana Simples")
				ER.getUtentes().at(index)->setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(1).at(0));
			else if(bikeType == "Corrida")
				ER.getUtentes().at(index)->setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(2).at(0));
			else
				ER.getUtentes().at(index)->setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(3).at(0));

			ER.getUtentes().at(index)->setAvailable();

			ER.getPontosPartilha().at(idPP)->removeBike(ER.getUtentes().at(index)->getBike());

			if(ER.getUtentes().at(index)->getTipoUtente() == "Socio")
			{
				Utilizacao p(bikeType, numHours, d1);
				ER.getUtentes().at(index)->setUtilizacoes(p);

			}
			else {
				/* Apresenta o preço do aluguer */

				if(bikeType == "Urbana")
					cout << "Total a pagar : " << numHours*4 << "€" << endl;
				else if(bikeType == "Urbana Simples")
					cout << "Total a pagar : " << numHours*3 << "€" << endl;
				else if(bikeType == "Corrida")
					cout << "Total a pagar : " << numHours*5 << "€" << endl;
				else //bikeType == "Infantil"
					cout << "Total a pagar : " << numHours*2 << "€" << endl;

				ER.getUtentes().at(index)->setHistoric(Utilizacao(bikeType, numHours, d1));
			}

			cout << endl << "Bicicleta alugada com sucesso !" << endl << endl;
		}

		system("pause");
		system("cls");
		return;
	}
}

void devolveBike(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	if(ER.getUtentes().at(index)->getAvailable() == true)
	{
		cout << "Neste momento o utente não tem nenhuma bicicleta para entregar" << endl << endl;
	}
	else if(ER.getUtentes().at(index)->getTipoUtente() == "Socio")
	{
		cout << "Devolve bicicleta: " << endl << endl;

		Utilizacao ut = ER.getUtentes().at(index)->getUtilizacoes().at(ER.getUtentes().at(index)->getUtilizacoes().size() - 1);

		cout << "Tipo de bicicleta: " << ut.getBikeType() << endl;
		cout << "Número de horas: " << ut.getUseTime() << endl;
		cout << "Data (dd/mm/aaaa): " << ut.getData() << endl;

		ER.getUtentes().at(index)->setAvailable();

		cout << endl << "Bicicleta devolvida com sucesso !" << endl << endl;
	}
	else
	{
		cout << "Devolve bicicleta: " << endl << endl;

		Utilizacao ut = ER.getUtentes().at(index)->getHistorico().at(ER.getUtentes().at(index)->getHistorico().size() - 1);

		cout << "Tipo de bicicleta: " << ut.getBikeType() << endl;
		cout << "Número de horas: " << ut.getUseTime() << endl;
		cout << "Data (dd/mm/aaaa): " << ut.getData() << endl;

		ER.getUtentes().at(index)->setAvailable();

		cout << endl << "Bicicleta devolvida com sucesso !" << endl << endl;
	}
	system("pause");
	system("cls");
	return;

}

int ExistID(Sistema & sys, int identificacao) {

	for(unsigned int i = 0; i < sys.getUtentes().size() ; i++)
	{
		if(sys.getUtentes().at(i)->getId() == identificacao)
			return i;
	}

	return -1;
}

void displayPagPendentes(Sistema &ER,int index){

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Pagamentos pendentes:" << endl << endl;

	if(ER.getUtentes().at(index)->getTipoUtente() == "Regular")
	{
		cout << "Neste tipo de utente (Regular) não é possivel ter pagamentos pendentes !" << endl << endl;

		system("pause");
		system("cls");
		return;

	}
	else
	{
		if(ER.getUtentes().at(index)->getUtilizacoes().size() != 0)
		{
			for(unsigned int i = 0; i < ER.getUtentes().at(index)->getUtilizacoes().size(); i++)
			{
				cout << "Tipo de bicicleta: " << ER.getUtentes().at(index)->getUtilizacoes().at(i).getBikeType() << endl;
				cout << "Número de horas: " << ER.getUtentes().at(index)->getUtilizacoes().at(i).getUseTime() << endl;
				cout << "Data (dd/mm/aaaa): " << ER.getUtentes().at(index)->getUtilizacoes().at(i).getData() << endl << endl;




				/////////////////////////////////////////////////
				//FALTA CALCULAR O PRECO DAS UTILIZACOES !!!!
				/////////////////////////////////////////////////




			}
		}
		else
		{
			cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
		}

		system("pause");
		system("cls");
		return;
	}

}

void updateLocation(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Localizacao: " << endl << endl;

	cout << "Indique as suas cordenadas GPS:" << endl;

	string option;
	double coordX { }, coordY { };

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	Localizacao spot;
	spot.setX(coordX);
	spot.setY(coordY);

	ER.getUtentes().at(index)->setUtenteLocation(spot);

	cout << "O utente encontra-se agora num novo local de coordenadas (" << coordX << " , " << coordY << ")" << endl << endl;

	system("pause");
	system("cls");
	return;

}

void efetuaPag(Sistema &ER,int index) {

	////// Notas: /////////
	//   Onde guardar os pagamentos ja efetuados?   removes de utilizaçoes e colocas em historico
	//   Acrescentar perguntas sobre que meses quer pagar  		sim
	//////////////////////////



	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Pagamentos pendentes:" << endl << endl;

	unsigned int somaU=0, somaUS=0, somaC=0, somaI=0, preco=0;

	if(ER.getUtentes().at(index)->getTipoUtente() == "Regular")
	{
		cout << "O pagamento já foi feito na altura do aluguer!" << endl << endl;

		system("pause");
		system("cls");
		return;

	}
	else
	{
		if(ER.getUtentes().at(index)->getUtilizacoes().size() != 0)
		{
			for(unsigned int i = 0; i < ER.getUtentes().at(index)->getUtilizacoes().size(); i++)
			{
				if(ER.getUtentes().at(index)->getUtilizacoes().at(i).getBikeType() == "Urbana")
					somaU += ER.getUtentes().at(index)->getUtilizacoes().at(i).getUseTime();
				else if(ER.getUtentes().at(index)->getUtilizacoes().at(i).getBikeType() == "Urbana Simples")
					somaUS += ER.getUtentes().at(index)->getUtilizacoes().at(i).getUseTime();
				else if(ER.getUtentes().at(index)->getUtilizacoes().at(i).getBikeType() == "Corrida")
					somaC += ER.getUtentes().at(index)->getUtilizacoes().at(i).getUseTime();
				else	//Infantil
					somaI += ER.getUtentes().at(index)->getUtilizacoes().at(i).getUseTime();
			}

			preco = (somaU>0 ? 40 : 0) + (somaUS>0 ? 30 : 0) + (somaC>0 ? 50 : 0) + (somaI>0 ? 20 : 0);

			if(somaU+somaUS+somaC+somaI < 20)  //descontos
				preco = preco * 0.95;
			else
				preco = preco * 0.9;

			cout << "Pagamento de " << preco << "€" << "efetuado!" << endl;

		}
		else
		{
			cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
		}

		system("pause");
		system("cls");
		return;
	}
}

void NearestPP(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Pontos de partilha mais próximo: " << endl << endl;

	vector<double> distancias;

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		distancias.push_back(ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(i)->getLocal()));
	}

	sort(distancias.begin(),distancias.end());

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		for(unsigned int k = 0; k < ER.getPontosPartilha().size(); k++)
		{
			if(distancias.at(i) == ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(k)->getLocal()))
			{
				cout << (i+1) << " - " << ER.getPontosPartilha().at(k)->getLocal().getNome() << endl;
			}
		}
	}

	cout << endl;

	system("pause");
	system("cls");
	return;

}

void infoER(Sistema &ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Informações:" << endl << endl;

	cout << "Nome da empresa: ECO RIDES" << endl << endl;
	cout << "Numero total de pontos de Partilha: 9" << endl << endl;
	cout << "Pontos de Partilha:" << endl;
	cout << "     - ECO_RIDES_A" << endl;
	cout << "     - ECO_RIDES_B" << endl;
	cout << "     - ECO_RIDES_C" << endl;
	cout << "     - ECO_RIDES_D" << endl;
	cout << "     - ECO_RIDES_E" << endl;
	cout << "     - ECO_RIDES_F" << endl;
	cout << "     - ECO_RIDES_G" << endl;
	cout << "     - ECO_RIDES_H" << endl;
	cout << "     - ECO_RIDES_I" << endl << endl;
	cout << "Numero total de utentes registados: " << ER.getUtentes().size() << endl << endl;
	cout << "Founders: " << endl;
	cout << "  - Rui Guedes" << endl;
	cout << "  - César Pinho" << endl;
	cout << "  - Bernardo Santos" << endl << endl;

	system("pause");
	system("cls");
	return;

}

void addPP(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Adiciona Ponto Partilha:" << endl << endl;

	string nome,locname;
	int value {};
	string option {};
	bool cond {false};

	while(1)
	{
		try {
			cout << "Nome: " ;
			cin >> nome;
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				if(ER.getPontosPartilha().at(i)->getNome() == nome)
					cond = true;
			}

			if(cond == true)
				throw OpcaoInvalida<string>(nome);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			if(cond == true)
				cout << "Já existe esse nome (" << op.opcao << ") ! Tente novamente." << endl;
			else
				cout << "Nome inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cond = false;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	cout << endl << "Localizacao: " << endl << endl;

	while(1)
	{
		try {
			cout << "Nome: " ;
			cin >> locname;
			if(valid_word(locname) == false)
				throw OpcaoInvalida<string>(nome);
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	cout << "Indique as suas cordenadas GPS:" << endl;

	double coordX { }, coordY { };

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	Localizacao spot;
	spot.setNome(locname);
	spot.setX(coordX);
	spot.setY(coordY);

	while(1)
	{
		try{
			cout << endl << "Capacidade: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Capacidade inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	PontoPartilha* pp = new PontoPartilha(spot,value,nome);

	ER.addPontoPartilha(pp);

	cout << endl << "Novo ponto de partilha adicionado ao sistema" << endl << endl;

	system("pause");
	system("cls");
	return;
}

void removePP(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Remove Ponto Partilha:" << endl << endl;

	string nomePP;
	int indexPP {-1};

	if(ER.getPontosPartilha().size() == 0)
	{
		cout << "Neste momento não existem pontos de partilha !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	//Verifica ponto de partilha que quer remover
	while(1)
	{
		try {
			cout << "Nome do Ponto Partilha: " ;
			cin >> nomePP;
			if(valid_word(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				if(ER.getPontosPartilha().at(i)->getNome() == nomePP)
					indexPP = i;
			}

			if(indexPP == -1)
				throw OpcaoInvalida<string>(nomePP);
			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Ponto de partilha inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	ER.removePonto(indexPP);

	cout << "Ponto de partilha removido com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;
}

void visualizaPP(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		cout << "Nome: " << ER.getPontosPartilha().at(i)->getNome() << endl;
		cout << "Capacidade: " << ER.getPontosPartilha().at(i)->getCapacidade() << endl;
		cout << "Localização: " << endl << "    Nome: " << ER.getPontosPartilha().at(i)->getLocal().getNome() << endl;
		cout << "    Coordenadas: (" << ER.getPontosPartilha().at(i)->getLocal().getX() << " , " << ER.getPontosPartilha().at(i)->getLocal().getY();
		cout << ") " << endl << endl;
	}

	system("pause");
	system("cls");
	return;
}

void visualizaUtente(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	for(unsigned int i = 0; i < ER.getUtentes().size(); i++)
	{
		cout << "Nome: " << ER.getUtentes().at(i)->getUtenteNome() << endl;
		cout << "Tipo de Utente: " << ER.getUtentes().at(i)->getTipoUtente() << endl;
		cout << "ID: " << ER.getUtentes().at(i)->getId() << endl;
		cout << "Localização: " << endl << "    Nome: " << ER.getUtentes().at(i)->getLocalizacao().getNome() << endl;
		cout << "    Coordenadas: (" << ER.getUtentes().at(i)->getLocalizacao().getX() << " , " << ER.getUtentes().at(i)->getLocalizacao().getY();
		cout << ") " << endl << endl;
	}

	system("pause");
	system("cls");
	return;

}

void visualizaBikes(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	int numU{}, numUS{}, numC{}, numI{};

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		numU += ER.getPontosPartilha().at(i)->getBikes().at(0).size();
		numUS += ER.getPontosPartilha().at(i)->getBikes().at(1).size();
		numC += ER.getPontosPartilha().at(i)->getBikes().at(2).size();
		numI += ER.getPontosPartilha().at(i)->getBikes().at(3).size();
	}

	cout << "No total existem no momento: " << endl;
	cout << "->  Bicicletas Urbanas: " << numU << endl;
	cout << "->  Bicicletas Urbanas Simples: " << numUS << endl;
	cout << "->  Bicicletas Corrida: " << numC << endl;
	cout << "->  Bicicletas Infantil: " << numI << endl << endl;

	system("pause");
	system("cls");
	return;

}

void adicionaBike(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Adiciona bicicleta: " << endl;

	string nomePP, biketype;
	bool cond {false};
	int indexPP {-1};
	int indexBB {-1};
	int numberbikes {0};

	//Verifica ponto de partilha ao qual quer adicionar
	while(1)
	{
		try {
			cout << "Nome do Ponto Partilha: " ;
			cin >> nomePP;
			if(valid_word(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				if(ER.getPontosPartilha().at(i)->getNome() == nomePP)
					indexPP = i;
			}

			if(indexPP == -1)
				throw OpcaoInvalida<string>(nomePP);
			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Ponto de partilha inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	for(unsigned int i = 0; i < ER.getPontosPartilha().at(indexPP)->getBikes().size(); i++)
	{

		numberbikes += ER.getPontosPartilha().at(indexPP)->getBikes().at(i).size();

	}

	if(ER.getPontosPartilha().at(indexPP)->getCapacidade() == numberbikes)
	{
		cout << "A capacidade deste ponto de partilha já foi alcancada ! Tente adicionar a outro ponto de partilha." << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	//Verifica tipo de bicicleta a adicionar
	while(1)
	{
		try {
			cout << "Tipo de Bicicleta: " ;
			cin >> biketype;
			if(valid_word(biketype) == false)
				throw OpcaoInvalida<string>(biketype);


			if(biketype == "Urbana")
				indexBB = 0;
			else if(biketype == "Urbana Simples")
				indexBB = 1;
			else if(biketype == "Corrida")
				indexBB = 2;
			else if(biketype == "Infantil")
				indexBB = 3;

			if(indexBB == -1)
				throw OpcaoInvalida<string>(biketype);


			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	//Verifica se o nome da bicicleta a adicionar é diferente e adiciona
	while(1)
	{
		try {
			cout << "Nome da Bicicleta: " ;
			cin >> nomePP;
			if(valid_bike(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				for(unsigned int k = 0; k < ER.getPontosPartilha().at(i)->getBikes().at(indexBB).size(); k++)
				{
					if(ER.getPontosPartilha().at(i)->getBikes().at(indexBB).at(k)->getBikeName() == nomePP)
						cond = true;
				}
			}

			if(cond == true)
				throw OpcaoInvalida<string>(nomePP);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome já existente(" << op.opcao << ") ! Tente novamente." << endl;
			cond = false;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	Bicicleta * bc = new Bicicleta(biketype,nomePP);
	ER.getPontosPartilha().at(indexPP)->adicionaBike(bc);

	cout << endl << "Bicicleta adicionada com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;
}

void removeBike(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Remove bicicleta: " << endl << endl;

	string nomePP, biketype;
	bool cond {false};
	int indexPP {-1};
	int indexBB {-1};

	//Verifica tipo de bicicleta a remover
	while(1)
	{
		try {
			cout << "Tipo de Bicicleta: " ;
			cin >> biketype;
			if(valid_word(biketype) == false)
				throw OpcaoInvalida<string>(biketype);

			if(biketype == "Urbana")
				indexBB = 0;
			else if(biketype == "Urbana Simples")
				indexBB = 1;
			else if(biketype == "Corrida")
				indexBB = 2;
			else if(biketype == "Infantil")
				indexBB = 3;

			if(indexBB == -1)
				throw OpcaoInvalida<string>(biketype);


			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	//Verifica se o nome da bicicleta a remover e verifica se existe
	while(1)
	{
		try {
			cout << "Nome da Bicicleta: " ;
			cin >> nomePP;
			if(valid_bike(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				for(unsigned int k = 0; k < ER.getPontosPartilha().at(i)->getBikes().at(indexBB).size(); k++)
				{
					if(ER.getPontosPartilha().at(i)->getBikes().at(indexBB).at(k)->getBikeName() == nomePP)
					{
						indexPP = i;
						cond = true;
					}
				}
			}

			if(cond == false)
				throw OpcaoInvalida<string>(nomePP);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Bicicleta inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cond = false;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	Bicicleta * bc = new Bicicleta(biketype,nomePP);
	ER.getPontosPartilha().at(indexPP)->removeBike(bc);

	cout << endl << "Bicicleta removida com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;

}

void removeUT(Sistema & ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Remove utente: " << endl << endl;

	if(ER.getUtentes().size() == 0)
	{
		cout << "Neste momento não existem utentes !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	string nomeUT;
	int indexUT {-1};

	//Verifica o nome do utente que quer remover
	while(1)
	{
		try {
			cout << "Nome do Utente: " ;
			cin >> nomeUT;
			if(valid_word(nomeUT) == false)
				throw OpcaoInvalida<string>(nomeUT);

			for(unsigned int i = 0; i < ER.getUtentes().size(); i++)
			{
				if(ER.getUtentes().at(i)->getUtenteNome() == nomeUT)
					indexUT = i;
			}

			if(indexUT == -1)
				throw OpcaoInvalida<string>(nomeUT);
			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Utente inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}

	ER.removeUtente(indexUT);

	if((unsigned int)indexUT == ER.getUtentes().size())
	{

		ER.getUtentes().at(0)->setLastId();

		cout << "Utente removido com sucesso !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	if(indexUT == 0)
	{
		for(unsigned int i = 0; i < ER.getUtentes().size(); i++)
		{

			ER.getUtentes().at(i)->setID();
		}

		ER.getUtentes().at(0)->setLastId();
	}
	else
	{

		for(unsigned int i = 0; i < ER.getUtentes().size(); i++)
		{
			if(i != 0)
				ER.getUtentes().at(i)->setID();
		}
		ER.getUtentes().at(0)->setLastId();
	}



	cout << "Utente removido com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;
}

void openInterface(Sistema & ER){

	int value { };
	string option;

	//Sistema ER { };

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
		cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
		cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
		cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
		cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

		cout << "1 - Registar " << endl;
		cout << "2 - Entrar" << endl;
		cout << "3 - Administrador" << endl;
		cout << "4 - Sair" << endl;

		while(1)
		{
			try{
				cout << endl << "Introduza uma opcao (1-4): ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 4)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			registo_utente(ER);
			break;
		case 2:
			system("cls");
			menu_interface(ER);
			break;
		case 3:
			system("cls");
			admin_interface(ER);
			break;
		case 4:
			cout << endl;
			break;
		}
	}while(value != 4);
	return;
}

void registo_utente(Sistema & ER){

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Regista novo utente:" << endl;

	string nome, tipoUtente;
	int value {};
	string option {};

	while(1)
	{
		try {
			cout << "Nome: " ;
			cin >> nome;
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	cout << endl << "Tipo de Utente :"<< endl ;
	cout << "     1 - Regular" << endl;
	cout << "     2 - Sócio" << endl << endl;

	while(1)
	{
		try{
			cout << endl << "Introduza uma opcao (1-2): ";
			cin >> option;
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);
			if(value < 1 || value > 3)
				throw OpcaoInvalida<int>(value);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	if(value==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	cout << endl << "Localizacao: " << endl << endl;

	cout << "Indique as suas cordenadas GPS:" << endl;

	double coordX { }, coordY { };

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	Localizacao spot;
	spot.setX(coordX);
	spot.setY(coordY);

	Utente* u12 = new Utente(nome,tipoUtente,spot);

	ER.addNewUtente(u12);

	cout << endl << "Utente #" << u12->getId() << " registado com sucesso." << endl << endl;

	system("pause");
	system("cls");
	return;
}

void menu_interface(Sistema &ER){


	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	int attempts { 0 };
	int identificacao { };
	int index {};	//Indice do utente no vector de utentes do sistema
	string info;

	while(attempts <= 3)
	{
		try{
			cout << "Username (ID): ";
			cin >> info;

			if(valid_number(info) == false)
				throw OpcaoInvalida<string>(info);

			identificacao = stoi(info);

			if(ExistID(ER,identificacao) == -1)
				throw OpcaoInvalida<int>(identificacao);

			index = ExistID(ER,identificacao);
			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Username inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	system("cls");

	string option;
	int value {};

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
		cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
		cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
		cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
		cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

		cout << "Bem-Vindo !" << endl << endl;

		cout << "1 - Alugar bicicleta" << endl;
		cout << "2 - Devolver bicicleta" << endl;
		cout << "3 - Historial" << endl;
		cout << "4 - Pagamentos pendentes" << endl;
		cout << "5 - Atualiza Localização" << endl;
		cout << "6 - Efetuar pagamento das mensalidades" << endl;
		cout << "7 - Ponto de partilha mais próximo" << endl;
		cout << "8 - Mudar o tipo de utente" << endl;
		cout << "9 - Obter informações sobre ECO RIDES" << endl; //
		cout << "10 - Sair" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opcao (1-10): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 10)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			alugaBike(ER,index,ExtraData(ER,index));
			break;
		case 2:
			system("cls");
			devolveBike(ER,index);
			break;
		case 3:
			system("cls");
			//Informacao inicial apresentadada ao utilizador
			cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
			cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
			cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
			cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
			cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

			cout << "Histórico: " << endl << endl;
			ER.getUtentes().at(index)->displayHistoric();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			displayPagPendentes(ER,index);
			break;
		case 5:
			system("cls");
			updateLocation(ER,index);
			break;
		case 6:
			system("cls");
			//Efetua pagamento
			break;
		case 7:
			system("cls");
			NearestPP(ER,index);
			break;
		case 8:
			system("cls");
			//Mudar tipo de utente
			break;
		case 9:
			system("cls");
			infoER(ER);
			break;
		case 10:
			///////////////////////////////////////////////////////////////
			//antes de fazer check out , os utentes tem que devolver bike//
			///////////////////////////////////////////////////////////////
			cout << endl;
			break;
		}
	}while(value != 10);

	system("cls");
	return;

}

void admin_interface(Sistema &ER) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;


	int attempts { 1 };
	string info;
	string password = "1234";

	while(attempts <= 3)
	{
		try{
			cout << "Admin (Password): ";
			cin >> info;

			if(info != password)
			{
				attempts++;
				throw OpcaoInvalida<string>(info);
			}

			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Password inválida (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	if(attempts > 3)
	{
		cout << endl << "Acesso negado: password incorreta" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	system("cls");

	string option;
	int value {};

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
		cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
		cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
		cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
		cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

		cout << "Administração" << endl << endl;

		cout << "1 - Adiciona bicicleta" << endl;
		cout << "2 - Adiciona ponto partilha" << endl;
		cout << "3 - Remove bicicleta" << endl;
		cout << "4 - Remove ponto de partilha" << endl;
		cout << "5 - Remove utente" << endl;
		cout << "6 - Visualiza pontos de partilha" << endl;
		cout << "7 - Visualiza bicicletas" << endl;
		cout << "8 - Visualiza utentes" << endl;
		cout << "9 - Sair" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opcao (1-9): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 9)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};


		//////////////////////////////////////////
		////////adicionar condiçao de mesmo nome ao criar ponto de partilha

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			adicionaBike(ER);
			break;
		case 2:
			system("cls");
			addPP(ER);
			break;
		case 3:
			system("cls");
			removeBike(ER);
			break;
		case 4:
			system("cls");
			removePP(ER);
			break;
		case 5:
			system("cls");
			removeUT(ER);
			break;
		case 6:
			system("cls");
			visualizaPP(ER);
			break;
		case 7:
			system("cls");
			visualizaBikes(ER);
			break;
		case 8:
			system("cls");
			visualizaUtente(ER);
			break;
		case 9:
			cout << endl;
			break;
		}
	}while(value != 9);

	system("cls");
	return;
}

vector<int> ExtraData(Sistema &ER,int index) {

	vector<double> distancias;
	vector<int> indices;

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		distancias.push_back(ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(i)->getLocal()));
	}

	sort(distancias.begin(),distancias.end());

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		for(unsigned int k = 0; k < ER.getPontosPartilha().size(); k++)
		{
			if(distancias.at(i) == ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(k)->getLocal()))
			{
				indices.push_back(k);
			}
		}
	}

	return indices;

}

bool valid_number(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if (!(isdigit(number.at(i))))
			return false;
	}
	return true;
}

bool valid_number_double(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if ((!(isdigit(number.at(i)))) && (number.at(i) != '.') && (number.at(i) != '-'))
			return false;
	}
	return true;
}

bool valid_word(string word)
{
	for (unsigned int i = 0; i < word.size(); i++){
		if (isdigit(word.at(i)))
			return false;
	}
	return true;
}

bool valid_bike(string bike)
{
	if (isdigit(bike.at(0)))
		return false;

	return true;
}

