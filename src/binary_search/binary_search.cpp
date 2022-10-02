#include "binary_search.hpp"

float binarySearch(vector <float> arr, int low, int high, float search){
	while (low <= high) {
        int mid = low + (high - low) / 2;
 
        // Check if x is present at mid
        if (arr[mid] == search){
            return mid;
        }
 
        // If x greater, ignore left half
        if (arr[mid] < search){
            low = mid + 1;
        }
 
        // If x is smaller, ignore right half
        else{
            high = mid - 1;
        }
    }
 
    // if we reach here, then element was
    // not present
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

	//Ordena
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