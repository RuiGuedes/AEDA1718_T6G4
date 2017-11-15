#include "Includes.h"
#include "Sistema.h"
#include "Exceções.h"

/* Procura um valor xnum vetor vde elementos comparáveiscom os operadores de comparação.
 * Retorna o índice da primeira ocorrência de xem v, se encontrar; senão, retorna -1.
 */
template <class T>
int SequentialSearch(const vector<T> &v, T x)
{
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return i;// encontrou
	return -1; // não encontrou
}

void registo_utente(Sistema & BS);
void menu_interface(Sistema &BS);
void admin_interface(Sistema &BS);
vector<int> ExtraData(Sistema &ER,int index);

void System_Manager(Sistema &ER,unsigned int index, string bikeType) {

	int value {-1};
	int tamanho{-1};
	vector<int> indicesSup5, indicesInf5;

	if(bikeType == "Urbana")
		value = 0;
	else if(bikeType == "Urbana Simples")
		value = 1;
	else if(bikeType == "Corrida")
		value = 2;
	else
		value = 3;

	tamanho = ER.getPontosPartilha().at(index)->getBikes().at(value).size();

	//Guarda num vetor os indices dos pontos de partilha nos vetores indicesSup5 e indicesInf5
	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		if(i != index)
		{
			if(ER.getPontosPartilha().at(i)->getBikes().at(value).size() > 5)
				indicesSup5.push_back(i);
			else if(ER.getPontosPartilha().at(i)->getBikes().at(value).size() < 5)
				indicesInf5.push_back(i);
		}

	}

	//Ordena os vectores por ordem crescente
	sort(indicesSup5.begin(), indicesSup5.end());
	sort(indicesInf5.begin(), indicesInf5.end());

	//Necessita de receber bicicletas
	if(tamanho <= 2)
	{
		//Distribui bicicletas
		for(int k = indicesSup5.size() - 1; k >= 0; k--)
		{
			while(ER.getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).size() > 5)
			{
				if(ER.getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
					break;

				ER.getPontosPartilha().at(index)->adicionaBike(ER.getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).at(0));
				ER.getPontosPartilha().at(indicesSup5.at(k))->removeBike(ER.getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).at(0));
			}

			if(ER.getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}
	else if(tamanho >= 8)	//Necessita de fornecer bicicletas
	{
		//Distribui bicicletas
		for(unsigned int k = 0; k < indicesInf5.size(); k++)
		{
			while(ER.getPontosPartilha().at(indicesInf5.at(k))->getBikes().at(value).size() < 5)
			{
				if(ER.getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
					break;

				ER.getPontosPartilha().at(indicesInf5.at(k))->adicionaBike(ER.getPontosPartilha().at(index)->getBikes().at(value).at(0));
				ER.getPontosPartilha().at(index)->removeBike(ER.getPontosPartilha().at(index)->getBikes().at(value).at(0));
			}

			if(ER.getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}

	return;
}

void alugaBike(Sistema &ER,int index,vector<int> distancias) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;


	if(ER.getUtentes().at(index)->getAvailable() == false)
	{
		cout << "Não é possível alugar duas bicicletas em simultâneo !"  << endl << endl;

		system("pause");
		system("cls");
		return;

	}
	else
	{
		cout << "Aluga Bicicleta: " << endl << endl;

		cout << "Preencha os seguintes campos: " << endl << endl;
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

		//Executa até obter um tipo de bicicleta válido
		while(1)
		{
			try{
				cout << endl << "Introduza uma opcao [1-4]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 4)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Verifica o tipo de bicicleta selecionada
		if(value == 1)
			bikeType = "Urbana";
		else if(value == 2)
			bikeType = "Urbana Simples";
		else if(value == 3)
			bikeType = "Corrida";
		else
			bikeType = "Infantil";

		//Executa até obter um número de horas válido
		while(1)
		{
			try{
				cout << endl << "Número de horas [1-24]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 24)
					throw OpcaoInvalida<int>(value);

				numHours = value;
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Número de horas inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Número de horas inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Executa até obter um ano válido
		while(1)
		{
			try{
				cout << endl << "Ano [2017 - ...]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 2017)
					throw OpcaoInvalida<int>(value);

				d1.setAno(value);
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Executa até obter um mês válido
		while(1)
		{
			try{
				cout << endl << "Mes [1-12]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 12)
					throw OpcaoInvalida<int>(value);

				d1.setMes(value);
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		/* Executa até obter um dia válido
		 * Considera que fevereiro tem 28 dias
		 */
		while(1)
		{
			try{
				cout << endl << "Dia: ";
				cin >> option;
				cin.ignore(1000,'\n');
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

				cout << "Dia inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Dia inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		int idPP {};
		vector<string> bikesType;

		//Verifica se tem o tipo de bicleta pretendida por ordem de distancia
		for (unsigned int i=0 ; i < distancias.size(); i++)
		{
			bikesType = ER.getPontosPartilha().at(distancias.at(i))->getBikeTypes();

			idPP = SequentialSearch(bikesType,bikeType);

			if(idPP != -1)
			{
				idPP = distancias.at(i);
				break;
			}

		}

		if(idPP == -1)
		{
			cout << endl << "Neste momento não existe nenhuma bicicleta do tipo " << bikeType << " disponivel." << endl << endl;
		}
		else
		{

			Utilizacao p(bikeType, numHours, d1,ER.getPontosPartilha().at(idPP)->getNome(),ER.getPontosPartilha().at(idPP)->getLocal().getNome());
			double price {0};

			ER.getUtentes().at(index)->alugaBicicleta(ER,bikeType,p,idPP);

			if(ER.getUtentes().at(index)->getTipoUtente() == "Regular")
			{
				price = p.getPrice();

			}

			cout << endl;
			system("cls");

			//Informacao inicial apresentadada ao utilizador
			cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
			cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
			cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
			cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
			cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

			cout << "Aluga Bicicleta: " << endl << endl;
			cout << "Resumo do aluger: " << endl << endl;

			p.displayUtilizacao();

			if(price !=0)
				cout << "Montante: " << price << "€" << endl;

			System_Manager(ER,idPP,bikeType);

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
		system("pause");
		system("cls");
		return;
	}

	int index_pp {-1};

	index_pp = ER.getUtentes().at(index)->removeBicicleta(ER,ExtraData(ER,index));

	cout << "Devolve bicicleta: " << endl << endl;
	cout << "Resumo do último aluguer: " << endl << endl;

	string bikeType;

	//Verifica o tipo de utente e apresenta a respetiva informação
	if(ER.getUtentes().at(index)->getTipoUtente() == "Socio")
	{
		Utilizacao ut = ER.getUtentes().at(index)->getUtilizacoes().at(ER.getUtentes().at(index)->getUtilizacoes().size() - 1);
		bikeType = ut.getBikeType();
		ut.displayUtilizacao();
	}
	else
	{
		Utilizacao ut = ER.getUtentes().at(index)->getHistorico().at(ER.getUtentes().at(index)->getHistorico().size() - 1);
		ut.displayUtilizacao();
		bikeType = ut.getBikeType();
		cout << "Montante: " << ut.getPrice() << "€" << endl;
	}

	cout << endl << "Bicicleta devolvida com sucesso no ponto de partilha ECO_RIDES_" << ER.getPontosPartilha().at(index_pp)->getNome() << " !" << endl << endl;

	System_Manager(ER,index_pp,bikeType);

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

	if(ER.getUtentes().at(index)->getTipoUtente() == "Regular")
		cout << "Neste tipo de utente [Regular] não é possivel ter pagamentos pendentes !" << endl << endl;
	else
	{
		if(ER.getUtentes().at(index)->getUtilizacoes().size() != 0)
		{
			cout << "Pagamentos pendentes:" << endl << endl;

			for(unsigned int i = 0; i < ER.getUtentes().at(index)->getUtilizacoes().size(); i++)
			{
				ER.getUtentes().at(index)->getUtilizacoes().at(i).displayUtilizacao();
				cout << endl;
			}
		}
		else
		{
			cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
		}
	}

	system("pause");
	system("cls");
	return;
}

void updateLocation(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Localizacao: " << endl << endl;

	cout << "Localização atual: (" << ER.getUtentes().at(index)->getLocalizacao().getX() << " , " << ER.getUtentes().at(index)->getLocalizacao().getY();
	cout << ")" << endl << endl;

	cout << "Indique as novas cordenadas GPS:" << endl;

	string option;
	double coordX { }, coordY { };

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	Localizacao spot;
	spot.setX(coordX);
	spot.setY(coordY);

	ER.getUtentes().at(index)->setUtenteLocation(spot);

	cout << endl << "O utente encontra-se agora num novo local de coordenadas (" << coordX << " , " << coordY << ")" << endl << endl;

	system("pause");
	system("cls");
	return;

}

void efetuaPag(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Efetua pagamento" << endl << endl;

	unsigned int ano{}, mes{};
	string option {};
	vector<unsigned int> meses;

	if(ER.getUtentes().at(index)->getAvailable() == false)
	{
		cout << "Não é possível efetuar o pagamento uma vez que a bicicleta alugada ainda não foi devolvida" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	if(ER.getUtentes().at(index)->getTipoUtente() == "Regular"){
		cout << "O pagamento já foi feito na altura do aluguer!" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	else if(ER.getUtentes().at(index)->getUtilizacoes().size() == 0){
		cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	//Executa até obter um ano válido
	while(1)
	{
		try{
			cout << "Liquidação de mensalidades do ano: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			ano = stoi(option);
			if(ano < 2017)
				throw OpcaoInvalida<int>(ano);

			cout << endl;
			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	//Verifica meses de utilização do respetivo ano
	for(unsigned int i = 0; i < ER.getUtentes().at(index)->getUtilizacoes().size(); i++)
	{
		if(ER.getUtentes().at(index)->getUtilizacoes().at(i).getData().getAno() == ano)
		{
			if(meses.size() == 0)
				meses.push_back(ER.getUtentes().at(index)->getUtilizacoes().at(i).getData().getMes());

			bool cond {false};
			for(unsigned int k = 0; k < meses.size(); k++)
			{
				if(meses.at(k) == ER.getUtentes().at(index)->getUtilizacoes().at(i).getData().getMes())
					cond = true;
			}

			if(cond == false)
				meses.push_back(ER.getUtentes().at(index)->getUtilizacoes().at(i).getData().getMes());

			cond = false;
		}
	}

	if(meses.size() == 0)
	{
		cout << "Este utente não possui qualquer pagamento pendente no ano " << ano << " ! " << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "Meses com mensalidades em atraso: " << endl;
		for(unsigned int i = 0; i < meses.size(); i++)
		{
			if(meses.at(i) == 1)
				cout << "1 - Janeiro" << endl;
			else if(meses.at(i) == 2)
				cout << "2 - Fevereiro" << endl;
			else if(meses.at(i) == 3)
				cout << "3 - Março" << endl;
			else if(meses.at(i) == 4)
				cout << "4 - Abril" << endl;
			else if(meses.at(i) == 5)
				cout << "5 - Maio" << endl;
			else if(meses.at(i) == 6)
				cout << "6 - Junho" << endl;
			else if(meses.at(i) == 7)
				cout << "7 - Julho" << endl;
			else if(meses.at(i) == 8)
				cout << "8 - Agosto" << endl;
			else if(meses.at(i) == 9)
				cout << "9 - Setembro" << endl;
			else if(meses.at(i) == 10)
				cout << "10 - Outubro" << endl;
			else if(meses.at(i) == 11)
				cout << "11 - Novembro" << endl;
			else if(meses.at(i) == 12)
				cout << "12 - Dezembro" << endl;
		}

		cout << endl;

		//Executa até obter um ano válido
		while(1)
		{
			try{
				cout << "Liquidação de mensalidades do mês: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				mes = stoi(option);

				bool cond {false};

				for(unsigned int i = 0; i < meses.size(); i++)
				{
					if(meses.at(i) == mes)
					{
						cond = true;
						break;
					}
				}

				if(cond == false)
					throw OpcaoInvalida<int>(mes);

				cout << endl;
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};
	}

	ER.getUtentes().at(index)->pagaMensalidade(ER,ano,mes);

	system("pause");
	system("cls");
	return;
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

	cout << "Ordem  Nome" << setw(16) << "Local"<< endl;

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		for(unsigned int k = 0; k < ER.getPontosPartilha().size(); k++)
		{
			if(distancias.at(i) == ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(k)->getLocal()))
			{
				cout << "  " << setw(5) << left << (i+1) << "ECO_RIDES_" << setw(5) << ER.getPontosPartilha().at(k)->getNome();
				cout << ER.getPontosPartilha().at(k)->getLocal().getNome() << endl;
			}

		}
	}

	cout << endl;

	system("pause");
	system("cls");
	return;

}

void mudaTipoUT(Sistema &ER,int index){


	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
	cout << "Muda tipo de utente" << endl << endl;

	string option;
	string tipo = ER.getUtentes().at(index)->getTipoUtente();

	if(ER.getUtentes().at(index)->getAvailable() == false)
	{
		cout << "Não é possível efetuar mudar o tipo de utente uma vez que a bicicleta alugada ainda não foi devolvida" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	if((tipo == "Regular") || (ER.getUtentes().at(index)->getUtilizacoes().size() == 0))
	{
		cout << "Neste momento encontra-se definido como: " << tipo << endl << endl;

		while(1)
		{
			try {
				if(tipo == "Regular")
					cout << "Tem a certeza que pretende mudar para Sócio [Y/N]: ";
				else
					cout << "Tem a certeza que pretende mudar para Regular [Y/N]: ";

				cin >> option;
				cin.ignore(1000,'\n');

				if(valid_word(option) == false)
					throw OpcaoInvalida<string>(option);

				if((option == "Y") || (option == "N"))
					break;

				throw OpcaoInvalida<string>(option);

			}
			catch (OpcaoInvalida<string> &op) {
				cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		}

		if(option == "Y")
		{
			if(tipo == "Regular")
			{
				ER.getUtentes().at(index)->setTipoUtente("Socio");
				cout << endl << "Mudança efetuada com sucesso. Agora o seu tipo é: Sócio" << endl << endl;
			}
			else
			{
				ER.getUtentes().at(index)->setTipoUtente("Regular");
				cout << endl << "Mudança efetuada com sucesso. Agora o seu tipo é: Regular" << endl << endl;
			}

		}
		else
			cout << endl << "Mudança cancelada com sucesso " << endl << endl;

	}
	else
	{
		cout << "Neste momento não é possível mudar o tipo de utente visto que existem pagamentos pendentes" << endl << endl;
	}

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
	cout << "Numero total de pontos de Partilha: " << ER.getPontosPartilha().size() << endl << endl;
	cout << "Pontos de Partilha:" << endl << endl;
	cout << setw (15) << left << "Nome" << setw (22) << "Local" << setw (13) << "GPS";
	cout << setw (10) << "Urbana" << setw (18) << "Urbana Simples" <<
			setw (9) << "Corrida" << setw(10) << "Infantil" << "Capacidade" << endl;

	for (unsigned int i=0 ; i<ER.getPontosPartilha().size() ; i++){
		cout << setw(5) << ER.getPontosPartilha().at(i)->getNome()
												<< setw(23) << ER.getPontosPartilha().at(i)->getLocal().getNome()
												<< '(' << setw(9) << ER.getPontosPartilha().at(i)->getLocal().getX()
												<< "," << setw(9) << ER.getPontosPartilha().at(i)->getLocal().getY() << setw(5) << ')';

		vector<int> numtypes = ER.getPontosPartilha().at(i)->getNumberOfBikes();

		cout << setw(13) << numtypes.at(0);
		cout << setw(15) << numtypes.at(1);
		cout << setw(9) << numtypes.at(2);
		cout << setw(11) << numtypes.at(3);
		cout << ER.getPontosPartilha().at(i)->getCapacidade();

		cout << endl;
	}

	cout << endl;

	cout << "Numero total de utentes registados: " << ER.getUtentes().size() << endl << endl;

	cout << left << setw(15) << "  Nome" << setw(6) << "ID" << setw(27) << "Tipo de utente" << setw (20) << "GPS" << endl;

	for (unsigned int i=0 ; i<ER.getUtentes().size() ; i++){
		cout << setw(15) << ER.getUtentes().at(i)->getUtenteNome()
										<< setw(10) << ER.getUtentes().at(i)->getId()
										<< setw(14) <<ER.getUtentes().at(i)->getTipoUtente()
										<< '(' << setw(9) << ER.getUtentes().at(i)->getLocalizacao().getX()
										<< "," << setw(9) << ER.getUtentes().at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
	}

	cout << endl;

	cout << "Tabela de Preços:" << endl << endl;

	cout << setw(20) << left << "Tipo de bicicleta" << "Preço por hora" << endl;
	cout << setw(26) << "Urbana" << "4€" << endl <<
			setw(26) << "Urbana Simples" << "3€" << endl <<
			setw(26) << "Corrida" << "5€" << endl <<
			setw(26) << "Infantil" << "2€" << endl << endl;

	cout << setw(18) << left << "Mensalidade" << "Acessos" << endl;
	cout << setw(4) << " " << setw(11) << "20€" << "Infantil" << endl;
	cout << setw(4) << " " << setw(11) << "30€" << "Infantil + Urbana Simples" << endl;
	cout << setw(4) << " " << setw(11) << "40€" << "Infantil + Urbana Simples + Urbana" << endl;
	cout << setw(4) << " " << setw(11) << "50€" << "Infantil + Urbana Simples + Urbana + Corrida" << endl << endl;

	cout << "Fundadores: " << endl;
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

	cin.ignore(1000,'\n');

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin,nome);
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
		}
	}

	Localizacao spot{};
	bool diffloc {true};

	cout << endl << "Localizacao: " << endl << endl;

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin , locname);
			if(valid_word(locname) == false)
				throw OpcaoInvalida<string>(nome);

			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				if(ER.getPontosPartilha().at(i)->getLocal().getNome() == locname)
				{
					diffloc = false;
					spot.setNome(locname);
					spot.setX(ER.getPontosPartilha().at(i)->getLocal().getX());
					spot.setY(ER.getPontosPartilha().at(i)->getLocal().getY());
					cout << endl << "Coordenada X: " << spot.getX() << endl << endl;
					cout << "Coordenada Y: " << spot.getY() << endl << endl;
					break;
				}
			}


			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	if(diffloc == true)
	{
		bool newcord{true};
		double coordX { }, coordY { };

		do
		{
			newcord = true;
			cout << "Indique as cordenadas GPS:" << endl;

			while(1)
			{
				try{
					cout << endl << "Coordenada X: ";
					cin >> option;
					cin.ignore(1000,'\n');
					if(valid_number_double(option) == false)
						throw OpcaoInvalida<string>(option);

					coordX = stod(option);
					break;
				}
				catch (OpcaoInvalida<string> &op){

					cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
					cin.clear();
				}
			};

			while(1)
			{
				try{
					cout << endl << "Coordenada Y: ";
					cin >> option;
					cin.ignore(1000,'\n');
					if(valid_number_double(option) == false)
						throw OpcaoInvalida<string>(option);

					coordY = stod(option);
					break;
				}
				catch (OpcaoInvalida<string> &op){

					cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
					cin.clear();
				}
			};


			for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
			{
				if((ER.getPontosPartilha().at(i)->getLocal().getX() == coordX) && (ER.getPontosPartilha().at(i)->getLocal().getY() == coordY))
				{
					newcord = false;
					cout << "Essas coordenadas já pertence à localização: " << ER.getPontosPartilha().at(i)->getLocal().getNome() << endl << endl;
					break;
				}
			}

		}while(newcord == false);

		spot.setNome(locname);
		spot.setX(coordX);
		spot.setY(coordY);
	}

	while(1)
	{
		try{
			cout << endl << "Capacidade [20,30]: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if((value < 20) || (value > 30))
				throw OpcaoInvalida<string>(option);

			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Capacidade inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	PontoPartilha* pp = new PontoPartilha(spot,value,nome);

	ER.addPontoPartilha(pp);

	for(unsigned int i = 0; i < 5; i++)
	{
		string u = "u" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Urbana"));
		string us = "us" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Urbana Simples"));
		string c = "c" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Corrida"));
		string inf = "i" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Infantil"));

		Bicicleta* b1 = new Bicicleta("Urbana",u);
		Bicicleta* b2 = new Bicicleta("Urbana Simples",us);
		Bicicleta* b3 = new Bicicleta("Corrida",c);
		Bicicleta* b4 = new Bicicleta("Infantil",inf);

		ER.getPontosPartilha().at(ER.getPontosPartilha().size() - 1)->adicionaBike(b1);
		ER.getPontosPartilha().at(ER.getPontosPartilha().size() - 1)->adicionaBike(b2);
		ER.getPontosPartilha().at(ER.getPontosPartilha().size() - 1)->adicionaBike(b3);
		ER.getPontosPartilha().at(ER.getPontosPartilha().size() - 1)->adicionaBike(b4);

		ER.getPontosPartilha().at(0)->setBikeLastIdFoward("Urbana");
		ER.getPontosPartilha().at(0)->setBikeLastIdFoward("Urbana Simples");
		ER.getPontosPartilha().at(0)->setBikeLastIdFoward("Corrida");
		ER.getPontosPartilha().at(0)->setBikeLastIdFoward("Infantil");
	}

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

	cin.ignore(1000,'\n');

	//Verifica ponto de partilha que quer remover
	while(1)
	{
		try {
			cout << "Nome do Ponto Partilha: " ;
			//cin >> nomePP;
			getline(cin,nomePP);
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
		}
	}

	ER.removePonto(indexPP);

	for(unsigned int i = 0; i < 5; i++)
	{
		ER.getPontosPartilha().at(0)->setBikeLastIdBackward("Urbana");
		ER.getPontosPartilha().at(0)->setBikeLastIdBackward("Urbana Simples");
		ER.getPontosPartilha().at(0)->setBikeLastIdBackward("Corrida");
		ER.getPontosPartilha().at(0)->setBikeLastIdBackward("Infantil");
	}

	cout << "Ponto de partilha removido com sucesso !" << endl << endl;

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

	cout << "Adiciona bicicleta: " << endl << endl;

	string biketype;
	string nomePP;
	int indexPP {-1};
	int indexBB {-1};
	int numberbikes {0};

	cin.ignore(1000,'\n');

	//Verifica ponto de partilha ao qual quer adicionar
	while(1)
	{
		try {
			cout << "Nome do Ponto Partilha: " ;
			getline(cin,nomePP);
			//cin >> nomePP;
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
			getline(cin,biketype);
			if(valid_word(biketype) == false)
				throw OpcaoInvalida<string>(biketype);


			if(biketype == "Urbana")
			{
				indexBB = 0;
				nomePP = "u" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Urbana"));
			}
			else if(biketype == "Urbana Simples")
			{
				indexBB = 1;
				nomePP = "us" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Urbana Simples"));
			}
			else if(biketype == "Corrida")
			{
				indexBB = 2;
				nomePP = "c" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Corrida"));
			}
			else if(biketype == "Infantil")
			{
				indexBB = 3;
				nomePP = "i" + to_string(ER.getPontosPartilha().at(0)->getBikeLastId("Infantil"));
			}

			if(indexBB == -1)
				throw OpcaoInvalida<string>(biketype);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
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

	cout << "Remove bicicleta " << endl << endl;

	string nomePP, biketype;
	bool cond {false};
	int indexPP {-1};
	int indexBB {-1};

	cin.ignore(1000,'\n');

	//Verifica tipo de bicicleta a remover
	while(1)
	{
		try {
			cout << "Tipo de Bicicleta: " ;
			getline(cin,biketype);
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

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	//Verifica se o nome da bicicleta a remover e verifica se existe
	while(1)
	{
		try {
			cout << "Nome da Bicicleta: " ;
			getline(cin,nomePP);

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
		}
	}

	ER.getPontosPartilha().at(0)->setBikeLastIdBackward(biketype);
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

	cout << "Remove utente " << endl << endl;

	if(ER.getUtentes().size() == 0)
	{
		cout << "Neste momento não existem utentes !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	string nomeUT;
	int indexUT {-1};

	cin.ignore(1000,'\n');

	//Verifica o nome do utente que quer remover
	while(1)
	{
		try {
			cout << "Nome do Utente: " ;
			getline(cin,nomeUT);
			if(valid_word(nomeUT) == false)
				throw OpcaoInvalida<string>(nomeUT);

			for(unsigned int i = 0; i < ER.getUtentes().size(); i++)
			{
				if(ER.getUtentes().at(i)->getUtenteNome() == nomeUT)
					indexUT = i;
			}

			if(indexUT == -1)
				throw OpcaoInvalida<string>(nomeUT);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Utente inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	ER.removeUtente(indexUT);

	if((unsigned int)indexUT == ER.getUtentes().size())
	{

		ER.getUtentes().at(0)->setLastId();

		cout << endl << "Utente removido com sucesso !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	for(unsigned int i = indexUT; i < ER.getUtentes().size(); i++)
	{
		ER.getUtentes().at(i)->setIDBackward();
	}

	ER.getUtentes().at(0)->setLastId();

	cout << endl << "Utente removido com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;
}

void openInterface(Sistema & ER){

	int value { };
	string option;

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
		cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
		cout << "#####   ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
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
				cin.ignore(1000,'\n');
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
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
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
	cout << "#####   ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	cout << "Regista novo utente:" << endl << endl;

	string nome, tipoUtente;
	int value {};
	string option {};
	double coordX { }, coordY { };

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin,nome);
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
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
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);
			if(value < 1 || value > 2)
				throw OpcaoInvalida<int>(value);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	if(value==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	cout << endl << "Localizacao: " << endl << endl;

	cout << "Indique as cordenadas GPS:" << endl;

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	Localizacao spot;

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		if((ER.getPontosPartilha().at(i)->getLocal().getX() == coordX) && (ER.getPontosPartilha().at(i)->getLocal().getY() == coordY))
		{
			spot.setNome(ER.getPontosPartilha().at(i)->getLocal().getNome());
			break;
		}
	}

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

		cout << "1  - Alugar bicicleta" << endl;
		cout << "2  - Devolver bicicleta" << endl;
		cout << "3  - Historial" << endl;				//CRIAR UMA FUNCAO
		cout << "4  - Pagamentos pendentes" << endl;		//FALTA CALCULAR O PRECO DAS UTILIZACOES
		cout << "5  - Atualiza Localização" << endl;		//ADICIONAR OPCAO PARA ADICIONAR LOCALIZACAO POR NOME
		cout << "6  - Efetuar pagamento das mensalidades" << endl;		//FALTA TERMINAR E VERIFICAR
		cout << "7  - Ponto de partilha mais próximo" << endl;
		cout << "8  - Mudar o tipo de utente" << endl;			//FALTA IMPLEMENTAR
		cout << "9  - Informações sobre ECO_RIDES" << endl;
		cout << "10 - Voltar" << endl << endl;

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
			efetuaPag(ER,index);
			break;
		case 7:
			system("cls");
			NearestPP(ER,index);
			break;
		case 8:
			system("cls");
			mudaTipoUT(ER,index);
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

	while(attempts <= 3)
	{
		try{
			cout << "Admin (Password): ";
			cin >> info;

			if(valid_number(info) == false)
				throw OpcaoInvalida<string>(info);

			if(info != "1234")
				throw OpcaoInvalida<string>(info);

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
		cout << "6 - Informações sobre ECO_RIDES" << endl;
		cout << "7 - Sair" << endl;


		while(1)
		{
			try {

				cout << endl << "Introduza uma opcao (1-7): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 7)
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
		////// - ADICIONA PONTO DE PARTILHA NUMA LOCALIZACAO EXISTENTE
		//////////////////////////////////////////
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
			infoER(ER);
			break;
		case 7:
			cout << endl;
			break;

		}
	}while(value != 7);

	system("cls");
	return;
}

//Retorna um vector com os indices dos pontos de partilha organizados por ordem crescente de distancia ao ponto de partilha com indicie = index
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

//Verifica se um número é positivo e contem apenas algarismos
bool valid_number(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if (!(isdigit(number.at(i))))
			return false;
	}
	return true;
}

//Verifica se um número é positivo/negativo e contem apenas algarismos ou apenas "." e "-"
bool valid_number_double(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if ((!(isdigit(number.at(i)))) && (number.at(i) != '.') && (number.at(i) != '-'))
			return false;
	}
	return true;
}

//Verifica se é a string não contem numeros
bool valid_word(string word)
{
	for (unsigned int i = 0; i < word.size(); i++){
		if (isdigit(word.at(i)))
			return false;
	}
	return true;
}

//Verifica se o nome da bicicleta é correto - não pode começar por um número
bool valid_bike(string bike)
{
	if (isdigit(bike.at(0)))
		return false;

	return true;
}

