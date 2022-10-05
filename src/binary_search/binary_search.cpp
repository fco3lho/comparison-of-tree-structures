#include "binary_search.hpp"

void printArray(vector <float> arr, int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }
}

float binarySearch(vector <float> arr, int low, int high, float search){
	while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] == search){
            return mid;
        }
 
        if (arr[mid] < search){
            low = mid + 1;
        }
 
        else{
            high = mid - 1;
        }
    }

    return -1;
}

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

	////////////////// Ordenação do vetor

	//Inicia Heap Sort
	int left = 0;
	int right = int(token.size());

	while(right > 0){
		right = right - 1;
		
		//Inicia Build Heap
		left = right/2;
		while(left > 0){
			left = left - 1;

			//Inicia Rebuild Heap
			int i = left;
			int child = (left > 0) ? (i*2):1;

			if((child+1 < int(token.size())) && (token[child] < token[child+1])){
				child += 1;
			}

			if(token[i] < token[child]){
				swap(token[i], token[child]);
			}
			//Termina Rebuild Heap
		}
		//Termica Build Heap

		swap(token[left], token[right]);
	}
	//Termina Heap Sort

	// printArray(token, int(token.size())); 

	////////////////// Fim da oredenação do vetor

	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << endl << "Tempo de execução da inserção e ordenamento do vetor: " << fixed << time_taken << " segundos." << endl;

    //A partir daqui faz a pesquisa com os 10000 elementos.
	file.open("text_files/numbersForSearch_10000.txt");

	float busca;
	int n = int(token.size()) - 1, low = 0, result;

	if(file.is_open()){
		start = clock();

		while(!file.eof()){
			getline(file, numberText);
			busca = stof(numberText);

			result = binarySearch(token, low, n, busca);

			//Condição para, se <result> for diferente de -1, ou seja, se o elemento existir no vetor, imprimi-lo junto com seu index.
			if (result == -1){
			}
			else{
				// cout << "Element is present at index " << result << ": " << token[result] << endl;
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