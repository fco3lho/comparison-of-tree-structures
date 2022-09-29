#include "avl_functions.hpp"

/*
Nesta função é feita a busca dos elementos no arquivo de texto e inseridos na árvore AVL 
onde, no loop feito para a inserção dos elementos é calculado o tempo de inserção, ou seja, 
é calculado o tempo necessário para montar a estrutura da árvore em memória.
*/
void insertElements_avl_tree(avl_Tree **t, Record_avl_tree r, string textFile){
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
			r.value = 1;
			insertTree_avl(t, r);
			// cout << number << endl;
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << endl << "Tempo de execução da inserção na árvore AVL: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}

/*
Nesta função é feita a busca dos 10000 elementos do arquivo de texto na árvore AVL a fim de
remover os mesmos da árvore, se existirem.
*/
void searchAndRemoveElements_avl_tree(avl_Tree **t, Record_avl_tree r){
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
			removeTree_avl(t, t, r);
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << "Tempo de execução da remoção da árvore AVL: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}