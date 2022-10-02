#include "binary_search.hpp"

void insertAndSearchElementsWithBinarySearch(string textFile){
	clock_t start,end;

	ifstream file;
	string numberText;
	float number;
	vector <float> token;

	file.open(textFile);	

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			number = stof(numberText);
			token.push_back(number);
		}

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}

	//Ordenando
	for(int i = 0; i < int(token.size()); i++){
		for(int j = i; j < int(token.size()); j++){
			if(token[i] > token[j]){
				swap(token[i], token[j]);
			}
		}
	}

	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << endl << "Tempo de execução da inserção e ordenamento do vetor: " << fixed << time_taken << " segundos." << endl;

	//Abrindo arquivo de elementos a serem pesquisados (DANDO ERRADO)
	file.open("text_files/numbersForSearch_10000.txt");

	int vetInicial, vetFinal, vetMeio;
	bool dadoEncontrado;
	float busca;

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			busca = stof(numberText);

			vetInicial = 1;
			vetFinal = int(token.size());
			dadoEncontrado = false;

			//Busca binária
			while(vetInicial <= vetFinal || dadoEncontrado == false){
				vetMeio = (vetInicial + vetFinal)/2;

				if(token[vetMeio] == busca){
					dadoEncontrado = true;
				}

				if(token[vetMeio] > busca){
					vetFinal = vetMeio - 1;
				}

				else{
					vetInicial = vetMeio + 1;
				}
			}

			//Exibir resultados
			if(dadoEncontrado == true){
				// cout << "Dado encontrado na posição: " << vetMeio << "\t\tDado: " << token[vetMeio] << endl;	
			}
			else{
				// cout << "Dado não encontrado." << endl;
			}
		}

		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    	cout << "Tempo de execução da pesquisa binária: " << fixed << time_taken << " segundos." << endl;

		file.close();
	}

	else{
		cout << "O arquivo não abriu." << endl;
		return;
	}
}