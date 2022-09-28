#include "readFile.hpp"

/*
Nesta função é feita a busca dos elementos no arquivo de texto e inseridos na árvore binária 
onde, no loop feito para a inserção dos elementos é calculado o tempo de inserção, ou seja, 
é calculado o tempo necessário para montar a estrutura da árvore em memória.
*/
void insertElements(Tree **t, Record r){
	clock_t start, end;

	ifstream file;
	string numberText;
	float number;

	string file1 = "randomNumbers_500.txt", file2 = "randomNumbers_5000.txt", file3 = "randomNumbers_50000.txt", file4 = "randomNumbers_500000.txt";
	int option = -1, cancel = -1;

	cout << endl << "Para selecionar o arquivo com 500 números aleatórios, digite 1." << endl;
	cout << "Para selecionar o arquivo com 5000 números aleatórios, digite 2." << endl;
	cout << "Para selecionar o arquivo com 50000 números aleatórios, digite 3." << endl;
	cout << "Para selecionar o arquivo com 500000 números aleatórios, digite 4." << endl << endl;

	while(cancel != 0){
		cout << "Opção: ";
		cin >> option;

		if(option == 1){
			file.open("randomNumbers_500.txt");
			cancel = 0;
		}
		else if(option == 2){
			file.open("randomNumbers_5000.txt");
			cancel = 0;
		}
		else if(option == 3){
			file.open("randomNumbers_50000.txt");
			cancel = 0;
		}
		else if(option == 4){
			file.open("randomNumbers_500000.txt");
			cancel = 0;
		}
		else{
			cout << "Opção inválida, digite novamente." << endl;
		}
	}

	if(file.is_open()){

		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);

			r.key = number;
			r.value = 1;
			insertTree(t, r);
			// cout << number << endl;
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << endl << "Tempo de execução da inserção: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}


/*
Nesta função é feita a busca dos 10000 elementos do arquivo de texto na árvore binária a fim de
remover os mesmos da árvore, se existirem.
*/

void searchAndRemoveElements(Tree **t, Record r){
	clock_t start, end;

	ifstream file;
	string numberText;
	float number;

	file.open("numbersForSearch_10000.txt");

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);

			r.key = number;
			removeTree(t, r);
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << "Tempo de execução da remoção: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}