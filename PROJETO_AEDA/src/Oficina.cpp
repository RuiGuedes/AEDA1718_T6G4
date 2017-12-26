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

void Oficina::displayBrokenBikeInfo() {

	if(brokenBikes.size() == 0)
	{
		cout << "Neste momento não existem bicicletas avariadas !" << endl << endl;
		return;
	}

	cout << "Informações acerca das bicicletas avariadas" << endl << endl;

	string option;
	int value {};

	cout << "Bicicletas avariadas: " << endl;

	for(unsigned int i = 0; i < brokenBikes.size(); i++)
		cout << (i+1) << " -> " << brokenBikes.at(i)->getBikeName() << endl;

	while(1)
	{
		try {

			cout << endl << "Selecione uma bicicleta (1-" << brokenBikes.size() << "):";
			cin >> option;

			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if(value < 1 || value > (int)brokenBikes.size())
				throw OpcaoInvalida<int>(value);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Bicicleta inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Bicicleta inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};


}
