#include "rb_functions.hpp"

/*
Nesta função é feita a busca dos elementos no arquivo de texto e inseridos na árvore rubronegra 
onde, no loop feito para a inserção dos elementos é calculado o tempo de inserção, ou seja, 
é calculado o tempo necessário para montar a estrutura da árvore em memória.
*/
void insertElements_rb(Tree_rb **t, Record_rb r, string textFile){
	clock_t start, end;

	ifstream file;
	string numberText;
	float number;

	file.open(textFile);

	if(file.is_open()){

		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);

			r.key = number;
			insertTree_rb(t, t, t, r);
			// cout << number << endl;
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << endl << "Tempo de execução da inserção da árvore rubronegra: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}

void searchAndRemoveElements_rb(Tree_rb **t, Record_rb r){
	clock_t start, end;

	ifstream file;
	string numberText;
	float number;

	file.open("text_files/numbersForSearch_10000.txt");

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);

			r.key = number;
			// cout << "Número a ser removido: " << r.key << endl;
			removeTree_rb(t, t, r);
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << "Tempo de execução da remoção da árvore rubronegra: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}