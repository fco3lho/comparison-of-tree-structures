#include "u_map.hpp"

void insertAndSearchElements_umap(unordered_map <string, float> u_map, string textFile){
	clock_t start, end;

	ifstream file;
	string numberText, key;
	float number;

	//Insere
	file.open(textFile);

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			key = numberText;
			number = stof(numberText);

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

	//Pesquisa
	file.open("text_files/numbersForSearch_10000.txt");

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			key = numberText;

			if(u_map.find(key) == u_map.end()){
				// cout << "";
			}
			else{
				// cout << "umap: " << u_map[key] << endl;
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