#include "u_map.hpp"

void insertElements_umap(unordered_map <float, float> u_map, string textFile){
	clock_t start, end;

	ifstream file;
	string numberText;
	float number, key;

	file.open(textFile);

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);
			key = number;

			u_map.emplace(key, number);
		}
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << endl << "Tempo de execução da inserção do unordered_map: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}

void searchElements_umap(unordered_map <float, float> u_map){
	clock_t start, end;

	ifstream file;
	string numberText;
	float key, find;

	file.open("text_files/numbersForSearch_10000.txt");

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			key = stof(numberText);

			find = u_map[key];

			if(find != 0){
				cout << "u_map: " << find << endl;
			}
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << "Tempo de execução da pesquisa do unordered_map: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}