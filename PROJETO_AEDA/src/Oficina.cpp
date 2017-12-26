#include "Oficina.h"
#include "Excecoes.h"

/////////////////
// METODOS GET //
/////////////////

vector<Bicicleta *> Oficina::getBrokenBikes() const {
	return brokenBikes;
}



////////////
// OTHERS //
////////////

void Oficina::addBrokenBike(Bicicleta * bike) {
	brokenBikes.push_back(bike);
}

void Oficina::addPiece() {

	cout << "Adiciona pe�a: " << endl << endl;

	string piece,option,nome;
	int value {};
	vector<string> piecesAvailable;

	piecesAvailable.push_back("Pneu"); piecesAvailable.push_back("Corrente"); piecesAvailable.push_back("Pedais");
	piecesAvailable.push_back("Guiador"); piecesAvailable.push_back("Assento"); piecesAvailable.push_back("Cremalheira");
	piecesAvailable.push_back("Punhos"); piecesAvailable.push_back("Trav�o traseiro"); piecesAvailable.push_back("Trav�o dianteiro");
	piecesAvailable.push_back("Roda");

	//Mostra as pe�as possiveis para se adicionarem a BST
	cout << "Pe�as disponiveis: " << endl << endl;

	for(unsigned int i = 0; i < piecesAvailable.size(); i++)
		cout << (i+1) << " -> " << piecesAvailable.at(i) << endl;

	//Seleciona uma das pe�as
	while(1)
	{
		try {
			cout << endl << "Pe�a (1-10): ";
			cin >> option;

			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if(value < 1 || value > 10)
				throw OpcaoInvalida<int>(value);

			piece = piecesAvailable.at(value - 1);
			break;
		}
		catch (OpcaoInvalida<int> &op){
			cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){
			cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	cin.ignore(1000,'\n');

	do
	{
		BSTItrIn<Peca> it(pieces);
		bool exist {false};

		//Verifica o nome do fornecedor da respetiva pe�a
		while(1)
		{
			try {
				cout << endl << "Nome do fornecedor: " ;
				getline(cin,nome);

				if((valid_word(nome) == false) || (nome.empty()))
					throw OpcaoInvalida<string>(nome);

				break;
			}
			catch (OpcaoInvalida<string> &op) {
				cout << "Nome do fornecedor inv�lido(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		}

		//Procura na BST o respetivo fornecedor, se ja existir verifica se este ja tem a pe�a,

		while(!it.isAtEnd())
		{
			if(it.retrieve().getSupplier() == nome)
			{
				if(it.retrieve().getPieceType() == piece){
					exist = true;
					break;
				}
			}
			it.advance();
		}

		if(exist == false)
			break;
		else
			cout << "J� existe um fornecedor " << nome << " a vender pe�as do tipo " << piece << " ! Tente novamente." << endl;


	}while(1);

	//Adiciona a nova pe�a
	pieces.insert(Peca(0,piece,nome));

	cout << endl << "Pe�a adicionada com sucesso !" << endl << endl;
}

void Oficina::removePiece() {

	BSTItrIn<Peca> it(pieces);

	if(it.isAtEnd())
	{
		cout << "N�o existem pe�as para serem removidas " << endl << endl;
		return;
	}

	cout << "Remove pe�a: " << endl << endl;

	string piece,option,nome;
	int value {};
	vector<string> piecesAvailable, toRemove, suppliers;

	piecesAvailable.push_back("Pneu"); piecesAvailable.push_back("Corrente"); piecesAvailable.push_back("Pedais");
	piecesAvailable.push_back("Guiador"); piecesAvailable.push_back("Assento"); piecesAvailable.push_back("Cremalheira");
	piecesAvailable.push_back("Punhos"); piecesAvailable.push_back("Trav�o traseiro"); piecesAvailable.push_back("Trav�o dianteiro");
	piecesAvailable.push_back("Roda");

	//Guarda as pe�as possiveis a serem removidas da BST
	for(unsigned int i = 0; i < piecesAvailable.size(); i++)
	{
		BSTItrIn<Peca> search(pieces);

		while(!search.isAtEnd())
		{
			if(search.retrieve().getPieceType() == piecesAvailable.at(i)){
				toRemove.push_back(search.retrieve().getPieceType());
				break;
			}
			search.advance();
		}
	}

	//Mostra as pe�as possiveis para remocao
	cout << "Pe�as possiveis para remo��o: " << endl;

	for(unsigned int i = 0; i < toRemove.size(); i++)
		cout << i+1 << " -> " << toRemove.at(i) << endl;

	//Seleciona uma das pe�as
	while(1)
	{
		try {
			cout << endl << "Pe�a (1-" << toRemove.size() << "): ";
			cin >> option;

			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if(value < 1 || value > (int)toRemove.size())
				throw OpcaoInvalida<int>(value);

			piece = toRemove.at(value - 1);

			break;
		}
		catch (OpcaoInvalida<int> &op){
			cout << "Pe�a inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){
			cout << "Pe�a inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};


	//Mostra se possivel as pe�as associadas aos fornecedores que podem ser removidas
	while(!it.isAtEnd())
	{
		if(it.retrieve().getPieceType() == piece)
			suppliers.push_back(it.retrieve().getSupplier());

		it.advance();
	}

	if(suppliers.size() == 0)
	{
		cout << "N�o existem pe�as do tipo " << piece << " dispoveis para serem removidas !" << endl << endl;
		return;
	}

	system("cls");
	mensagemInicial();

	cout << "Remove pe�a: " << endl << endl;
	cout << "Pe�a: " << piece << endl << endl;
	cout << "Fornecedores: " << endl;

	for(unsigned int i = 0; i < suppliers.size(); i++)
		cout << (i+1) << " -> " << suppliers.at(i) << endl;

	//Seleciona a pe�a a ser removida
	while(1)
	{
		try {
			cout << endl << "Pe�a (1-" << suppliers.size() << "): ";
			cin >> option;

			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if(value < 1 || value > (int)suppliers.size())
				throw OpcaoInvalida<int>(value);

			nome = suppliers.at(value - 1);

			break;
		}
		catch (OpcaoInvalida<int> &op){
			cout << "Pe�a inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){
			cout << "Pe�a inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	//Remove a pe�a
	BSTItrIn<Peca> iterator(pieces);
	//BST<Peca> tmp = pieces; tmp.makeEmpty();
	pieces.remove(Peca(0,piece,nome));
//	while(!iterator.isAtEnd())
//	{
//		if((iterator.retrieve().getPieceType() == piece) && (iterator.retrieve().getSupplier() == nome)) {
//			pieces.remove(iterator.retrieve());
//		}
//		else
//			tmp.insert(iterator.retrieve());
//
//		iterator.advance();
//	}
//
//	pieces = tmp;
	cout << endl << "Pe�a do tipo " << piece << " associada ao fornecedor " << nome << " removida com sucesso !" << endl << endl;
}

void Oficina::displayBSTInfo() {

	BSTItrIn<Peca> it(pieces);

	if(it.isAtEnd())
	{
		cout << "N�o existem pe�as na BST " << endl << endl;
		return;
	}

	cout << "Informa��o da BST: " << endl << endl;

	while(!it.isAtEnd())
	{
		cout << "Fornecedor: " << it.retrieve().getSupplier() << endl;
		cout << "Pe�a: " << it.retrieve().getPieceType() << endl;
		cout << "Valor da �ltima compra: " << it.retrieve().getLastPurchasePrice() << endl << endl;
		it.advance();
	}

}

void Oficina::displayBrokenBikeInfo() {

	if(brokenBikes.size() == 0)
	{
		cout << "Neste momento n�o existem bicicletas avariadas !" << endl << endl;
		return;
	}

	cout << "Informa��es acerca das bicicletas avariadas" << endl << endl;

	string option;
	int value {};

	cout << "Bicicletas avariadas: " << endl;

	for(unsigned int i = 0; i < brokenBikes.size(); i++)
		cout << (i+1) << " -> " << brokenBikes.at(i)->getBikeName() << endl;

	while(1)
	{
		try {

			cout << endl << "Selecione uma bicicleta (1-" << brokenBikes.size() << "): ";
			cin >> option;

			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if(value < 1 || value > (int)brokenBikes.size())
				throw OpcaoInvalida<int>(value);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Bicicleta inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Bicicleta inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	system("cls");
	mensagemInicial();
	cout << "Informa��o: " << endl << endl;

	//Mostra informa��o relativa a bicicleta selecionada
	cout << "Nome: " << brokenBikes.at(value - 1)->getBikeName() << endl << endl;

	if(brokenBikes.at(value - 1)->getBikeName().at(0) == 'c')
		cout << "Tipo: Corrida" << endl << endl;
	else if(brokenBikes.at(value - 1)->getBikeName().at(0) == 'i')
		cout << "Tipo: Infantil" << endl << endl;
	else
	{
		if(brokenBikes.at(value - 1)->getBikeName().at(1) == 's')
			cout << "Tipo: Urbana Simples" << endl << endl;
		else
			cout << "Tipo: Urbana" << endl << endl;
	}

	cout << "Avarias:" << endl;

	for(unsigned int i = 0; i < brokenBikes.at(value - 1)->getAvarias().size(); i++)
		cout << " -> " << brokenBikes.at(value - 1)->getAvarias().at(i) << endl;

	cout << endl;
}
