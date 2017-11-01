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
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;


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
		data d1;
		int numHours{};
		//, dia{}, mes{}, ano {}
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

				d1.ano = value;
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

				d1.mes = value;
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
				if(d1.mes == 2)
				{
					if(value < 1 || value > 28)
						throw OpcaoInvalida<int>(value);

					d1.dia = value;
					break;
				}
				else if((d1.mes == 1) ||(d1.mes == 3) ||(d1.mes == 5) ||(d1.mes == 7) ||(d1.mes == 8) ||(d1.mes == 10) ||(d1.mes == 12))
				{
					if(value < 1 || value > 31)
						throw OpcaoInvalida<int>(value);

					d1.dia = value;
					break;
				}
				else
				{
					if(value < 1 || value > 30)
						throw OpcaoInvalida<int>(value);

					d1.dia = value;
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
		//Verifica por ordem se tem o tipo de bicleta pretendida
		for(unsigned int i = 0; i < distancias.size(); i++)
		{
			vector <vector<Bicicleta *> > bikes = ER.getPontosPartilha().at(distancias.at(i))->getBikes();

			for(unsigned int k = 0; k < bikes.size(); k++)
			{
				for(unsigned int q = 0; q < bikes.at(k).size(); q++)
				{
					if(bikes.at(k).at(q)->getBikeType() == bikeType)
					{
						idPP = i;
						q = bikes.at(k).size();
					}


				}

				if(idPP != -1)
					k = bikes.size();
			}

			if(idPP != -1)
				i = distancias.size();

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

		cout << "AAAAA" << endl;
		ER.getUtentes().at(index)->setAvailable();

		ER.getPontosPartilha().at(idPP)->removeBike(ER.getUtentes().at(index)->getBike());

		if(ER.getUtentes().at(index)->getTipoUtente() == "Socio")
		{
			cout << "AAAAA" << endl;
			Utilizacao p(bikeType, numHours, d1.dia, d1.mes, d1.ano);
			ER.getUtentes().at(index)->getUtilizacoes().push_back(p);
			cout << "BBBBB" << endl;
		}
			else {

			/* Apresenta o preço do aluguer */

			/* Adiciona ao historio */
			ER.getUtentes().at(index)->setHistoric(Utilizacao(bikeType, numHours, d1.dia, d1.mes, d1.ano));
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
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	if(ER.getUtentes().at(index)->getAvailable() == true)
	{
		cout << "Neste momento o utente não tem nenhuma bicicleta para entregar" << endl << endl;
	}
	else
	{
		cout << "Devolve bicicleta: " << endl << endl;

		Utilizacao ut = ER.getUtentes().at(index)->getUtilizacoes().at(ER.getUtentes().at(index)->getUtilizacoes().size() - 1);

		cout << "Tipo de bicicleta: " << ut.getBikeType() << endl;
		cout << "Número de horas: " << ut.getUseTime() << endl;
		cout << "Data (dd/mm/aaaa): " << ut.getdia() << "/" << ut.getmes() << "/" << ut.getano()<< endl;

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
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
				cout << "Data (dd/mm/aaaa): " << ER.getUtentes().at(index)->getUtilizacoes().at(i).getdia() << "/";
				cout << ER.getUtentes().at(index)->getUtilizacoes().at(i).getmes();
				cout << "/" << ER.getUtentes().at(index)->getUtilizacoes().at(i).getano()<< endl << endl;

				//FALTA CALCULAR O PRECO DAS UTILIZACOES !!!!
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
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
void NearestPP(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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

void openInterface(Sistema & ER){

	int value { };
	string option;

	//Sistema ER { };

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
		cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
		cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
		cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
		cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
}

void registo_utente(Sistema & ER){

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
			cout << endl << "Introduza uma opcao (1-3): ";
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

	Utente* u1 = new Utente(nome,tipoUtente,spot);

	ER.addNewUtente(u1);

	cout << endl << "Utente #" << u1->getId() << " registado com sucesso." << endl << endl;

	system("pause");
	system("cls");
	return;
}

void menu_interface(Sistema &ER){


	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

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
		cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
		cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
		cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
		cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
		cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

		cout << "Bem-Vindo !" << endl << endl;

		cout << "1 - Alugar bicicleta" << endl;
		cout << "2 - Devolver bicicleta" << endl;
		cout << "3 - Historial" << endl;
		cout << "4 - Pagamentos pendentes" << endl;
		cout << "5 - Atualiza Localização" << endl;
		cout << "6 - Ponto de partilha mais próximo" << endl;
		cout << "7 - Obter informações sobre ECO RIDES" << endl;
		cout << "8 - Sair" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opcao (1-8): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 8)
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
			ER.getUtentes().at(index)->displayHistoric();
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
			NearestPP(ER,index);
			break;
		case 7:
			system("cls");
			infoER(ER);
			break;
		case 8:
			cout << endl;
			break;
		}
	}while(value != 8);

	system("pause");
	system("cls");
	return;

}

void admin_interface(Sistema &BS) {


	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Administração" << endl << endl;

	for(unsigned int i = 0; i < BS.getPontosPartilha().size(); i++)
	{
		for(unsigned int k = 0; k < BS.getPontosPartilha().at(i)->getBikes().size(); k++)
		{
			for(unsigned int q = 0; q < BS.getPontosPartilha().at(i)->getBikes().at(k).size(); q++)
			{
				cout << BS.getPontosPartilha().at(i)->getBikes().at(k).at(q)->getBikeType() << endl;
			}

			cout << endl;
		}
	}

	system("pause");
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
